//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS_Controller.cpp
//
// Code generated for Simulink model 'ROS_Controller'.
//
// Model version                  : 1.24
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sun Apr 10 13:42:56 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ROS_Controller.h"
#include "ROS_Controller_private.h"
#define ROS_Controller_MessageQueueLen (1)

// Block signals (auto storage)
B_ROS_Controller_T ROS_Controller_B;

// Continuous states
X_ROS_Controller_T ROS_Controller_X;

// Block states (auto storage)
DW_ROS_Controller_T ROS_Controller_DW;

// Real-time model
RT_MODEL_ROS_Controller_T ROS_Controller_M_;
RT_MODEL_ROS_Controller_T *const ROS_Controller_M = &ROS_Controller_M_;

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
  int_T nXc = 24;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  ROS_Controller_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ROS_Controller_step();
  ROS_Controller_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ROS_Controller_step();
  ROS_Controller_derivatives();

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
void ROS_Controller_step(void)
{
  if (rtmIsMajorTimeStep(ROS_Controller_M)) {
    // set solver stop time
    if (!(ROS_Controller_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ROS_Controller_M->solverInfo,
                            ((ROS_Controller_M->Timing.clockTickH0 + 1) *
        ROS_Controller_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ROS_Controller_M->solverInfo,
                            ((ROS_Controller_M->Timing.clockTick0 + 1) *
        ROS_Controller_M->Timing.stepSize0 +
        ROS_Controller_M->Timing.clockTickH0 *
        ROS_Controller_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(ROS_Controller_M)) {
    ROS_Controller_M->Timing.t[0] = rtsiGetT(&ROS_Controller_M->solverInfo);
  }

  {
    real_T (*lastU)[3];
    static const int8_T b[3] = { 0, 0, 1 };

    real_T t;
    boolean_T varargout_1;
    real_T rtb_TransferFcn5;
    real_T rtb_TransferFcn6;
    real_T rtb_TransferFcn7;
    int32_T i;

    // TransferFcn: '<S6>/Transfer Fcn5'
    rtb_TransferFcn5 = ROS_Controller_P.TransferFcn5_C *
      ROS_Controller_X.TransferFcn5_CSTATE;

    // TransferFcn: '<S6>/Transfer Fcn6'
    rtb_TransferFcn6 = ROS_Controller_P.TransferFcn6_C *
      ROS_Controller_X.TransferFcn6_CSTATE;

    // TransferFcn: '<S6>/Transfer Fcn7'
    rtb_TransferFcn7 = ROS_Controller_P.TransferFcn7_C *
      ROS_Controller_X.TransferFcn7_CSTATE;

    // BusAssignment: '<S7>/Bus Assignment1'
    ROS_Controller_B.BusAssignment1.X = rtb_TransferFcn5;
    ROS_Controller_B.BusAssignment1.Y = rtb_TransferFcn6;
    ROS_Controller_B.BusAssignment1.Z = rtb_TransferFcn7;

    // Outputs for Atomic SubSystem: '<S7>/Publish1'
    // MATLABSystem: '<S20>/SinkBlock'
    Pub_ROS_Controller_153.publish(&ROS_Controller_B.BusAssignment1);

    // End of Outputs for SubSystem: '<S7>/Publish1'

    // Integrator: '<S5>/Integrator2'
    ROS_Controller_B.Integrator2[0] = ROS_Controller_X.Integrator2_CSTATE[0];
    ROS_Controller_B.Integrator2[1] = ROS_Controller_X.Integrator2_CSTATE[1];
    ROS_Controller_B.Integrator2[2] = ROS_Controller_X.Integrator2_CSTATE[2];

    // Derivative: '<S1>/Derivative'
    if ((ROS_Controller_DW.TimeStampA >= ROS_Controller_M->Timing.t[0]) &&
        (ROS_Controller_DW.TimeStampB >= ROS_Controller_M->Timing.t[0])) {
      ROS_Controller_B.Gain1_m[0] = 0.0;
      ROS_Controller_B.Gain1_m[1] = 0.0;
      ROS_Controller_B.Gain1_m[2] = 0.0;
    } else {
      t = ROS_Controller_DW.TimeStampA;
      lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeA;
      if (ROS_Controller_DW.TimeStampA < ROS_Controller_DW.TimeStampB) {
        if (ROS_Controller_DW.TimeStampB < ROS_Controller_M->Timing.t[0]) {
          t = ROS_Controller_DW.TimeStampB;
          lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeB;
        }
      } else {
        if (ROS_Controller_DW.TimeStampA >= ROS_Controller_M->Timing.t[0]) {
          t = ROS_Controller_DW.TimeStampB;
          lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeB;
        }
      }

      t = ROS_Controller_M->Timing.t[0] - t;
      ROS_Controller_B.Gain1_m[0] = (ROS_Controller_B.Integrator2[0] - (*lastU)
        [0]) / t;
      ROS_Controller_B.Gain1_m[1] = (ROS_Controller_B.Integrator2[1] - (*lastU)
        [1]) / t;
      ROS_Controller_B.Gain1_m[2] = (ROS_Controller_B.Integrator2[2] - (*lastU)
        [2]) / t;
    }

    // End of Derivative: '<S1>/Derivative'

    // Sum: '<S1>/Sum' incorporates:
    //   Integrator: '<S9>/Integrator'

    ROS_Controller_B.Gain[0] = ROS_Controller_B.Integrator2[0] -
      ROS_Controller_X.Integrator_CSTATE[0];
    ROS_Controller_B.Gain[1] = ROS_Controller_B.Integrator2[1] -
      ROS_Controller_X.Integrator_CSTATE[1];
    ROS_Controller_B.Gain[2] = ROS_Controller_B.Integrator2[2] -
      ROS_Controller_X.Integrator_CSTATE[2];

    // MATLAB Function: '<S1>/Rotation Matrix' incorporates:
    //   Integrator: '<S9>/Integrator'

    // MATLAB Function 'DPcontroller/Rotation Matrix': '<S8>:1'
    // '<S8>:1:2'
    // '<S8>:1:3'
    ROS_Controller_B.R_c[0] = cos(ROS_Controller_X.Integrator_CSTATE[2]);
    ROS_Controller_B.R_c[1] = -sin(ROS_Controller_X.Integrator_CSTATE[2]);
    ROS_Controller_B.R_c[2] = 0.0;
    ROS_Controller_B.R_c[3] = sin(ROS_Controller_X.Integrator_CSTATE[2]);
    ROS_Controller_B.R_c[4] = cos(ROS_Controller_X.Integrator_CSTATE[2]);
    ROS_Controller_B.R_c[5] = 0.0;

    // R=[RotPhi(1:2,:);[0 0 0;0 0 0;0 0 0];RotPhi(3,:)]
    for (i = 0; i < 3; i++) {
      // Gain: '<S1>/Gain1'
      ROS_Controller_B.Gain1[i] = 0.0;
      ROS_Controller_B.Gain1[i] += ROS_Controller_P.Ki[i] *
        ROS_Controller_B.Gain[0];
      ROS_Controller_B.Gain1[i] += ROS_Controller_P.Ki[i + 3] *
        ROS_Controller_B.Gain[1];
      ROS_Controller_B.Gain1[i] += ROS_Controller_P.Ki[i + 6] *
        ROS_Controller_B.Gain[2];

      // MATLAB Function: '<S1>/Rotation Matrix'
      ROS_Controller_B.R_c[6 + i] = b[i];

      // Sum: '<S1>/Sum3' incorporates:
      //   Gain: '<S1>/Gain2'
      //   Integrator: '<S9>/Integrator1'
      //   Product: '<S1>/{XYD}->{BODY}'

      ROS_Controller_B.Sum2[i] = ((ROS_Controller_B.R_c[i + 3] *
        ROS_Controller_B.Gain1_m[1] + ROS_Controller_B.R_c[i] *
        ROS_Controller_B.Gain1_m[0]) + ROS_Controller_B.R_c[i + 6] *
        ROS_Controller_B.Gain1_m[2]) - ROS_Controller_X.Integrator1_CSTATE[i];
    }

    // Limited  Integrator
    for (i = 0; i < 3; i++) {
      // Integrator: '<S1>/Integrator1'
      if (ROS_Controller_X.Integrator1_CSTATE_d[i] >=
          ROS_Controller_P.Integrator1_UpperSat[i]) {
        ROS_Controller_X.Integrator1_CSTATE_d[i] =
          ROS_Controller_P.Integrator1_UpperSat[i];
      } else {
        if (ROS_Controller_X.Integrator1_CSTATE_d[i] <=
            ROS_Controller_P.Integrator1_LowerSat[i]) {
          ROS_Controller_X.Integrator1_CSTATE_d[i] =
            ROS_Controller_P.Integrator1_LowerSat[i];
        }
      }

      // Sum: '<S1>/Sum1' incorporates:
      //   Gain: '<S1>/Gain'
      //   Integrator: '<S1>/Integrator1'
      //   Product: '<S1>/{XYD}->{BODY}s'

      ROS_Controller_B.dv1[i] = ((ROS_Controller_P.Kp[i + 3] *
        ROS_Controller_B.Gain[1] + ROS_Controller_P.Kp[i] *
        ROS_Controller_B.Gain[0]) + ROS_Controller_P.Kp[i + 6] *
        ROS_Controller_B.Gain[2]) + ROS_Controller_X.Integrator1_CSTATE_d[i];

      // Gain: '<S1>/Gain2'
      ROS_Controller_B.Gain1_m[i] = ROS_Controller_P.Kd[i + 6] *
        ROS_Controller_B.Sum2[2] + (ROS_Controller_P.Kd[i + 3] *
        ROS_Controller_B.Sum2[1] + ROS_Controller_P.Kd[i] *
        ROS_Controller_B.Sum2[0]);
    }

    // Sum: '<S1>/Sum2' incorporates:
    //   Product: '<S1>/{XYD}->{BODY}s'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.Sum2[i] = ((ROS_Controller_B.R_c[i + 3] *
        ROS_Controller_B.dv1[1] + ROS_Controller_B.R_c[i] *
        ROS_Controller_B.dv1[0]) + ROS_Controller_B.R_c[i + 6] *
        ROS_Controller_B.dv1[2]) + ROS_Controller_B.Gain1_m[i];
    }

    // End of Sum: '<S1>/Sum2'
    // MATLAB Function 'NonlinearPassiveObs/Subsystem/Dampening matrix': '<S11>:1' 
    // '<S11>:1:3'
    // '<S11>:1:4'
    // MATLAB Function 'NonlinearPassiveObs/Subsystem/Correalis matrix': '<S10>:1' 
    // '<S10>:1:3'
    // '<S10>:1:4'
    if (rtmIsMajorTimeStep(ROS_Controller_M)) {
      // Outputs for Atomic SubSystem: '<S3>/Subscribe2'
      // Start for MATLABSystem: '<S14>/SourceBlock' incorporates:
      //   MATLABSystem: '<S14>/SourceBlock'

      varargout_1 = Sub_ROS_Controller_659.get_latest_msg
        (&ROS_Controller_B.BusAssignment1);

      // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S15>/Enable'

      // MATLABSystem: '<S14>/SourceBlock' incorporates:
      //   Inport: '<S15>/In1'

      if (varargout_1) {
        ROS_Controller_B.In1_i = ROS_Controller_B.BusAssignment1;
      }

      // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<S3>/Subscribe2'
    }

    // Sum: '<S9>/Sum' incorporates:
    //   Constant: '<S3>/Constant'
    //   Integrator: '<S9>/Integrator'

    ROS_Controller_B.nframetobframe[0] = ROS_Controller_B.In1_i.X -
      ROS_Controller_X.Integrator_CSTATE[0];
    ROS_Controller_B.nframetobframe[1] = ROS_Controller_B.In1_i.Y -
      ROS_Controller_X.Integrator_CSTATE[1];
    ROS_Controller_B.nframetobframe[2] = ROS_Controller_P.Constant_Value_b -
      ROS_Controller_X.Integrator_CSTATE[2];
    for (i = 0; i < 3; i++) {
      // Gain: '<S9>/Gain'
      ROS_Controller_B.Gain[i] = ROS_Controller_P.K2[i + 6] *
        ROS_Controller_B.nframetobframe[2] + (ROS_Controller_P.K2[i + 3] *
        ROS_Controller_B.nframetobframe[1] + ROS_Controller_P.K2[i] *
        ROS_Controller_B.nframetobframe[0]);

      // Gain: '<S9>/Gain1'
      ROS_Controller_B.Gain1_m[i] = ROS_Controller_P.K3[i + 6] *
        ROS_Controller_B.nframetobframe[2] + (ROS_Controller_P.K3[i + 3] *
        ROS_Controller_B.nframetobframe[1] + ROS_Controller_P.K3[i] *
        ROS_Controller_B.nframetobframe[0]);
    }

    if (rtmIsMajorTimeStep(ROS_Controller_M)) {
      // MATLAB Function: '<S9>/MATLAB Function' incorporates:
      //   Constant: '<S3>/Constant'

      // MATLAB Function 'NonlinearPassiveObs/Subsystem/MATLAB Function': '<S12>:1' 
      // '<S12>:1:2'
      // '<S12>:1:3'
      ROS_Controller_B.R_t[0] = cos(ROS_Controller_P.Constant_Value_b);
      ROS_Controller_B.R_t[1] = -sin(ROS_Controller_P.Constant_Value_b);
      ROS_Controller_B.R_t[2] = 0.0;
      ROS_Controller_B.R_t[3] = sin(ROS_Controller_P.Constant_Value_b);
      ROS_Controller_B.R_t[4] = cos(ROS_Controller_P.Constant_Value_b);
      ROS_Controller_B.R_t[5] = 0.0;

      // MATLAB Function: '<S9>/MATLAB Function1' incorporates:
      //   Constant: '<S3>/Constant'

      // R=[RotPhi(1:2,:);[0 0 0;0 0 0;0 0 0];RotPhi(3,:)]
      // MATLAB Function 'NonlinearPassiveObs/Subsystem/MATLAB Function1': '<S13>:1' 
      // '<S13>:1:2'
      // '<S13>:1:3'
      ROS_Controller_B.R[0] = cos(ROS_Controller_P.Constant_Value_b);
      ROS_Controller_B.R[3] = -sin(ROS_Controller_P.Constant_Value_b);
      ROS_Controller_B.R[6] = 0.0;
      ROS_Controller_B.R[1] = sin(ROS_Controller_P.Constant_Value_b);
      ROS_Controller_B.R[4] = cos(ROS_Controller_P.Constant_Value_b);
      ROS_Controller_B.R[7] = 0.0;

      // MATLAB Function: '<S9>/MATLAB Function'
      ROS_Controller_B.R_t[6] = 0.0;

      // MATLAB Function: '<S9>/MATLAB Function1'
      ROS_Controller_B.R[2] = 0.0;

      // MATLAB Function: '<S9>/MATLAB Function'
      ROS_Controller_B.R_t[7] = 0.0;

      // MATLAB Function: '<S9>/MATLAB Function1'
      ROS_Controller_B.R[5] = 0.0;

      // MATLAB Function: '<S9>/MATLAB Function'
      ROS_Controller_B.R_t[8] = 1.0;

      // MATLAB Function: '<S9>/MATLAB Function1'
      ROS_Controller_B.R[8] = 1.0;
    }

    // Gain: '<S9>/Gain2' incorporates:
    //   Product: '<S9>/{n} frame to {b} frame'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.dv1[i] = ROS_Controller_P.K4[i + 6] *
        ROS_Controller_B.nframetobframe[2] + (ROS_Controller_P.K4[i + 3] *
        ROS_Controller_B.nframetobframe[1] + ROS_Controller_P.K4[i] *
        ROS_Controller_B.nframetobframe[0]);
    }

    // End of Gain: '<S9>/Gain2'

    // MATLAB Function: '<S9>/Dampening matrix' incorporates:
    //   Constant: '<S9>/Constant2'
    //   Integrator: '<S9>/Integrator1'

    ROS_Controller_B.R_c[0] = ROS_Controller_P.D_nuParams[0] * fabs
      (ROS_Controller_X.Integrator1_CSTATE[0]);
    ROS_Controller_B.R_c[3] = 0.0;
    ROS_Controller_B.R_c[6] = 0.0;
    ROS_Controller_B.R_c[1] = 0.0;
    ROS_Controller_B.R_c[4] = ROS_Controller_P.D_nuParams[4] * fabs
      (ROS_Controller_X.Integrator1_CSTATE[1]);
    ROS_Controller_B.R_c[7] = 0.0;
    for (i = 0; i < 3; i++) {
      // Sum: '<S9>/Sum2' incorporates:
      //   Constant: '<S6>/Thrust allocation Matrix'
      //   Product: '<S6>/{u}->{thrust}'
      //   Product: '<S9>/{n} frame to {b} frame'
      //   SignalConversion: '<S6>/TmpSignal ConversionAt{u}->{thrust}Inport2'
      //   Sum: '<S9>/Sum3'

      ROS_Controller_B.nframetobframe[i] = ((ROS_Controller_P.Tr[i + 3] *
        rtb_TransferFcn6 + ROS_Controller_P.Tr[i] * rtb_TransferFcn5) +
        ROS_Controller_P.Tr[i + 6] * rtb_TransferFcn7) + (ROS_Controller_B.R_t[i
        + 6] * ROS_Controller_B.dv1[2] + (ROS_Controller_B.R_t[i + 3] *
        ROS_Controller_B.dv1[1] + ROS_Controller_B.R_t[i] *
        ROS_Controller_B.dv1[0]));

      // MATLAB Function: '<S9>/Dampening matrix'
      ROS_Controller_B.R_c[2 + 3 * i] = 0.0;

      // Product: '<S9>/Product4' incorporates:
      //   Integrator: '<S9>/Integrator2'
      //   Sum: '<S9>/Sum3'

      ROS_Controller_B.dv2[i] = ROS_Controller_B.R_t[i + 6] *
        ROS_Controller_X.Integrator2_CSTATE_n[2] + (ROS_Controller_B.R_t[i + 3] *
        ROS_Controller_X.Integrator2_CSTATE_n[1] + ROS_Controller_B.R_t[i] *
        ROS_Controller_X.Integrator2_CSTATE_n[0]);

      // Product: '<S9>/Product2' incorporates:
      //   Constant: '<S9>/Constant1'
      //   Integrator: '<S9>/Integrator1'
      //   Sum: '<S9>/Add'

      ROS_Controller_B.dv3[i] = ROS_Controller_P.D[i + 6] *
        ROS_Controller_X.Integrator1_CSTATE[2] + (ROS_Controller_P.D[i + 3] *
        ROS_Controller_X.Integrator1_CSTATE[1] + ROS_Controller_P.D[i] *
        ROS_Controller_X.Integrator1_CSTATE[0]);
    }

    // MATLAB Function: '<S9>/Correalis matrix' incorporates:
    //   Constant: '<S9>/Constant3'
    //   Integrator: '<S9>/Integrator1'

    ROS_Controller_B.dv0[0] = 0.0;
    ROS_Controller_B.dv0[3] = ROS_Controller_P.C_nuParams[1] *
      ROS_Controller_X.Integrator1_CSTATE[2];
    ROS_Controller_B.dv0[6] = 0.0;
    ROS_Controller_B.dv0[1] = -ROS_Controller_P.C_nuParams[3] *
      ROS_Controller_X.Integrator1_CSTATE[2];
    ROS_Controller_B.dv0[4] = 0.0;
    ROS_Controller_B.dv0[7] = 0.0;
    for (i = 0; i < 3; i++) {
      // MATLAB Function: '<S9>/Correalis matrix'
      ROS_Controller_B.dv0[2 + 3 * i] = 0.0;

      // MATLAB Function: '<S9>/Dampening matrix' incorporates:
      //   Integrator: '<S9>/Integrator1'
      //   Sum: '<S9>/Add'

      ROS_Controller_B.dv1[i] = 0.0 * ROS_Controller_X.Integrator1_CSTATE[2] +
        (ROS_Controller_B.R_c[i + 3] * ROS_Controller_X.Integrator1_CSTATE[1] +
         ROS_Controller_B.R_c[i] * ROS_Controller_X.Integrator1_CSTATE[0]);
    }

    // Sum: '<S9>/Sum3' incorporates:
    //   Integrator: '<S9>/Integrator1'
    //   MATLAB Function: '<S9>/Correalis matrix'
    //   Product: '<S9>/Product1'
    //   Sum: '<S9>/Add'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.dv4[i] = (ROS_Controller_B.dv2[i] +
        ROS_Controller_B.nframetobframe[i]) - (((ROS_Controller_B.dv0[i + 3] *
        ROS_Controller_X.Integrator1_CSTATE[1] + ROS_Controller_B.dv0[i] *
        ROS_Controller_X.Integrator1_CSTATE[0]) + 0.0 *
        ROS_Controller_X.Integrator1_CSTATE[2]) + (ROS_Controller_B.dv3[i] +
        ROS_Controller_B.dv1[i]));
    }

    for (i = 0; i < 3; i++) {
      // Product: '<S9>/Product1' incorporates:
      //   Constant: '<S9>/Constant'

      ROS_Controller_B.Product1[i] = 0.0;
      ROS_Controller_B.Product1[i] += ROS_Controller_P.invM[i] *
        ROS_Controller_B.dv4[0];
      ROS_Controller_B.Product1[i] += ROS_Controller_P.invM[i + 3] *
        ROS_Controller_B.dv4[1];
      ROS_Controller_B.Product1[i] += ROS_Controller_P.invM[i + 6] *
        ROS_Controller_B.dv4[2];

      // Sum: '<S9>/Sum1' incorporates:
      //   Integrator: '<S9>/Integrator1'
      //   Product: '<S9>/{b} frame to {n} frame'

      ROS_Controller_B.Sum1[i] = ((ROS_Controller_B.R[i + 3] *
        ROS_Controller_X.Integrator1_CSTATE[1] + ROS_Controller_B.R[i] *
        ROS_Controller_X.Integrator1_CSTATE[0]) + ROS_Controller_B.R[i + 6] *
        ROS_Controller_X.Integrator1_CSTATE[2]) + ROS_Controller_B.Gain[i];

      // Sum: '<S9>/Sum4' incorporates:
      //   Gain: '<S9>/Gain3'
      //   Integrator: '<S9>/Integrator2'

      ROS_Controller_B.Sum4[i] = ROS_Controller_B.Gain1_m[i] -
        ((ROS_Controller_P.invT[i + 3] * ROS_Controller_X.Integrator2_CSTATE_n[1]
          + ROS_Controller_P.invT[i] * ROS_Controller_X.Integrator2_CSTATE_n[0])
         + ROS_Controller_P.invT[i + 6] * ROS_Controller_X.Integrator2_CSTATE_n
         [2]);
    }

    if (rtmIsMajorTimeStep(ROS_Controller_M)) {
      // Outputs for Atomic SubSystem: '<S4>/Subscribe2'
      // Start for MATLABSystem: '<S16>/SourceBlock' incorporates:
      //   MATLABSystem: '<S16>/SourceBlock'

      varargout_1 = Sub_ROS_Controller_652.get_latest_msg
        (&ROS_Controller_B.BusAssignment1);

      // Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S17>/Enable'

      // MATLABSystem: '<S16>/SourceBlock' incorporates:
      //   Inport: '<S17>/In1'

      if (varargout_1) {
        ROS_Controller_B.In1 = ROS_Controller_B.BusAssignment1;
      }

      // End of Outputs for SubSystem: '<S16>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<S4>/Subscribe2'
    }

    // Sum: '<S5>/Sum' incorporates:
    //   Constant: '<S4>/Constant'

    ROS_Controller_B.dv5[0] = ROS_Controller_B.In1.X;
    ROS_Controller_B.dv5[1] = ROS_Controller_B.In1.Y;
    ROS_Controller_B.dv5[2] = ROS_Controller_P.Constant_Value_bw;
    for (i = 0; i < 3; i++) {
      // Saturate: '<S5>/Saturation4' incorporates:
      //   Integrator: '<S5>/Integrator1'

      if (ROS_Controller_X.Integrator1_CSTATE_i[i] > ROS_Controller_P.Sat2Up[i])
      {
        ROS_Controller_B.Saturation4[i] = ROS_Controller_P.Sat2Up[i];
      } else if (ROS_Controller_X.Integrator1_CSTATE_i[i] <
                 ROS_Controller_P.Sat2Low[i]) {
        ROS_Controller_B.Saturation4[i] = ROS_Controller_P.Sat2Low[i];
      } else {
        ROS_Controller_B.Saturation4[i] =
          ROS_Controller_X.Integrator1_CSTATE_i[i];
      }

      // End of Saturate: '<S5>/Saturation4'

      // Sum: '<S5>/Sum3' incorporates:
      //   Gain: '<S5>/ciwni'
      //   Gain: '<S5>/w_n1'
      //   Gain: '<S5>/w_n2'
      //   Integrator: '<S5>/Integrator'
      //   Integrator: '<S5>/Integrator1'
      //   Sum: '<S5>/Sum2'

      ROS_Controller_B.Sum3[i] = ((ROS_Controller_P.wnisquared[i + 6] *
        ROS_Controller_X.Integrator_CSTATE_a[2] + (ROS_Controller_P.wnisquared[i
        + 3] * ROS_Controller_X.Integrator_CSTATE_a[1] +
        ROS_Controller_P.wnisquared[i] * ROS_Controller_X.Integrator_CSTATE_a[0]))
        - (ROS_Controller_P.wnisquared[i + 6] * ROS_Controller_B.Integrator2[2]
           + (ROS_Controller_P.wnisquared[i + 3] * ROS_Controller_B.Integrator2
              [1] + ROS_Controller_P.wnisquared[i] *
              ROS_Controller_B.Integrator2[0]))) - ((ROS_Controller_P.wniCeta2[i
        + 3] * ROS_Controller_X.Integrator1_CSTATE_i[1] +
        ROS_Controller_P.wniCeta2[i] * ROS_Controller_X.Integrator1_CSTATE_i[0])
        + ROS_Controller_P.wniCeta2[i + 6] *
        ROS_Controller_X.Integrator1_CSTATE_i[2]);

      // Sum: '<S5>/Sum' incorporates:
      //   Gain: '<S5>/w_n'
      //   Integrator: '<S5>/Integrator'

      ROS_Controller_B.dv1[i] = ROS_Controller_B.dv5[i] -
        ROS_Controller_X.Integrator_CSTATE_a[i];
    }

    // Gain: '<S5>/w_n'
    for (i = 0; i < 3; i++) {
      ROS_Controller_B.w_n[i] = 0.0;
      ROS_Controller_B.w_n[i] += ROS_Controller_P.wni[i] * ROS_Controller_B.dv1
        [0];
      ROS_Controller_B.w_n[i] += ROS_Controller_P.wni[i + 3] *
        ROS_Controller_B.dv1[1];
      ROS_Controller_B.w_n[i] += ROS_Controller_P.wni[i + 6] *
        ROS_Controller_B.dv1[2];
    }

    // MATLAB Function: '<S6>/Torque Saturation'
    // MATLAB Function 'ThrustDynamics/Torque Saturation': '<S18>:1'
    // '<S18>:1:2'
    // '<S18>:1:3'
    rtb_TransferFcn6 = 2.2250738585072014E-308;
    rtb_TransferFcn7 = fabs(ROS_Controller_B.Sum2[0]);
    if (rtb_TransferFcn7 > 2.2250738585072014E-308) {
      rtb_TransferFcn5 = 1.0;
      rtb_TransferFcn6 = rtb_TransferFcn7;
    } else {
      t = rtb_TransferFcn7 / 2.2250738585072014E-308;
      rtb_TransferFcn5 = t * t;
    }

    rtb_TransferFcn7 = fabs(ROS_Controller_B.Sum2[1]);
    if (rtb_TransferFcn7 > rtb_TransferFcn6) {
      t = rtb_TransferFcn6 / rtb_TransferFcn7;
      rtb_TransferFcn5 = rtb_TransferFcn5 * t * t + 1.0;
      rtb_TransferFcn6 = rtb_TransferFcn7;
    } else {
      t = rtb_TransferFcn7 / rtb_TransferFcn6;
      rtb_TransferFcn5 += t * t;
    }

    rtb_TransferFcn5 = rtb_TransferFcn6 * sqrt(rtb_TransferFcn5);
    if (rtb_TransferFcn5 > 3.7) {
      // '<S18>:1:4'
      // '<S18>:1:5'
      rtb_TransferFcn5 = 3.7 / rtb_TransferFcn5;
      ROS_Controller_B.Sum2[0] *= rtb_TransferFcn5;
      ROS_Controller_B.Sum2[1] *= rtb_TransferFcn5;
    }

    // '<S18>:1:7'
    if (fabs(ROS_Controller_B.Sum2[2]) > 0.3) {
      // '<S18>:1:8'
      // '<S18>:1:9'
      ROS_Controller_B.Sum2[2] = 0.3 * ROS_Controller_B.Sum2[2] / fabs
        (ROS_Controller_B.Sum2[2]);
    }

    // End of MATLAB Function: '<S6>/Torque Saturation'

    // Product: '<S6>/{thrust}->{u}' incorporates:
    //   Constant: '<S6>/Inverse thrust allocation Matrix'

    // '<S18>:1:11'
    for (i = 0; i < 3; i++) {
      ROS_Controller_B.Gain1_m[i] = ROS_Controller_P.invThrustAloc[i + 6] *
        ROS_Controller_B.Sum2[2] + (ROS_Controller_P.invThrustAloc[i + 3] *
        ROS_Controller_B.Sum2[1] + ROS_Controller_P.invThrustAloc[i] *
        ROS_Controller_B.Sum2[0]);
    }

    // End of Product: '<S6>/{thrust}->{u}'

    // Saturate: '<S6>/Saturation5'
    if (ROS_Controller_B.Gain1_m[0] > ROS_Controller_P.Saturation5_UpperSat) {
      ROS_Controller_B.Saturation5 = ROS_Controller_P.Saturation5_UpperSat;
    } else if (ROS_Controller_B.Gain1_m[0] <
               ROS_Controller_P.Saturation5_LowerSat) {
      ROS_Controller_B.Saturation5 = ROS_Controller_P.Saturation5_LowerSat;
    } else {
      ROS_Controller_B.Saturation5 = ROS_Controller_B.Gain1_m[0];
    }

    // End of Saturate: '<S6>/Saturation5'

    // Saturate: '<S6>/Saturation6'
    if (ROS_Controller_B.Gain1_m[1] > ROS_Controller_P.Saturation6_UpperSat) {
      ROS_Controller_B.Saturation6 = ROS_Controller_P.Saturation6_UpperSat;
    } else if (ROS_Controller_B.Gain1_m[1] <
               ROS_Controller_P.Saturation6_LowerSat) {
      ROS_Controller_B.Saturation6 = ROS_Controller_P.Saturation6_LowerSat;
    } else {
      ROS_Controller_B.Saturation6 = ROS_Controller_B.Gain1_m[1];
    }

    // End of Saturate: '<S6>/Saturation6'

    // Saturate: '<S6>/Saturation7'
    if (ROS_Controller_B.Gain1_m[2] > ROS_Controller_P.Saturation7_UpperSat) {
      ROS_Controller_B.Saturation7 = ROS_Controller_P.Saturation7_UpperSat;
    } else if (ROS_Controller_B.Gain1_m[2] <
               ROS_Controller_P.Saturation7_LowerSat) {
      ROS_Controller_B.Saturation7 = ROS_Controller_P.Saturation7_LowerSat;
    } else {
      ROS_Controller_B.Saturation7 = ROS_Controller_B.Gain1_m[2];
    }

    // End of Saturate: '<S6>/Saturation7'
  }

  if (rtmIsMajorTimeStep(ROS_Controller_M)) {
    real_T (*lastU)[3];

    // Update for Derivative: '<S1>/Derivative'
    if (ROS_Controller_DW.TimeStampA == (rtInf)) {
      ROS_Controller_DW.TimeStampA = ROS_Controller_M->Timing.t[0];
      lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeA;
    } else if (ROS_Controller_DW.TimeStampB == (rtInf)) {
      ROS_Controller_DW.TimeStampB = ROS_Controller_M->Timing.t[0];
      lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeB;
    } else if (ROS_Controller_DW.TimeStampA < ROS_Controller_DW.TimeStampB) {
      ROS_Controller_DW.TimeStampA = ROS_Controller_M->Timing.t[0];
      lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeA;
    } else {
      ROS_Controller_DW.TimeStampB = ROS_Controller_M->Timing.t[0];
      lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeB;
    }

    (*lastU)[0] = ROS_Controller_B.Integrator2[0];
    (*lastU)[1] = ROS_Controller_B.Integrator2[1];
    (*lastU)[2] = ROS_Controller_B.Integrator2[2];

    // End of Update for Derivative: '<S1>/Derivative'
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(ROS_Controller_M)) {
    rt_ertODEUpdateContinuousStates(&ROS_Controller_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.
    //  Timer of this task consists of two 32 bit unsigned integers.
    //  The two integers represent the low bits Timing.clockTick0 and the high bits
    //  Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.

    if (!(++ROS_Controller_M->Timing.clockTick0)) {
      ++ROS_Controller_M->Timing.clockTickH0;
    }

    ROS_Controller_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ROS_Controller_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.
      //  Timer of this task consists of two 32 bit unsigned integers.
      //  The two integers represent the low bits Timing.clockTick1 and the high bits
      //  Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.

      ROS_Controller_M->Timing.clockTick1++;
      if (!ROS_Controller_M->Timing.clockTick1) {
        ROS_Controller_M->Timing.clockTickH1++;
      }
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void ROS_Controller_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  XDot_ROS_Controller_T *_rtXdot;
  _rtXdot = ((XDot_ROS_Controller_T *) ROS_Controller_M->ModelData.derivs);

  // Derivatives for TransferFcn: '<S6>/Transfer Fcn5'
  _rtXdot->TransferFcn5_CSTATE = 0.0;
  _rtXdot->TransferFcn5_CSTATE += ROS_Controller_P.TransferFcn5_A *
    ROS_Controller_X.TransferFcn5_CSTATE;
  _rtXdot->TransferFcn5_CSTATE += ROS_Controller_B.Saturation5;

  // Derivatives for TransferFcn: '<S6>/Transfer Fcn6'
  _rtXdot->TransferFcn6_CSTATE = 0.0;
  _rtXdot->TransferFcn6_CSTATE += ROS_Controller_P.TransferFcn6_A *
    ROS_Controller_X.TransferFcn6_CSTATE;
  _rtXdot->TransferFcn6_CSTATE += ROS_Controller_B.Saturation6;

  // Derivatives for TransferFcn: '<S6>/Transfer Fcn7'
  _rtXdot->TransferFcn7_CSTATE = 0.0;
  _rtXdot->TransferFcn7_CSTATE += ROS_Controller_P.TransferFcn7_A *
    ROS_Controller_X.TransferFcn7_CSTATE;
  _rtXdot->TransferFcn7_CSTATE += ROS_Controller_B.Saturation7;

  // Derivatives for Integrator: '<S5>/Integrator2'
  _rtXdot->Integrator2_CSTATE[0] = ROS_Controller_B.Saturation4[0];

  // Derivatives for Integrator: '<S9>/Integrator'
  _rtXdot->Integrator_CSTATE[0] = ROS_Controller_B.Sum1[0];

  // Derivatives for Integrator: '<S9>/Integrator1'
  _rtXdot->Integrator1_CSTATE[0] = ROS_Controller_B.Product1[0];

  // Derivatives for Integrator: '<S1>/Integrator1'
  lsat = (ROS_Controller_X.Integrator1_CSTATE_d[0] <=
          ROS_Controller_P.Integrator1_LowerSat[0]);
  usat = (ROS_Controller_X.Integrator1_CSTATE_d[0] >=
          ROS_Controller_P.Integrator1_UpperSat[0]);
  if (((!lsat) && (!usat)) || (lsat && (ROS_Controller_B.Gain1[0] > 0.0)) ||
      (usat && (ROS_Controller_B.Gain1[0] < 0.0))) {
    _rtXdot->Integrator1_CSTATE_d[0] = ROS_Controller_B.Gain1[0];
  } else {
    // in saturation
    _rtXdot->Integrator1_CSTATE_d[0] = 0.0;
  }

  // Derivatives for Integrator: '<S9>/Integrator2'
  _rtXdot->Integrator2_CSTATE_n[0] = ROS_Controller_B.Sum4[0];

  // Derivatives for Integrator: '<S5>/Integrator'
  _rtXdot->Integrator_CSTATE_a[0] = ROS_Controller_B.w_n[0];

  // Derivatives for Integrator: '<S5>/Integrator1'
  _rtXdot->Integrator1_CSTATE_i[0] = ROS_Controller_B.Sum3[0];

  // Derivatives for Integrator: '<S5>/Integrator2'
  _rtXdot->Integrator2_CSTATE[1] = ROS_Controller_B.Saturation4[1];

  // Derivatives for Integrator: '<S9>/Integrator'
  _rtXdot->Integrator_CSTATE[1] = ROS_Controller_B.Sum1[1];

  // Derivatives for Integrator: '<S9>/Integrator1'
  _rtXdot->Integrator1_CSTATE[1] = ROS_Controller_B.Product1[1];

  // Derivatives for Integrator: '<S1>/Integrator1'
  lsat = (ROS_Controller_X.Integrator1_CSTATE_d[1] <=
          ROS_Controller_P.Integrator1_LowerSat[1]);
  usat = (ROS_Controller_X.Integrator1_CSTATE_d[1] >=
          ROS_Controller_P.Integrator1_UpperSat[1]);
  if (((!lsat) && (!usat)) || (lsat && (ROS_Controller_B.Gain1[1] > 0.0)) ||
      (usat && (ROS_Controller_B.Gain1[1] < 0.0))) {
    _rtXdot->Integrator1_CSTATE_d[1] = ROS_Controller_B.Gain1[1];
  } else {
    // in saturation
    _rtXdot->Integrator1_CSTATE_d[1] = 0.0;
  }

  // Derivatives for Integrator: '<S9>/Integrator2'
  _rtXdot->Integrator2_CSTATE_n[1] = ROS_Controller_B.Sum4[1];

  // Derivatives for Integrator: '<S5>/Integrator'
  _rtXdot->Integrator_CSTATE_a[1] = ROS_Controller_B.w_n[1];

  // Derivatives for Integrator: '<S5>/Integrator1'
  _rtXdot->Integrator1_CSTATE_i[1] = ROS_Controller_B.Sum3[1];

  // Derivatives for Integrator: '<S5>/Integrator2'
  _rtXdot->Integrator2_CSTATE[2] = ROS_Controller_B.Saturation4[2];

  // Derivatives for Integrator: '<S9>/Integrator'
  _rtXdot->Integrator_CSTATE[2] = ROS_Controller_B.Sum1[2];

  // Derivatives for Integrator: '<S9>/Integrator1'
  _rtXdot->Integrator1_CSTATE[2] = ROS_Controller_B.Product1[2];

  // Derivatives for Integrator: '<S1>/Integrator1'
  lsat = (ROS_Controller_X.Integrator1_CSTATE_d[2] <=
          ROS_Controller_P.Integrator1_LowerSat[2]);
  usat = (ROS_Controller_X.Integrator1_CSTATE_d[2] >=
          ROS_Controller_P.Integrator1_UpperSat[2]);
  if (((!lsat) && (!usat)) || (lsat && (ROS_Controller_B.Gain1[2] > 0.0)) ||
      (usat && (ROS_Controller_B.Gain1[2] < 0.0))) {
    _rtXdot->Integrator1_CSTATE_d[2] = ROS_Controller_B.Gain1[2];
  } else {
    // in saturation
    _rtXdot->Integrator1_CSTATE_d[2] = 0.0;
  }

  // Derivatives for Integrator: '<S9>/Integrator2'
  _rtXdot->Integrator2_CSTATE_n[2] = ROS_Controller_B.Sum4[2];

  // Derivatives for Integrator: '<S5>/Integrator'
  _rtXdot->Integrator_CSTATE_a[2] = ROS_Controller_B.w_n[2];

  // Derivatives for Integrator: '<S5>/Integrator1'
  _rtXdot->Integrator1_CSTATE_i[2] = ROS_Controller_B.Sum3[2];
}

// Model initialize function
void ROS_Controller_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize real-time model
  (void) memset((void *)ROS_Controller_M, 0,
                sizeof(RT_MODEL_ROS_Controller_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&ROS_Controller_M->solverInfo,
                          &ROS_Controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&ROS_Controller_M->solverInfo, &rtmGetTPtr(ROS_Controller_M));
    rtsiSetStepSizePtr(&ROS_Controller_M->solverInfo,
                       &ROS_Controller_M->Timing.stepSize0);
    rtsiSetdXPtr(&ROS_Controller_M->solverInfo,
                 &ROS_Controller_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ROS_Controller_M->solverInfo, (real_T **)
                         &ROS_Controller_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ROS_Controller_M->solverInfo,
      &ROS_Controller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ROS_Controller_M->solverInfo,
      &ROS_Controller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ROS_Controller_M->solverInfo,
      &ROS_Controller_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ROS_Controller_M->solverInfo,
      &ROS_Controller_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ROS_Controller_M->solverInfo, (&rtmGetErrorStatus
      (ROS_Controller_M)));
    rtsiSetRTModelPtr(&ROS_Controller_M->solverInfo, ROS_Controller_M);
  }

  rtsiSetSimTimeStep(&ROS_Controller_M->solverInfo, MAJOR_TIME_STEP);
  ROS_Controller_M->ModelData.intgData.y = ROS_Controller_M->ModelData.odeY;
  ROS_Controller_M->ModelData.intgData.f[0] = ROS_Controller_M->ModelData.odeF[0];
  ROS_Controller_M->ModelData.intgData.f[1] = ROS_Controller_M->ModelData.odeF[1];
  ROS_Controller_M->ModelData.intgData.f[2] = ROS_Controller_M->ModelData.odeF[2];
  ROS_Controller_M->ModelData.contStates = ((X_ROS_Controller_T *)
    &ROS_Controller_X);
  rtsiSetSolverData(&ROS_Controller_M->solverInfo, (void *)
                    &ROS_Controller_M->ModelData.intgData);
  rtsiSetSolverName(&ROS_Controller_M->solverInfo,"ode3");
  rtmSetTPtr(ROS_Controller_M, &ROS_Controller_M->Timing.tArray[0]);
  ROS_Controller_M->Timing.stepSize0 = 0.05;

  // block I/O
  (void) memset(((void *) &ROS_Controller_B), 0,
                sizeof(B_ROS_Controller_T));

  // states (continuous)
  {
    (void) memset((void *)&ROS_Controller_X, 0,
                  sizeof(X_ROS_Controller_T));
  }

  // states (dwork)
  (void) memset((void *)&ROS_Controller_DW, 0,
                sizeof(DW_ROS_Controller_T));

  {
    static const char_T tmp[7] = { '/', 'E', 't', 'a', 'S', 'e', 't' };

    char_T tmp_0[8];
    char_T tmp_1[5];
    char_T tmp_2[3];
    int32_T i;

    // Start for Atomic SubSystem: '<S7>/Publish1'
    // Start for MATLABSystem: '<S20>/SinkBlock'
    ROS_Controller_DW.obj_i.isInitialized = 0;
    ROS_Controller_DW.objisempty = true;
    ROS_Controller_DW.obj_i.isInitialized = 1;
    tmp_2[0] = '/';
    tmp_2[1] = 'U';
    tmp_2[2] = '\x00';
    Pub_ROS_Controller_153.create_publisher(tmp_2,
      ROS_Controller_MessageQueueLen);

    // End of Start for SubSystem: '<S7>/Publish1'

    // Start for Atomic SubSystem: '<S3>/Subscribe2'
    // Start for MATLABSystem: '<S14>/SourceBlock'
    ROS_Controller_DW.obj_o.isInitialized = 0;
    ROS_Controller_DW.objisempty_i = true;
    ROS_Controller_DW.obj_o.isInitialized = 1;
    tmp_1[0] = '/';
    tmp_1[1] = 'E';
    tmp_1[2] = 't';
    tmp_1[3] = 'a';
    tmp_1[4] = '\x00';
    Sub_ROS_Controller_659.create_subscriber(tmp_1,
      ROS_Controller_MessageQueueLen);

    // Start for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S15>/Out1'
    ROS_Controller_B.In1_i = ROS_Controller_P.Out1_Y0;

    // End of Start for SubSystem: '<S14>/Enabled Subsystem'
    // End of Start for SubSystem: '<S3>/Subscribe2'

    // Start for Atomic SubSystem: '<S4>/Subscribe2'
    // Start for MATLABSystem: '<S16>/SourceBlock'
    ROS_Controller_DW.obj.isInitialized = 0;
    ROS_Controller_DW.objisempty_m = true;
    ROS_Controller_DW.obj.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      tmp_0[i] = tmp[i];
    }

    tmp_0[7] = '\x00';
    Sub_ROS_Controller_652.create_subscriber(tmp_0,
      ROS_Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S16>/SourceBlock'

    // Start for Enabled SubSystem: '<S16>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S17>/Out1'
    ROS_Controller_B.In1 = ROS_Controller_P.Out1_Y0_d;

    // End of Start for SubSystem: '<S16>/Enabled Subsystem'
    // End of Start for SubSystem: '<S4>/Subscribe2'

    // InitializeConditions for TransferFcn: '<S6>/Transfer Fcn5'
    ROS_Controller_X.TransferFcn5_CSTATE = 0.0;

    // InitializeConditions for TransferFcn: '<S6>/Transfer Fcn6'
    ROS_Controller_X.TransferFcn6_CSTATE = 0.0;

    // InitializeConditions for TransferFcn: '<S6>/Transfer Fcn7'
    ROS_Controller_X.TransferFcn7_CSTATE = 0.0;

    // InitializeConditions for Derivative: '<S1>/Derivative'
    ROS_Controller_DW.TimeStampA = (rtInf);
    ROS_Controller_DW.TimeStampB = (rtInf);

    // InitializeConditions for Integrator: '<S5>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE[0] = ROS_Controller_P.Integrator2_IC[0];

    // InitializeConditions for Integrator: '<S9>/Integrator'
    ROS_Controller_X.Integrator_CSTATE[0] = ROS_Controller_P.InitialPos[0];

    // InitializeConditions for Integrator: '<S9>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE[0] = ROS_Controller_P.Integrator1_IC;

    // InitializeConditions for Integrator: '<S1>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_d[0] =
      ROS_Controller_P.Integrator1_IC_h[0];

    // InitializeConditions for Integrator: '<S9>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE_n[0] =
      ROS_Controller_P.Integrator2_IC_j[0];

    // InitializeConditions for Integrator: '<S5>/Integrator'
    ROS_Controller_X.Integrator_CSTATE_a[0] = ROS_Controller_P.Integrator_IC[0];

    // InitializeConditions for Integrator: '<S5>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_i[0] =
      ROS_Controller_P.Integrator1_IC_e[0];

    // InitializeConditions for Integrator: '<S5>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE[1] = ROS_Controller_P.Integrator2_IC[1];

    // InitializeConditions for Integrator: '<S9>/Integrator'
    ROS_Controller_X.Integrator_CSTATE[1] = ROS_Controller_P.InitialPos[1];

    // InitializeConditions for Integrator: '<S9>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE[1] = ROS_Controller_P.Integrator1_IC;

    // InitializeConditions for Integrator: '<S1>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_d[1] =
      ROS_Controller_P.Integrator1_IC_h[1];

    // InitializeConditions for Integrator: '<S9>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE_n[1] =
      ROS_Controller_P.Integrator2_IC_j[1];

    // InitializeConditions for Integrator: '<S5>/Integrator'
    ROS_Controller_X.Integrator_CSTATE_a[1] = ROS_Controller_P.Integrator_IC[1];

    // InitializeConditions for Integrator: '<S5>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_i[1] =
      ROS_Controller_P.Integrator1_IC_e[1];

    // InitializeConditions for Integrator: '<S5>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE[2] = ROS_Controller_P.Integrator2_IC[2];

    // InitializeConditions for Integrator: '<S9>/Integrator'
    ROS_Controller_X.Integrator_CSTATE[2] = ROS_Controller_P.InitialPos[2];

    // InitializeConditions for Integrator: '<S9>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE[2] = ROS_Controller_P.Integrator1_IC;

    // InitializeConditions for Integrator: '<S1>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_d[2] =
      ROS_Controller_P.Integrator1_IC_h[2];

    // InitializeConditions for Integrator: '<S9>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE_n[2] =
      ROS_Controller_P.Integrator2_IC_j[2];

    // InitializeConditions for Integrator: '<S5>/Integrator'
    ROS_Controller_X.Integrator_CSTATE_a[2] = ROS_Controller_P.Integrator_IC[2];

    // InitializeConditions for Integrator: '<S5>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_i[2] =
      ROS_Controller_P.Integrator1_IC_e[2];
  }
}

// Model terminate function
void ROS_Controller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S7>/Publish1'
  // Start for MATLABSystem: '<S20>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S20>/SinkBlock'

  if (ROS_Controller_DW.obj_i.isInitialized == 1) {
    ROS_Controller_DW.obj_i.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S20>/SinkBlock'
  // End of Terminate for SubSystem: '<S7>/Publish1'

  // Terminate for Atomic SubSystem: '<S3>/Subscribe2'
  // Start for MATLABSystem: '<S14>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S14>/SourceBlock'

  if (ROS_Controller_DW.obj_o.isInitialized == 1) {
    ROS_Controller_DW.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S14>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S4>/Subscribe2'
  // Start for MATLABSystem: '<S16>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S16>/SourceBlock'

  if (ROS_Controller_DW.obj.isInitialized == 1) {
    ROS_Controller_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S16>/SourceBlock'
  // End of Terminate for SubSystem: '<S4>/Subscribe2'
}

//
// File trailer for generated code.
//
// [EOF]
//
