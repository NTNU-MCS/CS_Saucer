//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: VesselSimulator.cpp
//
// Code generated for Simulink model 'VesselSimulator'.
//
// Model version                  : 1.27
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Jun 22 13:00:06 2016
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

// Forward declaration for local functions
static real_T VesselSimulator_interp1(const real_T varargin_1[62], const real_T
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

// Function for MATLAB Function: '<S1>/PWM-Mapping'
static real_T VesselSimulator_interp1(const real_T varargin_1[62], const real_T
  varargin_2[62], real_T varargin_3)
{
  real_T Vq;
  int32_T k;
  real_T r;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  memcpy(&VesselSimulator_B.y[0], &varargin_2[0], 62U * sizeof(real_T));
  memcpy(&VesselSimulator_B.x[0], &varargin_1[0], 62U * sizeof(real_T));
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
          r = VesselSimulator_B.x[low_i];
          VesselSimulator_B.x[low_i] = VesselSimulator_B.x[61 - low_i];
          VesselSimulator_B.x[61 - low_i] = r;
        }

        for (low_i = 0; low_i < 31; low_i++) {
          r = VesselSimulator_B.y[low_i];
          VesselSimulator_B.y[low_i] = VesselSimulator_B.y[61 - low_i];
          VesselSimulator_B.y[61 - low_i] = r;
        }
      }

      if (!(rtIsNaN(varargin_3) || (varargin_3 > VesselSimulator_B.x[61]) ||
            (varargin_3 < VesselSimulator_B.x[0]))) {
        low_i = 1;
        low_ip1 = 2;
        high_i = 62;
        while (high_i > low_ip1) {
          mid_i = (low_i + high_i) >> 1;
          if (varargin_3 >= VesselSimulator_B.x[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }

        r = (varargin_3 - VesselSimulator_B.x[low_i - 1]) /
          (VesselSimulator_B.x[low_i] - VesselSimulator_B.x[low_i - 1]);
        if (r == 0.0) {
          Vq = VesselSimulator_B.y[low_i - 1];
        } else if (r == 1.0) {
          Vq = VesselSimulator_B.y[low_i];
        } else if (VesselSimulator_B.y[low_i - 1] == VesselSimulator_B.y[low_i])
        {
          Vq = VesselSimulator_B.y[low_i - 1];
        } else {
          Vq = (1.0 - r) * VesselSimulator_B.y[low_i - 1] + r *
            VesselSimulator_B.y[low_i];
        }
      }

      low_i = 1;
    }
  } while (low_i == 0);

  return Vq;
}

// Model step function
void VesselSimulator_step(void)
{
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  static const int8_T b[3] = { 0, 0, 1 };

  SL_Bus_VesselSimulator_std_msgs_UInt16 varargout_2;
  boolean_T varargout_1;
  int32_T i;
  real_T rtb_y_c_idx_0;
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

  // BusAssignment: '<S3>/Bus Assignment1' incorporates:
  //   Integrator: '<S4>/Integrator1'

  VesselSimulator_B.BusAssignment1.X = VesselSimulator_X.Integrator1_CSTATE[0];
  VesselSimulator_B.BusAssignment1.Y = VesselSimulator_X.Integrator1_CSTATE[1];
  VesselSimulator_B.BusAssignment1.Z = VesselSimulator_X.Integrator1_CSTATE[2];

  // Outputs for Atomic SubSystem: '<S3>/Publish1'
  // MATLABSystem: '<S13>/SinkBlock'
  Pub_VesselSimulator_269.publish(&VesselSimulator_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S3>/Publish1'
  if (rtmIsMajorTimeStep(VesselSimulator_M)) {
    // Outputs for Atomic SubSystem: '<S2>/Subscribe1'
    // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
    //   MATLABSystem: '<S6>/SourceBlock'

    varargout_1 = Sub_VesselSimulator_22.get_latest_msg(&varargout_2);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S9>/Enable'

    // MATLABSystem: '<S6>/SourceBlock' incorporates:
    //   Inport: '<S9>/In1'

    if (varargout_1) {
      VesselSimulator_B.In1_p = varargout_2;
    }

    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S2>/Subscribe1'

    // Outputs for Atomic SubSystem: '<S2>/Subscribe2'
    // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
    //   MATLABSystem: '<S7>/SourceBlock'

    varargout_1 = Sub_VesselSimulator_306.get_latest_msg(&varargout_2);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    // MATLABSystem: '<S7>/SourceBlock' incorporates:
    //   Inport: '<S10>/In1'

    if (varargout_1) {
      VesselSimulator_B.In1_i = varargout_2;
    }

    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S2>/Subscribe2'

    // Outputs for Atomic SubSystem: '<S2>/Subscribe3'
    // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
    //   MATLABSystem: '<S8>/SourceBlock'

    varargout_1 = Sub_VesselSimulator_307.get_latest_msg(&varargout_2);

    // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S11>/Enable'

    // MATLABSystem: '<S8>/SourceBlock' incorporates:
    //   Inport: '<S11>/In1'

    if (varargout_1) {
      VesselSimulator_B.In1 = varargout_2;
    }

    // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S2>/Subscribe3'

    // ManualSwitch: '<S1>/Manual Switch1' incorporates:
    //   Constant: '<S1>/Constant7'
    //   Constant: '<S1>/Constant8'
    //   Constant: '<S1>/Constant9'
    //   SignalConversion: '<S2>/SigConversion_InsertedFor_Bus Selector1_at_outport_0'
    //   SignalConversion: '<S2>/SigConversion_InsertedFor_Bus Selector2_at_outport_0'
    //   SignalConversion: '<S2>/SigConversion_InsertedFor_Bus Selector3_at_outport_0'

    if (VesselSimulator_P.ManualSwitch1_CurrentSetting == 1) {
      VesselSimulator_B.rtb_ManualSwitch1_idx_0 = VesselSimulator_B.In1_p.Data;
      VesselSimulator_B.rtb_ManualSwitch1_idx_1 = VesselSimulator_B.In1_i.Data;
      VesselSimulator_B.rtb_ManualSwitch1_idx_2 = VesselSimulator_B.In1.Data;
    } else {
      VesselSimulator_B.rtb_ManualSwitch1_idx_0 =
        VesselSimulator_P.Constant7_Value;
      VesselSimulator_B.rtb_ManualSwitch1_idx_1 =
        VesselSimulator_P.Constant8_Value;
      VesselSimulator_B.rtb_ManualSwitch1_idx_2 =
        VesselSimulator_P.Constant9_Value;
    }

    // End of ManualSwitch: '<S1>/Manual Switch1'

    // MATLAB Function: '<S1>/PWM-Mapping' incorporates:
    //   Constant: '<S1>/Constant1'
    //   Constant: '<S1>/Constant3'
    //   Constant: '<S1>/Constant4'
    //   Constant: '<S1>/Constant5'

    // MATLAB Function 'InverseMap180toU/PWM-Mapping': '<S5>:1'
    // load matrix mapperMat prior to running this node
    // '<S5>:1:3'
    // '<S5>:1:4'
    rtb_y_c_idx_0 = VesselSimulator_B.rtb_ManualSwitch1_idx_0;

    // '<S5>:1:4'
    if (VesselSimulator_B.rtb_ManualSwitch1_idx_0 == 0.0) {
      // '<S5>:1:5'
      // '<S5>:1:6'
      rtb_y_c_idx_0 = 80.0;
    }

    // '<S5>:1:4'
    VesselSimulator_B.rtb_ManualSwitch1_idx_0 = rtb_y_c_idx_0;
    rtb_y_c_idx_0 = VesselSimulator_B.rtb_ManualSwitch1_idx_1;

    // '<S5>:1:4'
    if (VesselSimulator_B.rtb_ManualSwitch1_idx_1 == 0.0) {
      // '<S5>:1:5'
      // '<S5>:1:6'
      rtb_y_c_idx_0 = 80.0;
    }

    // '<S5>:1:4'
    VesselSimulator_B.rtb_ManualSwitch1_idx_1 = rtb_y_c_idx_0;
    rtb_y_c_idx_0 = VesselSimulator_B.rtb_ManualSwitch1_idx_2;

    // '<S5>:1:4'
    if (VesselSimulator_B.rtb_ManualSwitch1_idx_2 == 0.0) {
      // '<S5>:1:5'
      // '<S5>:1:6'
      rtb_y_c_idx_0 = 80.0;
    }

    // '<S5>:1:4'
    // '<S5>:1:9'
    VesselSimulator_B.rtb_ManualSwitch1_idx_2 = -rtb_y_c_idx_0;

    // '<S5>:1:10'
    for (i = 0; i < 62; i++) {
      VesselSimulator_B.TH3[i] = -VesselSimulator_P.Th1[i];
    }

    i = 1;
    VesselSimulator_B.r = VesselSimulator_P.Th1[0];
    if (rtIsNaN(VesselSimulator_P.Th1[0])) {
      low_i = 2;
      varargout_1 = false;
      while ((!varargout_1) && (low_i < 63)) {
        i = low_i;
        if (!rtIsNaN(VesselSimulator_P.Th1[low_i - 1])) {
          VesselSimulator_B.r = VesselSimulator_P.Th1[low_i - 1];
          varargout_1 = true;
        } else {
          low_i++;
        }
      }
    }

    if (i < 62) {
      while (i + 1 < 63) {
        if (VesselSimulator_P.Th1[i] > VesselSimulator_B.r) {
          VesselSimulator_B.r = VesselSimulator_P.Th1[i];
        }

        i++;
      }
    }

    if (VesselSimulator_B.rtb_ManualSwitch1_idx_0 > VesselSimulator_B.r) {
      // '<S5>:1:13'
      // '<S5>:1:14'
      i = 1;
      VesselSimulator_B.r = VesselSimulator_P.Th1[0];
      if (rtIsNaN(VesselSimulator_P.Th1[0])) {
        low_i = 2;
        varargout_1 = false;
        while ((!varargout_1) && (low_i < 63)) {
          i = low_i;
          if (!rtIsNaN(VesselSimulator_P.Th1[low_i - 1])) {
            VesselSimulator_B.r = VesselSimulator_P.Th1[low_i - 1];
            varargout_1 = true;
          } else {
            low_i++;
          }
        }
      }

      if (i < 62) {
        while (i + 1 < 63) {
          if (VesselSimulator_P.Th1[i] > VesselSimulator_B.r) {
            VesselSimulator_B.r = VesselSimulator_P.Th1[i];
          }

          i++;
        }
      }

      VesselSimulator_B.rtb_ManualSwitch1_idx_0 = VesselSimulator_B.r;
    } else {
      i = 1;
      VesselSimulator_B.r = VesselSimulator_P.Th1[0];
      if (rtIsNaN(VesselSimulator_P.Th1[0])) {
        low_i = 2;
        varargout_1 = false;
        while ((!varargout_1) && (low_i < 63)) {
          i = low_i;
          if (!rtIsNaN(VesselSimulator_P.Th1[low_i - 1])) {
            VesselSimulator_B.r = VesselSimulator_P.Th1[low_i - 1];
            varargout_1 = true;
          } else {
            low_i++;
          }
        }
      }

      if (i < 62) {
        while (i + 1 < 63) {
          if (VesselSimulator_P.Th1[i] < VesselSimulator_B.r) {
            VesselSimulator_B.r = VesselSimulator_P.Th1[i];
          }

          i++;
        }
      }

      if (VesselSimulator_B.rtb_ManualSwitch1_idx_0 < VesselSimulator_B.r) {
        // '<S5>:1:15'
        // '<S5>:1:16'
        i = 1;
        VesselSimulator_B.r = VesselSimulator_P.Th1[0];
        if (rtIsNaN(VesselSimulator_P.Th1[0])) {
          low_i = 2;
          varargout_1 = false;
          while ((!varargout_1) && (low_i < 63)) {
            i = low_i;
            if (!rtIsNaN(VesselSimulator_P.Th1[low_i - 1])) {
              VesselSimulator_B.r = VesselSimulator_P.Th1[low_i - 1];
              varargout_1 = true;
            } else {
              low_i++;
            }
          }
        }

        if (i < 62) {
          while (i + 1 < 63) {
            if (VesselSimulator_P.Th1[i] < VesselSimulator_B.r) {
              VesselSimulator_B.r = VesselSimulator_P.Th1[i];
            }

            i++;
          }
        }

        VesselSimulator_B.rtb_ManualSwitch1_idx_0 = VesselSimulator_B.r;
      }
    }

    i = 1;
    VesselSimulator_B.r = VesselSimulator_P.Th2[0];
    if (rtIsNaN(VesselSimulator_P.Th2[0])) {
      low_i = 2;
      varargout_1 = false;
      while ((!varargout_1) && (low_i < 53)) {
        i = low_i;
        if (!rtIsNaN(VesselSimulator_P.Th2[low_i - 1])) {
          VesselSimulator_B.r = VesselSimulator_P.Th2[low_i - 1];
          varargout_1 = true;
        } else {
          low_i++;
        }
      }
    }

    if (i < 52) {
      while (i + 1 < 53) {
        if (VesselSimulator_P.Th2[i] > VesselSimulator_B.r) {
          VesselSimulator_B.r = VesselSimulator_P.Th2[i];
        }

        i++;
      }
    }

    if (VesselSimulator_B.rtb_ManualSwitch1_idx_1 > VesselSimulator_B.r) {
      // '<S5>:1:19'
      // '<S5>:1:20'
      i = 1;
      VesselSimulator_B.r = VesselSimulator_P.Th2[0];
      if (rtIsNaN(VesselSimulator_P.Th2[0])) {
        low_i = 2;
        varargout_1 = false;
        while ((!varargout_1) && (low_i < 53)) {
          i = low_i;
          if (!rtIsNaN(VesselSimulator_P.Th2[low_i - 1])) {
            VesselSimulator_B.r = VesselSimulator_P.Th2[low_i - 1];
            varargout_1 = true;
          } else {
            low_i++;
          }
        }
      }

      if (i < 52) {
        while (i + 1 < 53) {
          if (VesselSimulator_P.Th2[i] > VesselSimulator_B.r) {
            VesselSimulator_B.r = VesselSimulator_P.Th2[i];
          }

          i++;
        }
      }

      VesselSimulator_B.rtb_ManualSwitch1_idx_1 = VesselSimulator_B.r;
    } else {
      i = 1;
      VesselSimulator_B.r = VesselSimulator_P.Th2[0];
      if (rtIsNaN(VesselSimulator_P.Th2[0])) {
        low_i = 2;
        varargout_1 = false;
        while ((!varargout_1) && (low_i < 53)) {
          i = low_i;
          if (!rtIsNaN(VesselSimulator_P.Th2[low_i - 1])) {
            VesselSimulator_B.r = VesselSimulator_P.Th2[low_i - 1];
            varargout_1 = true;
          } else {
            low_i++;
          }
        }
      }

      if (i < 52) {
        while (i + 1 < 53) {
          if (VesselSimulator_P.Th2[i] < VesselSimulator_B.r) {
            VesselSimulator_B.r = VesselSimulator_P.Th2[i];
          }

          i++;
        }
      }

      if (VesselSimulator_B.rtb_ManualSwitch1_idx_1 < VesselSimulator_B.r) {
        // '<S5>:1:21'
        // '<S5>:1:22'
        i = 1;
        VesselSimulator_B.r = VesselSimulator_P.Th2[0];
        if (rtIsNaN(VesselSimulator_P.Th2[0])) {
          low_i = 2;
          varargout_1 = false;
          while ((!varargout_1) && (low_i < 53)) {
            i = low_i;
            if (!rtIsNaN(VesselSimulator_P.Th2[low_i - 1])) {
              VesselSimulator_B.r = VesselSimulator_P.Th2[low_i - 1];
              varargout_1 = true;
            } else {
              low_i++;
            }
          }
        }

        if (i < 52) {
          while (i + 1 < 53) {
            if (VesselSimulator_P.Th2[i] < VesselSimulator_B.r) {
              VesselSimulator_B.r = VesselSimulator_P.Th2[i];
            }

            i++;
          }
        }

        VesselSimulator_B.rtb_ManualSwitch1_idx_1 = VesselSimulator_B.r;
      }
    }

    i = 1;
    VesselSimulator_B.r = VesselSimulator_B.TH3[0];
    if (rtIsNaN(VesselSimulator_B.TH3[0])) {
      low_i = 2;
      varargout_1 = false;
      while ((!varargout_1) && (low_i < 63)) {
        i = low_i;
        if (!rtIsNaN(VesselSimulator_B.TH3[low_i - 1])) {
          VesselSimulator_B.r = VesselSimulator_B.TH3[low_i - 1];
          varargout_1 = true;
        } else {
          low_i++;
        }
      }
    }

    if (i < 62) {
      while (i + 1 < 63) {
        if (VesselSimulator_B.TH3[i] > VesselSimulator_B.r) {
          VesselSimulator_B.r = VesselSimulator_B.TH3[i];
        }

        i++;
      }
    }

    if (-rtb_y_c_idx_0 > VesselSimulator_B.r) {
      // '<S5>:1:25'
      // '<S5>:1:26'
      i = 1;
      VesselSimulator_B.r = VesselSimulator_B.TH3[0];
      if (rtIsNaN(VesselSimulator_B.TH3[0])) {
        low_i = 2;
        varargout_1 = false;
        while ((!varargout_1) && (low_i < 63)) {
          i = low_i;
          if (!rtIsNaN(VesselSimulator_B.TH3[low_i - 1])) {
            VesselSimulator_B.r = VesselSimulator_B.TH3[low_i - 1];
            varargout_1 = true;
          } else {
            low_i++;
          }
        }
      }

      if (i < 62) {
        while (i + 1 < 63) {
          if (VesselSimulator_B.TH3[i] > VesselSimulator_B.r) {
            VesselSimulator_B.r = VesselSimulator_B.TH3[i];
          }

          i++;
        }
      }

      VesselSimulator_B.rtb_ManualSwitch1_idx_2 = VesselSimulator_B.r;
    } else {
      i = 1;
      VesselSimulator_B.r = VesselSimulator_B.TH3[0];
      if (rtIsNaN(VesselSimulator_B.TH3[0])) {
        low_i = 2;
        varargout_1 = false;
        while ((!varargout_1) && (low_i < 63)) {
          i = low_i;
          if (!rtIsNaN(VesselSimulator_B.TH3[low_i - 1])) {
            VesselSimulator_B.r = VesselSimulator_B.TH3[low_i - 1];
            varargout_1 = true;
          } else {
            low_i++;
          }
        }
      }

      if (i < 62) {
        while (i + 1 < 63) {
          if (VesselSimulator_B.TH3[i] < VesselSimulator_B.r) {
            VesselSimulator_B.r = VesselSimulator_B.TH3[i];
          }

          i++;
        }
      }

      if (-rtb_y_c_idx_0 < VesselSimulator_B.r) {
        // '<S5>:1:27'
        // '<S5>:1:28'
        i = 1;
        VesselSimulator_B.r = VesselSimulator_B.TH3[0];
        if (rtIsNaN(VesselSimulator_B.TH3[0])) {
          low_i = 2;
          varargout_1 = false;
          while ((!varargout_1) && (low_i < 63)) {
            i = low_i;
            if (!rtIsNaN(VesselSimulator_B.TH3[low_i - 1])) {
              VesselSimulator_B.r = VesselSimulator_B.TH3[low_i - 1];
              varargout_1 = true;
            } else {
              low_i++;
            }
          }
        }

        if (i < 62) {
          while (i + 1 < 63) {
            if (VesselSimulator_B.TH3[i] < VesselSimulator_B.r) {
              VesselSimulator_B.r = VesselSimulator_B.TH3[i];
            }

            i++;
          }
        }

        VesselSimulator_B.rtb_ManualSwitch1_idx_2 = VesselSimulator_B.r;
      }
    }

    // '<S5>:1:31'
    rtb_y_c_idx_0 = VesselSimulator_interp1(VesselSimulator_P.Th1,
      VesselSimulator_P.MAPP1, VesselSimulator_B.rtb_ManualSwitch1_idx_0);

    // '<S5>:1:32'
    memcpy(&VesselSimulator_B.y_m[0], &VesselSimulator_P.MAPP2[0], 52U * sizeof
           (real_T));
    memcpy(&VesselSimulator_B.x_c[0], &VesselSimulator_P.Th2[0], 52U * sizeof
           (real_T));
    VesselSimulator_B.r = (rtNaN);
    i = 1;
    do {
      low_i = 0;
      if (i < 53) {
        if (rtIsNaN(VesselSimulator_P.Th2[i - 1])) {
          low_i = 1;
        } else {
          i++;
        }
      } else {
        if (VesselSimulator_P.Th2[1] < VesselSimulator_P.Th2[0]) {
          for (low_i = 0; low_i < 26; low_i++) {
            VesselSimulator_B.tmp = VesselSimulator_B.x_c[low_i];
            VesselSimulator_B.x_c[low_i] = VesselSimulator_B.x_c[51 - low_i];
            VesselSimulator_B.x_c[51 - low_i] = VesselSimulator_B.tmp;
          }

          for (low_i = 0; low_i < 26; low_i++) {
            VesselSimulator_B.tmp = VesselSimulator_B.y_m[low_i];
            VesselSimulator_B.y_m[low_i] = VesselSimulator_B.y_m[51 - low_i];
            VesselSimulator_B.y_m[51 - low_i] = VesselSimulator_B.tmp;
          }
        }

        if (!(rtIsNaN(VesselSimulator_B.rtb_ManualSwitch1_idx_1) ||
              (VesselSimulator_B.rtb_ManualSwitch1_idx_1 >
               VesselSimulator_B.x_c[51]) ||
              (VesselSimulator_B.rtb_ManualSwitch1_idx_1 <
               VesselSimulator_B.x_c[0]))) {
          low_i = 1;
          low_ip1 = 2;
          high_i = 52;
          while (high_i > low_ip1) {
            mid_i = (low_i + high_i) >> 1;
            if (VesselSimulator_B.rtb_ManualSwitch1_idx_1 >=
                VesselSimulator_B.x_c[mid_i - 1]) {
              low_i = mid_i;
              low_ip1 = mid_i + 1;
            } else {
              high_i = mid_i;
            }
          }

          VesselSimulator_B.r = (VesselSimulator_B.rtb_ManualSwitch1_idx_1 -
            VesselSimulator_B.x_c[low_i - 1]) / (VesselSimulator_B.x_c[low_i] -
            VesselSimulator_B.x_c[low_i - 1]);
          if (VesselSimulator_B.r == 0.0) {
            VesselSimulator_B.r = VesselSimulator_B.y_m[low_i - 1];
          } else if (VesselSimulator_B.r == 1.0) {
            VesselSimulator_B.r = VesselSimulator_B.y_m[low_i];
          } else if (VesselSimulator_B.y_m[low_i - 1] ==
                     VesselSimulator_B.y_m[low_i]) {
            VesselSimulator_B.r = VesselSimulator_B.y_m[low_i - 1];
          } else {
            VesselSimulator_B.r = (1.0 - VesselSimulator_B.r) *
              VesselSimulator_B.y_m[low_i - 1] + VesselSimulator_B.r *
              VesselSimulator_B.y_m[low_i];
          }
        }

        low_i = 1;
      }
    } while (low_i == 0);

    // '<S5>:1:33'
    VesselSimulator_B.tmp = VesselSimulator_interp1(VesselSimulator_B.TH3,
      VesselSimulator_P.MAPP1, VesselSimulator_B.rtb_ManualSwitch1_idx_2);
    if (fabs(VesselSimulator_B.rtb_ManualSwitch1_idx_0) < 0.01) {
      // '<S5>:1:35'
      // '<S5>:1:36'
      rtb_y_c_idx_0 = 80.0;
    }

    if (fabs(VesselSimulator_B.rtb_ManualSwitch1_idx_1) < 0.01) {
      // '<S5>:1:38'
      // '<S5>:1:39'
      VesselSimulator_B.r = 80.0;
    }

    if (fabs(VesselSimulator_B.rtb_ManualSwitch1_idx_2) < 0.01) {
      // '<S5>:1:41'
      // '<S5>:1:42'
      VesselSimulator_B.tmp = 80.0;
    }

    // '<S5>:1:44'
    VesselSimulator_B.rtb_ManualSwitch1_idx_0 = rtb_y_c_idx_0;

    // '<S5>:1:44'
    if (fabs(rtb_y_c_idx_0) < 0.01) {
      // '<S5>:1:45'
      // '<S5>:1:46'
      VesselSimulator_B.rtb_ManualSwitch1_idx_0 = 0.0;
    }

    // '<S5>:1:44'
    rtb_y_c_idx_0 = VesselSimulator_B.rtb_ManualSwitch1_idx_0;
    VesselSimulator_B.rtb_ManualSwitch1_idx_0 = VesselSimulator_B.r;

    // '<S5>:1:44'
    if (fabs(VesselSimulator_B.r) < 0.01) {
      // '<S5>:1:45'
      // '<S5>:1:46'
      VesselSimulator_B.rtb_ManualSwitch1_idx_0 = 0.0;
    }

    // '<S5>:1:44'
    VesselSimulator_B.r = VesselSimulator_B.rtb_ManualSwitch1_idx_0;
    VesselSimulator_B.rtb_ManualSwitch1_idx_0 = VesselSimulator_B.tmp;

    // '<S5>:1:44'
    if (fabs(VesselSimulator_B.tmp) < 0.01) {
      // '<S5>:1:45'
      // '<S5>:1:46'
      VesselSimulator_B.rtb_ManualSwitch1_idx_0 = 0.0;
    }

    // End of MATLAB Function: '<S1>/PWM-Mapping'

    // Product: '<Root>/Product' incorporates:
    //   Constant: '<Root>/Thrust allocation Matrix'

    // '<S5>:1:44'
    for (i = 0; i < 3; i++) {
      VesselSimulator_B.Product[i] = 0.0;
      VesselSimulator_B.Product[i] += VesselSimulator_P.Tr[i] * rtb_y_c_idx_0;
      VesselSimulator_B.Product[i] += VesselSimulator_P.Tr[i + 3] *
        VesselSimulator_B.r;
      VesselSimulator_B.Product[i] += VesselSimulator_P.Tr[i + 6] *
        VesselSimulator_B.rtb_ManualSwitch1_idx_0;
    }

    // End of Product: '<Root>/Product'
  }

  // MATLAB Function: '<S4>/D_nu' incorporates:
  //   Constant: '<S4>/Constant'
  //   Integrator: '<S4>/Integrator2'

  // MATLAB Function 'Vessel Dynamics/D_nu': '<S15>:1'
  // '<S15>:1:3'
  // '<S15>:1:4'
  // MATLAB Function 'Vessel Dynamics/C_nu1': '<S14>:1'
  // '<S14>:1:3'
  // '<S14>:1:4'
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

    // Sum: '<S4>/Add' incorporates:
    //   Gain: '<S4>/Gain1'

    VesselSimulator_B.dv2[i] = 0.0 - ((VesselSimulator_P.D[i + 3] *
      VesselSimulator_X.Integrator2_CSTATE[1] + VesselSimulator_P.D[i] *
      VesselSimulator_X.Integrator2_CSTATE[0]) + VesselSimulator_P.D[i + 6] *
      VesselSimulator_X.Integrator2_CSTATE[2]);
  }

  // MATLAB Function: '<S4>/C_nu1' incorporates:
  //   Constant: '<S4>/Constant1'
  //   Integrator: '<S4>/Integrator2'

  VesselSimulator_B.dv1[0] = 0.0;
  VesselSimulator_B.dv1[3] = VesselSimulator_P.C_nuParams[3] *
    VesselSimulator_X.Integrator2_CSTATE[2];
  VesselSimulator_B.dv1[6] = 0.0;
  VesselSimulator_B.dv1[1] = VesselSimulator_P.C_nuParams[1] *
    VesselSimulator_X.Integrator2_CSTATE[2];
  VesselSimulator_B.dv1[4] = 0.0;
  VesselSimulator_B.dv1[7] = 0.0;
  for (i = 0; i < 3; i++) {
    // MATLAB Function: '<S4>/C_nu1'
    VesselSimulator_B.dv1[2 + 3 * i] = 0.0;

    // MATLAB Function: '<S4>/D_nu' incorporates:
    //   Integrator: '<S4>/Integrator2'
    //   Sum: '<S4>/Add'

    VesselSimulator_B.dv3[i] = 0.0 * VesselSimulator_X.Integrator2_CSTATE[2] +
      (VesselSimulator_B.dv0[i + 3] * VesselSimulator_X.Integrator2_CSTATE[1] +
       VesselSimulator_B.dv0[i] * VesselSimulator_X.Integrator2_CSTATE[0]);
  }

  // Sum: '<S4>/Sum' incorporates:
  //   Gain: '<S4>/Gain'
  //   Integrator: '<S4>/Integrator2'
  //   MATLAB Function: '<S4>/C_nu1'
  //   Sum: '<S4>/Add'
  //   Sum: '<S4>/Add1'

  for (i = 0; i < 3; i++) {
    VesselSimulator_B.dv4[i] = ((VesselSimulator_B.dv2[i] -
      VesselSimulator_B.dv3[i]) - ((VesselSimulator_B.dv1[i + 3] *
      VesselSimulator_X.Integrator2_CSTATE[1] + VesselSimulator_B.dv1[i] *
      VesselSimulator_X.Integrator2_CSTATE[0]) + 0.0 *
      VesselSimulator_X.Integrator2_CSTATE[2])) + VesselSimulator_B.Product[i];
  }

  // End of Sum: '<S4>/Sum'

  // MATLAB Function: '<S4>/MATLAB Function' incorporates:
  //   Integrator: '<S4>/Integrator1'

  // MATLAB Function 'Vessel Dynamics/MATLAB Function': '<S16>:1'
  // '<S16>:1:2'
  // R=[RotPhi(1:2,:);[0 0 0;0 0 0;0 0 0];RotPhi(3,:)]
  VesselSimulator_B.dv0[0] = cos(VesselSimulator_X.Integrator1_CSTATE[2]);
  VesselSimulator_B.dv0[3] = -sin(VesselSimulator_X.Integrator1_CSTATE[2]);
  VesselSimulator_B.dv0[6] = 0.0;
  VesselSimulator_B.dv0[1] = sin(VesselSimulator_X.Integrator1_CSTATE[2]);
  VesselSimulator_B.dv0[4] = cos(VesselSimulator_X.Integrator1_CSTATE[2]);
  VesselSimulator_B.dv0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    // Gain: '<S4>/Gain'
    VesselSimulator_B.Gain[i] = 0.0;
    VesselSimulator_B.Gain[i] += VesselSimulator_P.invM[i] *
      VesselSimulator_B.dv4[0];
    VesselSimulator_B.Gain[i] += VesselSimulator_P.invM[i + 3] *
      VesselSimulator_B.dv4[1];
    VesselSimulator_B.Gain[i] += VesselSimulator_P.invM[i + 6] *
      VesselSimulator_B.dv4[2];

    // MATLAB Function: '<S4>/MATLAB Function' incorporates:
    //   Product: '<S4>/Product2'

    VesselSimulator_B.dv0[2 + 3 * i] = b[i];
  }

  // Product: '<S4>/Product2' incorporates:
  //   Integrator: '<S4>/Integrator2'

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

  // Derivatives for Integrator: '<S4>/Integrator1'
  _rtXdot->Integrator1_CSTATE[0] = VesselSimulator_B.Product2[0];

  // Derivatives for Integrator: '<S4>/Integrator2'
  _rtXdot->Integrator2_CSTATE[0] = VesselSimulator_B.Gain[0];

  // Derivatives for Integrator: '<S4>/Integrator1'
  _rtXdot->Integrator1_CSTATE[1] = VesselSimulator_B.Product2[1];

  // Derivatives for Integrator: '<S4>/Integrator2'
  _rtXdot->Integrator2_CSTATE[1] = VesselSimulator_B.Gain[1];

  // Derivatives for Integrator: '<S4>/Integrator1'
  _rtXdot->Integrator1_CSTATE[2] = VesselSimulator_B.Product2[2];

  // Derivatives for Integrator: '<S4>/Integrator2'
  _rtXdot->Integrator2_CSTATE[2] = VesselSimulator_B.Gain[2];
}

// Model initialize function
void VesselSimulator_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

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
    static const char_T tmp[8] = { '/', 'T', 'h', 'r', 'u', 's', 't', '3' };

    static const char_T tmp_0[8] = { '/', 'T', 'h', 'r', 'u', 's', 't', '2' };

    static const char_T tmp_1[8] = { '/', 'T', 'h', 'r', 'u', 's', 't', '1' };

    static const char_T tmp_2[9] = { '/', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n'
    };

    char_T tmp_3[9];
    char_T tmp_4[10];
    int32_T i;

    // Start for Atomic SubSystem: '<S3>/Publish1'
    // Start for MATLABSystem: '<S13>/SinkBlock'
    VesselSimulator_DW.obj_o.isInitialized = 0;
    VesselSimulator_DW.objisempty = true;
    VesselSimulator_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_4[i] = tmp_2[i];
    }

    tmp_4[9] = '\x00';
    Pub_VesselSimulator_269.create_publisher(tmp_4,
      VesselSimulator_MessageQueueLen);

    // End of Start for MATLABSystem: '<S13>/SinkBlock'
    // End of Start for SubSystem: '<S3>/Publish1'

    // Start for Atomic SubSystem: '<S2>/Subscribe1'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    VesselSimulator_DW.obj_dv.isInitialized = 0;
    VesselSimulator_DW.objisempty_l = true;
    VesselSimulator_DW.obj_dv.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_3[i] = tmp_1[i];
    }

    tmp_3[8] = '\x00';
    Sub_VesselSimulator_22.create_subscriber(tmp_3,
      VesselSimulator_MessageQueueLen);

    // End of Start for MATLABSystem: '<S6>/SourceBlock'

    // Start for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S9>/Out1'
    VesselSimulator_B.In1_p = VesselSimulator_P.Out1_Y0;

    // End of Start for SubSystem: '<S6>/Enabled Subsystem'
    // End of Start for SubSystem: '<S2>/Subscribe1'

    // Start for Atomic SubSystem: '<S2>/Subscribe2'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    VesselSimulator_DW.obj_d.isInitialized = 0;
    VesselSimulator_DW.objisempty_p = true;
    VesselSimulator_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[8] = '\x00';
    Sub_VesselSimulator_306.create_subscriber(tmp_3,
      VesselSimulator_MessageQueueLen);

    // End of Start for MATLABSystem: '<S7>/SourceBlock'

    // Start for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S10>/Out1'
    VesselSimulator_B.In1_i = VesselSimulator_P.Out1_Y0_j;

    // End of Start for SubSystem: '<S7>/Enabled Subsystem'
    // End of Start for SubSystem: '<S2>/Subscribe2'

    // Start for Atomic SubSystem: '<S2>/Subscribe3'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    VesselSimulator_DW.obj.isInitialized = 0;
    VesselSimulator_DW.objisempty_a = true;
    VesselSimulator_DW.obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_3[i] = tmp[i];
    }

    tmp_3[8] = '\x00';
    Sub_VesselSimulator_307.create_subscriber(tmp_3,
      VesselSimulator_MessageQueueLen);

    // End of Start for MATLABSystem: '<S8>/SourceBlock'

    // Start for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S11>/Out1'
    VesselSimulator_B.In1 = VesselSimulator_P.Out1_Y0_k;

    // End of Start for SubSystem: '<S8>/Enabled Subsystem'
    // End of Start for SubSystem: '<S2>/Subscribe3'

    // InitializeConditions for Integrator: '<S4>/Integrator1'
    VesselSimulator_X.Integrator1_CSTATE[0] = VesselSimulator_P.Integrator1_IC[0];

    // InitializeConditions for Integrator: '<S4>/Integrator2'
    VesselSimulator_X.Integrator2_CSTATE[0] = VesselSimulator_P.Integrator2_IC[0];

    // InitializeConditions for Integrator: '<S4>/Integrator1'
    VesselSimulator_X.Integrator1_CSTATE[1] = VesselSimulator_P.Integrator1_IC[1];

    // InitializeConditions for Integrator: '<S4>/Integrator2'
    VesselSimulator_X.Integrator2_CSTATE[1] = VesselSimulator_P.Integrator2_IC[1];

    // InitializeConditions for Integrator: '<S4>/Integrator1'
    VesselSimulator_X.Integrator1_CSTATE[2] = VesselSimulator_P.Integrator1_IC[2];

    // InitializeConditions for Integrator: '<S4>/Integrator2'
    VesselSimulator_X.Integrator2_CSTATE[2] = VesselSimulator_P.Integrator2_IC[2];
  }
}

// Model terminate function
void VesselSimulator_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S3>/Publish1'
  // Start for MATLABSystem: '<S13>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S13>/SinkBlock'

  if (VesselSimulator_DW.obj_o.isInitialized == 1) {
    VesselSimulator_DW.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S13>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish1'

  // Terminate for Atomic SubSystem: '<S2>/Subscribe1'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SourceBlock'

  if (VesselSimulator_DW.obj_dv.isInitialized == 1) {
    VesselSimulator_DW.obj_dv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S2>/Subscribe2'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SourceBlock'

  if (VesselSimulator_DW.obj_d.isInitialized == 1) {
    VesselSimulator_DW.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S2>/Subscribe3'
  // Start for MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SourceBlock'

  if (VesselSimulator_DW.obj.isInitialized == 1) {
    VesselSimulator_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe3'
}

//
// File trailer for generated code.
//
// [EOF]
//
