//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hector2P2.cpp
//
// Code generated for Simulink model 'Hector2P2'.
//
// Model version                  : 1.66
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Tue Apr 19 10:15:10 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Hector2P2.h"
#include "Hector2P2_private.h"
#define Hector2P2_MessageQueueLen      (1)

// Block signals (auto storage)
B_Hector2P2_T Hector2P2_B;

// Block states (auto storage)
DW_Hector2P2_T Hector2P2_DW;

// Real-time model
RT_MODEL_Hector2P2_T Hector2P2_M_;
RT_MODEL_Hector2P2_T *const Hector2P2_M = &Hector2P2_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Model step function
void Hector2P2_step(void)
{
  boolean_T varargout_1;
  real_T rtb_Product3_k;
  real_T rtb_fcn5;
  real_T rtb_Product1_g;
  real_T rtb_Product2_o;
  real_T rtb_Add2;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   MATLABSystem: '<S3>/SourceBlock'

  varargout_1 = Sub_Hector2P2_82.get_latest_msg(&Hector2P2_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'

  if (varargout_1) {
    Hector2P2_B.In1 = Hector2P2_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // Outputs for Atomic SubSystem: '<S4>/Subscribe2'
  // Start for MATLABSystem: '<S11>/SourceBlock' incorporates:
  //   MATLABSystem: '<S11>/SourceBlock'

  varargout_1 = Sub_Hector2P2_89.get_latest_msg(&Hector2P2_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  // MATLABSystem: '<S11>/SourceBlock' incorporates:
  //   Inport: '<S12>/In1'

  if (varargout_1) {
    Hector2P2_B.In1_b = Hector2P2_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S11>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<S4>/Subscribe2'

  // Sqrt: '<S8>/sqrt' incorporates:
  //   Product: '<S9>/Product'
  //   Product: '<S9>/Product1'
  //   Product: '<S9>/Product2'
  //   Product: '<S9>/Product3'
  //   Sum: '<S9>/Sum'

  rtb_Product3_k = sqrt(((Hector2P2_B.In1.Pose.Pose.Orientation.X *
    Hector2P2_B.In1.Pose.Pose.Orientation.X +
    Hector2P2_B.In1.Pose.Pose.Orientation.Y *
    Hector2P2_B.In1.Pose.Pose.Orientation.Y) +
    Hector2P2_B.In1.Pose.Pose.Orientation.Z *
    Hector2P2_B.In1.Pose.Pose.Orientation.Z) +
                        Hector2P2_B.In1.Pose.Pose.Orientation.W *
                        Hector2P2_B.In1.Pose.Pose.Orientation.W);

  // Product: '<S7>/Product'
  rtb_fcn5 = Hector2P2_B.In1.Pose.Pose.Orientation.X / rtb_Product3_k;

  // Product: '<S7>/Product1'
  rtb_Product1_g = Hector2P2_B.In1.Pose.Pose.Orientation.Y / rtb_Product3_k;

  // Product: '<S7>/Product2'
  rtb_Product2_o = Hector2P2_B.In1.Pose.Pose.Orientation.Z / rtb_Product3_k;

  // Product: '<S7>/Product3'
  rtb_Product3_k = Hector2P2_B.In1.Pose.Pose.Orientation.W / rtb_Product3_k;

  // Fcn: '<S2>/fcn4'
  rtb_Add2 = (rtb_Product2_o * rtb_Product3_k + rtb_fcn5 * rtb_Product1_g) * 2.0;

  // Fcn: '<S2>/fcn5'
  rtb_fcn5 = ((rtb_fcn5 * rtb_fcn5 - rtb_Product1_g * rtb_Product1_g) -
              rtb_Product2_o * rtb_Product2_o) + rtb_Product3_k * rtb_Product3_k;

  // BusAssignment: '<S1>/Bus Assignment1' incorporates:
  //   Gain: '<Root>/Gain'
  //   Gain: '<Root>/Gain1'
  //   Sum: '<Root>/Add'
  //   Sum: '<Root>/Add1'
  //   Sum: '<Root>/Add2'
  //   Trigonometry: '<S2>/Trigonometric Function3'

  Hector2P2_B.BusAssignment1.X = Hector2P2_B.In1.Pose.Pose.Position.X -
    Hector2P2_B.In1_b.X;
  Hector2P2_B.BusAssignment1.Y = Hector2P2_P.Gain_Gain *
    Hector2P2_B.In1.Pose.Pose.Position.Y - Hector2P2_B.In1_b.Y;
  Hector2P2_B.BusAssignment1.Z = Hector2P2_P.Gain1_Gain * rt_atan2d_snf(rtb_Add2,
    rtb_fcn5) - Hector2P2_B.In1_b.Z;

  // Outputs for Atomic SubSystem: '<S1>/Publish1'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_Hector2P2_73.publish(&Hector2P2_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S1>/Publish1'
}

// Model initialize function
void Hector2P2_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(Hector2P2_M, (NULL));

  // block I/O
  (void) memset(((void *) &Hector2P2_B), 0,
                sizeof(B_Hector2P2_T));

  // states (dwork)
  (void) memset((void *)&Hector2P2_DW, 0,
                sizeof(DW_Hector2P2_T));

  {
    static const char_T tmp[12] = { '/', 'E', 't', 'a', 'C', 'o', 'o', 'r', 'd',
      'S', 'e', 't' };

    static const char_T tmp_0[11] = { '/', 'p', 'o', 's', 'e', 'u', 'p', 'd',
      'a', 't', 'e' };

    char_T tmp_1[5];
    char_T tmp_2[13];
    char_T tmp_3[12];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe2'
    // Start for MATLABSystem: '<S3>/SourceBlock'
    Hector2P2_DW.obj_h.isInitialized = 0;
    Hector2P2_DW.objisempty_j = true;
    Hector2P2_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[11] = '\x00';
    Sub_Hector2P2_82.create_subscriber(tmp_3, Hector2P2_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SourceBlock'

    // Start for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S10>/Out1'
    Hector2P2_B.In1 = Hector2P2_P.Out1_Y0;

    // End of Start for SubSystem: '<S3>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe2'

    // Start for Atomic SubSystem: '<S4>/Subscribe2'
    // Start for MATLABSystem: '<S11>/SourceBlock'
    Hector2P2_DW.obj_j.isInitialized = 0;
    Hector2P2_DW.objisempty = true;
    Hector2P2_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[12] = '\x00';
    Sub_Hector2P2_89.create_subscriber(tmp_2, Hector2P2_MessageQueueLen);

    // End of Start for MATLABSystem: '<S11>/SourceBlock'

    // Start for Enabled SubSystem: '<S11>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S12>/Out1'
    Hector2P2_B.In1_b = Hector2P2_P.Out1_Y0_g;

    // End of Start for SubSystem: '<S11>/Enabled Subsystem'
    // End of Start for SubSystem: '<S4>/Subscribe2'

    // Start for Atomic SubSystem: '<S1>/Publish1'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    Hector2P2_DW.obj.isInitialized = 0;
    Hector2P2_DW.objisempty_a = true;
    Hector2P2_DW.obj.isInitialized = 1;
    tmp_1[0] = '/';
    tmp_1[1] = 'E';
    tmp_1[2] = 't';
    tmp_1[3] = 'a';
    tmp_1[4] = '\x00';
    Pub_Hector2P2_73.create_publisher(tmp_1, Hector2P2_MessageQueueLen);

    // End of Start for SubSystem: '<S1>/Publish1'
  }
}

// Model terminate function
void Hector2P2_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SourceBlock'

  if (Hector2P2_DW.obj_h.isInitialized == 1) {
    Hector2P2_DW.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S4>/Subscribe2'
  // Start for MATLABSystem: '<S11>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S11>/SourceBlock'

  if (Hector2P2_DW.obj_j.isInitialized == 1) {
    Hector2P2_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S11>/SourceBlock'
  // End of Terminate for SubSystem: '<S4>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S1>/Publish1'
  // Start for MATLABSystem: '<S6>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SinkBlock'

  if (Hector2P2_DW.obj.isInitialized == 1) {
    Hector2P2_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
