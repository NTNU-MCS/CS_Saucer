//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TESTT.cpp
//
// Code generated for Simulink model 'TESTT'.
//
// Model version                  : 1.55
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Thu Apr  7 20:04:11 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "TESTT.h"
#include "TESTT_private.h"
#define TESTT_MessageQueueLen          (1)

// Block signals (auto storage)
B_TESTT_T TESTT_B;

// Block states (auto storage)
DW_TESTT_T TESTT_DW;

// Real-time model
RT_MODEL_TESTT_T TESTT_M_;
RT_MODEL_TESTT_T *const TESTT_M = &TESTT_M_;
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
void TESTT_step(void)
{
  int32_T i;
  real32_T MID;
  real32_T RobotPositionX;
  real_T Radangle;
  real32_T XPOS;
  real32_T YPOS;
  boolean_T guard1;
  int32_T b;
  int32_T c;
  boolean_T varargout_1;
  int32_T loop_ub;
  int32_T f_sizes_idx_1;

  // Outputs for Atomic SubSystem: '<S8>/Subscribe'
  // Start for MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   MATLABSystem: '<S10>/SourceBlock'

  varargout_1 = Sub_TESTT_21.get_latest_msg(&TESTT_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  // MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  if (varargout_1) {
    TESTT_B.In1_h = TESTT_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S8>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   MATLABSystem: '<S7>/SourceBlock'

  varargout_1 = Sub_TESTT_4.get_latest_msg(&TESTT_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  if (varargout_1) {
    TESTT_B.In1 = TESTT_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
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
      TESTT_B.y[c] = TESTT_B.In1.Data[b + c];
    }

    for (c = 0; c < 128; c++) {
      TESTT_B.y_o[i + (c << 7)] = TESTT_B.y[c];
    }

    // '<S1>:1:5'
  }

  // End of MATLAB Function: '<Root>/2Matrix'

  // MATLAB Function: '<Root>/LidarUpdate1' incorporates:
  //   Constant: '<Root>/Constant'
  //   SignalConversion: '<S5>/TmpSignal ConversionAt SFunction Inport1'

  // '<S1>:1:8'
  // MATLAB Function 'LidarUpdate1': '<S5>:1'
  // '<S5>:1:3'
  MID = 128.0F * TESTT_B.In1.Info.Resolution / 2.0F;

  // '<S5>:1:4'
  RobotPositionX = rt_roundf_snf(((real32_T)TESTT_B.In1_h.Pose.Pose.Position.X +
    MID) / TESTT_B.In1.Info.Resolution);

  // '<S5>:1:5'
  MID = rt_roundf_snf(((real32_T)TESTT_B.In1_h.Pose.Pose.Position.Y + MID) /
                      TESTT_B.In1.Info.Resolution);

  // ROBOMAP(RobotPositionX,RobotPositionY)=1;
  // '<S5>:1:10'
  for (i = 0; i < 91; i++) {
    // '<S5>:1:10'
    // '<S5>:1:11'
    Radangle = (real_T)i * 4.0 * 3.1415926535897931 / 180.0;

    // '<S5>:1:12'
    b = (int32_T)((6.0F / TESTT_B.In1.Info.Resolution + 0.5F) / 0.5F);

    // '<S5>:1:12'
    c = 0;
    varargout_1 = false;
    while ((!varargout_1) && (c <= b - 1)) {
      // '<S5>:1:12'
      YPOS = (real32_T)c * 0.5F;

      // '<S5>:1:13'
      XPOS = rt_roundf_snf(YPOS * (real32_T)cos(Radangle)) + RobotPositionX;

      // '<S5>:1:14'
      YPOS = rt_roundf_snf(YPOS * (real32_T)sin(Radangle)) + MID;
      guard1 = false;
      if ((XPOS > 0.0F) && (XPOS < 129.0F) && (YPOS > 0.0F) && (YPOS < 129.0F))
      {
        // '<S5>:1:15'
        if (TESTT_P.REFMAP[((((int32_T)YPOS - 1) << 7) + (int32_T)XPOS) - 1] ==
            0.0) {
          // '<S5>:1:17'
          // '<S5>:1:18'
          TESTT_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 7)) - 1] = 0;
          if (TESTT_B.y_o[((((int32_T)YPOS - 1) << 7) + (int32_T)XPOS) - 1] ==
              -1) {
            // '<S5>:1:19'
            // '<S5>:1:20'
            TESTT_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 7)) - 1] = 0;
          }
        }

        if (TESTT_P.REFMAP[((((int32_T)YPOS - 1) << 7) + (int32_T)XPOS) - 1] ==
            2.0) {
          // '<S5>:1:24'
          // '<S5>:1:25'
          TESTT_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 7)) - 1] = 100;
          varargout_1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        // '<S5>:1:12'
        c++;
      }
    }

    // '<S5>:1:10'
  }

  // End of MATLAB Function: '<Root>/LidarUpdate1'

  // MATLAB Function: '<Root>/2Vector'
  // '<S5>:1:31'
  // MATLAB Function '2Vector': '<S2>:1'
  // '<S2>:1:3'
  memset(&TESTT_B.y[0], 0, sizeof(int8_T) << 14U);

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
      TESTT_B.f_data[c] = (int16_T)(b + c);
    }

    // '<S2>:1:5'
    for (c = 0; c < 128; c++) {
      TESTT_B.rtb_y_o_c[c] = TESTT_B.y_o[(c << 7) + i];
    }

    for (c = 0; c < f_sizes_idx_1; c++) {
      TESTT_B.y[TESTT_B.f_data[c]] = TESTT_B.rtb_y_o_c[c];
    }

    // '<S2>:1:4'
  }

  // End of MATLAB Function: '<Root>/2Vector'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'

  for (i = 0; i < 16384; i++) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    c = (int32_T)fmod((real_T)TESTT_B.y[i], 256.0);
    TESTT_B.BusAssignment1.Data[i] = (int8_T)(c < 0 ? (int32_T)(int8_T)-(int8_T)
      (uint8_T)-(real_T)c : (int32_T)(int8_T)c);
  }

  TESTT_B.BusAssignment1.Data_SL_Info = TESTT_B.In1.Data_SL_Info;
  TESTT_B.BusAssignment1.Header = TESTT_B.In1.Header;
  TESTT_B.BusAssignment1.Info = TESTT_B.In1.Info;

  // End of BusAssignment: '<Root>/Bus Assignment1'

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_TESTT_37.publish(&TESTT_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish2'
}

// Model initialize function
void TESTT_initialize(void)
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(TESTT_M, (NULL));

  // block I/O
  (void) memset(((void *) &TESTT_B), 0,
                sizeof(B_TESTT_T));

  // states (dwork)
  (void) memset((void *)&TESTT_DW, 0,
                sizeof(DW_TESTT_T));

  {
    static const char_T tmp[11] = { '/', 'p', 'o', 's', 'e', 'u', 'p', 'd', 'a',
      't', 'e' };

    char_T tmp_0[5];
    char_T tmp_1[5];
    char_T tmp_2[12];
    int32_T i;

    // Start for Atomic SubSystem: '<S8>/Subscribe'
    // Start for MATLABSystem: '<S10>/SourceBlock'
    TESTT_DW.obj_n.isInitialized = 0;
    TESTT_DW.objisempty = true;
    TESTT_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[11] = '\x00';
    Sub_TESTT_21.create_subscriber(tmp_2, TESTT_MessageQueueLen);

    // End of Start for MATLABSystem: '<S10>/SourceBlock'

    // Start for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S11>/Out1'
    TESTT_B.In1_h = TESTT_P.Out1_Y0_a;

    // End of Start for SubSystem: '<S10>/Enabled Subsystem'
    // End of Start for SubSystem: '<S8>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    TESTT_DW.obj_m.isInitialized = 0;
    TESTT_DW.objisempty_l = true;
    TESTT_DW.obj_m.isInitialized = 1;
    tmp_1[0] = '/';
    tmp_1[1] = 'm';
    tmp_1[2] = 'a';
    tmp_1[3] = 'p';
    tmp_1[4] = '\x00';
    Sub_TESTT_4.create_subscriber(tmp_1, TESTT_MessageQueueLen);

    // Start for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S9>/Out1'
    TESTT_B.In1 = TESTT_P.Out1_Y0;

    // End of Start for SubSystem: '<S7>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    TESTT_DW.obj.isInitialized = 0;
    TESTT_DW.objisempty_k = true;
    TESTT_DW.obj.isInitialized = 1;
    tmp_0[0] = '/';
    tmp_0[1] = 'm';
    tmp_0[2] = 'a';
    tmp_0[3] = 'p';
    tmp_0[4] = '\x00';
    Pub_TESTT_37.create_publisher(tmp_0, TESTT_MessageQueueLen);

    // End of Start for SubSystem: '<Root>/Publish2'
  }
}

// Model terminate function
void TESTT_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S8>/Subscribe'
  // Start for MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S10>/SourceBlock'

  if (TESTT_DW.obj_n.isInitialized == 1) {
    TESTT_DW.obj_n.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<S8>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SourceBlock'

  if (TESTT_DW.obj_m.isInitialized == 1) {
    TESTT_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Start for MATLABSystem: '<S6>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SinkBlock'

  if (TESTT_DW.obj.isInitialized == 1) {
    TESTT_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
