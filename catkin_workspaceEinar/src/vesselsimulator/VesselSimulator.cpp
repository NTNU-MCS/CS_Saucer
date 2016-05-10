//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: VesselSimulator.cpp
//
// Code generated for Simulink model 'VesselSimulator'.
//
// Model version                  : 1.21
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sun Apr 10 13:39:52 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "VesselSimulator.h"
#include "VesselSimulator_private.h"
#define VesselSimulator_MessageQueueLen (1)

// Block signals (auto storage)
B_VesselSimulator_T VesselSimulator_B;

// Continuous states
X_VesselSimulator_T VesselSimulator_X;

// Block states (auto storage)
DW_VesselSimulator_T VesselSimulator_DW;

// Real-time model
RT_MODEL_VesselSimulator_T VesselSimulator_M_;
RT_MODEL_VesselSimulator_T *const VesselSimulator_M = &VesselSimulator_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  VesselSimulator_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  VesselSimulator_step();
  VesselSimulator_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  VesselSimulator_step();
  VesselSimulator_derivatives();

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
void VesselSimulator_step(void)
{
  static const int8_T b[3] = { 0, 0, 1 };

  boolean_T varargout_1;
  int32_T i;
  real_T tmp[3];
  real_T tmp_0[3];
  if (rtmIsMajorTimeStep(VesselSimulator_M)) {
    // set solver stop time
    if (!(VesselSimulator_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&VesselSimulator_M->solverInfo,
                            ((VesselSimulator_M->Timing.clockTickH0 + 1) *
        VesselSimulator_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&VesselSimulator_M->solverInfo,
                            ((VesselSimulator_M->Timing.clockTick0 + 1) *
        VesselSimulator_M->Timing.stepSize0 +
        VesselSimulator_M->Timing.clockTickH0 *
        VesselSimulator_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(VesselSimulator_M)) {
    VesselSimulator_M->Timing.t[0] = rtsiGetT(&VesselSimulator_M->solverInfo);
  }

  // BusAssignment: '<S2>/Bus Assignment1' incorporates:
  //   Integrator: '<S3>/Integrator1'

  VesselSimulator_B.BusAssignment1.X = VesselSimulator_X.Integrator1_CSTATE[0];
  VesselSimulator_B.BusAssignment1.Y = VesselSimulator_X.Integrator1_CSTATE[1];
  VesselSimulator_B.BusAssignment1.Z = VesselSimulator_X.Integrator1_CSTATE[2];

  // Outputs for Atomic SubSystem: '<S2>/Publish1'
  // MATLABSystem: '<S7>/SinkBlock'
  Pub_VesselSimulator_269.publish(&VesselSimulator_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S2>/Publish1'
  if (rtmIsMajorTimeStep(VesselSimulator_M)) {
    // Outputs for Atomic SubSystem: '<S1>/Subscribe1'
    // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   MATLABSystem: '<S4>/SourceBlock'

    varargout_1 = Sub_VesselSimulator_22.get_latest_msg
      (&VesselSimulator_B.BusAssignment1);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S5>/Enable'

    // MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   Inport: '<S5>/In1'

    if (varargout_1) {
      VesselSimulator_B.In1 = VesselSimulator_B.BusAssignment1;
    }

    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S1>/Subscribe1'

    // Product: '<Root>/Product' incorporates:
    //   Constant: '<Root>/Thrust allocation Matrix'
    //   SignalConversion: '<Root>/TmpSignal ConversionAtProductInport2'

    for (i = 0; i < 3; i++) {
      VesselSimulator_B.Product[i] = 0.0;
      VesselSimulator_B.Product[i] += VesselSimulator_P.Tr[i] *
        VesselSimulator_B.In1.X;
      VesselSimulator_B.Product[i] += VesselSimulator_P.Tr[i + 3] *
        VesselSimulator_B.In1.Y;
      VesselSimulator_B.Product[i] += VesselSimulator_P.Tr[i + 6] *
        VesselSimulator_B.In1.Z;
    }

    // End of Product: '<Root>/Product'
  }

  // MATLAB Function: '<S3>/D_nu' incorporates:
  //   Constant: '<S3>/Constant'
  //   Integrator: '<S3>/Integrator2'

  // MATLAB Function 'Vessel Dynamics/D_nu': '<S9>:1'
  // '<S9>:1:3'
  // '<S9>:1:4'
  // MATLAB Function 'Vessel Dynamics/C_nu1': '<S8>:1'
  // '<S8>:1:3'
  // '<S8>:1:4'
  VesselSimulator_B.dv0[0] = VesselSimulator_P.D_nuParams[0] * fabs
    (VesselSimulator_X.Integrator2_CSTATE[0]);
  VesselSimulator_B.dv0[3] = 0.0;
  VesselSimulator_B.dv0[6] = 0.0;
  VesselSimulator_B.dv0[1] = 0.0;
  VesselSimulator_B.dv0[4] = VesselSimulator_P.D_nuParams[4] * fabs
    (VesselSimulator_X.Integrator2_CSTATE[1]);
  VesselSimulator_B.dv0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    VesselSimulator_B.dv0[2 + 3 * i] = 0.0;

    // Sum: '<S3>/Add' incorporates:
    //   Gain: '<S3>/Gain1'

    VesselSimulator_B.dv2[i] = 0.0 - ((VesselSimulator_P.D[i + 3] *
      VesselSimulator_X.Integrator2_CSTATE[1] + VesselSimulator_P.D[i] *
      VesselSimulator_X.Integrator2_CSTATE[0]) + VesselSimulator_P.D[i + 6] *
      VesselSimulator_X.Integrator2_CSTATE[2]);
  }

  // MATLAB Function: '<S3>/C_nu1' incorporates:
  //   Constant: '<S3>/Constant1'
  //   Integrator: '<S3>/Integrator2'

  VesselSimulator_B.dv1[0] = 0.0;
  VesselSimulator_B.dv1[3] = VesselSimulator_P.C_nuParams[3] *
    VesselSimulator_X.Integrator2_CSTATE[2];
  VesselSimulator_B.dv1[6] = 0.0;
  VesselSimulator_B.dv1[1] = VesselSimulator_P.C_nuParams[1] *
    VesselSimulator_X.Integrator2_CSTATE[2];
  VesselSimulator_B.dv1[4] = 0.0;
  VesselSimulator_B.dv1[7] = 0.0;
  for (i = 0; i < 3; i++) {
    // MATLAB Function: '<S3>/C_nu1'
    VesselSimulator_B.dv1[2 + 3 * i] = 0.0;

    // MATLAB Function: '<S3>/D_nu' incorporates:
    //   Integrator: '<S3>/Integrator2'
    //   Sum: '<S3>/Add'

    tmp[i] = 0.0 * VesselSimulator_X.Integrator2_CSTATE[2] +
      (VesselSimulator_B.dv0[i + 3] * VesselSimulator_X.Integrator2_CSTATE[1] +
       VesselSimulator_B.dv0[i] * VesselSimulator_X.Integrator2_CSTATE[0]);
  }

  // Sum: '<S3>/Sum' incorporates:
  //   Gain: '<S3>/Gain'
  //   Integrator: '<S3>/Integrator2'
  //   MATLAB Function: '<S3>/C_nu1'
  //   Sum: '<S3>/Add'
  //   Sum: '<S3>/Add1'

  for (i = 0; i < 3; i++) {
    tmp_0[i] = ((VesselSimulator_B.dv2[i] - tmp[i]) - ((VesselSimulator_B.dv1[i
      + 3] * VesselSimulator_X.Integrator2_CSTATE[1] + VesselSimulator_B.dv1[i] *
      VesselSimulator_X.Integrator2_CSTATE[0]) + 0.0 *
      VesselSimulator_X.Integrator2_CSTATE[2])) + VesselSimulator_B.Product[i];
  }

  // End of Sum: '<S3>/Sum'

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   Integrator: '<S3>/Integrator1'

  // MATLAB Function 'Vessel Dynamics/MATLAB Function': '<S10>:1'
  // '<S10>:1:2'
  // R=[RotPhi(1:2,:);[0 0 0;0 0 0;0 0 0];RotPhi(3,:)]
  VesselSimulator_B.dv0[0] = cos(VesselSimulator_X.Integrator1_CSTATE[2]);
  VesselSimulator_B.dv0[3] = -sin(VesselSimulator_X.Integrator1_CSTATE[2]);
  VesselSimulator_B.dv0[6] = 0.0;
  VesselSimulator_B.dv0[1] = sin(VesselSimulator_X.Integrator1_CSTATE[2]);
  VesselSimulator_B.dv0[4] = cos(VesselSimulator_X.Integrator1_CSTATE[2]);
  VesselSimulator_B.dv0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    // Gain: '<S3>/Gain'
    VesselSimulator_B.Gain[i] = 0.0;
    VesselSimulator_B.Gain[i] += VesselSimulator_P.invM[i] * tmp_0[0];
    VesselSimulator_B.Gain[i] += VesselSimulator_P.invM[i + 3] * tmp_0[1];
    VesselSimulator_B.Gain[i] += VesselSimulator_P.invM[i + 6] * tmp_0[2];

    // MATLAB Function: '<S3>/MATLAB Function' incorporates:
    //   Product: '<S3>/Product2'

    VesselSimulator_B.dv0[2 + 3 * i] = b[i];
  }

  // Product: '<S3>/Product2' incorporates:
  //   Integrator: '<S3>/Integrator2'

  for (i = 0; i < 3; i++) {
    VesselSimulator_B.Product2[i] = 0.0;
    VesselSimulator_B.Product2[i] += VesselSimulator_B.dv0[i] *
      VesselSimulator_X.Integrator2_CSTATE[0];
    VesselSimulator_B.Product2[i] += VesselSimulator_B.dv0[i + 3] *
      VesselSimulator_X.Integrator2_CSTATE[1];
    VesselSimulator_B.Product2[i] += VesselSimulator_B.dv0[i + 6] *
      VesselSimulator_X.Integrator2_CSTATE[2];
  }

  if (rtmIsMajorTimeStep(VesselSimulator_M)) {
    rt_ertODEUpdateContinuousStates(&VesselSimulator_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.
    //  Timer of this task consists of two 32 bit unsigned integers.
    //  The two integers represent the low bits Timing.clockTick0 and the high bits
    //  Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.

    if (!(++VesselSimulator_M->Timing.clockTick0)) {
      ++VesselSimulator_M->Timing.clockTickH0;
    }

    VesselSimulator_M->Timing.t[0] = rtsiGetSolverStopTime
      (&VesselSimulator_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.
      //  Timer of this task consists of two 32 bit unsigned integers.
      //  The two integers represent the low bits Timing.clockTick1 and the high bits
      //  Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.

      VesselSimulator_M->Timing.clockTick1++;
      if (!VesselSimulator_M->Timing.clockTick1) {
        VesselSimulator_M->Timing.clockTickH1++;
      }
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void VesselSimulator_derivatives(void)
{
  XDot_VesselSimulator_T *_rtXdot;
  _rtXdot = ((XDot_VesselSimulator_T *) VesselSimulator_M->ModelData.derivs);

  // Derivatives for Integrator: '<S3>/Integrator1'
  _rtXdot->Integrator1_CSTATE[0] = VesselSimulator_B.Product2[0];

  // Derivatives for Integrator: '<S3>/Integrator2'
  _rtXdot->Integrator2_CSTATE[0] = VesselSimulator_B.Gain[0];

  // Derivatives for Integrator: '<S3>/Integrator1'
  _rtXdot->Integrator1_CSTATE[1] = VesselSimulator_B.Product2[1];

  // Derivatives for Integrator: '<S3>/Integrator2'
  _rtXdot->Integrator2_CSTATE[1] = VesselSimulator_B.Gain[1];

  // Derivatives for Integrator: '<S3>/Integrator1'
  _rtXdot->Integrator1_CSTATE[2] = VesselSimulator_B.Product2[2];

  // Derivatives for Integrator: '<S3>/Integrator2'
  _rtXdot->Integrator2_CSTATE[2] = VesselSimulator_B.Gain[2];
}

// Model initialize function
void VesselSimulator_initialize(void)
{
  // Registration code

  // initialize real-time model
  (void) memset((void *)VesselSimulator_M, 0,
                sizeof(RT_MODEL_VesselSimulator_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&VesselSimulator_M->solverInfo,
                          &VesselSimulator_M->Timing.simTimeStep);
    rtsiSetTPtr(&VesselSimulator_M->solverInfo, &rtmGetTPtr(VesselSimulator_M));
    rtsiSetStepSizePtr(&VesselSimulator_M->solverInfo,
                       &VesselSimulator_M->Timing.stepSize0);
    rtsiSetdXPtr(&VesselSimulator_M->solverInfo,
                 &VesselSimulator_M->ModelData.derivs);
    rtsiSetContStatesPtr(&VesselSimulator_M->solverInfo, (real_T **)
                         &VesselSimulator_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&VesselSimulator_M->solverInfo,
      &VesselSimulator_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&VesselSimulator_M->solverInfo,
      &VesselSimulator_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&VesselSimulator_M->solverInfo,
      &VesselSimulator_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&VesselSimulator_M->solverInfo,
      &VesselSimulator_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&VesselSimulator_M->solverInfo, (&rtmGetErrorStatus
      (VesselSimulator_M)));
    rtsiSetRTModelPtr(&VesselSimulator_M->solverInfo, VesselSimulator_M);
  }

  rtsiSetSimTimeStep(&VesselSimulator_M->solverInfo, MAJOR_TIME_STEP);
  VesselSimulator_M->ModelData.intgData.y = VesselSimulator_M->ModelData.odeY;
  VesselSimulator_M->ModelData.intgData.f[0] = VesselSimulator_M->
    ModelData.odeF[0];
  VesselSimulator_M->ModelData.intgData.f[1] = VesselSimulator_M->
    ModelData.odeF[1];
  VesselSimulator_M->ModelData.intgData.f[2] = VesselSimulator_M->
    ModelData.odeF[2];
  VesselSimulator_M->ModelData.contStates = ((X_VesselSimulator_T *)
    &VesselSimulator_X);
  rtsiSetSolverData(&VesselSimulator_M->solverInfo, (void *)
                    &VesselSimulator_M->ModelData.intgData);
  rtsiSetSolverName(&VesselSimulator_M->solverInfo,"ode3");
  rtmSetTPtr(VesselSimulator_M, &VesselSimulator_M->Timing.tArray[0]);
  VesselSimulator_M->Timing.stepSize0 = 0.05;

  // block I/O
  (void) memset(((void *) &VesselSimulator_B), 0,
                sizeof(B_VesselSimulator_T));

  // states (continuous)
  {
    (void) memset((void *)&VesselSimulator_X, 0,
                  sizeof(X_VesselSimulator_T));
  }

  // states (dwork)
  (void) memset((void *)&VesselSimulator_DW, 0,
                sizeof(DW_VesselSimulator_T));

  {
    char_T tmp[3];
    char_T tmp_0[5];

    // Start for Atomic SubSystem: '<S2>/Publish1'
    // Start for MATLABSystem: '<S7>/SinkBlock'
    VesselSimulator_DW.obj_o.isInitialized = 0;
    VesselSimulator_DW.objisempty = true;
    VesselSimulator_DW.obj_o.isInitialized = 1;
    tmp_0[0] = '/';
    tmp_0[1] = 'E';
    tmp_0[2] = 't';
    tmp_0[3] = 'a';
    tmp_0[4] = '\x00';
    Pub_VesselSimulator_269.create_publisher(tmp_0,
      VesselSimulator_MessageQueueLen);

    // End of Start for SubSystem: '<S2>/Publish1'

    // Start for Atomic SubSystem: '<S1>/Subscribe1'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    VesselSimulator_DW.obj.isInitialized = 0;
    VesselSimulator_DW.objisempty_l = true;
    VesselSimulator_DW.obj.isInitialized = 1;
    tmp[0] = '/';
    tmp[1] = 'U';
    tmp[2] = '\x00';
    Sub_VesselSimulator_22.create_subscriber(tmp,
      VesselSimulator_MessageQueueLen);

    // Start for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S5>/Out1'
    VesselSimulator_B.In1 = VesselSimulator_P.Out1_Y0;

    // End of Start for SubSystem: '<S4>/Enabled Subsystem'
    // End of Start for SubSystem: '<S1>/Subscribe1'

    // InitializeConditions for Integrator: '<S3>/Integrator1'
    VesselSimulator_X.Integrator1_CSTATE[0] = VesselSimulator_P.Integrator1_IC[0];

    // InitializeConditions for Integrator: '<S3>/Integrator2'
    VesselSimulator_X.Integrator2_CSTATE[0] = VesselSimulator_P.Integrator2_IC[0];

    // InitializeConditions for Integrator: '<S3>/Integrator1'
    VesselSimulator_X.Integrator1_CSTATE[1] = VesselSimulator_P.Integrator1_IC[1];

    // InitializeConditions for Integrator: '<S3>/Integrator2'
    VesselSimulator_X.Integrator2_CSTATE[1] = VesselSimulator_P.Integrator2_IC[1];

    // InitializeConditions for Integrator: '<S3>/Integrator1'
    VesselSimulator_X.Integrator1_CSTATE[2] = VesselSimulator_P.Integrator1_IC[2];

    // InitializeConditions for Integrator: '<S3>/Integrator2'
    VesselSimulator_X.Integrator2_CSTATE[2] = VesselSimulator_P.Integrator2_IC[2];
  }
}

// Model terminate function
void VesselSimulator_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S2>/Publish1'
  // Start for MATLABSystem: '<S7>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SinkBlock'

  if (VesselSimulator_DW.obj_o.isInitialized == 1) {
    VesselSimulator_DW.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish1'

  // Terminate for Atomic SubSystem: '<S1>/Subscribe1'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (VesselSimulator_DW.obj.isInitialized == 1) {
    VesselSimulator_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<S1>/Subscribe1'
}

//
// File trailer for generated code.
//
// [EOF]
//
