//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mindistfromscan2.cpp
//
// Code generated for Simulink model 'mindistfromscan2'.
//
// Model version                  : 1.109
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Fri May  6 18:33:58 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "mindistfromscan2.h"
#include "mindistfromscan2_private.h"
#define mindistfromscan_MessageQueueLen (1)

// Block signals (auto storage)
B_mindistfromscan2_T mindistfromscan2_B;

// Block states (auto storage)
DW_mindistfromscan2_T mindistfromscan2_DW;

// Real-time model
RT_MODEL_mindistfromscan2_T mindistfromscan2_M_;
RT_MODEL_mindistfromscan2_T *const mindistfromscan2_M = &mindistfromscan2_M_;

// Model step function
void mindistfromscan2_step(void)
{
  real32_T EtaSet;
  real32_T mtmp;
  int32_T ixstart;
  int32_T ix;
  boolean_T varargout_1;
  SL_Bus_mindistfromscan2_std_msgs_Float32 rtb_BusAssignment3;
  SL_Bus_mindistfromscan2_std_msgs_Float64 rtb_BusAssignment1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  varargout_1 = Sub_mindistfromscan2_416.get_latest_msg
    (&mindistfromscan2_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S7>/In1'

  if (varargout_1) {
    mindistfromscan2_B.In1 = mindistfromscan2_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // MATLAB Function: '<Root>/ReadDist'
  // MATLAB Function 'ReadDist': '<S5>:1'
  // '<S5>:1:2'
  ixstart = 1;
  mtmp = mindistfromscan2_B.In1.Ranges[0];
  if (rtIsNaNF(mindistfromscan2_B.In1.Ranges[0])) {
    ix = 2;
    varargout_1 = false;
    while ((!varargout_1) && (ix < 361)) {
      ixstart = ix;
      if (!rtIsNaNF(mindistfromscan2_B.In1.Ranges[ix - 1])) {
        mtmp = mindistfromscan2_B.In1.Ranges[ix - 1];
        varargout_1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 360) {
    while (ixstart + 1 < 361) {
      if (mindistfromscan2_B.In1.Ranges[ixstart] < mtmp) {
        mtmp = mindistfromscan2_B.In1.Ranges[ixstart];
      }

      ixstart++;
    }
  }

  if (mtmp < 1.0F) {
    // '<S5>:1:3'
    // '<S5>:1:4'
    EtaSet = mtmp - 0.2F;
  } else {
    // '<S5>:1:6'
    EtaSet = 2.0F * mtmp - 1.2F;
  }

  // '<S5>:1:8'
  ixstart = 1;
  if (rtIsNaNF(EtaSet)) {
    ixstart = 2;
    EtaSet = 3.0F;
  }

  if ((ixstart < 2) && (3.0F < EtaSet)) {
    EtaSet = 3.0F;
  }

  // '<S5>:1:9'
  ixstart = 1;
  if (rtIsNaNF(EtaSet)) {
    ixstart = 2;
    EtaSet = 0.1F;
  }

  if ((ixstart < 2) && (0.1F > EtaSet)) {
    EtaSet = 0.1F;
  }

  // BusAssignment: '<Root>/Bus Assignment3' incorporates:
  //   MATLAB Function: '<Root>/ReadDist'

  rtb_BusAssignment3.Data = mtmp;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_mindistfromscan2_413.publish(&rtb_BusAssignment3);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   MATLAB Function: '<Root>/ReadDist'

  rtb_BusAssignment1.Data = EtaSet;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_mindistfromscan2_414.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish2'
}

// Model initialize function
void mindistfromscan2_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(mindistfromscan2_M, (NULL));

  // block I/O
  (void) memset(((void *) &mindistfromscan2_B), 0,
                sizeof(B_mindistfromscan2_T));

  // states (dwork)
  (void) memset((void *)&mindistfromscan2_DW, 0,
                sizeof(DW_mindistfromscan2_T));

  {
    static const char_T tmp[15] = { '/', 'E', 't', 'a', 'S', 'e', 't', 'D', 'i',
      's', 't', 'a', 'n', 'c', 'e' };

    static const char_T tmp_0[13] = { '/', 'S', 'c', 'a', 'n', 'D', 'i', 's',
      't', 'a', 'n', 'c', 'e' };

    static const char_T tmp_1[5] = { '/', 's', 'c', 'a', 'n' };

    char_T tmp_2[16];
    char_T tmp_3[14];
    char_T tmp_4[6];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    mindistfromscan2_DW.obj_c.isInitialized = 0;
    mindistfromscan2_DW.objisempty = true;
    mindistfromscan2_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[5] = '\x00';
    Sub_mindistfromscan2_416.create_subscriber(tmp_4,
      mindistfromscan_MessageQueueLen);

    // End of Start for MATLABSystem: '<S6>/SourceBlock'

    // Start for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S7>/Out1'
    mindistfromscan2_B.In1 = mindistfromscan2_P.Out1_Y0;

    // End of Start for SubSystem: '<S6>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe1'

    // Start for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    mindistfromscan2_DW.obj_k.isInitialized = 0;
    mindistfromscan2_DW.objisempty_fg = true;
    mindistfromscan2_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[13] = '\x00';
    Pub_mindistfromscan2_413.create_publisher(tmp_3,
      mindistfromscan_MessageQueueLen);

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish1'

    // Start for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    mindistfromscan2_DW.obj.isInitialized = 0;
    mindistfromscan2_DW.objisempty_f = true;
    mindistfromscan2_DW.obj.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[15] = '\x00';
    Pub_mindistfromscan2_414.create_publisher(tmp_2,
      mindistfromscan_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish2'
  }
}

// Model terminate function
void mindistfromscan2_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SourceBlock'

  if (mindistfromscan2_DW.obj_c.isInitialized == 1) {
    mindistfromscan2_DW.obj_c.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Start for MATLABSystem: '<S3>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SinkBlock'

  if (mindistfromscan2_DW.obj_k.isInitialized == 1) {
    mindistfromscan2_DW.obj_k.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Start for MATLABSystem: '<S4>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SinkBlock'

  if (mindistfromscan2_DW.obj.isInitialized == 1) {
    mindistfromscan2_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
