//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Q2PAll.cpp
//
// Code generated for Simulink model 'Q2PAll'.
//
// Model version                  : 1.66
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Apr 20 14:43:07 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Q2PAll.h"
#include "Q2PAll_private.h"
#define Q2PAll_MessageQueueLen         (1)

// Block signals (auto storage)
B_Q2PAll_T Q2PAll_B;

// Block states (auto storage)
DW_Q2PAll_T Q2PAll_DW;

// Real-time model
RT_MODEL_Q2PAll_T Q2PAll_M_;
RT_MODEL_Q2PAll_T *const Q2PAll_M = &Q2PAll_M_;
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
void Q2PAll_step(void)
{
  boolean_T varargout_1;
  real_T rtb_fcn5;
  real_T rtb_Product1_g;
  real_T rtb_Product2_o;
  real_T rtb_fcn4;
  real_T rtb_VectorConcatenate_idx_0;
  real_T u0;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   MATLABSystem: '<S4>/SourceBlock'

  varargout_1 = Sub_Q2PAll_82.get_latest_msg(&Q2PAll_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S12>/In1'

  if (varargout_1) {
    Q2PAll_B.In1 = Q2PAll_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // BusAssignment: '<S1>/Bus Assignment1'
  Q2PAll_B.BusAssignment1.X = Q2PAll_B.In1.Position.X;
  Q2PAll_B.BusAssignment1.Y = Q2PAll_B.In1.Position.Y;
  Q2PAll_B.BusAssignment1.Z = Q2PAll_B.In1.Position.Z;

  // Outputs for Atomic SubSystem: '<S1>/Publish1'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_Q2PAll_73.publish(&Q2PAll_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S1>/Publish1'

  // Sqrt: '<S10>/sqrt' incorporates:
  //   Product: '<S11>/Product'
  //   Product: '<S11>/Product1'
  //   Product: '<S11>/Product2'
  //   Product: '<S11>/Product3'
  //   Sum: '<S11>/Sum'

  Q2PAll_B.Product3_m = sqrt(((Q2PAll_B.In1.Orientation.X *
    Q2PAll_B.In1.Orientation.X + Q2PAll_B.In1.Orientation.Y *
    Q2PAll_B.In1.Orientation.Y) + Q2PAll_B.In1.Orientation.Z *
    Q2PAll_B.In1.Orientation.Z) + Q2PAll_B.In1.Orientation.W *
    Q2PAll_B.In1.Orientation.W);

  // Product: '<S9>/Product'
  rtb_fcn5 = Q2PAll_B.In1.Orientation.X / Q2PAll_B.Product3_m;

  // Product: '<S9>/Product1'
  rtb_Product1_g = Q2PAll_B.In1.Orientation.Y / Q2PAll_B.Product3_m;

  // Product: '<S9>/Product2'
  rtb_Product2_o = Q2PAll_B.In1.Orientation.Z / Q2PAll_B.Product3_m;

  // Product: '<S9>/Product3'
  Q2PAll_B.Product3_m = Q2PAll_B.In1.Orientation.W / Q2PAll_B.Product3_m;

  // Trigonometry: '<S3>/Trigonometric Function1' incorporates:
  //   Fcn: '<S3>/fcn1'
  //   Fcn: '<S3>/fcn2'

  rtb_VectorConcatenate_idx_0 = rt_atan2d_snf((rtb_Product1_g * rtb_Product2_o +
    rtb_fcn5 * Q2PAll_B.Product3_m) * 2.0, ((rtb_fcn5 * rtb_fcn5 +
    rtb_Product1_g * rtb_Product1_g) - rtb_Product2_o * rtb_Product2_o) -
    Q2PAll_B.Product3_m * Q2PAll_B.Product3_m);

  // Fcn: '<S3>/fcn3'
  u0 = (rtb_Product1_g * Q2PAll_B.Product3_m - rtb_fcn5 * rtb_Product2_o) * -2.0;

  // Fcn: '<S3>/fcn4'
  rtb_fcn4 = (rtb_Product2_o * Q2PAll_B.Product3_m + rtb_fcn5 * rtb_Product1_g) *
    2.0;

  // Fcn: '<S3>/fcn5'
  rtb_fcn5 = ((rtb_fcn5 * rtb_fcn5 - rtb_Product1_g * rtb_Product1_g) -
              rtb_Product2_o * rtb_Product2_o) + Q2PAll_B.Product3_m *
    Q2PAll_B.Product3_m;

  // BusAssignment: '<S2>/Bus Assignment1'
  Q2PAll_B.BusAssignment1_i.X = rtb_VectorConcatenate_idx_0;

  // Trigonometry: '<S3>/trigFcn'
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  // BusAssignment: '<S2>/Bus Assignment1' incorporates:
  //   Trigonometry: '<S3>/Trigonometric Function3'
  //   Trigonometry: '<S3>/trigFcn'

  Q2PAll_B.BusAssignment1_i.Y = asin(u0);
  Q2PAll_B.BusAssignment1_i.Z = rt_atan2d_snf(rtb_fcn4, rtb_fcn5);

  // Outputs for Atomic SubSystem: '<S2>/Publish1'
  // MATLABSystem: '<S8>/SinkBlock'
  Pub_Q2PAll_100.publish(&Q2PAll_B.BusAssignment1_i);

  // End of Outputs for SubSystem: '<S2>/Publish1'
}

// Model initialize function
void Q2PAll_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(Q2PAll_M, (NULL));

  // block I/O
  (void) memset(((void *) &Q2PAll_B), 0,
                sizeof(B_Q2PAll_T));

  // states (dwork)
  (void) memset((void *)&Q2PAll_DW, 0,
                sizeof(DW_Q2PAll_T));

  {
    static const char_T tmp[9] = { '/', 'E', 'u', 'l', 'e', 'r', 'A', 'n', 'g' };

    static const char_T tmp_0[16] = { '/', 'q', 'u', 'a', 'l', 'i', 's', 'y',
      's', '/', 'S', 'a', 'u', 'c', 'e', 'r' };

    char_T tmp_1[10];
    char_T tmp_2[5];
    char_T tmp_3[17];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe2'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    Q2PAll_DW.obj_h.isInitialized = 0;
    Q2PAll_DW.objisempty = true;
    Q2PAll_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[16] = '\x00';
    Sub_Q2PAll_82.create_subscriber(tmp_3, Q2PAll_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SourceBlock'

    // Start for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S12>/Out1'
    Q2PAll_B.In1 = Q2PAll_P.Out1_Y0;

    // End of Start for SubSystem: '<S4>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe2'

    // Start for Atomic SubSystem: '<S1>/Publish1'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    Q2PAll_DW.obj_l.isInitialized = 0;
    Q2PAll_DW.objisempty_a = true;
    Q2PAll_DW.obj_l.isInitialized = 1;
    tmp_2[0] = '/';
    tmp_2[1] = 'E';
    tmp_2[2] = 't';
    tmp_2[3] = 'a';
    tmp_2[4] = '\x00';
    Pub_Q2PAll_73.create_publisher(tmp_2, Q2PAll_MessageQueueLen);

    // End of Start for SubSystem: '<S1>/Publish1'

    // Start for Atomic SubSystem: '<S2>/Publish1'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    Q2PAll_DW.obj.isInitialized = 0;
    Q2PAll_DW.objisempty_k = true;
    Q2PAll_DW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_1[i] = tmp[i];
    }

    tmp_1[9] = '\x00';
    Pub_Q2PAll_100.create_publisher(tmp_1, Q2PAll_MessageQueueLen);

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of Start for SubSystem: '<S2>/Publish1'
  }
}

// Model terminate function
void Q2PAll_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (Q2PAll_DW.obj_h.isInitialized == 1) {
    Q2PAll_DW.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S1>/Publish1'
  // Start for MATLABSystem: '<S6>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SinkBlock'

  if (Q2PAll_DW.obj_l.isInitialized == 1) {
    Q2PAll_DW.obj_l.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish1'

  // Terminate for Atomic SubSystem: '<S2>/Publish1'
  // Start for MATLABSystem: '<S8>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SinkBlock'

  if (Q2PAll_DW.obj.isInitialized == 1) {
    Q2PAll_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
