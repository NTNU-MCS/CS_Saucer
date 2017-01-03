//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS_Controller.cpp
//
// Code generated for Simulink model 'ROS_Controller'.
//
// Model version                  : 1.76
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Fri Jun  3 22:05:53 2016
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

// Forward declaration for local functions
static real_T ROS_Controller_interp1(const real_T varargin_1[62], const real_T
  varargin_2[62], real_T varargin_3);

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
  int_T nXc = 21;
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

// Function for MATLAB Function: '<S2>/PWM-Mapping'
static real_T ROS_Controller_interp1(const real_T varargin_1[62], const real_T
  varargin_2[62], real_T varargin_3)
{
  real_T Vq;
  int32_T k;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  memcpy(&ROS_Controller_B.y[0], &varargin_2[0], 62U * sizeof(real_T));
  memcpy(&ROS_Controller_B.x[0], &varargin_1[0], 62U * sizeof(real_T));
  Vq = (rtNaN);
  k = 1;
  do {
    low_i = 0;
    if (k < 63) {
      if (rtIsNaN(varargin_1[k - 1])) {
        low_i = 1;
      } else {
        k++;
      }
    } else {
      if (varargin_1[1] < varargin_1[0]) {
        for (low_i = 0; low_i < 31; low_i++) {
          ROS_Controller_B.r_p = ROS_Controller_B.x[low_i];
          ROS_Controller_B.x[low_i] = ROS_Controller_B.x[61 - low_i];
          ROS_Controller_B.x[61 - low_i] = ROS_Controller_B.r_p;
        }

        for (low_i = 0; low_i < 31; low_i++) {
          ROS_Controller_B.r_p = ROS_Controller_B.y[low_i];
          ROS_Controller_B.y[low_i] = ROS_Controller_B.y[61 - low_i];
          ROS_Controller_B.y[61 - low_i] = ROS_Controller_B.r_p;
        }
      }

      if (!(rtIsNaN(varargin_3) || (varargin_3 > ROS_Controller_B.x[61]) ||
            (varargin_3 < ROS_Controller_B.x[0]))) {
        low_i = 1;
        low_ip1 = 2;
        high_i = 62;
        while (high_i > low_ip1) {
          mid_i = (low_i + high_i) >> 1;
          if (varargin_3 >= ROS_Controller_B.x[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        ROS_Controller_B.r_p = (varargin_3 - ROS_Controller_B.x[low_i - 1]) /
          (ROS_Controller_B.x[low_i] - ROS_Controller_B.x[low_i - 1]);
        if (ROS_Controller_B.r_p == 0.0) {
          Vq = ROS_Controller_B.y[low_i - 1];
        } else if (ROS_Controller_B.r_p == 1.0) {
          Vq = ROS_Controller_B.y[low_i];
        } else if (ROS_Controller_B.y[low_i - 1] == ROS_Controller_B.y[low_i]) {
          Vq = ROS_Controller_B.y[low_i - 1];
        } else {
          Vq = (1.0 - ROS_Controller_B.r_p) * ROS_Controller_B.y[low_i - 1] +
            ROS_Controller_B.r_p * ROS_Controller_B.y[low_i];
        }
      }

      low_i = 1;
    }
  } while (low_i == 0);

  return Vq;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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
    int32_T high_i;
    int32_T mid_i;
    boolean_T exitg13;
    SL_Bus_ROS_Controller_std_msgs_Bool varargout_2;
    SL_Bus_ROS_Controller_std_msgs_UInt16 rtb_BusAssignment1_g;
    SL_Bus_ROS_Controller_std_msgs_UInt16 rtb_BusAssignment2;
    int16_T rtb_DataTypeConversion;
    SL_Bus_ROS_Controller_std_msgs_UInt16 rtb_BusAssignment3_f;
    SL_Bus_ROS_Controller_std_msgs_UInt16 rtb_BusAssignment1_e;
    SL_Bus_ROS_Controller_std_msgs_UInt16 rtb_BusAssignment2_k;
    SL_Bus_ROS_Controller_std_msgs_UInt16 rtb_BusAssignment3_k;
    int32_T i;
    uint16_T rtb_Switch_idx_0;
    uint16_T rtb_Switch_idx_1;
    uint16_T rtb_Switch_idx_2;

    // MATLAB Function: '<S1>/Rotation Matrix' incorporates:
    //   Integrator: '<S16>/Integrator'

    // MATLAB Function 'DPcontroller/Rotation Matrix': '<S10>:1'
    // '<S10>:1:2'
    // '<S10>:1:3'
    ROS_Controller_B.R_k[0] = cos(ROS_Controller_X.Integrator_CSTATE[2]);
    ROS_Controller_B.R_k[1] = -sin(ROS_Controller_X.Integrator_CSTATE[2]);
    ROS_Controller_B.R_k[2] = 0.0;
    ROS_Controller_B.R_k[3] = sin(ROS_Controller_X.Integrator_CSTATE[2]);
    ROS_Controller_B.R_k[4] = cos(ROS_Controller_X.Integrator_CSTATE[2]);
    ROS_Controller_B.R_k[5] = 0.0;

    // R=[RotPhi(1:2,:);[0 0 0;0 0 0;0 0 0];RotPhi(3,:)]
    ROS_Controller_B.R_k[6] = 0.0;

    // Integrator: '<S6>/Integrator2'
    ROS_Controller_B.Integrator2[0] = ROS_Controller_X.Integrator2_CSTATE[0];

    // MATLAB Function: '<S1>/Rotation Matrix'
    ROS_Controller_B.R_k[7] = 0.0;

    // Integrator: '<S6>/Integrator2'
    ROS_Controller_B.Integrator2[1] = ROS_Controller_X.Integrator2_CSTATE[1];

    // MATLAB Function: '<S1>/Rotation Matrix'
    ROS_Controller_B.R_k[8] = 1.0;

    // Integrator: '<S6>/Integrator2'
    ROS_Controller_B.Integrator2[2] = ROS_Controller_X.Integrator2_CSTATE[2];

    // Derivative: '<S1>/Derivative'
    if ((ROS_Controller_DW.TimeStampA >= ROS_Controller_M->Timing.t[0]) &&
        (ROS_Controller_DW.TimeStampB >= ROS_Controller_M->Timing.t[0])) {
      ROS_Controller_B.Gain1_c[0] = 0.0;
      ROS_Controller_B.Gain1_c[1] = 0.0;
      ROS_Controller_B.Gain1_c[2] = 0.0;
    } else {
      ROS_Controller_B.scale = ROS_Controller_DW.TimeStampA;
      lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeA;
      if (ROS_Controller_DW.TimeStampA < ROS_Controller_DW.TimeStampB) {
        if (ROS_Controller_DW.TimeStampB < ROS_Controller_M->Timing.t[0]) {
          ROS_Controller_B.scale = ROS_Controller_DW.TimeStampB;
          lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeB;
        }
      } else {
        if (ROS_Controller_DW.TimeStampA >= ROS_Controller_M->Timing.t[0]) {
          ROS_Controller_B.scale = ROS_Controller_DW.TimeStampB;
          lastU = (real_T (*)[3])ROS_Controller_DW.LastUAtTimeB;
        }
      }

      ROS_Controller_B.scale = ROS_Controller_M->Timing.t[0] -
        ROS_Controller_B.scale;
      ROS_Controller_B.Gain1_c[0] = (ROS_Controller_B.Integrator2[0] - (*lastU)
        [0]) / ROS_Controller_B.scale;
      ROS_Controller_B.Gain1_c[1] = (ROS_Controller_B.Integrator2[1] - (*lastU)
        [1]) / ROS_Controller_B.scale;
      ROS_Controller_B.Gain1_c[2] = (ROS_Controller_B.Integrator2[2] - (*lastU)
        [2]) / ROS_Controller_B.scale;
    }

    // End of Derivative: '<S1>/Derivative'

    // Sum: '<S1>/Sum3' incorporates:
    //   Gain: '<S1>/Gain2'
    //   Integrator: '<S16>/Integrator1'
    //   Product: '<S1>/{XYD}->{BODY}'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.rtb_R_b[i] = ((ROS_Controller_B.R_k[i + 3] *
        ROS_Controller_B.Gain1_c[1] + ROS_Controller_B.R_k[i] *
        ROS_Controller_B.Gain1_c[0]) + ROS_Controller_B.R_k[i + 6] *
        ROS_Controller_B.Gain1_c[2]) - ROS_Controller_X.Integrator1_CSTATE[i];
    }

    // End of Sum: '<S1>/Sum3'
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

      // Sum: '<S1>/Sum' incorporates:
      //   Integrator: '<S16>/Integrator'

      ROS_Controller_B.nframetobframe[i] = ROS_Controller_B.Integrator2[i] -
        ROS_Controller_X.Integrator_CSTATE[i];

      // Gain: '<S1>/Gain2'
      ROS_Controller_B.Gain1_c[i] = ROS_Controller_P.Gain2_Gain[i + 6] *
        ROS_Controller_B.rtb_R_b[2] + (ROS_Controller_P.Gain2_Gain[i + 3] *
        ROS_Controller_B.rtb_R_b[1] + ROS_Controller_P.Gain2_Gain[i] *
        ROS_Controller_B.rtb_R_b[0]);
    }

    // Sum: '<S1>/Sum1' incorporates:
    //   Gain: '<S1>/Gain'
    //   Integrator: '<S1>/Integrator1'
    //   Product: '<S1>/{XYD}->{BODY}s'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.rtb_R_b[i] = ((ROS_Controller_P.Gain_Gain[i + 3] *
        ROS_Controller_B.nframetobframe[1] + ROS_Controller_P.Gain_Gain[i] *
        ROS_Controller_B.nframetobframe[0]) + ROS_Controller_P.Gain_Gain[i + 6] *
        ROS_Controller_B.nframetobframe[2]) +
        ROS_Controller_X.Integrator1_CSTATE_d[i];
    }

    // End of Sum: '<S1>/Sum1'

    // Sum: '<S1>/Sum2' incorporates:
    //   Product: '<S1>/{XYD}->{BODY}s'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.Sum2[i] = ((ROS_Controller_B.R_k[i + 3] *
        ROS_Controller_B.rtb_R_b[1] + ROS_Controller_B.R_k[i] *
        ROS_Controller_B.rtb_R_b[0]) + ROS_Controller_B.R_k[i + 6] *
        ROS_Controller_B.rtb_R_b[2]) + ROS_Controller_B.Gain1_c[i];
    }

    // End of Sum: '<S1>/Sum2'

    // MATLAB Function: '<S7>/Torque Saturation' incorporates:
    //   Constant: '<S7>/Thrust Sat'

    // MATLAB Function 'ThrustDynamics/Torque Saturation': '<S27>:1'
    // '<S27>:1:2'
    ROS_Controller_B.scale = 2.2250738585072014E-308;
    ROS_Controller_B.r = fabs(ROS_Controller_B.Sum2[0]);
    if (ROS_Controller_B.r > 2.2250738585072014E-308) {
      ROS_Controller_B.Com_Torque = 1.0;
      ROS_Controller_B.scale = ROS_Controller_B.r;
    } else {
      ROS_Controller_B.tmp = ROS_Controller_B.r / 2.2250738585072014E-308;
      ROS_Controller_B.Com_Torque = ROS_Controller_B.tmp * ROS_Controller_B.tmp;
    }

    ROS_Controller_B.r = fabs(ROS_Controller_B.Sum2[1]);
    if (ROS_Controller_B.r > ROS_Controller_B.scale) {
      ROS_Controller_B.tmp = ROS_Controller_B.scale / ROS_Controller_B.r;
      ROS_Controller_B.Com_Torque = ROS_Controller_B.Com_Torque *
        ROS_Controller_B.tmp * ROS_Controller_B.tmp + 1.0;
      ROS_Controller_B.scale = ROS_Controller_B.r;
    } else {
      ROS_Controller_B.tmp = ROS_Controller_B.r / ROS_Controller_B.scale;
      ROS_Controller_B.Com_Torque += ROS_Controller_B.tmp * ROS_Controller_B.tmp;
    }

    ROS_Controller_B.Com_Torque = ROS_Controller_B.scale * sqrt
      (ROS_Controller_B.Com_Torque);
    if (ROS_Controller_B.Com_Torque > ROS_Controller_P.ThrustSat_Value) {
      // '<S27>:1:3'
      // '<S27>:1:4'
      ROS_Controller_B.scale = ROS_Controller_P.ThrustSat_Value /
        ROS_Controller_B.Com_Torque;
      ROS_Controller_B.Sum2[0] *= ROS_Controller_B.scale;
      ROS_Controller_B.Sum2[1] *= ROS_Controller_B.scale;
    }

    // '<S27>:1:6'
    if (fabs(ROS_Controller_B.Sum2[2]) > 0.3) {
      // '<S27>:1:7'
      // '<S27>:1:8'
      ROS_Controller_B.Sum2[2] = 0.3 * ROS_Controller_B.Sum2[2] / fabs
        (ROS_Controller_B.Sum2[2]);
    }

    // End of MATLAB Function: '<S7>/Torque Saturation'

    // ManualSwitch: '<S7>/Manual Switch'
    // '<S27>:1:10'
    exitg13 = (ROS_Controller_P.ManualSwitch_CurrentSetting == 1);

    // Gain: '<S7>/Gain' incorporates:
    //   Constant: '<S7>/Constant'
    //   ManualSwitch: '<S7>/Manual Switch'

    if (exitg13) {
      ROS_Controller_B.tmp = ROS_Controller_P.Constant_Value_h[0];
    } else {
      ROS_Controller_B.tmp = ROS_Controller_B.Sum2[0];
    }

    ROS_Controller_B.Sum2[0] = ROS_Controller_P.Gain_Gain_b[0] *
      ROS_Controller_B.tmp;
    if (exitg13) {
      ROS_Controller_B.tmp = ROS_Controller_P.Constant_Value_h[1];
    } else {
      ROS_Controller_B.tmp = ROS_Controller_B.Sum2[1];
    }

    ROS_Controller_B.Sum2[1] = ROS_Controller_P.Gain_Gain_b[1] *
      ROS_Controller_B.tmp;
    if (exitg13) {
      ROS_Controller_B.tmp = ROS_Controller_P.Constant_Value_h[2];
    } else {
      ROS_Controller_B.tmp = ROS_Controller_B.Sum2[2];
    }

    ROS_Controller_B.Sum2[2] = ROS_Controller_P.Gain_Gain_b[2] *
      ROS_Controller_B.tmp;

    // End of Gain: '<S7>/Gain'

    // Saturate: '<S7>/Saturation1'
    if (ROS_Controller_B.Sum2[0] > ROS_Controller_P.Saturation1_UpperSat) {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.r = ROS_Controller_P.Saturation1_UpperSat;
    } else if (ROS_Controller_B.Sum2[0] < ROS_Controller_P.Saturation1_LowerSat)
    {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.r = ROS_Controller_P.Saturation1_LowerSat;
    } else {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.r = ROS_Controller_B.Sum2[0];
    }

    // End of Saturate: '<S7>/Saturation1'

    // Saturate: '<S7>/Saturation2'
    if (ROS_Controller_B.Sum2[1] > ROS_Controller_P.Saturation2_UpperSat) {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.unnamed_idx_1 = ROS_Controller_P.Saturation2_UpperSat;
    } else if (ROS_Controller_B.Sum2[1] < ROS_Controller_P.Saturation2_LowerSat)
    {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.unnamed_idx_1 = ROS_Controller_P.Saturation2_LowerSat;
    } else {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.unnamed_idx_1 = ROS_Controller_B.Sum2[1];
    }

    // End of Saturate: '<S7>/Saturation2'

    // Saturate: '<S7>/Saturation3'
    if (ROS_Controller_B.Sum2[2] > ROS_Controller_P.Saturation3_UpperSat) {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.unnamed_idx_2 = ROS_Controller_P.Saturation3_UpperSat;
    } else if (ROS_Controller_B.Sum2[2] < ROS_Controller_P.Saturation3_LowerSat)
    {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.unnamed_idx_2 = ROS_Controller_P.Saturation3_LowerSat;
    } else {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{thrust}->{u}Inport2'
      ROS_Controller_B.unnamed_idx_2 = ROS_Controller_B.Sum2[2];
    }

    // End of Saturate: '<S7>/Saturation3'

    // Product: '<S7>/{thrust}->{u}' incorporates:
    //   Constant: '<S7>/Inverse thrust allocation Matrix'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.Gain[i] = ROS_Controller_P.invThrustAloc[i + 6] *
        ROS_Controller_B.unnamed_idx_2 + (ROS_Controller_P.invThrustAloc[i + 3] *
        ROS_Controller_B.unnamed_idx_1 + ROS_Controller_P.invThrustAloc[i] *
        ROS_Controller_B.r);
    }

    // End of Product: '<S7>/{thrust}->{u}'

    // Saturate: '<S7>/Saturation5'
    if (ROS_Controller_B.Gain[0] > ROS_Controller_P.Saturation5_UpperSat) {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{u}->{thrust}Inport2'
      ROS_Controller_B.Sum2[0] = ROS_Controller_P.Saturation5_UpperSat;
    } else if (ROS_Controller_B.Gain[0] < ROS_Controller_P.Saturation5_LowerSat)
    {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{u}->{thrust}Inport2'
      ROS_Controller_B.Sum2[0] = ROS_Controller_P.Saturation5_LowerSat;
    } else {
      // SignalConversion: '<S7>/TmpSignal ConversionAt{u}->{thrust}Inport2'
      ROS_Controller_B.Sum2[0] = ROS_Controller_B.Gain[0];
    }

    // Saturate: '<S7>/Saturation6'
    if (ROS_Controller_B.Gain[1] > ROS_Controller_P.Saturation6_UpperSat) {
      ROS_Controller_B.unnamed_idx_1 = ROS_Controller_P.Saturation6_UpperSat;
    } else if (ROS_Controller_B.Gain[1] < ROS_Controller_P.Saturation6_LowerSat)
    {
      ROS_Controller_B.unnamed_idx_1 = ROS_Controller_P.Saturation6_LowerSat;
    } else {
      ROS_Controller_B.unnamed_idx_1 = ROS_Controller_B.Gain[1];
    }

    // End of Saturate: '<S7>/Saturation6'

    // Saturate: '<S7>/Saturation7'
    if (ROS_Controller_B.Gain[2] > ROS_Controller_P.Saturation7_UpperSat) {
      ROS_Controller_B.unnamed_idx_2 = ROS_Controller_P.Saturation7_UpperSat;
    } else if (ROS_Controller_B.Gain[2] < ROS_Controller_P.Saturation7_LowerSat)
    {
      ROS_Controller_B.unnamed_idx_2 = ROS_Controller_P.Saturation7_LowerSat;
    } else {
      ROS_Controller_B.unnamed_idx_2 = ROS_Controller_B.Gain[2];
    }

    // End of Saturate: '<S7>/Saturation7'

    // ManualSwitch: '<S2>/Manual Switch1' incorporates:
    //   Constant: '<S2>/Constant7'
    //   Constant: '<S2>/Constant8'
    //   Constant: '<S2>/Constant9'
    //   SignalConversion: '<S7>/TmpSignal ConversionAt{u}->{thrust}Inport2'

    if (ROS_Controller_P.ManualSwitch1_CurrentSetting == 1) {
      // Saturate: '<S7>/Saturation5'
      if (ROS_Controller_B.Gain[0] > ROS_Controller_P.Saturation5_UpperSat) {
        ROS_Controller_B.Gain1_c[0] = ROS_Controller_P.Saturation5_UpperSat;
      } else if (ROS_Controller_B.Gain[0] <
                 ROS_Controller_P.Saturation5_LowerSat) {
        ROS_Controller_B.Gain1_c[0] = ROS_Controller_P.Saturation5_LowerSat;
      } else {
        ROS_Controller_B.Gain1_c[0] = ROS_Controller_B.Gain[0];
      }

      ROS_Controller_B.Gain1_c[1] = ROS_Controller_B.unnamed_idx_1;
      ROS_Controller_B.Gain1_c[2] = ROS_Controller_B.unnamed_idx_2;
    } else {
      ROS_Controller_B.Gain1_c[0] = ROS_Controller_P.Constant7_Value;
      ROS_Controller_B.Gain1_c[1] = ROS_Controller_P.Constant8_Value;
      ROS_Controller_B.Gain1_c[2] = ROS_Controller_P.Constant9_Value;
    }

    // End of ManualSwitch: '<S2>/Manual Switch1'

    // MATLAB Function: '<S2>/PWM-Mapping' incorporates:
    //   Constant: '<S2>/Constant1'
    //   Constant: '<S2>/Constant3'
    //   Constant: '<S2>/Constant4'
    //   Constant: '<S2>/Constant5'

    ROS_Controller_B.Gain[0] = ROS_Controller_B.Gain1_c[0];
    ROS_Controller_B.Gain[1] = ROS_Controller_B.Gain1_c[1];

    // MATLAB Function 'EINAR2180MAP1/PWM-Mapping': '<S11>:1'
    // '<S11>:1:2'
    // '<S11>:1:3'
    ROS_Controller_B.Gain[2] = -ROS_Controller_B.Gain1_c[2];

    // '<S11>:1:4'
    for (i = 0; i < 62; i++) {
      ROS_Controller_B.MAPP3[i] = -ROS_Controller_P.MAPP1[i];
    }

    i = 1;
    ROS_Controller_B.scale = ROS_Controller_P.MAPP1[0];
    if (rtIsNaN(ROS_Controller_P.MAPP1[0])) {
      ROS_Controller_B.low_i = 2;
      exitg13 = false;
      while ((!exitg13) && (ROS_Controller_B.low_i < 63)) {
        i = ROS_Controller_B.low_i;
        if (!rtIsNaN(ROS_Controller_P.MAPP1[ROS_Controller_B.low_i - 1])) {
          ROS_Controller_B.scale = ROS_Controller_P.MAPP1[ROS_Controller_B.low_i
            - 1];
          exitg13 = true;
        } else {
          ROS_Controller_B.low_i++;
        }
      }
    }

    if (i < 62) {
      while (i + 1 < 63) {
        if (ROS_Controller_P.MAPP1[i] > ROS_Controller_B.scale) {
          ROS_Controller_B.scale = ROS_Controller_P.MAPP1[i];
        }

        i++;
      }
    }

    if (ROS_Controller_B.Gain1_c[0] > ROS_Controller_B.scale) {
      // '<S11>:1:7'
      // '<S11>:1:8'
      i = 1;
      ROS_Controller_B.scale = ROS_Controller_P.MAPP1[0];
      if (rtIsNaN(ROS_Controller_P.MAPP1[0])) {
        ROS_Controller_B.low_i = 2;
        exitg13 = false;
        while ((!exitg13) && (ROS_Controller_B.low_i < 63)) {
          i = ROS_Controller_B.low_i;
          if (!rtIsNaN(ROS_Controller_P.MAPP1[ROS_Controller_B.low_i - 1])) {
            ROS_Controller_B.scale =
              ROS_Controller_P.MAPP1[ROS_Controller_B.low_i - 1];
            exitg13 = true;
          } else {
            ROS_Controller_B.low_i++;
          }
        }
      }

      if (i < 62) {
        while (i + 1 < 63) {
          if (ROS_Controller_P.MAPP1[i] > ROS_Controller_B.scale) {
            ROS_Controller_B.scale = ROS_Controller_P.MAPP1[i];
          }

          i++;
        }
      }

      ROS_Controller_B.Gain[0] = ROS_Controller_B.scale;
    } else {
      i = 1;
      ROS_Controller_B.scale = ROS_Controller_P.MAPP1[0];
      if (rtIsNaN(ROS_Controller_P.MAPP1[0])) {
        ROS_Controller_B.low_i = 2;
        exitg13 = false;
        while ((!exitg13) && (ROS_Controller_B.low_i < 63)) {
          i = ROS_Controller_B.low_i;
          if (!rtIsNaN(ROS_Controller_P.MAPP1[ROS_Controller_B.low_i - 1])) {
            ROS_Controller_B.scale =
              ROS_Controller_P.MAPP1[ROS_Controller_B.low_i - 1];
            exitg13 = true;
          } else {
            ROS_Controller_B.low_i++;
          }
        }
      }

      if (i < 62) {
        while (i + 1 < 63) {
          if (ROS_Controller_P.MAPP1[i] < ROS_Controller_B.scale) {
            ROS_Controller_B.scale = ROS_Controller_P.MAPP1[i];
          }

          i++;
        }
      }

      if (ROS_Controller_B.Gain1_c[0] < ROS_Controller_B.scale) {
        // '<S11>:1:9'
        // '<S11>:1:10'
        i = 1;
        ROS_Controller_B.scale = ROS_Controller_P.MAPP1[0];
        if (rtIsNaN(ROS_Controller_P.MAPP1[0])) {
          ROS_Controller_B.low_i = 2;
          exitg13 = false;
          while ((!exitg13) && (ROS_Controller_B.low_i < 63)) {
            i = ROS_Controller_B.low_i;
            if (!rtIsNaN(ROS_Controller_P.MAPP1[ROS_Controller_B.low_i - 1])) {
              ROS_Controller_B.scale =
                ROS_Controller_P.MAPP1[ROS_Controller_B.low_i - 1];
              exitg13 = true;
            } else {
              ROS_Controller_B.low_i++;
            }
          }
        }

        if (i < 62) {
          while (i + 1 < 63) {
            if (ROS_Controller_P.MAPP1[i] < ROS_Controller_B.scale) {
              ROS_Controller_B.scale = ROS_Controller_P.MAPP1[i];
            }

            i++;
          }
        }

        ROS_Controller_B.Gain[0] = ROS_Controller_B.scale;
      }
    }

    i = 1;
    ROS_Controller_B.scale = ROS_Controller_P.MAPP2[0];
    if (rtIsNaN(ROS_Controller_P.MAPP2[0])) {
      ROS_Controller_B.low_i = 2;
      exitg13 = false;
      while ((!exitg13) && (ROS_Controller_B.low_i < 53)) {
        i = ROS_Controller_B.low_i;
        if (!rtIsNaN(ROS_Controller_P.MAPP2[ROS_Controller_B.low_i - 1])) {
          ROS_Controller_B.scale = ROS_Controller_P.MAPP2[ROS_Controller_B.low_i
            - 1];
          exitg13 = true;
        } else {
          ROS_Controller_B.low_i++;
        }
      }
    }

    if (i < 52) {
      while (i + 1 < 53) {
        if (ROS_Controller_P.MAPP2[i] > ROS_Controller_B.scale) {
          ROS_Controller_B.scale = ROS_Controller_P.MAPP2[i];
        }

        i++;
      }
    }

    if (ROS_Controller_B.Gain1_c[1] > ROS_Controller_B.scale) {
      // '<S11>:1:13'
      // '<S11>:1:14'
      i = 1;
      ROS_Controller_B.scale = ROS_Controller_P.MAPP2[0];
      if (rtIsNaN(ROS_Controller_P.MAPP2[0])) {
        ROS_Controller_B.low_i = 2;
        exitg13 = false;
        while ((!exitg13) && (ROS_Controller_B.low_i < 53)) {
          i = ROS_Controller_B.low_i;
          if (!rtIsNaN(ROS_Controller_P.MAPP2[ROS_Controller_B.low_i - 1])) {
            ROS_Controller_B.scale =
              ROS_Controller_P.MAPP2[ROS_Controller_B.low_i - 1];
            exitg13 = true;
          } else {
            ROS_Controller_B.low_i++;
          }
        }
      }

      if (i < 52) {
        while (i + 1 < 53) {
          if (ROS_Controller_P.MAPP2[i] > ROS_Controller_B.scale) {
            ROS_Controller_B.scale = ROS_Controller_P.MAPP2[i];
          }

          i++;
        }
      }

      ROS_Controller_B.Gain[1] = ROS_Controller_B.scale;
    } else {
      i = 1;
      ROS_Controller_B.scale = ROS_Controller_P.MAPP2[0];
      if (rtIsNaN(ROS_Controller_P.MAPP2[0])) {
        ROS_Controller_B.low_i = 2;
        exitg13 = false;
        while ((!exitg13) && (ROS_Controller_B.low_i < 53)) {
          i = ROS_Controller_B.low_i;
          if (!rtIsNaN(ROS_Controller_P.MAPP2[ROS_Controller_B.low_i - 1])) {
            ROS_Controller_B.scale =
              ROS_Controller_P.MAPP2[ROS_Controller_B.low_i - 1];
            exitg13 = true;
          } else {
            ROS_Controller_B.low_i++;
          }
        }
      }

      if (i < 52) {
        while (i + 1 < 53) {
          if (ROS_Controller_P.MAPP2[i] < ROS_Controller_B.scale) {
            ROS_Controller_B.scale = ROS_Controller_P.MAPP2[i];
          }

          i++;
        }
      }

      if (ROS_Controller_B.Gain1_c[1] < ROS_Controller_B.scale) {
        // '<S11>:1:15'
        // '<S11>:1:16'
        i = 1;
        ROS_Controller_B.scale = ROS_Controller_P.MAPP2[0];
        if (rtIsNaN(ROS_Controller_P.MAPP2[0])) {
          ROS_Controller_B.low_i = 2;
          exitg13 = false;
          while ((!exitg13) && (ROS_Controller_B.low_i < 53)) {
            i = ROS_Controller_B.low_i;
            if (!rtIsNaN(ROS_Controller_P.MAPP2[ROS_Controller_B.low_i - 1])) {
              ROS_Controller_B.scale =
                ROS_Controller_P.MAPP2[ROS_Controller_B.low_i - 1];
              exitg13 = true;
            } else {
              ROS_Controller_B.low_i++;
            }
          }
        }

        if (i < 52) {
          while (i + 1 < 53) {
            if (ROS_Controller_P.MAPP2[i] < ROS_Controller_B.scale) {
              ROS_Controller_B.scale = ROS_Controller_P.MAPP2[i];
            }

            i++;
          }
        }

        ROS_Controller_B.Gain[1] = ROS_Controller_B.scale;
      }
    }

    i = 1;
    ROS_Controller_B.scale = ROS_Controller_B.MAPP3[0];
    if (rtIsNaN(ROS_Controller_B.MAPP3[0])) {
      ROS_Controller_B.low_i = 2;
      exitg13 = false;
      while ((!exitg13) && (ROS_Controller_B.low_i < 63)) {
        i = ROS_Controller_B.low_i;
        if (!rtIsNaN(ROS_Controller_B.MAPP3[ROS_Controller_B.low_i - 1])) {
          ROS_Controller_B.scale = ROS_Controller_B.MAPP3[ROS_Controller_B.low_i
            - 1];
          exitg13 = true;
        } else {
          ROS_Controller_B.low_i++;
        }
      }
    }

    if (i < 62) {
      while (i + 1 < 63) {
        if (ROS_Controller_B.MAPP3[i] > ROS_Controller_B.scale) {
          ROS_Controller_B.scale = ROS_Controller_B.MAPP3[i];
        }

        i++;
      }
    }

    if (-ROS_Controller_B.Gain1_c[2] > ROS_Controller_B.scale) {
      // '<S11>:1:19'
      // '<S11>:1:20'
      i = 1;
      ROS_Controller_B.scale = ROS_Controller_B.MAPP3[0];
      if (rtIsNaN(ROS_Controller_B.MAPP3[0])) {
        ROS_Controller_B.low_i = 2;
        exitg13 = false;
        while ((!exitg13) && (ROS_Controller_B.low_i < 63)) {
          i = ROS_Controller_B.low_i;
          if (!rtIsNaN(ROS_Controller_B.MAPP3[ROS_Controller_B.low_i - 1])) {
            ROS_Controller_B.scale =
              ROS_Controller_B.MAPP3[ROS_Controller_B.low_i - 1];
            exitg13 = true;
          } else {
            ROS_Controller_B.low_i++;
          }
        }
      }

      if (i < 62) {
        while (i + 1 < 63) {
          if (ROS_Controller_B.MAPP3[i] > ROS_Controller_B.scale) {
            ROS_Controller_B.scale = ROS_Controller_B.MAPP3[i];
          }

          i++;
        }
      }

      ROS_Controller_B.Gain[2] = ROS_Controller_B.scale;
    } else {
      i = 1;
      ROS_Controller_B.scale = ROS_Controller_B.MAPP3[0];
      if (rtIsNaN(ROS_Controller_B.MAPP3[0])) {
        ROS_Controller_B.low_i = 2;
        exitg13 = false;
        while ((!exitg13) && (ROS_Controller_B.low_i < 63)) {
          i = ROS_Controller_B.low_i;
          if (!rtIsNaN(ROS_Controller_B.MAPP3[ROS_Controller_B.low_i - 1])) {
            ROS_Controller_B.scale =
              ROS_Controller_B.MAPP3[ROS_Controller_B.low_i - 1];
            exitg13 = true;
          } else {
            ROS_Controller_B.low_i++;
          }
        }
      }

      if (i < 62) {
        while (i + 1 < 63) {
          if (ROS_Controller_B.MAPP3[i] < ROS_Controller_B.scale) {
            ROS_Controller_B.scale = ROS_Controller_B.MAPP3[i];
          }

          i++;
        }
      }

      if (-ROS_Controller_B.Gain1_c[2] < ROS_Controller_B.scale) {
        // '<S11>:1:21'
        // '<S11>:1:22'
        i = 1;
        ROS_Controller_B.scale = ROS_Controller_B.MAPP3[0];
        if (rtIsNaN(ROS_Controller_B.MAPP3[0])) {
          ROS_Controller_B.low_i = 2;
          exitg13 = false;
          while ((!exitg13) && (ROS_Controller_B.low_i < 63)) {
            i = ROS_Controller_B.low_i;
            if (!rtIsNaN(ROS_Controller_B.MAPP3[ROS_Controller_B.low_i - 1])) {
              ROS_Controller_B.scale =
                ROS_Controller_B.MAPP3[ROS_Controller_B.low_i - 1];
              exitg13 = true;
            } else {
              ROS_Controller_B.low_i++;
            }
          }
        }

        if (i < 62) {
          while (i + 1 < 63) {
            if (ROS_Controller_B.MAPP3[i] < ROS_Controller_B.scale) {
              ROS_Controller_B.scale = ROS_Controller_B.MAPP3[i];
            }

            i++;
          }
        }

        ROS_Controller_B.Gain[2] = ROS_Controller_B.scale;
      }
    }

    // '<S11>:1:25'
    ROS_Controller_B.Com_Torque = ROS_Controller_interp1(ROS_Controller_P.MAPP1,
      ROS_Controller_P.Th1, ROS_Controller_B.Gain[0]);

    // '<S11>:1:26'
    ROS_Controller_B.scale = ROS_Controller_B.Gain[1];
    memcpy(&ROS_Controller_B.y_m[0], &ROS_Controller_P.Th2[0], 52U * sizeof
           (real_T));
    memcpy(&ROS_Controller_B.x_c[0], &ROS_Controller_P.MAPP2[0], 52U * sizeof
           (real_T));
    ROS_Controller_B.r = (rtNaN);
    i = 1;
    do {
      ROS_Controller_B.low_i = 0;
      if (i < 53) {
        if (rtIsNaN(ROS_Controller_P.MAPP2[i - 1])) {
          ROS_Controller_B.low_i = 1;
        } else {
          i++;
        }
      } else {
        if (ROS_Controller_P.MAPP2[1] < ROS_Controller_P.MAPP2[0]) {
          for (ROS_Controller_B.low_i = 0; ROS_Controller_B.low_i < 26;
               ROS_Controller_B.low_i++) {
            ROS_Controller_B.tmp = ROS_Controller_B.x_c[ROS_Controller_B.low_i];
            ROS_Controller_B.x_c[ROS_Controller_B.low_i] = ROS_Controller_B.x_c
              [51 - ROS_Controller_B.low_i];
            ROS_Controller_B.x_c[51 - ROS_Controller_B.low_i] =
              ROS_Controller_B.tmp;
          }

          for (ROS_Controller_B.low_i = 0; ROS_Controller_B.low_i < 26;
               ROS_Controller_B.low_i++) {
            ROS_Controller_B.tmp = ROS_Controller_B.y_m[ROS_Controller_B.low_i];
            ROS_Controller_B.y_m[ROS_Controller_B.low_i] = ROS_Controller_B.y_m
              [51 - ROS_Controller_B.low_i];
            ROS_Controller_B.y_m[51 - ROS_Controller_B.low_i] =
              ROS_Controller_B.tmp;
          }
        }

        if (!(rtIsNaN(ROS_Controller_B.scale) || (ROS_Controller_B.scale >
              ROS_Controller_B.x_c[51]) || (ROS_Controller_B.scale <
              ROS_Controller_B.x_c[0]))) {
          ROS_Controller_B.low_i = 1;
          ROS_Controller_B.low_ip1 = 2;
          high_i = 52;
          while (high_i > ROS_Controller_B.low_ip1) {
            mid_i = (ROS_Controller_B.low_i + high_i) >> 1;
            if (ROS_Controller_B.scale >= ROS_Controller_B.x_c[mid_i - 1]) {
              ROS_Controller_B.low_i = mid_i;
              ROS_Controller_B.low_ip1 = mid_i + 1;
            } else {
              high_i = mid_i;
            }
          }

          ROS_Controller_B.r = (ROS_Controller_B.scale -
                                ROS_Controller_B.x_c[ROS_Controller_B.low_i - 1])
            / (ROS_Controller_B.x_c[ROS_Controller_B.low_i] -
               ROS_Controller_B.x_c[ROS_Controller_B.low_i - 1]);
          if (ROS_Controller_B.r == 0.0) {
            ROS_Controller_B.r = ROS_Controller_B.y_m[ROS_Controller_B.low_i - 1];
          } else if (ROS_Controller_B.r == 1.0) {
            ROS_Controller_B.r = ROS_Controller_B.y_m[ROS_Controller_B.low_i];
          } else if (ROS_Controller_B.y_m[ROS_Controller_B.low_i - 1] ==
                     ROS_Controller_B.y_m[ROS_Controller_B.low_i]) {
            ROS_Controller_B.r = ROS_Controller_B.y_m[ROS_Controller_B.low_i - 1];
          } else {
            ROS_Controller_B.r = (1.0 - ROS_Controller_B.r) *
              ROS_Controller_B.y_m[ROS_Controller_B.low_i - 1] +
              ROS_Controller_B.r * ROS_Controller_B.y_m[ROS_Controller_B.low_i];
          }
        }

        ROS_Controller_B.low_i = 1;
      }
    } while (ROS_Controller_B.low_i == 0);

    // '<S11>:1:27'
    ROS_Controller_B.scale = ROS_Controller_interp1(ROS_Controller_B.MAPP3,
      ROS_Controller_P.Th1, ROS_Controller_B.Gain[2]);
    if (fabs(ROS_Controller_B.Gain[0]) < 0.01) {
      // '<S11>:1:29'
      // '<S11>:1:30'
      ROS_Controller_B.Com_Torque = 80.0;
    }

    if (fabs(ROS_Controller_B.Gain[1]) < 0.01) {
      // '<S11>:1:32'
      // '<S11>:1:33'
      ROS_Controller_B.r = 80.0;
    }

    if (fabs(ROS_Controller_B.Gain[2]) < 0.01) {
      // '<S11>:1:35'
      // '<S11>:1:36'
      ROS_Controller_B.scale = 80.0;
    }

    // End of MATLAB Function: '<S2>/PWM-Mapping'
    if (rtmIsMajorTimeStep(ROS_Controller_M)) {
      // Outputs for Atomic SubSystem: '<S8>/Subscribe2'
      // Start for MATLABSystem: '<S33>/SourceBlock' incorporates:
      //   MATLABSystem: '<S33>/SourceBlock'

      exitg13 = Sub_ROS_Controller_892.get_latest_msg(&varargout_2);

      // Outputs for Enabled SubSystem: '<S33>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S34>/Enable'

      // MATLABSystem: '<S33>/SourceBlock' incorporates:
      //   Inport: '<S34>/In1'

      if (exitg13) {
        ROS_Controller_B.In1_h = varargout_2;
      }

      // End of Outputs for SubSystem: '<S33>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<S8>/Subscribe2'
    }

    // Switch: '<S8>/Switch' incorporates:
    //   Constant: '<S8>/Constant'
    //   Constant: '<S8>/Constant1'
    //   Constant: '<S8>/Constant2'
    //   DataTypeConversion: '<Root>/Data Type Conversion'

    if (ROS_Controller_B.In1_h.Data) {
      // DataTypeConversion: '<Root>/Data Type Conversion'
      ROS_Controller_B.tmp = floor(ROS_Controller_B.Com_Torque);
      if (rtIsNaN(ROS_Controller_B.tmp) || rtIsInf(ROS_Controller_B.tmp)) {
        ROS_Controller_B.tmp = 0.0;
      } else {
        ROS_Controller_B.tmp = fmod(ROS_Controller_B.tmp, 65536.0);
      }

      rtb_Switch_idx_0 = (uint16_T)(ROS_Controller_B.tmp < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-ROS_Controller_B.tmp : (int32_T)(uint16_T)
        ROS_Controller_B.tmp);

      // DataTypeConversion: '<Root>/Data Type Conversion'
      ROS_Controller_B.tmp = floor(ROS_Controller_B.r);
      if (rtIsNaN(ROS_Controller_B.tmp) || rtIsInf(ROS_Controller_B.tmp)) {
        ROS_Controller_B.tmp = 0.0;
      } else {
        ROS_Controller_B.tmp = fmod(ROS_Controller_B.tmp, 65536.0);
      }

      rtb_Switch_idx_1 = (uint16_T)(ROS_Controller_B.tmp < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-ROS_Controller_B.tmp : (int32_T)(uint16_T)
        ROS_Controller_B.tmp);

      // DataTypeConversion: '<Root>/Data Type Conversion'
      ROS_Controller_B.tmp = floor(ROS_Controller_B.scale);
      if (rtIsNaN(ROS_Controller_B.tmp) || rtIsInf(ROS_Controller_B.tmp)) {
        ROS_Controller_B.tmp = 0.0;
      } else {
        ROS_Controller_B.tmp = fmod(ROS_Controller_B.tmp, 65536.0);
      }

      rtb_Switch_idx_2 = (uint16_T)(ROS_Controller_B.tmp < 0.0 ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-ROS_Controller_B.tmp : (int32_T)(uint16_T)
        ROS_Controller_B.tmp);
    } else {
      rtb_Switch_idx_0 = ROS_Controller_P.Constant_Value_n;
      rtb_Switch_idx_1 = ROS_Controller_P.Constant1_Value;
      rtb_Switch_idx_2 = ROS_Controller_P.Constant2_Value;
    }

    // End of Switch: '<S8>/Switch'

    // BusAssignment: '<S8>/Bus Assignment1'
    rtb_BusAssignment1_g.Data = rtb_Switch_idx_0;

    // Outputs for Atomic SubSystem: '<S8>/Publish1'
    // MATLABSystem: '<S30>/SinkBlock'
    Pub_ROS_Controller_701.publish(&rtb_BusAssignment1_g);

    // End of Outputs for SubSystem: '<S8>/Publish1'

    // BusAssignment: '<S8>/Bus Assignment2'
    rtb_BusAssignment2.Data = rtb_Switch_idx_1;

    // Outputs for Atomic SubSystem: '<S8>/Publish2'
    // MATLABSystem: '<S31>/SinkBlock'
    Pub_ROS_Controller_702.publish(&rtb_BusAssignment2);

    // End of Outputs for SubSystem: '<S8>/Publish2'

    // DataTypeConversion: '<S8>/Data Type Conversion'
    rtb_DataTypeConversion = (int16_T)rtb_Switch_idx_2;

    // MATLAB Function: '<S8>/Calibrate'
    // MATLAB Function 'UOUT/Calibrate': '<S29>:1'
    // '<S29>:1:2'
    if (rtb_DataTypeConversion < 80) {
      // '<S29>:1:3'
      // '<S29>:1:4'
      rtb_DataTypeConversion = (int16_T)(rtb_DataTypeConversion + 3);
    }

    // End of MATLAB Function: '<S8>/Calibrate'

    // BusAssignment: '<S8>/Bus Assignment3' incorporates:
    //   DataTypeConversion: '<S8>/Data Type Conversion1'

    //      y=y+1;
    //  elseif u<80
    //      y=y+3;
    //  end
    rtb_BusAssignment3_f.Data = (uint16_T)rtb_DataTypeConversion;

    // Outputs for Atomic SubSystem: '<S8>/Publish3'
    // MATLABSystem: '<S32>/SinkBlock'
    Pub_ROS_Controller_703.publish(&rtb_BusAssignment3_f);

    // End of Outputs for SubSystem: '<S8>/Publish3'

    // Gain: '<S1>/Gain1'
    for (i = 0; i < 3; i++) {
      ROS_Controller_B.Gain1[i] = 0.0;
      ROS_Controller_B.Gain1[i] += ROS_Controller_P.Ki[i] *
        ROS_Controller_B.nframetobframe[0];
      ROS_Controller_B.Gain1[i] += ROS_Controller_P.Ki[i + 3] *
        ROS_Controller_B.nframetobframe[1];
      ROS_Controller_B.Gain1[i] += ROS_Controller_P.Ki[i + 6] *
        ROS_Controller_B.nframetobframe[2];
    }

    // End of Gain: '<S1>/Gain1'

    // BusAssignment: '<S14>/Bus Assignment3' incorporates:
    //   Integrator: '<S16>/Integrator1'

    ROS_Controller_B.BusAssignment3.X = ROS_Controller_X.Integrator1_CSTATE[0];
    ROS_Controller_B.BusAssignment3.Y = ROS_Controller_X.Integrator1_CSTATE[1];
    ROS_Controller_B.BusAssignment3.Z = ROS_Controller_X.Integrator1_CSTATE[2];

    // Outputs for Atomic SubSystem: '<S14>/Publish3'
    // MATLABSystem: '<S18>/SinkBlock'
    Pub_ROS_Controller_779.publish(&ROS_Controller_B.BusAssignment3);

    // End of Outputs for SubSystem: '<S14>/Publish3'

    // MATLAB Function: '<S3>/MATLAB Function' incorporates:
    //   Integrator: '<S16>/Integrator1'

    // MATLAB Function 'NonlinearPassiveObs/MATLAB Function': '<S13>:1'
    // '<S13>:1:3'
    ROS_Controller_B.scale = 2.2250738585072014E-308;
    ROS_Controller_B.r = fabs(ROS_Controller_X.Integrator1_CSTATE[0]);
    if (ROS_Controller_B.r > 2.2250738585072014E-308) {
      ROS_Controller_B.Com_Torque = 1.0;
      ROS_Controller_B.scale = ROS_Controller_B.r;
    } else {
      ROS_Controller_B.tmp = ROS_Controller_B.r / 2.2250738585072014E-308;
      ROS_Controller_B.Com_Torque = ROS_Controller_B.tmp * ROS_Controller_B.tmp;
    }

    ROS_Controller_B.r = fabs(ROS_Controller_X.Integrator1_CSTATE[1]);
    if (ROS_Controller_B.r > ROS_Controller_B.scale) {
      ROS_Controller_B.tmp = ROS_Controller_B.scale / ROS_Controller_B.r;
      ROS_Controller_B.Com_Torque = ROS_Controller_B.Com_Torque *
        ROS_Controller_B.tmp * ROS_Controller_B.tmp + 1.0;
      ROS_Controller_B.scale = ROS_Controller_B.r;
    } else {
      ROS_Controller_B.tmp = ROS_Controller_B.r / ROS_Controller_B.scale;
      ROS_Controller_B.Com_Torque += ROS_Controller_B.tmp * ROS_Controller_B.tmp;
    }

    ROS_Controller_B.Com_Torque = ROS_Controller_B.scale * sqrt
      (ROS_Controller_B.Com_Torque);

    // End of MATLAB Function: '<S3>/MATLAB Function'

    // BusAssignment: '<S3>/Bus Assignment1'
    ROS_Controller_B.BusAssignment1.Data = ROS_Controller_B.Com_Torque;

    // Outputs for Atomic SubSystem: '<S3>/Publish1'
    // MATLABSystem: '<S15>/SinkBlock'
    Pub_ROS_Controller_888.publish(&ROS_Controller_B.BusAssignment1);

    // End of Outputs for SubSystem: '<S3>/Publish1'
    // MATLAB Function 'NonlinearPassiveObs/Subsystem/Dampening matrix': '<S20>:1' 
    // '<S20>:1:3'
    // '<S20>:1:4'
    // MATLAB Function 'NonlinearPassiveObs/Subsystem/Correalis matrix': '<S19>:1' 
    // '<S19>:1:3'
    // '<S19>:1:4'
    if (rtmIsMajorTimeStep(ROS_Controller_M)) {
      // Outputs for Atomic SubSystem: '<S4>/Subscribe2'
      // Start for MATLABSystem: '<S23>/SourceBlock' incorporates:
      //   MATLABSystem: '<S23>/SourceBlock'

      exitg13 = Sub_ROS_Controller_659.get_latest_msg
        (&ROS_Controller_B.BusAssignment3);

      // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S24>/Enable'

      // MATLABSystem: '<S23>/SourceBlock' incorporates:
      //   Inport: '<S24>/In1'

      if (exitg13) {
        ROS_Controller_B.In1_i = ROS_Controller_B.BusAssignment3;
      }

      // End of Outputs for SubSystem: '<S23>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<S4>/Subscribe2'

      // SignalConversion: '<S4>/SigConversion_InsertedFor_Bus Selector2_at_outport_0' 
      ROS_Controller_B.X = ROS_Controller_B.In1_i.X;

      // SignalConversion: '<S4>/SigConversion_InsertedFor_Bus Selector2_at_outport_1' 
      ROS_Controller_B.Y = ROS_Controller_B.In1_i.Y;

      // SignalConversion: '<S4>/SigConversion_InsertedFor_Bus Selector2_at_outport_2' 
      ROS_Controller_B.Z = ROS_Controller_B.In1_i.Z;
    }

    // Sum: '<S16>/Sum' incorporates:
    //   Integrator: '<S16>/Integrator'

    ROS_Controller_B.nframetobframe[0] = ROS_Controller_B.X -
      ROS_Controller_X.Integrator_CSTATE[0];
    ROS_Controller_B.nframetobframe[1] = ROS_Controller_B.Y -
      ROS_Controller_X.Integrator_CSTATE[1];
    ROS_Controller_B.nframetobframe[2] = ROS_Controller_B.Z -
      ROS_Controller_X.Integrator_CSTATE[2];
    for (i = 0; i < 3; i++) {
      // Gain: '<S16>/Gain'
      ROS_Controller_B.Gain[i] = ROS_Controller_P.K2[i + 6] *
        ROS_Controller_B.nframetobframe[2] + (ROS_Controller_P.K2[i + 3] *
        ROS_Controller_B.nframetobframe[1] + ROS_Controller_P.K2[i] *
        ROS_Controller_B.nframetobframe[0]);

      // Gain: '<S16>/Gain1'
      ROS_Controller_B.Gain1_c[i] = ROS_Controller_P.K3[i + 6] *
        ROS_Controller_B.nframetobframe[2] + (ROS_Controller_P.K3[i + 3] *
        ROS_Controller_B.nframetobframe[1] + ROS_Controller_P.K3[i] *
        ROS_Controller_B.nframetobframe[0]);
    }

    if (rtmIsMajorTimeStep(ROS_Controller_M)) {
      // MATLAB Function: '<S16>/MATLAB Function'
      // MATLAB Function 'NonlinearPassiveObs/Subsystem/MATLAB Function': '<S21>:1' 
      // '<S21>:1:2'
      // '<S21>:1:3'
      ROS_Controller_B.R_t[0] = cos(ROS_Controller_B.Z);
      ROS_Controller_B.R_t[1] = -sin(ROS_Controller_B.Z);
      ROS_Controller_B.R_t[2] = 0.0;
      ROS_Controller_B.R_t[3] = sin(ROS_Controller_B.Z);
      ROS_Controller_B.R_t[4] = cos(ROS_Controller_B.Z);
      ROS_Controller_B.R_t[5] = 0.0;

      // MATLAB Function: '<S16>/MATLAB Function1'
      // R=[RotPhi(1:2,:);[0 0 0;0 0 0;0 0 0];RotPhi(3,:)]
      // MATLAB Function 'NonlinearPassiveObs/Subsystem/MATLAB Function1': '<S22>:1' 
      // '<S22>:1:2'
      // '<S22>:1:3'
      ROS_Controller_B.R[0] = cos(ROS_Controller_B.Z);
      ROS_Controller_B.R[3] = -sin(ROS_Controller_B.Z);
      ROS_Controller_B.R[6] = 0.0;
      ROS_Controller_B.R[1] = sin(ROS_Controller_B.Z);
      ROS_Controller_B.R[4] = cos(ROS_Controller_B.Z);
      ROS_Controller_B.R[7] = 0.0;

      // MATLAB Function: '<S16>/MATLAB Function'
      ROS_Controller_B.R_t[6] = 0.0;

      // MATLAB Function: '<S16>/MATLAB Function1'
      ROS_Controller_B.R[2] = 0.0;

      // MATLAB Function: '<S16>/MATLAB Function'
      ROS_Controller_B.R_t[7] = 0.0;

      // MATLAB Function: '<S16>/MATLAB Function1'
      ROS_Controller_B.R[5] = 0.0;

      // MATLAB Function: '<S16>/MATLAB Function'
      ROS_Controller_B.R_t[8] = 1.0;

      // MATLAB Function: '<S16>/MATLAB Function1'
      ROS_Controller_B.R[8] = 1.0;
    }

    // Gain: '<S16>/Gain2' incorporates:
    //   Product: '<S16>/{n} frame to {b} frame'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.rtb_R_b[i] = ROS_Controller_P.K4[i + 6] *
        ROS_Controller_B.nframetobframe[2] + (ROS_Controller_P.K4[i + 3] *
        ROS_Controller_B.nframetobframe[1] + ROS_Controller_P.K4[i] *
        ROS_Controller_B.nframetobframe[0]);
    }

    // End of Gain: '<S16>/Gain2'

    // MATLAB Function: '<S16>/Dampening matrix' incorporates:
    //   Constant: '<S16>/Constant2'
    //   Integrator: '<S16>/Integrator1'

    ROS_Controller_B.R_k[0] = ROS_Controller_P.D_nuParams[0] * fabs
      (ROS_Controller_X.Integrator1_CSTATE[0]);
    ROS_Controller_B.R_k[3] = 0.0;
    ROS_Controller_B.R_k[6] = 0.0;
    ROS_Controller_B.R_k[1] = 0.0;
    ROS_Controller_B.R_k[4] = ROS_Controller_P.D_nuParams[4] * fabs
      (ROS_Controller_X.Integrator1_CSTATE[1]);
    ROS_Controller_B.R_k[7] = 0.0;
    for (i = 0; i < 3; i++) {
      // Sum: '<S16>/Sum2' incorporates:
      //   Constant: '<S7>/Thrust allocation Matrix'
      //   Product: '<S16>/{n} frame to {b} frame'
      //   Product: '<S7>/{u}->{thrust}'
      //   SignalConversion: '<S7>/TmpSignal ConversionAt{u}->{thrust}Inport2'
      //   Sum: '<S16>/Sum3'

      ROS_Controller_B.nframetobframe[i] = ((ROS_Controller_P.Tr[i + 3] *
        ROS_Controller_B.unnamed_idx_1 + ROS_Controller_P.Tr[i] *
        ROS_Controller_B.Sum2[0]) + ROS_Controller_P.Tr[i + 6] *
        ROS_Controller_B.unnamed_idx_2) + (ROS_Controller_B.R_t[i + 6] *
        ROS_Controller_B.rtb_R_b[2] + (ROS_Controller_B.R_t[i + 3] *
        ROS_Controller_B.rtb_R_b[1] + ROS_Controller_B.R_t[i] *
        ROS_Controller_B.rtb_R_b[0]));

      // MATLAB Function: '<S16>/Dampening matrix'
      ROS_Controller_B.R_k[2 + 3 * i] = 0.0;

      // Product: '<S16>/Product4' incorporates:
      //   Integrator: '<S16>/Integrator2'
      //   Sum: '<S16>/Sum3'

      ROS_Controller_B.dv0[i] = ROS_Controller_B.R_t[i + 6] *
        ROS_Controller_X.Integrator2_CSTATE_n[2] + (ROS_Controller_B.R_t[i + 3] *
        ROS_Controller_X.Integrator2_CSTATE_n[1] + ROS_Controller_B.R_t[i] *
        ROS_Controller_X.Integrator2_CSTATE_n[0]);

      // Product: '<S16>/Product2' incorporates:
      //   Constant: '<S16>/Constant1'
      //   Integrator: '<S16>/Integrator1'
      //   Sum: '<S16>/Add'

      ROS_Controller_B.dv1[i] = ROS_Controller_P.D[i + 6] *
        ROS_Controller_X.Integrator1_CSTATE[2] + (ROS_Controller_P.D[i + 3] *
        ROS_Controller_X.Integrator1_CSTATE[1] + ROS_Controller_P.D[i] *
        ROS_Controller_X.Integrator1_CSTATE[0]);
    }

    // MATLAB Function: '<S16>/Correalis matrix' incorporates:
    //   Constant: '<S16>/Constant3'
    //   Integrator: '<S16>/Integrator1'

    ROS_Controller_B.dv3[0] = 0.0;
    ROS_Controller_B.dv3[3] = ROS_Controller_P.C_nuParams[1] *
      ROS_Controller_X.Integrator1_CSTATE[2];
    ROS_Controller_B.dv3[6] = 0.0;
    ROS_Controller_B.dv3[1] = -ROS_Controller_P.C_nuParams[3] *
      ROS_Controller_X.Integrator1_CSTATE[2];
    ROS_Controller_B.dv3[4] = 0.0;
    ROS_Controller_B.dv3[7] = 0.0;
    for (i = 0; i < 3; i++) {
      // MATLAB Function: '<S16>/Correalis matrix'
      ROS_Controller_B.dv3[2 + 3 * i] = 0.0;

      // MATLAB Function: '<S16>/Dampening matrix' incorporates:
      //   Integrator: '<S16>/Integrator1'
      //   Sum: '<S16>/Add'

      ROS_Controller_B.rtb_R_b[i] = 0.0 * ROS_Controller_X.Integrator1_CSTATE[2]
        + (ROS_Controller_B.R_k[i + 3] * ROS_Controller_X.Integrator1_CSTATE[1]
           + ROS_Controller_B.R_k[i] * ROS_Controller_X.Integrator1_CSTATE[0]);
    }

    // Sum: '<S16>/Sum3' incorporates:
    //   Integrator: '<S16>/Integrator1'
    //   MATLAB Function: '<S16>/Correalis matrix'
    //   Product: '<S16>/Product1'
    //   Sum: '<S16>/Add'

    for (i = 0; i < 3; i++) {
      ROS_Controller_B.Sum2[i] = (ROS_Controller_B.dv0[i] +
        ROS_Controller_B.nframetobframe[i]) - (((ROS_Controller_B.dv3[i + 3] *
        ROS_Controller_X.Integrator1_CSTATE[1] + ROS_Controller_B.dv3[i] *
        ROS_Controller_X.Integrator1_CSTATE[0]) + 0.0 *
        ROS_Controller_X.Integrator1_CSTATE[2]) + (ROS_Controller_B.dv1[i] +
        ROS_Controller_B.rtb_R_b[i]));
    }

    for (i = 0; i < 3; i++) {
      // Product: '<S16>/Product1' incorporates:
      //   Constant: '<S16>/Constant'

      ROS_Controller_B.Product1[i] = 0.0;
      ROS_Controller_B.Product1[i] += ROS_Controller_P.invM[i] *
        ROS_Controller_B.Sum2[0];
      ROS_Controller_B.Product1[i] += ROS_Controller_P.invM[i + 3] *
        ROS_Controller_B.Sum2[1];
      ROS_Controller_B.Product1[i] += ROS_Controller_P.invM[i + 6] *
        ROS_Controller_B.Sum2[2];

      // Sum: '<S16>/Sum1' incorporates:
      //   Integrator: '<S16>/Integrator1'
      //   Product: '<S16>/{b} frame to {n} frame'

      ROS_Controller_B.Sum1[i] = ((ROS_Controller_B.R[i + 3] *
        ROS_Controller_X.Integrator1_CSTATE[1] + ROS_Controller_B.R[i] *
        ROS_Controller_X.Integrator1_CSTATE[0]) + ROS_Controller_B.R[i + 6] *
        ROS_Controller_X.Integrator1_CSTATE[2]) + ROS_Controller_B.Gain[i];

      // Sum: '<S16>/Sum4' incorporates:
      //   Gain: '<S16>/Gain3'
      //   Integrator: '<S16>/Integrator2'

      ROS_Controller_B.Sum4[i] = ROS_Controller_B.Gain1_c[i] -
        ((ROS_Controller_P.invT[i + 3] * ROS_Controller_X.Integrator2_CSTATE_n[1]
          + ROS_Controller_P.invT[i] * ROS_Controller_X.Integrator2_CSTATE_n[0])
         + ROS_Controller_P.invT[i + 6] * ROS_Controller_X.Integrator2_CSTATE_n
         [2]);
    }

    if (rtmIsMajorTimeStep(ROS_Controller_M)) {
      // Outputs for Atomic SubSystem: '<S5>/Subscribe2'
      // Start for MATLABSystem: '<S25>/SourceBlock' incorporates:
      //   MATLABSystem: '<S25>/SourceBlock'

      exitg13 = Sub_ROS_Controller_652.get_latest_msg
        (&ROS_Controller_B.BusAssignment3);

      // Outputs for Enabled SubSystem: '<S25>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S26>/Enable'

      // MATLABSystem: '<S25>/SourceBlock' incorporates:
      //   Inport: '<S26>/In1'

      if (exitg13) {
        ROS_Controller_B.In1 = ROS_Controller_B.BusAssignment3;
      }

      // End of Outputs for SubSystem: '<S25>/Enabled Subsystem'
      // End of Outputs for SubSystem: '<S5>/Subscribe2'

      // SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector2_at_outport_0' 
      ROS_Controller_B.X_h = ROS_Controller_B.In1.X;

      // SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector2_at_outport_1' 
      ROS_Controller_B.Y_i = ROS_Controller_B.In1.Y;

      // SignalConversion: '<S5>/SigConversion_InsertedFor_Bus Selector2_at_outport_2' 
      ROS_Controller_B.Z_n = ROS_Controller_B.In1.Z;
    }

    // Sum: '<S6>/Sum'
    ROS_Controller_B.dv2[0] = ROS_Controller_B.X_h;
    ROS_Controller_B.dv2[1] = ROS_Controller_B.Y_i;
    ROS_Controller_B.dv2[2] = ROS_Controller_B.Z_n;
    for (i = 0; i < 3; i++) {
      // Saturate: '<S6>/Saturation4' incorporates:
      //   Integrator: '<S6>/Integrator1'

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

      // End of Saturate: '<S6>/Saturation4'

      // Sum: '<S6>/Sum3' incorporates:
      //   Gain: '<S6>/ciwni'
      //   Gain: '<S6>/w_n1'
      //   Gain: '<S6>/w_n2'
      //   Integrator: '<S6>/Integrator'
      //   Integrator: '<S6>/Integrator1'
      //   Sum: '<S6>/Sum2'

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

      // Sum: '<S6>/Sum' incorporates:
      //   Gain: '<S6>/w_n'
      //   Integrator: '<S6>/Integrator'

      ROS_Controller_B.rtb_R_b[i] = ROS_Controller_B.dv2[i] -
        ROS_Controller_X.Integrator_CSTATE_a[i];
    }

    // Gain: '<S6>/w_n'
    for (i = 0; i < 3; i++) {
      ROS_Controller_B.w_n[i] = 0.0;
      ROS_Controller_B.w_n[i] += ROS_Controller_P.wni[i] *
        ROS_Controller_B.rtb_R_b[0];
      ROS_Controller_B.w_n[i] += ROS_Controller_P.wni[i + 3] *
        ROS_Controller_B.rtb_R_b[1];
      ROS_Controller_B.w_n[i] += ROS_Controller_P.wni[i + 6] *
        ROS_Controller_B.rtb_R_b[2];
    }

    if (rtmIsMajorTimeStep(ROS_Controller_M)) {
      // MATLAB Function: '<S9>/PWM2Map180 ' incorporates:
      //   Constant: '<Root>/Pwm1'

      // MATLAB Function 'aout/PWM2Map180 ': '<S36>:1'
      // '<S36>:1:3'
      // '<S36>:1:4'
      // '<S36>:1:5'
      ROS_Controller_B.tmp = rt_roundd_snf((ROS_Controller_P.Pwm1_Value - 0.027)
        * 180.0 / 0.093);
      if (ROS_Controller_B.tmp < 65536.0) {
        if (ROS_Controller_B.tmp >= 0.0) {
          // BusAssignment: '<S9>/Bus Assignment1'
          rtb_BusAssignment1_e.Data = (uint16_T)ROS_Controller_B.tmp;
        } else {
          // BusAssignment: '<S9>/Bus Assignment1'
          rtb_BusAssignment1_e.Data = 0U;
        }
      } else {
        // BusAssignment: '<S9>/Bus Assignment1'
        rtb_BusAssignment1_e.Data = MAX_uint16_T;
      }

      // Outputs for Atomic SubSystem: '<S9>/Publish1'
      // MATLABSystem: '<S37>/SinkBlock'
      Pub_ROS_Controller_736.publish(&rtb_BusAssignment1_e);

      // End of Outputs for SubSystem: '<S9>/Publish1'

      // MATLAB Function: '<S9>/PWM2Map180 ' incorporates:
      //   Constant: '<Root>/PWm3'

      ROS_Controller_B.tmp = rt_roundd_snf((ROS_Controller_P.PWm3_Value - 0.027)
        * 180.0 / 0.093);
      if (ROS_Controller_B.tmp < 65536.0) {
        if (ROS_Controller_B.tmp >= 0.0) {
          // BusAssignment: '<S9>/Bus Assignment2'
          rtb_BusAssignment2_k.Data = (uint16_T)ROS_Controller_B.tmp;
        } else {
          // BusAssignment: '<S9>/Bus Assignment2'
          rtb_BusAssignment2_k.Data = 0U;
        }
      } else {
        // BusAssignment: '<S9>/Bus Assignment2'
        rtb_BusAssignment2_k.Data = MAX_uint16_T;
      }

      // Outputs for Atomic SubSystem: '<S9>/Publish2'
      // MATLABSystem: '<S38>/SinkBlock'
      Pub_ROS_Controller_737.publish(&rtb_BusAssignment2_k);

      // End of Outputs for SubSystem: '<S9>/Publish2'

      // MATLAB Function: '<S9>/PWM2Map180 ' incorporates:
      //   Constant: '<Root>/PWm4'

      ROS_Controller_B.tmp = rt_roundd_snf((ROS_Controller_P.PWm4_Value - 0.027)
        * 180.0 / 0.093);
      if (ROS_Controller_B.tmp < 65536.0) {
        if (ROS_Controller_B.tmp >= 0.0) {
          // BusAssignment: '<S9>/Bus Assignment3'
          rtb_BusAssignment3_k.Data = (uint16_T)ROS_Controller_B.tmp;
        } else {
          // BusAssignment: '<S9>/Bus Assignment3'
          rtb_BusAssignment3_k.Data = 0U;
        }
      } else {
        // BusAssignment: '<S9>/Bus Assignment3'
        rtb_BusAssignment3_k.Data = MAX_uint16_T;
      }

      // Outputs for Atomic SubSystem: '<S9>/Publish3'
      // MATLABSystem: '<S39>/SinkBlock'
      Pub_ROS_Controller_738.publish(&rtb_BusAssignment3_k);

      // End of Outputs for SubSystem: '<S9>/Publish3'
    }
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

  // Derivatives for Integrator: '<S16>/Integrator1'
  _rtXdot->Integrator1_CSTATE[0] = ROS_Controller_B.Product1[0];

  // Derivatives for Integrator: '<S16>/Integrator'
  _rtXdot->Integrator_CSTATE[0] = ROS_Controller_B.Sum1[0];

  // Derivatives for Integrator: '<S6>/Integrator2'
  _rtXdot->Integrator2_CSTATE[0] = ROS_Controller_B.Saturation4[0];

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

  // Derivatives for Integrator: '<S16>/Integrator2'
  _rtXdot->Integrator2_CSTATE_n[0] = ROS_Controller_B.Sum4[0];

  // Derivatives for Integrator: '<S6>/Integrator'
  _rtXdot->Integrator_CSTATE_a[0] = ROS_Controller_B.w_n[0];

  // Derivatives for Integrator: '<S6>/Integrator1'
  _rtXdot->Integrator1_CSTATE_i[0] = ROS_Controller_B.Sum3[0];

  // Derivatives for Integrator: '<S16>/Integrator1'
  _rtXdot->Integrator1_CSTATE[1] = ROS_Controller_B.Product1[1];

  // Derivatives for Integrator: '<S16>/Integrator'
  _rtXdot->Integrator_CSTATE[1] = ROS_Controller_B.Sum1[1];

  // Derivatives for Integrator: '<S6>/Integrator2'
  _rtXdot->Integrator2_CSTATE[1] = ROS_Controller_B.Saturation4[1];

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

  // Derivatives for Integrator: '<S16>/Integrator2'
  _rtXdot->Integrator2_CSTATE_n[1] = ROS_Controller_B.Sum4[1];

  // Derivatives for Integrator: '<S6>/Integrator'
  _rtXdot->Integrator_CSTATE_a[1] = ROS_Controller_B.w_n[1];

  // Derivatives for Integrator: '<S6>/Integrator1'
  _rtXdot->Integrator1_CSTATE_i[1] = ROS_Controller_B.Sum3[1];

  // Derivatives for Integrator: '<S16>/Integrator1'
  _rtXdot->Integrator1_CSTATE[2] = ROS_Controller_B.Product1[2];

  // Derivatives for Integrator: '<S16>/Integrator'
  _rtXdot->Integrator_CSTATE[2] = ROS_Controller_B.Sum1[2];

  // Derivatives for Integrator: '<S6>/Integrator2'
  _rtXdot->Integrator2_CSTATE[2] = ROS_Controller_B.Saturation4[2];

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

  // Derivatives for Integrator: '<S16>/Integrator2'
  _rtXdot->Integrator2_CSTATE_n[2] = ROS_Controller_B.Sum4[2];

  // Derivatives for Integrator: '<S6>/Integrator'
  _rtXdot->Integrator_CSTATE_a[2] = ROS_Controller_B.w_n[2];

  // Derivatives for Integrator: '<S6>/Integrator1'
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

    static const char_T tmp_0[12] = { '/', 'V', 'e', 's', 's', 'e', 'l', 'S',
      'p', 'e', 'e', 'd' };

    static const char_T tmp_1[8] = { '/', 'T', 'h', 'r', 'u', 's', 't', '3' };

    static const char_T tmp_2[8] = { '/', 'T', 'h', 'r', 'u', 's', 't', '2' };

    static const char_T tmp_3[8] = { '/', 'T', 'h', 'r', 'u', 's', 't', '1' };

    static const char_T tmp_4[13] = { '/', 'M', 'o', 't', 'o', 'r', '_', 'o',
      'n', '_', 'o', 'f', 'f' };

    char_T tmp_5[4];
    char_T tmp_6[4];
    char_T tmp_7[4];
    char_T tmp_8[8];
    char_T tmp_9[5];
    char_T tmp_a[13];
    char_T tmp_b[4];
    char_T tmp_c[9];
    int32_T i;

    // Start for Atomic SubSystem: '<S8>/Subscribe2'
    // Start for MATLABSystem: '<S33>/SourceBlock'
    ROS_Controller_DW.obj_pd.isInitialized = 0;
    ROS_Controller_DW.objisempty_h = true;
    ROS_Controller_DW.obj_pd.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      ROS_Controller_B.cv0[i] = tmp_4[i];
    }

    ROS_Controller_B.cv0[13] = '\x00';
    Sub_ROS_Controller_892.create_subscriber(ROS_Controller_B.cv0,
      ROS_Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S33>/SourceBlock'

    // Start for Enabled SubSystem: '<S33>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S34>/Out1'
    ROS_Controller_B.In1_h = ROS_Controller_P.Out1_Y0_p;

    // End of Start for SubSystem: '<S33>/Enabled Subsystem'
    // End of Start for SubSystem: '<S8>/Subscribe2'

    // Start for Atomic SubSystem: '<S8>/Publish1'
    // Start for MATLABSystem: '<S30>/SinkBlock'
    ROS_Controller_DW.obj_nl.isInitialized = 0;
    ROS_Controller_DW.objisempty_je = true;
    ROS_Controller_DW.obj_nl.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_c[i] = tmp_3[i];
    }

    tmp_c[8] = '\x00';
    Pub_ROS_Controller_701.create_publisher(tmp_c,
      ROS_Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S30>/SinkBlock'
    // End of Start for SubSystem: '<S8>/Publish1'

    // Start for Atomic SubSystem: '<S8>/Publish2'
    // Start for MATLABSystem: '<S31>/SinkBlock'
    ROS_Controller_DW.obj_n.isInitialized = 0;
    ROS_Controller_DW.objisempty_p = true;
    ROS_Controller_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_c[i] = tmp_2[i];
    }

    tmp_c[8] = '\x00';
    Pub_ROS_Controller_702.create_publisher(tmp_c,
      ROS_Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S31>/SinkBlock'
    // End of Start for SubSystem: '<S8>/Publish2'

    // Start for Atomic SubSystem: '<S8>/Publish3'
    // Start for MATLABSystem: '<S32>/SinkBlock'
    ROS_Controller_DW.obj_b.isInitialized = 0;
    ROS_Controller_DW.objisempty_j = true;
    ROS_Controller_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_c[i] = tmp_1[i];
    }

    tmp_c[8] = '\x00';
    Pub_ROS_Controller_703.create_publisher(tmp_c,
      ROS_Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S32>/SinkBlock'
    // End of Start for SubSystem: '<S8>/Publish3'

    // Start for Atomic SubSystem: '<S14>/Publish3'
    // Start for MATLABSystem: '<S18>/SinkBlock'
    ROS_Controller_DW.obj_m.isInitialized = 0;
    ROS_Controller_DW.objisempty_fo = true;
    ROS_Controller_DW.obj_m.isInitialized = 1;
    tmp_b[0] = '/';
    tmp_b[1] = 'n';
    tmp_b[2] = 'u';
    tmp_b[3] = '\x00';
    Pub_ROS_Controller_779.create_publisher(tmp_b,
      ROS_Controller_MessageQueueLen);

    // End of Start for SubSystem: '<S14>/Publish3'

    // Start for Atomic SubSystem: '<S3>/Publish1'
    // Start for MATLABSystem: '<S15>/SinkBlock'
    ROS_Controller_DW.obj_g.isInitialized = 0;
    ROS_Controller_DW.objisempty_d = true;
    ROS_Controller_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_a[i] = tmp_0[i];
    }

    tmp_a[12] = '\x00';
    Pub_ROS_Controller_888.create_publisher(tmp_a,
      ROS_Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S15>/SinkBlock'
    // End of Start for SubSystem: '<S3>/Publish1'

    // Start for Atomic SubSystem: '<S4>/Subscribe2'
    // Start for MATLABSystem: '<S23>/SourceBlock'
    ROS_Controller_DW.obj_o.isInitialized = 0;
    ROS_Controller_DW.objisempty_i = true;
    ROS_Controller_DW.obj_o.isInitialized = 1;
    tmp_9[0] = '/';
    tmp_9[1] = 'E';
    tmp_9[2] = 't';
    tmp_9[3] = 'a';
    tmp_9[4] = '\x00';
    Sub_ROS_Controller_659.create_subscriber(tmp_9,
      ROS_Controller_MessageQueueLen);

    // Start for Enabled SubSystem: '<S23>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S24>/Out1'
    ROS_Controller_B.In1_i = ROS_Controller_P.Out1_Y0;

    // End of Start for SubSystem: '<S23>/Enabled Subsystem'
    // End of Start for SubSystem: '<S4>/Subscribe2'

    // Start for Atomic SubSystem: '<S5>/Subscribe2'
    // Start for MATLABSystem: '<S25>/SourceBlock'
    ROS_Controller_DW.obj_k.isInitialized = 0;
    ROS_Controller_DW.objisempty_m = true;
    ROS_Controller_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      tmp_8[i] = tmp[i];
    }

    tmp_8[7] = '\x00';
    Sub_ROS_Controller_652.create_subscriber(tmp_8,
      ROS_Controller_MessageQueueLen);

    // End of Start for MATLABSystem: '<S25>/SourceBlock'

    // Start for Enabled SubSystem: '<S25>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S26>/Out1'
    ROS_Controller_B.In1 = ROS_Controller_P.Out1_Y0_d;

    // End of Start for SubSystem: '<S25>/Enabled Subsystem'
    // End of Start for SubSystem: '<S5>/Subscribe2'

    // Start for Atomic SubSystem: '<S9>/Publish1'
    // Start for MATLABSystem: '<S37>/SinkBlock'
    ROS_Controller_DW.obj_j.isInitialized = 0;
    ROS_Controller_DW.objisempty_f = true;
    ROS_Controller_DW.obj_j.isInitialized = 1;
    tmp_7[0] = '/';
    tmp_7[1] = 'a';
    tmp_7[2] = '1';
    tmp_7[3] = '\x00';
    Pub_ROS_Controller_736.create_publisher(tmp_7,
      ROS_Controller_MessageQueueLen);

    // End of Start for SubSystem: '<S9>/Publish1'

    // Start for Atomic SubSystem: '<S9>/Publish2'
    // Start for MATLABSystem: '<S38>/SinkBlock'
    ROS_Controller_DW.obj_p.isInitialized = 0;
    ROS_Controller_DW.objisempty_e = true;
    ROS_Controller_DW.obj_p.isInitialized = 1;
    tmp_6[0] = '/';
    tmp_6[1] = 'a';
    tmp_6[2] = '2';
    tmp_6[3] = '\x00';
    Pub_ROS_Controller_737.create_publisher(tmp_6,
      ROS_Controller_MessageQueueLen);

    // End of Start for SubSystem: '<S9>/Publish2'

    // Start for Atomic SubSystem: '<S9>/Publish3'
    // Start for MATLABSystem: '<S39>/SinkBlock'
    ROS_Controller_DW.obj.isInitialized = 0;
    ROS_Controller_DW.objisempty = true;
    ROS_Controller_DW.obj.isInitialized = 1;
    tmp_5[0] = '/';
    tmp_5[1] = 'a';
    tmp_5[2] = '3';
    tmp_5[3] = '\x00';
    Pub_ROS_Controller_738.create_publisher(tmp_5,
      ROS_Controller_MessageQueueLen);

    // End of Start for SubSystem: '<S9>/Publish3'

    // InitializeConditions for Derivative: '<S1>/Derivative'
    ROS_Controller_DW.TimeStampA = (rtInf);
    ROS_Controller_DW.TimeStampB = (rtInf);

    // InitializeConditions for Integrator: '<S16>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE[0] = ROS_Controller_P.Integrator1_IC;

    // InitializeConditions for Integrator: '<S16>/Integrator'
    ROS_Controller_X.Integrator_CSTATE[0] = ROS_Controller_P.InitialPos[0];

    // InitializeConditions for Integrator: '<S6>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE[0] = ROS_Controller_P.Integrator2_IC[0];

    // InitializeConditions for Integrator: '<S1>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_d[0] =
      ROS_Controller_P.Integrator1_IC_h[0];

    // InitializeConditions for Integrator: '<S16>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE_n[0] =
      ROS_Controller_P.Integrator2_IC_j[0];

    // InitializeConditions for Integrator: '<S6>/Integrator'
    ROS_Controller_X.Integrator_CSTATE_a[0] = ROS_Controller_P.Integrator_IC[0];

    // InitializeConditions for Integrator: '<S6>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_i[0] =
      ROS_Controller_P.Integrator1_IC_e[0];

    // InitializeConditions for Integrator: '<S16>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE[1] = ROS_Controller_P.Integrator1_IC;

    // InitializeConditions for Integrator: '<S16>/Integrator'
    ROS_Controller_X.Integrator_CSTATE[1] = ROS_Controller_P.InitialPos[1];

    // InitializeConditions for Integrator: '<S6>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE[1] = ROS_Controller_P.Integrator2_IC[1];

    // InitializeConditions for Integrator: '<S1>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_d[1] =
      ROS_Controller_P.Integrator1_IC_h[1];

    // InitializeConditions for Integrator: '<S16>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE_n[1] =
      ROS_Controller_P.Integrator2_IC_j[1];

    // InitializeConditions for Integrator: '<S6>/Integrator'
    ROS_Controller_X.Integrator_CSTATE_a[1] = ROS_Controller_P.Integrator_IC[1];

    // InitializeConditions for Integrator: '<S6>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_i[1] =
      ROS_Controller_P.Integrator1_IC_e[1];

    // InitializeConditions for Integrator: '<S16>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE[2] = ROS_Controller_P.Integrator1_IC;

    // InitializeConditions for Integrator: '<S16>/Integrator'
    ROS_Controller_X.Integrator_CSTATE[2] = ROS_Controller_P.InitialPos[2];

    // InitializeConditions for Integrator: '<S6>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE[2] = ROS_Controller_P.Integrator2_IC[2];

    // InitializeConditions for Integrator: '<S1>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_d[2] =
      ROS_Controller_P.Integrator1_IC_h[2];

    // InitializeConditions for Integrator: '<S16>/Integrator2'
    ROS_Controller_X.Integrator2_CSTATE_n[2] =
      ROS_Controller_P.Integrator2_IC_j[2];

    // InitializeConditions for Integrator: '<S6>/Integrator'
    ROS_Controller_X.Integrator_CSTATE_a[2] = ROS_Controller_P.Integrator_IC[2];

    // InitializeConditions for Integrator: '<S6>/Integrator1'
    ROS_Controller_X.Integrator1_CSTATE_i[2] =
      ROS_Controller_P.Integrator1_IC_e[2];
  }
}

// Model terminate function
void ROS_Controller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S8>/Subscribe2'
  // Start for MATLABSystem: '<S33>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S33>/SourceBlock'

  if (ROS_Controller_DW.obj_pd.isInitialized == 1) {
    ROS_Controller_DW.obj_pd.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S33>/SourceBlock'
  // End of Terminate for SubSystem: '<S8>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S8>/Publish1'
  // Start for MATLABSystem: '<S30>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S30>/SinkBlock'

  if (ROS_Controller_DW.obj_nl.isInitialized == 1) {
    ROS_Controller_DW.obj_nl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S30>/SinkBlock'
  // End of Terminate for SubSystem: '<S8>/Publish1'

  // Terminate for Atomic SubSystem: '<S8>/Publish2'
  // Start for MATLABSystem: '<S31>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S31>/SinkBlock'

  if (ROS_Controller_DW.obj_n.isInitialized == 1) {
    ROS_Controller_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S31>/SinkBlock'
  // End of Terminate for SubSystem: '<S8>/Publish2'

  // Terminate for Atomic SubSystem: '<S8>/Publish3'
  // Start for MATLABSystem: '<S32>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S32>/SinkBlock'

  if (ROS_Controller_DW.obj_b.isInitialized == 1) {
    ROS_Controller_DW.obj_b.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S32>/SinkBlock'
  // End of Terminate for SubSystem: '<S8>/Publish3'

  // Terminate for Atomic SubSystem: '<S14>/Publish3'
  // Start for MATLABSystem: '<S18>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S18>/SinkBlock'

  if (ROS_Controller_DW.obj_m.isInitialized == 1) {
    ROS_Controller_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S18>/SinkBlock'
  // End of Terminate for SubSystem: '<S14>/Publish3'

  // Terminate for Atomic SubSystem: '<S3>/Publish1'
  // Start for MATLABSystem: '<S15>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S15>/SinkBlock'

  if (ROS_Controller_DW.obj_g.isInitialized == 1) {
    ROS_Controller_DW.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S15>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish1'

  // Terminate for Atomic SubSystem: '<S4>/Subscribe2'
  // Start for MATLABSystem: '<S23>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S23>/SourceBlock'

  if (ROS_Controller_DW.obj_o.isInitialized == 1) {
    ROS_Controller_DW.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S23>/SourceBlock'
  // End of Terminate for SubSystem: '<S4>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S5>/Subscribe2'
  // Start for MATLABSystem: '<S25>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S25>/SourceBlock'

  if (ROS_Controller_DW.obj_k.isInitialized == 1) {
    ROS_Controller_DW.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/SourceBlock'
  // End of Terminate for SubSystem: '<S5>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S9>/Publish1'
  // Start for MATLABSystem: '<S37>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S37>/SinkBlock'

  if (ROS_Controller_DW.obj_j.isInitialized == 1) {
    ROS_Controller_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S37>/SinkBlock'
  // End of Terminate for SubSystem: '<S9>/Publish1'

  // Terminate for Atomic SubSystem: '<S9>/Publish2'
  // Start for MATLABSystem: '<S38>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S38>/SinkBlock'

  if (ROS_Controller_DW.obj_p.isInitialized == 1) {
    ROS_Controller_DW.obj_p.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S38>/SinkBlock'
  // End of Terminate for SubSystem: '<S9>/Publish2'

  // Terminate for Atomic SubSystem: '<S9>/Publish3'
  // Start for MATLABSystem: '<S39>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S39>/SinkBlock'

  if (ROS_Controller_DW.obj.isInitialized == 1) {
    ROS_Controller_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S39>/SinkBlock'
  // End of Terminate for SubSystem: '<S9>/Publish3'
}

//
// File trailer for generated code.
//
// [EOF]
//
