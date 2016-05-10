//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: provPos.cpp
//
// Code generated for Simulink model 'provPos'.
//
// Model version                  : 1.5
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Mon Feb 15 16:41:50 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "provPos.h"
#include "provPos_private.h"
#define provPos_MessageQueueLen        (1)
#define provPos_ParameterInitialValue  (0.0)

// Block signals (auto storage)
B_provPos_T provPos_B;

// Continuous states
X_provPos_T provPos_X;

// Block states (auto storage)
DW_provPos_T provPos_DW;

// Real-time model
RT_MODEL_provPos_T provPos_M_;
RT_MODEL_provPos_T *const provPos_M = &provPos_M_;

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
  provPos_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  provPos_step();
  provPos_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  provPos_step();
  provPos_derivatives();

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
void provPos_step(void)
{
  real_T varargout_1;
  boolean_T varargout_1_0;
  boolean_T p;
  SL_Bus_provPos_std_msgs_Float64 rtb_BusAssignment;
  if (rtmIsMajorTimeStep(provPos_M)) {
    // set solver stop time
    if (!(provPos_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&provPos_M->solverInfo,
                            ((provPos_M->Timing.clockTickH0 + 1) *
        provPos_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&provPos_M->solverInfo,
                            ((provPos_M->Timing.clockTick0 + 1) *
        provPos_M->Timing.stepSize0 + provPos_M->Timing.clockTickH0 *
        provPos_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(provPos_M)) {
    provPos_M->Timing.t[0] = rtsiGetT(&provPos_M->solverInfo);
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Integrator: '<Root>/Integrator'

  rtb_BusAssignment.Data = provPos_X.Integrator_CSTATE;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_provPos_15.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(provPos_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   MATLABSystem: '<S4>/SourceBlock'

    varargout_1_0 = Sub_provPos_2.get_latest_msg(&rtb_BusAssignment);

    // Outputs for Enabled SubSystem: '<Root>/Out' incorporates:
    //   EnablePort: '<S2>/Enable'

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S7>/Enable'

    // MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   Inport: '<S7>/In1'

    if (varargout_1_0) {
      provPos_B.In1 = rtb_BusAssignment;

      // Outputs for Atomic SubSystem: '<S2>/Publish'
      // MATLABSystem: '<S6>/SinkBlock' incorporates:
      //   BusAssignment: '<S2>/Bus Assignment'
      //   Inport: '<S7>/In1'

      Pub_provPos_3.publish(&provPos_B.In1);

      // End of Outputs for SubSystem: '<S2>/Publish'
    }

    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Out'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Start for MATLABSystem: '<Root>/Get Parameter' incorporates:
    //   MATLABSystem: '<Root>/Get Parameter'

    varargout_1_0 = false;
    p = true;
    if (!(provPos_DW.obj.SampleTime == provPos_P.GetParameter_SampleTime)) {
      p = false;
    }

    if (p) {
      varargout_1_0 = true;
    }

    if (!varargout_1_0) {
      provPos_DW.obj.SampleTime = provPos_P.GetParameter_SampleTime;
    }

    ParamGet_provPos_20.get_parameter(&varargout_1);

    // End of Start for MATLABSystem: '<Root>/Get Parameter'

    // MATLABSystem: '<Root>/Set Parameter' incorporates:
    //   Constant: '<Root>/Kp1'

    ParamSet_provPos_16.set_parameter(provPos_P.Kp1_Value);

    // MATLABSystem: '<Root>/Set Parameter1' incorporates:
    //   Constant: '<Root>/Kp2'

    ParamSet_provPos_19.set_parameter(provPos_P.Kp2_Value);
  }

  if (rtmIsMajorTimeStep(provPos_M)) {
    rt_ertODEUpdateContinuousStates(&provPos_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.
    //  Timer of this task consists of two 32 bit unsigned integers.
    //  The two integers represent the low bits Timing.clockTick0 and the high bits
    //  Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.

    if (!(++provPos_M->Timing.clockTick0)) {
      ++provPos_M->Timing.clockTickH0;
    }

    provPos_M->Timing.t[0] = rtsiGetSolverStopTime(&provPos_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.
      //  Timer of this task consists of two 32 bit unsigned integers.
      //  The two integers represent the low bits Timing.clockTick1 and the high bits
      //  Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.

      provPos_M->Timing.clockTick1++;
      if (!provPos_M->Timing.clockTick1) {
        provPos_M->Timing.clockTickH1++;
      }
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void provPos_derivatives(void)
{
  XDot_provPos_T *_rtXdot;
  _rtXdot = ((XDot_provPos_T *) provPos_M->ModelData.derivs);

  // Derivatives for Integrator: '<Root>/Integrator' incorporates:
  //   Constant: '<Root>/Constant'

  _rtXdot->Integrator_CSTATE = provPos_P.Constant_Value;
}

// Model initialize function
void provPos_initialize(void)
{
  // Registration code

  // initialize real-time model
  (void) memset((void *)provPos_M, 0,
                sizeof(RT_MODEL_provPos_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&provPos_M->solverInfo, &provPos_M->Timing.simTimeStep);
    rtsiSetTPtr(&provPos_M->solverInfo, &rtmGetTPtr(provPos_M));
    rtsiSetStepSizePtr(&provPos_M->solverInfo, &provPos_M->Timing.stepSize0);
    rtsiSetdXPtr(&provPos_M->solverInfo, &provPos_M->ModelData.derivs);
    rtsiSetContStatesPtr(&provPos_M->solverInfo, (real_T **)
                         &provPos_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&provPos_M->solverInfo,
      &provPos_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&provPos_M->solverInfo,
      &provPos_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&provPos_M->solverInfo,
      &provPos_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&provPos_M->solverInfo,
      &provPos_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&provPos_M->solverInfo, (&rtmGetErrorStatus(provPos_M)));
    rtsiSetRTModelPtr(&provPos_M->solverInfo, provPos_M);
  }

  rtsiSetSimTimeStep(&provPos_M->solverInfo, MAJOR_TIME_STEP);
  provPos_M->ModelData.intgData.y = provPos_M->ModelData.odeY;
  provPos_M->ModelData.intgData.f[0] = provPos_M->ModelData.odeF[0];
  provPos_M->ModelData.intgData.f[1] = provPos_M->ModelData.odeF[1];
  provPos_M->ModelData.intgData.f[2] = provPos_M->ModelData.odeF[2];
  provPos_M->ModelData.contStates = ((X_provPos_T *) &provPos_X);
  rtsiSetSolverData(&provPos_M->solverInfo, (void *)
                    &provPos_M->ModelData.intgData);
  rtsiSetSolverName(&provPos_M->solverInfo,"ode3");
  rtmSetTPtr(provPos_M, &provPos_M->Timing.tArray[0]);
  provPos_M->Timing.stepSize0 = 0.05;

  // block I/O
  (void) memset(((void *) &provPos_B), 0,
                sizeof(B_provPos_T));

  // states (continuous)
  {
    (void) memset((void *)&provPos_X, 0,
                  sizeof(X_provPos_T));
  }

  // states (dwork)
  (void) memset((void *)&provPos_DW, 0,
                sizeof(DW_provPos_T));

  {
    static const char_T tmp[10] = { '/', 'm', 'y', '_', 'p', 'a', 'r', 'a', 'm',
      '2' };

    static const char_T tmp_0[9] = { '/', 'm', 'y', '_', 'p', 'a', 'r', 'a', 'm'
    };

    static const char_T tmp_1[10] = { '/', 'm', 'y', '_', 'p', 'a', 'r', 'a',
      'm', '3' };

    static const char_T tmp_2[13] = { '/', 'P', 'r', 'e', 'f', 'P', 'o', 's',
      'i', 't', 'i', 'o', 'n' };

    static const char_T tmp_3[9] = { '/', 'S', 'i', 'm', 'u', 'T', 'i', 'm', 'e'
    };

    char_T tmp_4[11];
    char_T tmp_5[5];
    char_T tmp_6[14];
    char_T tmp_7[10];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    provPos_DW.obj_g.isInitialized = 0;
    provPos_DW.objisempty_o = true;
    provPos_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_7[i] = tmp_3[i];
    }

    tmp_7[9] = '\x00';
    Pub_provPos_15.create_publisher(tmp_7, provPos_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    provPos_DW.obj_gv.isInitialized = 0;
    provPos_DW.objisempty = true;
    provPos_DW.obj_gv.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_6[i] = tmp_2[i];
    }

    tmp_6[13] = '\x00';
    Sub_provPos_2.create_subscriber(tmp_6, provPos_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SourceBlock'

    // Start for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S7>/Out1'
    provPos_B.In1 = provPos_P.Out1_Y0;

    // End of Start for SubSystem: '<S4>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Enabled SubSystem: '<Root>/Out'
    // Start for Atomic SubSystem: '<S2>/Publish'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    provPos_DW.obj_h.isInitialized = 0;
    provPos_DW.objisempty_j = true;
    provPos_DW.obj_h.isInitialized = 1;
    tmp_5[0] = '/';
    tmp_5[1] = 'P';
    tmp_5[2] = 'W';
    tmp_5[3] = 'M';
    tmp_5[4] = '\x00';
    Pub_provPos_3.create_publisher(tmp_5, provPos_MessageQueueLen);

    // End of Start for SubSystem: '<S2>/Publish'
    // End of Start for SubSystem: '<Root>/Out'

    // Start for MATLABSystem: '<Root>/Get Parameter'
    provPos_DW.obj.isInitialized = 0;
    provPos_DW.objisempty_b = true;
    provPos_DW.obj.SampleTime = provPos_P.GetParameter_SampleTime;
    provPos_DW.obj.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[10] = '\x00';
    ParamGet_provPos_20.initialize(tmp_4, provPos_ParameterInitialValue, 0U, 1U,
      2U);

    // End of Start for MATLABSystem: '<Root>/Get Parameter'

    // Start for MATLABSystem: '<Root>/Set Parameter'
    provPos_DW.obj_k.isInitialized = 0;
    provPos_DW.objisempty_n = true;
    provPos_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_7[i] = tmp_0[i];
    }

    tmp_7[9] = '\x00';
    ParamSet_provPos_16.initialize(tmp_7);

    // End of Start for MATLABSystem: '<Root>/Set Parameter'

    // Start for MATLABSystem: '<Root>/Set Parameter1'
    provPos_DW.obj_n.isInitialized = 0;
    provPos_DW.objisempty_bi = true;
    provPos_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      tmp_4[i] = tmp[i];
    }

    tmp_4[10] = '\x00';
    ParamSet_provPos_19.initialize(tmp_4);

    // End of Start for MATLABSystem: '<Root>/Set Parameter1'

    // InitializeConditions for Integrator: '<Root>/Integrator'
    provPos_X.Integrator_CSTATE = provPos_P.Integrator_IC;
  }
}

// Model terminate function
void provPos_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SinkBlock'

  if (provPos_DW.obj_g.isInitialized == 1) {
    provPos_DW.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (provPos_DW.obj_gv.isInitialized == 1) {
    provPos_DW.obj_gv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Enabled SubSystem: '<Root>/Out'
  // Terminate for Atomic SubSystem: '<S2>/Publish'
  // Start for MATLABSystem: '<S6>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SinkBlock'

  if (provPos_DW.obj_h.isInitialized == 1) {
    provPos_DW.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish'
  // End of Terminate for SubSystem: '<Root>/Out'

  // Start for MATLABSystem: '<Root>/Get Parameter' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Get Parameter'

  if (provPos_DW.obj.isInitialized == 1) {
    provPos_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Get Parameter'

  // Start for MATLABSystem: '<Root>/Set Parameter' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Set Parameter'

  if (provPos_DW.obj_k.isInitialized == 1) {
    provPos_DW.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Set Parameter'

  // Start for MATLABSystem: '<Root>/Set Parameter1' incorporates:
  //   Terminate for MATLABSystem: '<Root>/Set Parameter1'

  if (provPos_DW.obj_n.isInitialized == 1) {
    provPos_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<Root>/Set Parameter1'
}

//
// File trailer for generated code.
//
// [EOF]
//
