//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: LidarMapSim.cpp
//
// Code generated for Simulink model 'LidarMapSim'.
//
// Model version                  : 1.65
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Apr 27 17:41:22 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "LidarMapSim.h"
#include "LidarMapSim_private.h"
#define LidarMapSim_MessageQueueLen    (1)

// Block signals (auto storage)
B_LidarMapSim_T LidarMapSim_B;

// Block states (auto storage)
DW_LidarMapSim_T LidarMapSim_DW;

// Real-time model
RT_MODEL_LidarMapSim_T LidarMapSim_M_;
RT_MODEL_LidarMapSim_T *const LidarMapSim_M = &LidarMapSim_M_;
real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs((real_T)u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor((real_T)(u + 0.5F));
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil((real_T)(u - 0.5F));
    }
  } else {
    y = u;
  }

  return y;
}

// Model step function
void LidarMapSim_step(void)
{
  int32_T i;
  real32_T MID;
  real32_T RobotPositionY;
  real_T Radangle;
  real32_T XPOS;
  real32_T YPOS;
  boolean_T guard1;
  int32_T b;
  int32_T c;
  boolean_T varargout_1;
  int32_T loop_ub;
  int32_T f_sizes_idx_1;

  // Outputs for Atomic SubSystem: '<S7>/Subscribe2'
  // Start for MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   MATLABSystem: '<S9>/SourceBlock'

  varargout_1 = Sub_LidarMapSim_57.get_latest_msg(&LidarMapSim_B.varargout_2_c);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'

  if (varargout_1) {
    LidarMapSim_B.In1_i = LidarMapSim_B.varargout_2_c;
  }

  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S7>/Subscribe2'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  varargout_1 = Sub_LidarMapSim_4.get_latest_msg(&LidarMapSim_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S8>/In1'

  if (varargout_1) {
    LidarMapSim_B.In1 = LidarMapSim_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // MATLAB Function: '<Root>/2Matrix'
  // MATLAB Function '2Matrix': '<S1>:1'
  // length(u)^0.5;
  // '<S1>:1:4'
  // '<S1>:1:5'
  for (i = 0; i < 128; i++) {
    // '<S1>:1:5'
    b = i << 7;
    c = (1 + i) << 7;
    if (b + 1 > c) {
      b = 0;
      c = 0;
    }

    // '<S1>:1:6'
    loop_ub = c - b;
    for (c = 0; c < loop_ub; c++) {
      LidarMapSim_B.y[c] = LidarMapSim_B.In1.Data[b + c];
    }

    for (c = 0; c < 128; c++) {
      LidarMapSim_B.y_o[i + (c << 7)] = LidarMapSim_B.y[c];
    }

    // '<S1>:1:5'
  }

  // End of MATLAB Function: '<Root>/2Matrix'

  // MATLAB Function: '<Root>/LidarUpdate1' incorporates:
  //   Constant: '<Root>/Constant'
  //   Gain: '<S7>/Gain'
  //   SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport1'

  // '<S1>:1:8'
  // MATLAB Function 'LidarUpdate1': '<S4>:1'
  // '<S4>:1:3'
  MID = 128.0F * LidarMapSim_B.In1.Info.Resolution / 2.0F;

  // '<S4>:1:4'
  RobotPositionY = rt_roundf_snf(((real32_T)LidarMapSim_B.In1_i.X + MID) /
    LidarMapSim_B.In1.Info.Resolution);

  // '<S4>:1:5'
  MID = rt_roundf_snf(((real32_T)(LidarMapSim_P.Gain_Gain *
    LidarMapSim_B.In1_i.Y) + MID) / LidarMapSim_B.In1.Info.Resolution);

  // ROBOMAP(RobotPositionX,RobotPositionY)=1;
  // '<S4>:1:10'
  for (i = 0; i < 361; i++) {
    // '<S4>:1:10'
    // '<S4>:1:11'
    Radangle = (real_T)i * 3.1415926535897931 / 180.0;

    // '<S4>:1:12'
    b = (int32_T)((6.0F / LidarMapSim_B.In1.Info.Resolution + 0.5F) / 0.5F);

    // '<S4>:1:12'
    c = 0;
    varargout_1 = false;
    while ((!varargout_1) && (c <= b - 1)) {
      // '<S4>:1:12'
      YPOS = (real32_T)c * 0.5F;

      // '<S4>:1:13'
      XPOS = rt_roundf_snf(YPOS * (real32_T)cos(Radangle)) + MID;

      // '<S4>:1:14'
      YPOS = rt_roundf_snf(YPOS * (real32_T)sin(Radangle)) + RobotPositionY;
      guard1 = false;
      if ((XPOS > 0.0F) && (XPOS < 129.0F) && (YPOS > 0.0F) && (YPOS < 129.0F))
      {
        // '<S4>:1:15'
        if (LidarMapSim_P.REFMAP[((((int32_T)YPOS - 1) << 7) + (int32_T)XPOS) -
            1] == 0.0) {
          // '<S4>:1:17'
          // '<S4>:1:18'
          LidarMapSim_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 7)) - 1] =
            0;
          if (LidarMapSim_B.y_o[((((int32_T)YPOS - 1) << 7) + (int32_T)XPOS) - 1]
              == -1) {
            // '<S4>:1:19'
            // '<S4>:1:20'
            LidarMapSim_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 7)) - 1] =
              0;
          }
        }

        if (LidarMapSim_P.REFMAP[((((int32_T)YPOS - 1) << 7) + (int32_T)XPOS) -
            1] == 2.0) {
          // '<S4>:1:24'
          // '<S4>:1:25'
          LidarMapSim_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 7)) - 1] =
            100;
          varargout_1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        // '<S4>:1:12'
        c++;
      }
    }

    // '<S4>:1:10'
  }

  // End of MATLAB Function: '<Root>/LidarUpdate1'

  // MATLAB Function: '<Root>/2Vector'
  // '<S4>:1:31'
  // MATLAB Function '2Vector': '<S2>:1'
  // '<S2>:1:3'
  memset(&LidarMapSim_B.y[0], 0, sizeof(int8_T) << 14U);

  // '<S2>:1:4'
  for (i = 0; i < 128; i++) {
    // '<S2>:1:4'
    b = i << 7;
    c = (1 + i) << 7;
    if (b + 1 > c) {
      b = 0;
      c = 0;
    }

    f_sizes_idx_1 = c - b;
    loop_ub = c - b;
    for (c = 0; c < loop_ub; c++) {
      LidarMapSim_B.f_data[c] = (int16_T)(b + c);
    }

    // '<S2>:1:5'
    for (c = 0; c < 128; c++) {
      LidarMapSim_B.rtb_y_o_m[c] = LidarMapSim_B.y_o[(c << 7) + i];
    }

    for (c = 0; c < f_sizes_idx_1; c++) {
      LidarMapSim_B.y[LidarMapSim_B.f_data[c]] = LidarMapSim_B.rtb_y_o_m[c];
    }

    // '<S2>:1:4'
  }

  // End of MATLAB Function: '<Root>/2Vector'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'

  for (i = 0; i < 16384; i++) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    c = (int32_T)fmod((real_T)LidarMapSim_B.y[i], 256.0);
    LidarMapSim_B.BusAssignment1.Data[i] = (int8_T)(c < 0 ? (int32_T)(int8_T)
      -(int8_T)(uint8_T)-(real_T)c : (int32_T)(int8_T)c);
  }

  LidarMapSim_B.BusAssignment1.Data_SL_Info = LidarMapSim_B.In1.Data_SL_Info;
  LidarMapSim_B.BusAssignment1.Header = LidarMapSim_B.In1.Header;
  LidarMapSim_B.BusAssignment1.Info = LidarMapSim_B.In1.Info;

  // End of BusAssignment: '<Root>/Bus Assignment1'

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_LidarMapSim_37.publish(&LidarMapSim_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish2'
}

// Model initialize function
void LidarMapSim_initialize(void)
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(LidarMapSim_M, (NULL));

  // block I/O
  (void) memset(((void *) &LidarMapSim_B), 0,
                sizeof(B_LidarMapSim_T));

  // states (dwork)
  (void) memset((void *)&LidarMapSim_DW, 0,
                sizeof(DW_LidarMapSim_T));

  {
    char_T tmp[5];
    char_T tmp_0[5];
    char_T tmp_1[5];

    // Start for Atomic SubSystem: '<S7>/Subscribe2'
    // Start for MATLABSystem: '<S9>/SourceBlock'
    LidarMapSim_DW.obj_f.isInitialized = 0;
    LidarMapSim_DW.objisempty = true;
    LidarMapSim_DW.obj_f.isInitialized = 1;
    tmp_1[0] = '/';
    tmp_1[1] = 'E';
    tmp_1[2] = 't';
    tmp_1[3] = 'a';
    tmp_1[4] = '\x00';
    Sub_LidarMapSim_57.create_subscriber(tmp_1, LidarMapSim_MessageQueueLen);

    // Start for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S10>/Out1'
    LidarMapSim_B.In1_i = LidarMapSim_P.Out1_Y0_e;

    // End of Start for SubSystem: '<S9>/Enabled Subsystem'
    // End of Start for SubSystem: '<S7>/Subscribe2'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    LidarMapSim_DW.obj_m.isInitialized = 0;
    LidarMapSim_DW.objisempty_l = true;
    LidarMapSim_DW.obj_m.isInitialized = 1;
    tmp_0[0] = '/';
    tmp_0[1] = 'm';
    tmp_0[2] = 'a';
    tmp_0[3] = 'p';
    tmp_0[4] = '\x00';
    Sub_LidarMapSim_4.create_subscriber(tmp_0, LidarMapSim_MessageQueueLen);

    // Start for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S8>/Out1'
    LidarMapSim_B.In1 = LidarMapSim_P.Out1_Y0;

    // End of Start for SubSystem: '<S6>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    LidarMapSim_DW.obj.isInitialized = 0;
    LidarMapSim_DW.objisempty_k = true;
    LidarMapSim_DW.obj.isInitialized = 1;
    tmp[0] = '/';
    tmp[1] = 'm';
    tmp[2] = 'a';
    tmp[3] = 'p';
    tmp[4] = '\x00';
    Pub_LidarMapSim_37.create_publisher(tmp, LidarMapSim_MessageQueueLen);

    // End of Start for SubSystem: '<Root>/Publish2'
  }
}

// Model terminate function
void LidarMapSim_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S7>/Subscribe2'
  // Start for MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S9>/SourceBlock'

  if (LidarMapSim_DW.obj_f.isInitialized == 1) {
    LidarMapSim_DW.obj_f.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<S7>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SourceBlock'

  if (LidarMapSim_DW.obj_m.isInitialized == 1) {
    LidarMapSim_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Start for MATLABSystem: '<S5>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SinkBlock'

  if (LidarMapSim_DW.obj.isInitialized == 1) {
    LidarMapSim_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
