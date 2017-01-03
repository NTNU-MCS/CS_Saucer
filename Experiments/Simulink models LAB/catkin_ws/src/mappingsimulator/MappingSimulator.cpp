//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MappingSimulator.cpp
//
// Code generated for Simulink model 'MappingSimulator'.
//
// Model version                  : 1.130
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Jun 22 14:54:41 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "MappingSimulator.h"
#include "MappingSimulator_private.h"
#define MappingSimulato_MessageQueueLen (1)

// Block signals (auto storage)
B_MappingSimulator_T MappingSimulator_B;

// Block states (auto storage)
DW_MappingSimulator_T MappingSimulator_DW;

// Real-time model
RT_MODEL_MappingSimulator_T MappingSimulator_M_;
RT_MODEL_MappingSimulator_T *const MappingSimulator_M = &MappingSimulator_M_;
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
void MappingSimulator_step(void)
{
  real32_T MID;
  real32_T RobotPositionY;
  real32_T r;
  real32_T XPOS;
  real32_T YPOS;
  real32_T b;
  int32_T ixstart;
  int32_T n;
  int32_T ix;
  boolean_T varargout_1;
  SL_Bus_MappingSimulator_std_msgs_Float64 rtb_BusAssignment2;
  int32_T loop_ub;
  int32_T d_sizes;
  real_T varargin_1_idx_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S1>/SourceBlock' incorporates:
  //   MATLABSystem: '<S1>/SourceBlock'

  varargout_1 = Sub_MappingSimulator_4.get_latest_msg
    (&MappingSimulator_B.varargout_2);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S3>/Enable'

  // MATLABSystem: '<S1>/SourceBlock' incorporates:
  //   Inport: '<S13>/In1'
  //   Inport: '<S3>/In1'
  //   MATLABSystem: '<S12>/SourceBlock'

  if (varargout_1) {
    MappingSimulator_B.In1 = MappingSimulator_B.varargout_2;

    // Outputs for Atomic SubSystem: '<S11>/Subscribe2'
    // Start for MATLABSystem: '<S12>/SourceBlock' incorporates:
    //   Inport: '<S3>/In1'
    //   MATLABSystem: '<S12>/SourceBlock'

    varargout_1 = Sub_MappingSimulator_57.get_latest_msg
      (&MappingSimulator_B.varargout_2_c);

    // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S13>/Enable'

    if (varargout_1) {
      MappingSimulator_B.In1_i = MappingSimulator_B.varargout_2_c;
    }

    // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S11>/Subscribe2'

    // MATLAB Function: '<S2>/2Matrix' incorporates:
    //   Inport: '<S13>/In1'
    //   MATLABSystem: '<S12>/SourceBlock'

    // MATLAB Function 'Subsystem1/2Matrix': '<S4>:1'
    // length(u)^0.5;
    // '<S4>:1:4'
    // '<S4>:1:5'
    for (n = 0; n < 256; n++) {
      // '<S4>:1:5'
      ix = n << 8;
      ixstart = (1 + n) << 8;
      if (ix + 1 > ixstart) {
        ix = 0;
        ixstart = 0;
      }

      // '<S4>:1:6'
      loop_ub = ixstart - ix;
      for (ixstart = 0; ixstart < loop_ub; ixstart++) {
        MappingSimulator_B.y[ixstart] = MappingSimulator_B.In1.Data[ix + ixstart];
      }

      for (ixstart = 0; ixstart < 256; ixstart++) {
        MappingSimulator_B.y_o[n + (ixstart << 8)] =
          MappingSimulator_B.y[ixstart];
      }

      // '<S4>:1:5'
    }

    // End of MATLAB Function: '<S2>/2Matrix'

    // MATLAB Function: '<S2>/Lidar Dont See Wall' incorporates:
    //   Constant: '<S2>/Constant'
    //   Gain: '<S11>/Gain'
    //   SignalConversion: '<S8>/TmpSignal ConversionAt SFunction Inport1'

    // '<S4>:1:8'
    // MATLAB Function 'Subsystem1/Lidar Dont See Wall': '<S8>:1'
    //  function ExploredOut=UpdateUserMap3(eta,RefMap,ROBOMAP,resolution)
    // '<S8>:1:5'
    MID = 256.0F * MappingSimulator_B.In1.Info.Resolution / 2.0F;

    // '<S8>:1:6'
    RobotPositionY = rt_roundf_snf(((real32_T)MappingSimulator_B.In1_i.X + MID) /
      MappingSimulator_B.In1.Info.Resolution);

    // '<S8>:1:7'
    MID = rt_roundf_snf(((real32_T)(MappingSimulator_P.Gain_Gain *
      MappingSimulator_B.In1_i.Y) + MID) /
                        MappingSimulator_B.In1.Info.Resolution);

    // '<S8>:1:8'
    // ROBOMAP(RobotPositionX,RobotPositionY)=1;
    // '<S8>:1:11'
    for (n = 0; n < 361; n++) {
      MappingSimulator_B.RREG[n] = 0.0;

      // '<S8>:1:11'
      // '<S8>:1:12'
      MappingSimulator_B.Radangle = (real_T)n * 3.1415926535897931 / 180.0;

      // '<S8>:1:13'
      b = 6.5F / MappingSimulator_B.In1.Info.Resolution;

      // '<S8>:1:13'
      ix = 0;
      varargout_1 = false;
      while ((!varargout_1) && (ix <= (int32_T)(b + 1.0F) - 1)) {
        // '<S8>:1:13'
        // '<S8>:1:14'
        XPOS = rt_roundf_snf((real32_T)ix * (real32_T)cos
                             (MappingSimulator_B.Radangle)) + MID;

        // '<S8>:1:15'
        YPOS = rt_roundf_snf((real32_T)ix * (real32_T)sin
                             (MappingSimulator_B.Radangle)) + RobotPositionY;
        if ((XPOS > 0.0F) && (XPOS < 257.0F) && (YPOS > 0.0F) && (YPOS < 257.0F)
            && (MappingSimulator_P.REFMAP[((((int32_T)YPOS - 1) << 8) + (int32_T)
              XPOS) - 1] == 2)) {
          // '<S8>:1:16'
          // '<S8>:1:18'
          // '<S8>:1:19'
          MappingSimulator_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 8)) -
            1] = 100;

          // '<S8>:1:21'
          ixstart = (int32_T)((((real32_T)ix - 1.0F) + 0.5F) / 0.5F);

          // '<S8>:1:21'
          r = 0.0F;

          // '<S8>:1:21'
          for (d_sizes = 0; d_sizes < ixstart; d_sizes++) {
            // '<S8>:1:21'
            r = (real32_T)d_sizes * 0.5F;

            // '<S8>:1:22'
            XPOS = rt_roundf_snf(r * (real32_T)cos(MappingSimulator_B.Radangle))
              + MID;

            // '<S8>:1:23'
            YPOS = rt_roundf_snf(r * (real32_T)sin(MappingSimulator_B.Radangle))
              + RobotPositionY;
            if (MappingSimulator_P.REFMAP[((((int32_T)YPOS - 1) << 8) + (int32_T)
                 XPOS) - 1] == 0) {
              // '<S8>:1:24'
              // '<S8>:1:25'
              MappingSimulator_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) << 8))
                - 1] = 0;
              if (MappingSimulator_B.y_o[((((int32_T)YPOS - 1) << 8) + (int32_T)
                   XPOS) - 1] == -1) {
                // '<S8>:1:26'
                // '<S8>:1:27'
                MappingSimulator_B.y_o[((int32_T)XPOS + (((int32_T)YPOS - 1) <<
                  8)) - 1] = 0;
              }
            }

            // '<S8>:1:21'
          }

          // '<S8>:1:31'
          MappingSimulator_B.RREG[n] = r *
            MappingSimulator_B.In1.Info.Resolution;
          varargout_1 = true;
        } else {
          // '<S8>:1:13'
          ix++;
        }
      }

      // '<S8>:1:11'
    }

    // '<S8>:1:38'
    ixstart = 0;
    for (n = 0; n < 361; n++) {
      if (MappingSimulator_B.RREG[n] != 0.0) {
        // '<S8>:1:39'
        ixstart++;
      }
    }

    d_sizes = ixstart;
    ixstart = 0;
    for (n = 0; n < 361; n++) {
      if (MappingSimulator_B.RREG[n] != 0.0) {
        // '<S8>:1:39'
        MappingSimulator_B.d_data[ixstart] = (int16_T)(n + 1);
        ixstart++;
      }
    }

    // '<S8>:1:39'
    ixstart = 1;
    MappingSimulator_B.Radangle =
      MappingSimulator_B.RREG[MappingSimulator_B.d_data[0] - 1];
    if (d_sizes > 1) {
      if (rtIsNaN(MappingSimulator_B.RREG[MappingSimulator_B.d_data[0] - 1])) {
        ix = 2;
        varargout_1 = false;
        while ((!varargout_1) && (ix <= d_sizes)) {
          ixstart = ix;
          if (!rtIsNaN(MappingSimulator_B.RREG[MappingSimulator_B.d_data[ix - 1]
                       - 1])) {
            MappingSimulator_B.Radangle =
              MappingSimulator_B.RREG[MappingSimulator_B.d_data[ix - 1] - 1];
            varargout_1 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < d_sizes) {
        while (ixstart + 1 <= d_sizes) {
          if (MappingSimulator_B.RREG[MappingSimulator_B.d_data[ixstart] - 1] <
              MappingSimulator_B.Radangle) {
            MappingSimulator_B.Radangle =
              MappingSimulator_B.RREG[MappingSimulator_B.d_data[ixstart] - 1];
          }

          ixstart++;
        }
      }
    }

    varargin_1_idx_1 = MappingSimulator_B.Radangle;
    MappingSimulator_B.Radangle = 0.0;
    if (varargin_1_idx_1 > 0.0) {
      MappingSimulator_B.Radangle = varargin_1_idx_1;
    }

    // BusAssignment: '<S2>/Bus Assignment2' incorporates:
    //   MATLAB Function: '<S2>/Lidar Dont See Wall'

    rtb_BusAssignment2.Data = MappingSimulator_B.Radangle;

    // Outputs for Atomic SubSystem: '<S2>/Publish1'
    // MATLABSystem: '<S9>/SinkBlock'
    Pub_MappingSimulator_77.publish(&rtb_BusAssignment2);

    // End of Outputs for SubSystem: '<S2>/Publish1'

    // MATLAB Function: '<S2>/2Vector'
    // MATLAB Function 'Subsystem1/2Vector': '<S5>:1'
    // '<S5>:1:3'
    memset(&MappingSimulator_B.y[0], 0, sizeof(int8_T) << 16U);

    // '<S5>:1:4'
    for (n = 0; n < 256; n++) {
      // '<S5>:1:4'
      ix = n << 8;
      ixstart = (1 + n) << 8;
      if (ix + 1 > ixstart) {
        ix = 0;
        ixstart = 0;
      }

      d_sizes = ixstart - ix;
      loop_ub = ixstart - ix;
      for (ixstart = 0; ixstart < loop_ub; ixstart++) {
        MappingSimulator_B.f_data[ixstart] = ix + ixstart;
      }

      // '<S5>:1:5'
      for (ixstart = 0; ixstart < 256; ixstart++) {
        MappingSimulator_B.rtb_y_o_m[ixstart] = MappingSimulator_B.y_o[(ixstart <<
          8) + n];
      }

      for (ixstart = 0; ixstart < d_sizes; ixstart++) {
        MappingSimulator_B.y[MappingSimulator_B.f_data[ixstart]] =
          MappingSimulator_B.rtb_y_o_m[ixstart];
      }

      // '<S5>:1:4'
    }

    // End of MATLAB Function: '<S2>/2Vector'

    // BusAssignment: '<S2>/Bus Assignment1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion'

    for (n = 0; n < 65536; n++) {
      // DataTypeConversion: '<S2>/Data Type Conversion'
      ixstart = (int32_T)fmod((real_T)MappingSimulator_B.y[n], 256.0);
      MappingSimulator_B.BusAssignment1.Data[n] = (int8_T)(ixstart < 0 ?
        (int32_T)(int8_T)-(int8_T)(uint8_T)-(real_T)ixstart : (int32_T)(int8_T)
        ixstart);
    }

    MappingSimulator_B.BusAssignment1.Data_SL_Info =
      MappingSimulator_B.In1.Data_SL_Info;
    MappingSimulator_B.BusAssignment1.Header = MappingSimulator_B.In1.Header;
    MappingSimulator_B.BusAssignment1.Info = MappingSimulator_B.In1.Info;

    // End of BusAssignment: '<S2>/Bus Assignment1'

    // Outputs for Atomic SubSystem: '<S2>/Publish2'
    // MATLABSystem: '<S10>/SinkBlock'
    Pub_MappingSimulator_37.publish(&MappingSimulator_B.BusAssignment1);

    // End of Outputs for SubSystem: '<S2>/Publish2'
  }

  // End of Outputs for SubSystem: '<S1>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  // End of Outputs for SubSystem: '<Root>/Subscribe'
}

// Model initialize function
void MappingSimulator_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(MappingSimulator_M, (NULL));

  // block I/O
  (void) memset(((void *) &MappingSimulator_B), 0,
                sizeof(B_MappingSimulator_T));

  // states (dwork)
  (void) memset((void *)&MappingSimulator_DW, 0,
                sizeof(DW_MappingSimulator_T));

  {
    static const char_T tmp[13] = { '/', 'S', 'e', 't', 'P', 'o', 'i', 'n', 't',
      'D', 'i', 's', 't' };

    static const char_T tmp_0[9] = { '/', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n'
    };

    char_T tmp_1[5];
    char_T tmp_2[14];
    char_T tmp_3[10];
    char_T tmp_4[5];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S1>/SourceBlock'
    MappingSimulator_DW.obj_m.isInitialized = 0;
    MappingSimulator_DW.objisempty_l = true;
    MappingSimulator_DW.obj_m.isInitialized = 1;
    tmp_4[0] = '/';
    tmp_4[1] = 'm';
    tmp_4[2] = 'a';
    tmp_4[3] = 'p';
    tmp_4[4] = '\x00';
    Sub_MappingSimulator_4.create_subscriber(tmp_4,
      MappingSimulato_MessageQueueLen);

    // Start for Enabled SubSystem: '<S1>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S3>/Out1'
    MappingSimulator_B.In1 = MappingSimulator_P.Out1_Y0;

    // End of Start for SubSystem: '<S1>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Enabled SubSystem: '<Root>/Subsystem1'
    // Start for Atomic SubSystem: '<S11>/Subscribe2'
    // Start for MATLABSystem: '<S12>/SourceBlock'
    MappingSimulator_DW.obj.isInitialized = 0;
    MappingSimulator_DW.objisempty = true;
    MappingSimulator_DW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[9] = '\x00';
    Sub_MappingSimulator_57.create_subscriber(tmp_3,
      MappingSimulato_MessageQueueLen);

    // End of Start for MATLABSystem: '<S12>/SourceBlock'

    // Start for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S13>/Out1'
    MappingSimulator_B.In1_i = MappingSimulator_P.Out1_Y0_e;

    // End of Start for SubSystem: '<S12>/Enabled Subsystem'
    // End of Start for SubSystem: '<S11>/Subscribe2'

    // Start for Atomic SubSystem: '<S2>/Publish1'
    // Start for MATLABSystem: '<S9>/SinkBlock'
    MappingSimulator_DW.obj_e.isInitialized = 0;
    MappingSimulator_DW.objisempty_kk = true;
    MappingSimulator_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[13] = '\x00';
    Pub_MappingSimulator_77.create_publisher(tmp_2,
      MappingSimulato_MessageQueueLen);

    // End of Start for MATLABSystem: '<S9>/SinkBlock'
    // End of Start for SubSystem: '<S2>/Publish1'

    // Start for Atomic SubSystem: '<S2>/Publish2'
    // Start for MATLABSystem: '<S10>/SinkBlock'
    MappingSimulator_DW.obj_o.isInitialized = 0;
    MappingSimulator_DW.objisempty_k = true;
    MappingSimulator_DW.obj_o.isInitialized = 1;
    tmp_1[0] = '/';
    tmp_1[1] = 'm';
    tmp_1[2] = 'a';
    tmp_1[3] = 'p';
    tmp_1[4] = '\x00';
    Pub_MappingSimulator_37.create_publisher(tmp_1,
      MappingSimulato_MessageQueueLen);

    // End of Start for SubSystem: '<S2>/Publish2'
    // End of Start for SubSystem: '<Root>/Subsystem1'
  }
}

// Model terminate function
void MappingSimulator_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S1>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S1>/SourceBlock'

  if (MappingSimulator_DW.obj_m.isInitialized == 1) {
    MappingSimulator_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S1>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Enabled SubSystem: '<Root>/Subsystem1'
  // Terminate for Atomic SubSystem: '<S11>/Subscribe2'
  // Start for MATLABSystem: '<S12>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S12>/SourceBlock'

  if (MappingSimulator_DW.obj.isInitialized == 1) {
    MappingSimulator_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S12>/SourceBlock'
  // End of Terminate for SubSystem: '<S11>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S2>/Publish1'
  // Start for MATLABSystem: '<S9>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S9>/SinkBlock'

  if (MappingSimulator_DW.obj_e.isInitialized == 1) {
    MappingSimulator_DW.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S9>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish1'

  // Terminate for Atomic SubSystem: '<S2>/Publish2'
  // Start for MATLABSystem: '<S10>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S10>/SinkBlock'

  if (MappingSimulator_DW.obj_o.isInitialized == 1) {
    MappingSimulator_DW.obj_o.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S10>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish2'
  // End of Terminate for SubSystem: '<Root>/Subsystem1'
}

//
// File trailer for generated code.
//
// [EOF]
//
