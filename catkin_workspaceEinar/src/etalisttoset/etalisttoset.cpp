//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etalisttoset.cpp
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
#include "etalisttoset.h"
#include "etalisttoset_private.h"
#define etalisttoset_MessageQueueLen   (1)

// Block signals (auto storage)
B_etalisttoset_T etalisttoset_B;

// Block states (auto storage)
DW_etalisttoset_T etalisttoset_DW;

// Real-time model
RT_MODEL_etalisttoset_T etalisttoset_M_;
RT_MODEL_etalisttoset_T *const etalisttoset_M = &etalisttoset_M_;
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void etalisttoset_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(etalisttoset_M, 1));
}

//
//   This function updates active task flag for each subrate
// and rate transition flags for tasks that exchange data.
// The function assumes rate-monotonic multitasking scheduler.
// The function must be called at model base rate so that
// the generated code self-manages all its subrates and rate
// transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (etalisttoset_M->Timing.TaskCounters.TID[1])++;
  if ((etalisttoset_M->Timing.TaskCounters.TID[1]) > 9) {// Sample time: [0.5s, 0.0s] 
    etalisttoset_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// Model step function for TID0
void etalisttoset_step0(void)          // Sample time: [0.05s, 0.0s]
{
  {                                    // Sample time: [0.05s, 0.0s]
    rate_monotonic_scheduler();
  }
}

// Model step function for TID1
void etalisttoset_step1(void)          // Sample time: [0.5s, 0.0s]
{
  int32_T NearestPointPos;
  real32_T a;
  real32_T b_a;
  boolean_T varargout_1;
  SL_Bus_etalisttoset_geometry_msgs_Vector3 rtb_BusAssignment1;
  int32_T i;
  int8_T varargin_1_idx_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   MATLABSystem: '<S3>/SourceBlock'

  varargout_1 = Sub_etalisttoset_694.get_latest_msg(&etalisttoset_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S7>/In1'

  if (varargout_1) {
    etalisttoset_B.In1 = etalisttoset_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<S4>/Subscribe2'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   MATLABSystem: '<S8>/SourceBlock'

  varargout_1 = Sub_etalisttoset_699.get_latest_msg
    (&etalisttoset_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  if (varargout_1) {
    etalisttoset_B.In1_p = etalisttoset_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S4>/Subscribe2'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport2'

  // MATLAB Function 'MATLAB Function': '<S2>:1'
  // '<S2>:1:2'
  // '<S2>:1:5'
  // save('TESTlist2Eta')
  // '<S2>:1:8'
  // '<S2>:1:9'
  // '<S2>:1:11'
  NearestPointPos = 3;

  // '<S2>:1:12'
  // '<S2>:1:13'
  for (i = 0; i < 64; i++) {
    etalisttoset_B.Values[i] = etalisttoset_B.In1.Data[i];
    etalisttoset_B.Values[i + 64] = etalisttoset_B.In1.Data[64 + i];

    // '<S2>:1:13'
    // '<S2>:1:14'
    a = (real32_T)etalisttoset_B.In1_p.Y - etalisttoset_B.Values[i];
    b_a = (real32_T)etalisttoset_B.In1_p.X - etalisttoset_B.Values[64 + i];
    if (a * a + b_a * b_a < 1000.0F) {
      // '<S2>:1:15'
      // '<S2>:1:17'
      NearestPointPos = i;
    }

    // '<S2>:1:13'
  }

  // [Avstand NearestPointPos]=min((sum((abs(Values-repmat(eta,Z/2,1))).^2')));
  // '<S2>:1:28'
  varargin_1_idx_1 = (int8_T)(NearestPointPos - 2);
  NearestPointPos = 1;
  if (varargin_1_idx_1 > 1) {
    NearestPointPos = varargin_1_idx_1;
  }

  // BusAssignment: '<S1>/Bus Assignment1' incorporates:
  //   Constant: '<S1>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function'

  // '<S2>:1:29'
  // '<S2>:1:30'
  // etaset = u;11
  rtb_BusAssignment1.X = etalisttoset_B.Values[NearestPointPos + 63];
  rtb_BusAssignment1.Y = etalisttoset_B.Values[NearestPointPos - 1];
  rtb_BusAssignment1.Z = etalisttoset_P.Constant_Value_c;

  // Outputs for Atomic SubSystem: '<S1>/Publish1'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_etalisttoset_692.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<S1>/Publish1'
}

// Model step wrapper function for compatibility with a static main program
void etalisttoset_step(int_T tid)
{
  switch (tid) {
   case 0 :
    etalisttoset_step0();
    break;

   case 1 :
    etalisttoset_step1();
    break;

   default :
    break;
  }
}

// Model initialize function
void etalisttoset_initialize(void)
{
  // Registration code

  // initialize real-time model
  (void) memset((void *)etalisttoset_M, 0,
                sizeof(RT_MODEL_etalisttoset_T));

  // block I/O
  (void) memset(((void *) &etalisttoset_B), 0,
                sizeof(B_etalisttoset_T));

  // states (dwork)
  (void) memset((void *)&etalisttoset_DW, 0,
                sizeof(DW_etalisttoset_T));

  {
    static const char_T tmp[7] = { '/', 'E', 't', 'a', 'S', 'e', 't' };

    static const char_T tmp_0[11] = { '/', 'E', 't', 'a', 'S', 'e', 't', 'L',
      'i', 's', 't' };

    char_T tmp_1[8];
    char_T tmp_2[5];
    char_T tmp_3[12];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S3>/SourceBlock'
    etalisttoset_DW.obj_l.isInitialized = 0;
    etalisttoset_DW.objisempty_g = true;
    etalisttoset_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[11] = '\x00';
    Sub_etalisttoset_694.create_subscriber(tmp_3, etalisttoset_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SourceBlock'

    // Start for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S7>/Out1'
    etalisttoset_B.In1 = etalisttoset_P.Out1_Y0;

    // End of Start for SubSystem: '<S3>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<S4>/Subscribe2'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    etalisttoset_DW.obj_i.isInitialized = 0;
    etalisttoset_DW.objisempty = true;
    etalisttoset_DW.obj_i.isInitialized = 1;
    tmp_2[0] = '/';
    tmp_2[1] = 'E';
    tmp_2[2] = 't';
    tmp_2[3] = 'a';
    tmp_2[4] = '\x00';
    Sub_etalisttoset_699.create_subscriber(tmp_2, etalisttoset_MessageQueueLen);

    // Start for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S9>/Out1'
    etalisttoset_B.In1_p = etalisttoset_P.Out1_Y0_c;

    // End of Start for SubSystem: '<S8>/Enabled Subsystem'
    // End of Start for SubSystem: '<S4>/Subscribe2'

    // Start for Atomic SubSystem: '<S1>/Publish1'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    etalisttoset_DW.obj.isInitialized = 0;
    etalisttoset_DW.objisempty_o = true;
    etalisttoset_DW.obj.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      tmp_1[i] = tmp[i];
    }

    tmp_1[7] = '\x00';
    Pub_etalisttoset_692.create_publisher(tmp_1, etalisttoset_MessageQueueLen);

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of Start for SubSystem: '<S1>/Publish1'
  }
}

// Model terminate function
void etalisttoset_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SourceBlock'

  if (etalisttoset_DW.obj_l.isInitialized == 1) {
    etalisttoset_DW.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<S4>/Subscribe2'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SourceBlock'

  if (etalisttoset_DW.obj_i.isInitialized == 1) {
    etalisttoset_DW.obj_i.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<S4>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S1>/Publish1'
  // Start for MATLABSystem: '<S6>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SinkBlock'

  if (etalisttoset_DW.obj.isInitialized == 1) {
    etalisttoset_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
