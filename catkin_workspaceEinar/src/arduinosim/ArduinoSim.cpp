//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ArduinoSim.cpp
//
// Code generated for Simulink model 'ArduinoSim'.
//
// Model version                  : 1.13
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sat Feb 20 18:11:47 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ArduinoSim.h"
#include "ArduinoSim_private.h"
#define ArduinoSim_MessageQueueLen     (1)

// Block signals (auto storage)
B_ArduinoSim_T ArduinoSim_B;

// Block states (auto storage)
DW_ArduinoSim_T ArduinoSim_DW;

// Real-time model
RT_MODEL_ArduinoSim_T ArduinoSim_M_;
RT_MODEL_ArduinoSim_T *const ArduinoSim_M = &ArduinoSim_M_;

// Model step function
void ArduinoSim_step(void)
{
  boolean_T varargout_1;
  SL_Bus_ArduinoSim_std_msgs_Float64 rtb_BusAssignment1;
  SL_Bus_ArduinoSim_std_msgs_Float64 rtb_BusAssignment2;
  SL_Bus_ArduinoSim_std_msgs_Float64 rtb_BusAssignment3;
  real_T rtb_y_c_idx_0;
  real_T rtb_y_c_idx_1;
  real_T rtb_y_c_idx_2;
  real_T rtb_y_idx_0;

  // Outputs for Atomic SubSystem: '<S2>/Subscribe1'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  varargout_1 = Sub_ArduinoSim_22.get_latest_msg(&ArduinoSim_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  if (varargout_1) {
    ArduinoSim_B.In1_p = ArduinoSim_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S2>/Subscribe1'

  // Outputs for Atomic SubSystem: '<S2>/Subscribe'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  varargout_1 = Sub_ArduinoSim_2.get_latest_msg(&ArduinoSim_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S8>/In1'

  if (varargout_1) {
    ArduinoSim_B.In1_j = ArduinoSim_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S2>/Subscribe'

  // Outputs for Atomic SubSystem: '<S2>/Subscribe2'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   MATLABSystem: '<S7>/SourceBlock'

  varargout_1 = Sub_ArduinoSim_23.get_latest_msg(&ArduinoSim_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'

  if (varargout_1) {
    ArduinoSim_B.In1 = ArduinoSim_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S2>/Subscribe2'

  // MATLAB Function: '<Root>/Inv_PWM-Mapping' incorporates:
  //   SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport1'

  // MATLAB Function 'Inv_PWM-Mapping': '<S1>:1'
  // '<S1>:1:2'
  rtb_y_c_idx_0 = (ArduinoSim_B.In1_p.Data - 0.0685) / 0.0255;
  rtb_y_c_idx_1 = (ArduinoSim_B.In1_j.Data - 0.0685) / 0.0255;
  rtb_y_c_idx_2 = (ArduinoSim_B.In1.Data - 0.0685) / 0.0255;

  // MATLAB Function: '<Root>/inv_deadzone'
  // MATLAB Function 'inv_deadzone': '<S4>:1'
  // '<S4>:1:3'
  // '<S4>:1:4'
  rtb_y_idx_0 = 0.0;

  // '<S4>:1:4'
  if (rtb_y_c_idx_0 < 0.0) {
    // '<S4>:1:5'
    // '<S4>:1:6'
    rtb_y_idx_0 = (rtb_y_c_idx_0 + 0.15) / 0.8;
  } else {
    if (rtb_y_c_idx_0 > 0.0) {
      // '<S4>:1:7'
      // '<S4>:1:8'
      rtb_y_idx_0 = (rtb_y_c_idx_0 - 0.15) / 0.8;
    }
  }

  // '<S4>:1:4'
  rtb_y_c_idx_0 = 0.0;

  // '<S4>:1:4'
  if (rtb_y_c_idx_1 < 0.0) {
    // '<S4>:1:5'
    // '<S4>:1:6'
    rtb_y_c_idx_0 = (rtb_y_c_idx_1 + 0.15) / 0.8;
  } else {
    if (rtb_y_c_idx_1 > 0.0) {
      // '<S4>:1:7'
      // '<S4>:1:8'
      rtb_y_c_idx_0 = (rtb_y_c_idx_1 - 0.15) / 0.8;
    }
  }

  // '<S4>:1:4'
  rtb_y_c_idx_1 = 0.0;

  // '<S4>:1:4'
  if (rtb_y_c_idx_2 < 0.0) {
    // '<S4>:1:5'
    // '<S4>:1:6'
    rtb_y_c_idx_1 = (rtb_y_c_idx_2 + 0.15) / 0.8;
  } else {
    if (rtb_y_c_idx_2 > 0.0) {
      // '<S4>:1:7'
      // '<S4>:1:8'
      rtb_y_c_idx_1 = (rtb_y_c_idx_2 - 0.15) / 0.8;
    }
  }

  // End of MATLAB Function: '<Root>/inv_deadzone'

  // BusAssignment: '<S3>/Bus Assignment1'
  // '<S4>:1:4'
  rtb_BusAssignment1.Data = rtb_y_idx_0;

  // Outputs for Atomic SubSystem: '<S3>/Publish1'
  // MATLABSystem: '<S12>/SinkBlock'
  Pub_ArduinoSim_153.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<S3>/Publish1'

  // BusAssignment: '<S3>/Bus Assignment2'
  rtb_BusAssignment2.Data = rtb_y_c_idx_0;

  // Outputs for Atomic SubSystem: '<S3>/Publish2'
  // MATLABSystem: '<S13>/SinkBlock'
  Pub_ArduinoSim_156.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<S3>/Publish2'

  // BusAssignment: '<S3>/Bus Assignment3'
  rtb_BusAssignment3.Data = rtb_y_c_idx_1;

  // Outputs for Atomic SubSystem: '<S3>/Publish3'
  // MATLABSystem: '<S14>/SinkBlock'
  Pub_ArduinoSim_158.publish(&rtb_BusAssignment3);

  // End of Outputs for SubSystem: '<S3>/Publish3'
}

// Model initialize function
void ArduinoSim_initialize(void)
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(ArduinoSim_M, (NULL));

  // block I/O
  (void) memset(((void *) &ArduinoSim_B), 0,
                sizeof(B_ArduinoSim_T));

  // states (dwork)
  (void) memset((void *)&ArduinoSim_DW, 0,
                sizeof(DW_ArduinoSim_T));

  {
    static const char_T tmp[6] = { '/', 'P', 'w', 'm', '/', '3' };

    static const char_T tmp_0[6] = { '/', 'P', 'w', 'm', '/', '2' };

    static const char_T tmp_1[6] = { '/', 'P', 'w', 'm', '/', '1' };

    char_T tmp_2[5];
    char_T tmp_3[5];
    char_T tmp_4[5];
    char_T tmp_5[7];
    int32_T i;

    // Start for Atomic SubSystem: '<S2>/Subscribe1'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    ArduinoSim_DW.obj_d.isInitialized = 0;
    ArduinoSim_DW.objisempty_l = true;
    ArduinoSim_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      tmp_5[i] = tmp_1[i];
    }

    tmp_5[6] = '\x00';
    Sub_ArduinoSim_22.create_subscriber(tmp_5, ArduinoSim_MessageQueueLen);

    // End of Start for MATLABSystem: '<S6>/SourceBlock'

    // Start for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S9>/Out1'
    ArduinoSim_B.In1_p = ArduinoSim_P.Out1_Y0_k;

    // End of Start for SubSystem: '<S6>/Enabled Subsystem'
    // End of Start for SubSystem: '<S2>/Subscribe1'

    // Start for Atomic SubSystem: '<S2>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    ArduinoSim_DW.obj_g.isInitialized = 0;
    ArduinoSim_DW.objisempty_h = true;
    ArduinoSim_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      tmp_5[i] = tmp_0[i];
    }

    tmp_5[6] = '\x00';
    Sub_ArduinoSim_2.create_subscriber(tmp_5, ArduinoSim_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'

    // Start for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S8>/Out1'
    ArduinoSim_B.In1_j = ArduinoSim_P.Out1_Y0;

    // End of Start for SubSystem: '<S5>/Enabled Subsystem'
    // End of Start for SubSystem: '<S2>/Subscribe'

    // Start for Atomic SubSystem: '<S2>/Subscribe2'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    ArduinoSim_DW.obj.isInitialized = 0;
    ArduinoSim_DW.objisempty_g = true;
    ArduinoSim_DW.obj.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      tmp_5[i] = tmp[i];
    }

    tmp_5[6] = '\x00';
    Sub_ArduinoSim_23.create_subscriber(tmp_5, ArduinoSim_MessageQueueLen);

    // End of Start for MATLABSystem: '<S7>/SourceBlock'

    // Start for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S10>/Out1'
    ArduinoSim_B.In1 = ArduinoSim_P.Out1_Y0_b;

    // End of Start for SubSystem: '<S7>/Enabled Subsystem'
    // End of Start for SubSystem: '<S2>/Subscribe2'

    // Start for Atomic SubSystem: '<S3>/Publish1'
    // Start for MATLABSystem: '<S12>/SinkBlock'
    ArduinoSim_DW.obj_ij.isInitialized = 0;
    ArduinoSim_DW.objisempty_p = true;
    ArduinoSim_DW.obj_ij.isInitialized = 1;
    tmp_4[0] = '/';
    tmp_4[1] = 'U';
    tmp_4[2] = '/';
    tmp_4[3] = '1';
    tmp_4[4] = '\x00';
    Pub_ArduinoSim_153.create_publisher(tmp_4, ArduinoSim_MessageQueueLen);

    // End of Start for SubSystem: '<S3>/Publish1'

    // Start for Atomic SubSystem: '<S3>/Publish2'
    // Start for MATLABSystem: '<S13>/SinkBlock'
    ArduinoSim_DW.obj_h.isInitialized = 0;
    ArduinoSim_DW.objisempty_i = true;
    ArduinoSim_DW.obj_h.isInitialized = 1;
    tmp_3[0] = '/';
    tmp_3[1] = 'U';
    tmp_3[2] = '/';
    tmp_3[3] = '2';
    tmp_3[4] = '\x00';
    Pub_ArduinoSim_156.create_publisher(tmp_3, ArduinoSim_MessageQueueLen);

    // End of Start for SubSystem: '<S3>/Publish2'

    // Start for Atomic SubSystem: '<S3>/Publish3'
    // Start for MATLABSystem: '<S14>/SinkBlock'
    ArduinoSim_DW.obj_i.isInitialized = 0;
    ArduinoSim_DW.objisempty = true;
    ArduinoSim_DW.obj_i.isInitialized = 1;
    tmp_2[0] = '/';
    tmp_2[1] = 'U';
    tmp_2[2] = '/';
    tmp_2[3] = '3';
    tmp_2[4] = '\x00';
    Pub_ArduinoSim_158.create_publisher(tmp_2, ArduinoSim_MessageQueueLen);

    // End of Start for SubSystem: '<S3>/Publish3'
  }
}

// Model terminate function
void ArduinoSim_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S2>/Subscribe1'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SourceBlock'

  if (ArduinoSim_DW.obj_d.isInitialized == 1) {
    ArduinoSim_DW.obj_d.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S2>/Subscribe'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (ArduinoSim_DW.obj_g.isInitialized == 1) {
    ArduinoSim_DW.obj_g.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe'

  // Terminate for Atomic SubSystem: '<S2>/Subscribe2'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SourceBlock'

  if (ArduinoSim_DW.obj.isInitialized == 1) {
    ArduinoSim_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S3>/Publish1'
  // Start for MATLABSystem: '<S12>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S12>/SinkBlock'

  if (ArduinoSim_DW.obj_ij.isInitialized == 1) {
    ArduinoSim_DW.obj_ij.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S12>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish1'

  // Terminate for Atomic SubSystem: '<S3>/Publish2'
  // Start for MATLABSystem: '<S13>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S13>/SinkBlock'

  if (ArduinoSim_DW.obj_h.isInitialized == 1) {
    ArduinoSim_DW.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S13>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish2'

  // Terminate for Atomic SubSystem: '<S3>/Publish3'
  // Start for MATLABSystem: '<S14>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S14>/SinkBlock'

  if (ArduinoSim_DW.obj_i.isInitialized == 1) {
    ArduinoSim_DW.obj_i.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S14>/SinkBlock'
  // End of Terminate for SubSystem: '<S3>/Publish3'
}

//
// File trailer for generated code.
//
// [EOF]
//
