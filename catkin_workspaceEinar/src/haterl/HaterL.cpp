//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: HaterL.cpp
//
// Code generated for Simulink model 'HaterL'.
//
// Model version                  : 1.2
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Mon Feb 15 16:02:13 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "HaterL.h"
#include "HaterL_private.h"
#define HaterL_MessageQueueLen         (1)

// Block signals (auto storage)
B_HaterL_T HaterL_B;

// Continuous states
X_HaterL_T HaterL_X;

// Block states (auto storage)
DW_HaterL_T HaterL_DW;

// Real-time model
RT_MODEL_HaterL_T HaterL_M_;
RT_MODEL_HaterL_T *const HaterL_M = &HaterL_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  HaterL_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  HaterL_step();
  HaterL_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  HaterL_step();
  HaterL_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void HaterL_step(void)
{
  boolean_T varargout_1;
  SL_Bus_HaterL_std_msgs_Float64 rtb_BusAssignment;
  if (rtmIsMajorTimeStep(HaterL_M)) {
    // set solver stop time
    if (!(HaterL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&HaterL_M->solverInfo,
                            ((HaterL_M->Timing.clockTickH0 + 1) *
        HaterL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&HaterL_M->solverInfo, ((HaterL_M->Timing.clockTick0
        + 1) * HaterL_M->Timing.stepSize0 + HaterL_M->Timing.clockTickH0 *
        HaterL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(HaterL_M)) {
    HaterL_M->Timing.t[0] = rtsiGetT(&HaterL_M->solverInfo);
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Integrator: '<Root>/Integrator'

  rtb_BusAssignment.Data = HaterL_X.Integrator_CSTATE;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_HaterL_15.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(HaterL_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   MATLABSystem: '<S4>/SourceBlock'

    varargout_1 = Sub_HaterL_2.get_latest_msg(&rtb_BusAssignment);

    // Outputs for Enabled SubSystem: '<Root>/Out' incorporates:
    //   EnablePort: '<S2>/Enable'

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S7>/Enable'

    // MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   Inport: '<S7>/In1'

    if (varargout_1) {
      HaterL_B.In1 = rtb_BusAssignment;

      // Outputs for Atomic SubSystem: '<S2>/Publish'
      // MATLABSystem: '<S6>/SinkBlock' incorporates:
      //   BusAssignment: '<S2>/Bus Assignment'
      //   Inport: '<S7>/In1'

      Pub_HaterL_3.publish(&HaterL_B.In1);

      // End of Outputs for SubSystem: '<S2>/Publish'
    }

    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Out'
    // End of Outputs for SubSystem: '<Root>/Subscribe'
  }

  if (rtmIsMajorTimeStep(HaterL_M)) {
    rt_ertODEUpdateContinuousStates(&HaterL_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.
    //  Timer of this task consists of two 32 bit unsigned integers.
    //  The two integers represent the low bits Timing.clockTick0 and the high bits
    //  Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.

    if (!(++HaterL_M->Timing.clockTick0)) {
      ++HaterL_M->Timing.clockTickH0;
    }

    HaterL_M->Timing.t[0] = rtsiGetSolverStopTime(&HaterL_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.
      //  Timer of this task consists of two 32 bit unsigned integers.
      //  The two integers represent the low bits Timing.clockTick1 and the high bits
      //  Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.

      HaterL_M->Timing.clockTick1++;
      if (!HaterL_M->Timing.clockTick1) {
        HaterL_M->Timing.clockTickH1++;
      }
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void HaterL_derivatives(void)
{
  XDot_HaterL_T *_rtXdot;
  _rtXdot = ((XDot_HaterL_T *) HaterL_M->ModelData.derivs);

  // Derivatives for Integrator: '<Root>/Integrator' incorporates:
  //   Constant: '<Root>/Constant'

  _rtXdot->Integrator_CSTATE = HaterL_P.Constant_Value;
}

// Model initialize function
void HaterL_initialize(void)
{
  // Registration code

  // initialize real-time model
  (void) memset((void *)HaterL_M, 0,
                sizeof(RT_MODEL_HaterL_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&HaterL_M->solverInfo, &HaterL_M->Timing.simTimeStep);
    rtsiSetTPtr(&HaterL_M->solverInfo, &rtmGetTPtr(HaterL_M));
    rtsiSetStepSizePtr(&HaterL_M->solverInfo, &HaterL_M->Timing.stepSize0);
    rtsiSetdXPtr(&HaterL_M->solverInfo, &HaterL_M->ModelData.derivs);
    rtsiSetContStatesPtr(&HaterL_M->solverInfo, (real_T **)
                         &HaterL_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&HaterL_M->solverInfo,
      &HaterL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&HaterL_M->solverInfo,
      &HaterL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&HaterL_M->solverInfo,
      &HaterL_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&HaterL_M->solverInfo,
      &HaterL_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&HaterL_M->solverInfo, (&rtmGetErrorStatus(HaterL_M)));
    rtsiSetRTModelPtr(&HaterL_M->solverInfo, HaterL_M);
  }

  rtsiSetSimTimeStep(&HaterL_M->solverInfo, MAJOR_TIME_STEP);
  HaterL_M->ModelData.intgData.y = HaterL_M->ModelData.odeY;
  HaterL_M->ModelData.intgData.f[0] = HaterL_M->ModelData.odeF[0];
  HaterL_M->ModelData.intgData.f[1] = HaterL_M->ModelData.odeF[1];
  HaterL_M->ModelData.intgData.f[2] = HaterL_M->ModelData.odeF[2];
  HaterL_M->ModelData.contStates = ((X_HaterL_T *) &HaterL_X);
  rtsiSetSolverData(&HaterL_M->solverInfo, (void *)&HaterL_M->ModelData.intgData);
  rtsiSetSolverName(&HaterL_M->solverInfo,"ode3");
  rtmSetTPtr(HaterL_M, &HaterL_M->Timing.tArray[0]);
  HaterL_M->Timing.stepSize0 = 0.05;

  // block I/O
  (void) memset(((void *) &HaterL_B), 0,
                sizeof(B_HaterL_T));

  // states (continuous)
  {
    (void) memset((void *)&HaterL_X, 0,
                  sizeof(X_HaterL_T));
  }

  // states (dwork)
  (void) memset((void *)&HaterL_DW, 0,
                sizeof(DW_HaterL_T));

  {
    static const char_T tmp[13] = { '/', 'P', 'r', 'e', 'f', 'P', 'o', 's', 'i',
      't', 'i', 'o', 'n' };

    static const char_T tmp_0[9] = { '/', 'S', 'i', 'm', 'u', 'T', 'i', 'm', 'e'
    };

    char_T tmp_1[5];
    char_T tmp_2[14];
    char_T tmp_3[10];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    HaterL_DW.obj.isInitialized = 0;
    HaterL_DW.objisempty_o = true;
    HaterL_DW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[9] = '\x00';
    Pub_HaterL_15.create_publisher(tmp_3, HaterL_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    HaterL_DW.obj_g.isInitialized = 0;
    HaterL_DW.objisempty = true;
    HaterL_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[13] = '\x00';
    Sub_HaterL_2.create_subscriber(tmp_2, HaterL_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SourceBlock'

    // Start for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S7>/Out1'
    HaterL_B.In1 = HaterL_P.Out1_Y0;

    // End of Start for SubSystem: '<S4>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Enabled SubSystem: '<Root>/Out'
    // Start for Atomic SubSystem: '<S2>/Publish'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    HaterL_DW.obj_h.isInitialized = 0;
    HaterL_DW.objisempty_j = true;
    HaterL_DW.obj_h.isInitialized = 1;
    tmp_1[0] = '/';
    tmp_1[1] = 'P';
    tmp_1[2] = 'W';
    tmp_1[3] = 'M';
    tmp_1[4] = '\x00';
    Pub_HaterL_3.create_publisher(tmp_1, HaterL_MessageQueueLen);

    // End of Start for SubSystem: '<S2>/Publish'
    // End of Start for SubSystem: '<Root>/Out'

    // InitializeConditions for Integrator: '<Root>/Integrator'
    HaterL_X.Integrator_CSTATE = HaterL_P.Integrator_IC;
  }
}

// Model terminate function
void HaterL_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SinkBlock'

  if (HaterL_DW.obj.isInitialized == 1) {
    HaterL_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (HaterL_DW.obj_g.isInitialized == 1) {
    HaterL_DW.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Enabled SubSystem: '<Root>/Out'
  // Terminate for Atomic SubSystem: '<S2>/Publish'
  // Start for MATLABSystem: '<S6>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SinkBlock'

  if (HaterL_DW.obj_h.isInitialized == 1) {
    HaterL_DW.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish'
  // End of Terminate for SubSystem: '<Root>/Out'
}

//
// File trailer for generated code.
//
// [EOF]
//
