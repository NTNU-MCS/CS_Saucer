//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'etalisttoset'.
//
// Model version                  : 1.31
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Tue Apr 12 13:16:37 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stdio.h>
#include <stdlib.h>
#include "etalisttoset.h"
#include "etalisttoset_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"

volatile boolean_T runModel = 1;
sem_t stopSem;
sem_t termSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[1];
int taskId[1];
pthread_t terminateThread;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
pthread_t subRateThread[1];
int subratePriority[1];
void subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    etalisttoset_step(subRateId);

    // Get model outputs here
  }

  pthread_exit((void *)0);
}

void baseRateTask(void *arg)
{
  int_T i;
  runModel = (rtmGetErrorStatus(etalisttoset_M) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    if (rtmStepTask(etalisttoset_M, 1)
        ) {
      sem_post(&subrateTaskSem[0]);
    }

    etalisttoset_step(0);

    // Get model outputs here
    runModel = (rtmGetErrorStatus(etalisttoset_M) == (NULL));
  }

  sem_post(&termSem);
  pthread_exit((void *)0);
}

void exitTask(int sig)
{
  rtmSetErrorStatus(etalisttoset_M, "stopping the model");
}

void terminateTask(void *arg)
{
  int i;
  int ret;
  sem_wait(&termSem);
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  // Signal all periodic tasks to complete
  for (i=0;i<1;i++) {
    CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
    CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
  }

  // Wait for all periodic tasks to complete
  for (i=0;i<1;i++) {
    ret = pthread_join(subRateThread[i], (void *)&threadJoinStatus);
    CHECK_STATUS(ret, 0, "pthread_join");
  }

  // Wait for baseRate task to complete
  ret = pthread_join(baseRateThread, (void *)&threadJoinStatus);
  CHECK_STATUS(ret, 0, "pthread_join");

  // Disable rt_OneStep() here

  // Terminate model
  etalisttoset_terminate();
  sem_post(&stopSem);
}

int main(int argc, char **argv)
{
  subratePriority[0] = 41;
  void slros_node_init(int argc, char** argv);
  slros_node_init(argc, argv);
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(etalisttoset_M, 0);

  // Initialize model
  etalisttoset_initialize();

  // Call RTOS Initialization funcation
  myRTOSInit(0.05, 1);

  // Wait for stop semaphore
  sem_wait(&stopSem);
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
