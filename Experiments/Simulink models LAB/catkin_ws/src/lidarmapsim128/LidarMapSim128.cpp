//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: LidarMapSim128.cpp
//
// Code generated for Simulink model 'LidarMapSim128'.
//
// Model version                  : 1.113
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sun May 15 17:26:15 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "LidarMapSim128.h"
#include "LidarMapSim128_private.h"
#define LidarMapSim128_MessageQueueLen (1)

// Block signals (auto storage)
B_LidarMapSim128_T LidarMapSim128_B;

// Block states (auto storage)
DW_LidarMapSim128_T LidarMapSim128_DW;

// Real-time model
RT_MODEL_LidarMapSim128_T LidarMapSim128_M_;
RT_MODEL_LidarMapSim128_T *const LidarMapSim128_M = &LidarMapSim128_M_;
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
void LidarMapSim128_step(void)
{
  int32_T i;
  real32_T MID;
  real32_T RobotPositionY;
  real_T Radangle;
  real32_T r;
  real32_T XPOS;
  real32_T YPOS;
  int32_T ixstart;
  int32_T n;
  boolean_T varargout_1;
  SL_Bus_LidarMapSim128_std_msgs_Float64 rtb_BusAssignment2;
  int32_T loop_ub;
  int32_T d_sizes;

  // Outputs for Atomic SubSystem: '<S10>/Subscribe2'
  // Start for MATLABSystem: '<S12>/SourceBlock' incorporates:
  //   MATLABSystem: '<S12>/SourceBlock'

  varargout_1 = Sub_LidarMapSim128_57.get_latest_msg
    (&LidarMapSim128_B.varargout_2_c);

  // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  // MATLABSystem: '<S12>/SourceBlock' incorporates:
  //   Inport: '<S13>/In1'

  if (varargout_1) {
    LidarMapSim128_B.In1_i = LidarMapSim128_B.varargout_2_c;
  }

  // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S10>/Subscribe2'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   MATLABSystem: '<S9>/SourceBlock'

  varargout_1 = Sub_LidarMapSim128_4.get_latest_msg
    (&LidarMapSim128_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  // MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  if (varargout_1) {
    LidarMapSim128_B.In1 = LidarMapSim128_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // MATLAB Function: '<Root>/2Matrix'
  // MATLAB Function '2Matrix': '<S1>:1'
  // length(u)^0.5;
  // '<S1>:1:4'
  // '<S1>:1:5'
  for (i = 0; i < 256; i++) {
    // '<S1>:1:5'
    ixstart = i << 8;
    n = (1 + i) << 8;
    if (ixstart + 1 > n) {
      ixstart = 0;
      n = 0;
    }

    // '<S1>:1:6'
    loop_ub = n - ixstart;
    for (n = 0; n < loop_ub; n++) {
      LidarMapSim128_B.y[n] = LidarMapSim128_B.In1.Data[ixstart + n];
    }

    for (n = 0; n < 256; n++) {
      LidarMapSim128_B.y_o[i + (n << 8)] = LidarMapSim128_B.y[n];
    }

    // '<S1>:1:5'
  }

  // End of MATLAB Function: '<Root>/2Matrix'

  // MATLAB Function: '<Root>/Lidar Dont See Wall' incorporates:
  //   Constant: '<Root>/Constant'
  //   Gain: '<S10>/Gain'
  //   SignalConversion: '<S5>/TmpSignal ConversionAt SFunction Inport1'

  // '<S1>:1:8'
  // MATLAB Function 'Lidar Dont See Wall': '<S5>:1'
  //  function ExploredOut=UpdateUserMap3(eta,RefMap,ROBOMAP,resolution)
  // '<S5>:1:5'
  MID = 256.0F * LidarMapSim128_B.In1.Info.Resolution / 2.0F;

  // '<S5>:1:6'
  RobotPositionY = rt_roundf_snf(((real32_T)LidarMapSim128_B.In1_i.X + MID) /
    LidarMapSim128_B.In1.Info.Resolution);

  // '<S5>:1:7'
  MID = rt_roundf_snf(((real32_T)(LidarMapSim128_P.Gain_Gain *
    LidarMapSim128_B.In1_i.Y) + MID) / LidarMapSim128_B.In1.Info.Resolution);

  // '<S5>:1:8'
  // ROBOMAP(RobotPositionX,RobotPositionY)=1;
  // '<S5>:1:11'
  for (i = 0; i < 361; i++) {
    LidarMapSim128_B.RREG[i] = 0.0;

    // '<S5>:1:11'
    // '<S5>:1:12'
    Radangle = (real_T)i * 3.1415926535897931 / 180.0;

    // '<S5>:1:13'
    ixstart = (int32_T)((6.5F / LidarMapSim128_B.In1.Info.Resolution + 0.5F) /
                        0.5F);

    // '<S5>:1:13'
    d_sizes = 0;
    varargout_1 = false;
    while ((!varargout_1) && (d_sizes <= ixstart - 1)) {
      // '<S5>:1:13'
      r = (real32_T)d_sizes * 0.5F;

      // '<S5>:1:14'
      XPOS = rt_roundf_snf(r * (real32_T)cos(Radangle)) + MID;

      // '<S5>:1:15'
      YPOS = rt_roundf_snf(r * (real32_T)sin(Radangle)) + RobotPositionY;
      if ((XPOS > 0.0F) && (XPOS < 257.0F) && (YPOS > 0.0F) && (YPOS < 257.0F) &&
          (LidarMapSim128_P.REFMAP[((((int32_T)YPOS - 1) << 8) + (int32_T)XPOS)
           - 1] == 2)) {
        // '<S5>:1:16'
        // '<S5>:1:18'
        // '<S5>:1:19'
        LidarMapSim128_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 8)) - 1] =
          100;

        // '<S5>:1:21'
        n = (int32_T)(((r - 1.0F) + 0.5F) / 0.5F);

        // '<S5>:1:21'
        r = 0.0F;

        // '<S5>:1:21'
        for (loop_ub = 0; loop_ub < n; loop_ub++) {
          // '<S5>:1:21'
          r = (real32_T)loop_ub * 0.5F;

          // '<S5>:1:22'
          XPOS = rt_roundf_snf(r * (real32_T)cos(Radangle)) + MID;

          // '<S5>:1:23'
          YPOS = rt_roundf_snf(r * (real32_T)sin(Radangle)) + RobotPositionY;
          if (LidarMapSim128_P.REFMAP[((((int32_T)YPOS - 1) << 8) + (int32_T)
               XPOS) - 1] == 0) {
            // '<S5>:1:24'
            // '<S5>:1:25'
            LidarMapSim128_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 8)) -
              1] = 0;
            if (LidarMapSim128_B.y_o[((((int32_T)YPOS - 1) << 8) + (int32_T)XPOS)
                - 1] == -1) {
              // '<S5>:1:26'
              // '<S5>:1:27'
              LidarMapSim128_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 8))
                - 1] = 0;
            }
          }

          // '<S5>:1:21'
        }

        // '<S5>:1:31'
        LidarMapSim128_B.RREG[i] = r * LidarMapSim128_B.In1.Info.Resolution;
        varargout_1 = true;
      } else {
        // '<S5>:1:13'
        d_sizes++;
      }
    }

    // '<S5>:1:11'
  }

  // '<S5>:1:38'
  ixstart = 0;
  for (i = 0; i < 361; i++) {
    if (LidarMapSim128_B.RREG[i] != 0.0) {
      // '<S5>:1:39'
      ixstart++;
    }
  }

  d_sizes = ixstart;
  ixstart = 0;
  for (n = 0; n < 361; n++) {
    if (LidarMapSim128_B.RREG[n] != 0.0) {
      // '<S5>:1:39'
      LidarMapSim128_B.d_data[ixstart] = (int16_T)(n + 1);
      ixstart++;
    }
  }

  // '<S5>:1:39'
  ixstart = 1;
  Radangle = LidarMapSim128_B.RREG[LidarMapSim128_B.d_data[0] - 1];
  if (d_sizes > 1) {
    if (rtIsNaN(LidarMapSim128_B.RREG[LidarMapSim128_B.d_data[0] - 1])) {
      i = 2;
      varargout_1 = false;
      while ((!varargout_1) && (i <= d_sizes)) {
        ixstart = i;
        if (!rtIsNaN(LidarMapSim128_B.RREG[LidarMapSim128_B.d_data[i - 1] - 1]))
        {
          Radangle = LidarMapSim128_B.RREG[LidarMapSim128_B.d_data[i - 1] - 1];
          varargout_1 = true;
        } else {
          i++;
        }
      }
    }

    if (ixstart < d_sizes) {
      while (ixstart + 1 <= d_sizes) {
        if (LidarMapSim128_B.RREG[LidarMapSim128_B.d_data[ixstart] - 1] <
            Radangle) {
          Radangle = LidarMapSim128_B.RREG[LidarMapSim128_B.d_data[ixstart] - 1];
        }

        ixstart++;
      }
    }
  }

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   MATLAB Function: '<Root>/Lidar Dont See Wall'

  rtb_BusAssignment2.Data = Radangle;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S7>/SinkBlock'
  Pub_LidarMapSim128_77.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // MATLAB Function: '<Root>/2Vector'
  // MATLAB Function '2Vector': '<S2>:1'
  // '<S2>:1:3'
  memset(&LidarMapSim128_B.y[0], 0, sizeof(int8_T) << 16U);

  // '<S2>:1:4'
  for (i = 0; i < 256; i++) {
    // '<S2>:1:4'
    ixstart = i << 8;
    n = (1 + i) << 8;
    if (ixstart + 1 > n) {
      ixstart = 0;
      n = 0;
    }

    d_sizes = n - ixstart;
    loop_ub = n - ixstart;
    for (n = 0; n < loop_ub; n++) {
      LidarMapSim128_B.f_data[n] = ixstart + n;
    }

    // '<S2>:1:5'
    for (n = 0; n < 256; n++) {
      LidarMapSim128_B.rtb_y_o_m[n] = LidarMapSim128_B.y_o[(n << 8) + i];
    }

    for (n = 0; n < d_sizes; n++) {
      LidarMapSim128_B.y[LidarMapSim128_B.f_data[n]] =
        LidarMapSim128_B.rtb_y_o_m[n];
    }

    // '<S2>:1:4'
  }

  // End of MATLAB Function: '<Root>/2Vector'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion'

  for (i = 0; i < 65536; i++) {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    n = (int32_T)fmod((real_T)LidarMapSim128_B.y[i], 256.0);
    LidarMapSim128_B.BusAssignment1.Data[i] = (int8_T)(n < 0 ? (int32_T)(int8_T)
      -(int8_T)(uint8_T)-(real_T)n : (int32_T)(int8_T)n);
  }

  LidarMapSim128_B.BusAssignment1.Data_SL_Info =
    LidarMapSim128_B.In1.Data_SL_Info;
  LidarMapSim128_B.BusAssignment1.Header = LidarMapSim128_B.In1.Header;
  LidarMapSim128_B.BusAssignment1.Info = LidarMapSim128_B.In1.Info;

  // End of BusAssignment: '<Root>/Bus Assignment1'

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S8>/SinkBlock'
  Pub_LidarMapSim128_37.publish(&LidarMapSim128_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish2'
}

// Model initialize function
void LidarMapSim128_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(LidarMapSim128_M, (NULL));

  // block I/O
  (void) memset(((void *) &LidarMapSim128_B), 0,
                sizeof(B_LidarMapSim128_T));

  // states (dwork)
  (void) memset((void *)&LidarMapSim128_DW, 0,
                sizeof(DW_LidarMapSim128_T));

  {
    static const char_T tmp[15] = { '/', 'E', 't', 'a', 'S', 'e', 't', 'D', 'i',
      's', 't', 'a', 'n', 'c', 'e' };

    char_T tmp_0[5];
    char_T tmp_1[16];
    char_T tmp_2[5];
    char_T tmp_3[5];
    int32_T i;

    // Start for Atomic SubSystem: '<S10>/Subscribe2'
    // Start for MATLABSystem: '<S12>/SourceBlock'
    LidarMapSim128_DW.obj_f.isInitialized = 0;
    LidarMapSim128_DW.objisempty = true;
    LidarMapSim128_DW.obj_f.isInitialized = 1;
    tmp_3[0] = '/';
    tmp_3[1] = 'E';
    tmp_3[2] = 't';
    tmp_3[3] = 'a';
    tmp_3[4] = '\x00';
    Sub_LidarMapSim128_57.create_subscriber(tmp_3,
      LidarMapSim128_MessageQueueLen);

    // Start for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S13>/Out1'
    LidarMapSim128_B.In1_i = LidarMapSim128_P.Out1_Y0_e;

    // End of Start for SubSystem: '<S12>/Enabled Subsystem'
    // End of Start for SubSystem: '<S10>/Subscribe2'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S9>/SourceBlock'
    LidarMapSim128_DW.obj_m.isInitialized = 0;
    LidarMapSim128_DW.objisempty_l = true;
    LidarMapSim128_DW.obj_m.isInitialized = 1;
    tmp_2[0] = '/';
    tmp_2[1] = 'm';
    tmp_2[2] = 'a';
    tmp_2[3] = 'p';
    tmp_2[4] = '\x00';
    Sub_LidarMapSim128_4.create_subscriber(tmp_2, LidarMapSim128_MessageQueueLen);

    // Start for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S11>/Out1'
    LidarMapSim128_B.In1 = LidarMapSim128_P.Out1_Y0;

    // End of Start for SubSystem: '<S9>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S7>/SinkBlock'
    LidarMapSim128_DW.obj_e.isInitialized = 0;
    LidarMapSim128_DW.objisempty_kk = true;
    LidarMapSim128_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      tmp_1[i] = tmp[i];
    }

    tmp_1[15] = '\x00';
    Pub_LidarMapSim128_77.create_publisher(tmp_1, LidarMapSim128_MessageQueueLen);

    // End of Start for MATLABSystem: '<S7>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish1'

    // Start for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    LidarMapSim128_DW.obj.isInitialized = 0;
    LidarMapSim128_DW.objisempty_k = true;
    LidarMapSim128_DW.obj.isInitialized = 1;
    tmp_0[0] = '/';
    tmp_0[1] = 'm';
    tmp_0[2] = 'a';
    tmp_0[3] = 'p';
    tmp_0[4] = '\x00';
    Pub_LidarMapSim128_37.create_publisher(tmp_0, LidarMapSim128_MessageQueueLen);

    // End of Start for SubSystem: '<Root>/Publish2'
  }
}

// Model terminate function
void LidarMapSim128_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S10>/Subscribe2'
  // Start for MATLABSystem: '<S12>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S12>/SourceBlock'

  if (LidarMapSim128_DW.obj_f.isInitialized == 1) {
    LidarMapSim128_DW.obj_f.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S12>/SourceBlock'
  // End of Terminate for SubSystem: '<S10>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S9>/SourceBlock'

  if (LidarMapSim128_DW.obj_m.isInitialized == 1) {
    LidarMapSim128_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Start for MATLABSystem: '<S7>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SinkBlock'

  if (LidarMapSim128_DW.obj_e.isInitialized == 1) {
    LidarMapSim128_DW.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Start for MATLABSystem: '<S8>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SinkBlock'

  if (LidarMapSim128_DW.obj.isInitialized == 1) {
    LidarMapSim128_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
