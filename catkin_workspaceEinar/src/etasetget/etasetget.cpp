//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etasetget.cpp
//
// Code generated for Simulink model 'etasetget'.
//
// Model version                  : 1.33
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sat Apr 16 18:54:16 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "etasetget.h"
#include "etasetget_private.h"
#define etasetget_MessageQueueLen      (1)

// Block signals (auto storage)
B_etasetget_T etasetget_B;

// Block states (auto storage)
DW_etasetget_T etasetget_DW;

// Real-time model
RT_MODEL_etasetget_T etasetget_M_;
RT_MODEL_etasetget_T *const etasetget_M = &etasetget_M_;

// Model step function
void etasetget_step(void)
{
  int32_T ix;
  int32_T iy;
  int32_T ixstart;
  int32_T i;
  real32_T mtmp;
  boolean_T varargout_1;
  real_T rtb_TmpSignalConversionAtSFunct[3];
  int8_T varargin_1_idx_1;

  // Outputs for Atomic SubSystem: '<S1>/Subscribe2'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   MATLABSystem: '<S3>/SourceBlock'

  varargout_1 = Sub_etasetget_370.get_latest_msg(&etasetget_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'
  //   Inport: '<S4>/In1'
  //   MATLABSystem: '<S7>/SourceBlock'

  if (varargout_1) {
    etasetget_B.In1_k = etasetget_B.varargout_2_m;

    // Outputs for Atomic SubSystem: '<S2>/Subscribe'
    // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
    //   Inport: '<S4>/In1'
    //   MATLABSystem: '<S7>/SourceBlock'

    varargout_1 = Sub_etasetget_365.get_latest_msg(&etasetget_B.varargout_2);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    if (varargout_1) {
      etasetget_B.In1 = etasetget_B.varargout_2;
    }

    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S2>/Subscribe'

    // SignalConversion: '<S6>/TmpSignal ConversionAt SFunction Inport2' incorporates:
    //   Constant: '<S1>/Constant'
    //   Inport: '<S10>/In1'
    //   MATLAB Function: '<S2>/MATLAB Function'
    //   MATLABSystem: '<S7>/SourceBlock'

    rtb_TmpSignalConversionAtSFunct[0] = etasetget_B.In1_k.X;
    rtb_TmpSignalConversionAtSFunct[1] = etasetget_B.In1_k.Y;
    rtb_TmpSignalConversionAtSFunct[2] = etasetget_P.Constant_Value_o;

    // MATLAB Function: '<S2>/MATLAB Function'
    // MATLAB Function 'Subsystem1/MATLAB Function': '<S6>:1'
    // save('EtaTolistSTUFF')
    // '<S6>:1:3'
    // '<S6>:1:6'
    // save('TESTlist2Eta')
    // '<S6>:1:9'
    for (ix = 0; ix < 64; ix++) {
      etasetget_B.Values[ix] = etasetget_B.In1.Data[ix];
      etasetget_B.Values[ix + 64] = etasetget_B.In1.Data[64 + ix];
    }

    // '<S6>:1:10'
    // for i=1:64
    // AvstandDummy=(eta(1)-Values(i,1))^2+(eta(2)-Values(i,2))^2;
    //  if AvstandDummy<AvstandSaved
    //      AvstandDummy=AvstandSaved;
    //  NearestPointPos=i;
    //  end
    // end
    for (ix = 0; ix < 2; ix++) {
      iy = ix << 6;
      for (i = 0; i < 64; i++) {
        etasetget_B.b[iy + i] = rtb_TmpSignalConversionAtSFunct[1 - ix];
      }
    }

    for (ix = 0; ix < 128; ix++) {
      mtmp = (real32_T)fabs((real_T)(etasetget_B.Values[ix] - (real32_T)
        etasetget_B.b[ix]));
      etasetget_B.x[ix] = mtmp * mtmp;
    }

    for (ix = 0; ix < 64; ix++) {
      etasetget_B.b_x[ix << 1] = etasetget_B.x[ix];
      etasetget_B.b_x[1 + (ix << 1)] = etasetget_B.x[ix + 64];
    }

    ix = 0;
    iy = -1;
    for (i = 0; i < 64; i++) {
      ixstart = ix;
      ix += 2;
      iy++;
      etasetget_B.b_y[iy] = etasetget_B.b_x[ixstart + 1] +
        etasetget_B.b_x[ixstart];
    }

    ix = 1;
    mtmp = etasetget_B.b_y[0];
    iy = -2;
    if (rtIsNaNF(etasetget_B.b_y[0])) {
      i = 2;
      varargout_1 = false;
      while ((!varargout_1) && (i < 65)) {
        ix = i;
        if (!rtIsNaNF(etasetget_B.b_y[i - 1])) {
          mtmp = etasetget_B.b_y[i - 1];
          iy = i - 3;
          varargout_1 = true;
        } else {
          i++;
        }
      }
    }

    if (ix < 64) {
      while (ix + 1 < 65) {
        if (etasetget_B.b_y[ix] < mtmp) {
          mtmp = etasetget_B.b_y[ix];
          iy = ix - 2;
        }

        ix++;
      }
    }

    // '<S6>:1:30'
    varargin_1_idx_1 = (int8_T)iy;
    ix = 1;
    if (varargin_1_idx_1 > 1) {
      ix = varargin_1_idx_1;
    }

    // BusAssignment: '<S5>/Bus Assignment1' incorporates:
    //   Constant: '<S5>/Constant'
    //   MATLAB Function: '<S2>/MATLAB Function'

    // '<S6>:1:31'
    // '<S6>:1:32'
    // etaset = u;11
    etasetget_B.BusAssignment1.X = etasetget_B.Values[ix + 63];
    etasetget_B.BusAssignment1.Y = etasetget_B.Values[ix - 1];
    etasetget_B.BusAssignment1.Z = etasetget_P.Constant_Value_ga;

    // Outputs for Atomic SubSystem: '<S5>/Publish1'
    // MATLABSystem: '<S9>/SinkBlock'
    Pub_etasetget_363.publish(&etasetget_B.BusAssignment1);

    // End of Outputs for SubSystem: '<S5>/Publish1'
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  // End of Outputs for SubSystem: '<S1>/Subscribe2'
}

// Model initialize function
void etasetget_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(etasetget_M, (NULL));

  // block I/O
  (void) memset(((void *) &etasetget_B), 0,
                sizeof(B_etasetget_T));

  // states (dwork)
  (void) memset((void *)&etasetget_DW, 0,
                sizeof(DW_etasetget_T));

  {
    static const char_T tmp[7] = { '/', 'E', 't', 'a', 'S', 'e', 't' };

    static const char_T tmp_0[11] = { '/', 'E', 't', 'a', 'S', 'e', 't', 'L',
      'i', 's', 't' };

    char_T tmp_1[8];
    char_T tmp_2[12];
    char_T tmp_3[5];
    int32_T i;

    // Start for Atomic SubSystem: '<S1>/Subscribe2'
    // Start for MATLABSystem: '<S3>/SourceBlock'
    etasetget_DW.obj_j.isInitialized = 0;
    etasetget_DW.objisempty_a = true;
    etasetget_DW.obj_j.isInitialized = 1;
    tmp_3[0] = '/';
    tmp_3[1] = 'E';
    tmp_3[2] = 't';
    tmp_3[3] = 'a';
    tmp_3[4] = '\x00';
    Sub_etasetget_370.create_subscriber(tmp_3, etasetget_MessageQueueLen);

    // Start for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S4>/Out1'
    etasetget_B.In1_k = etasetget_P.Out1_Y0_g;

    // End of Start for SubSystem: '<S3>/Enabled Subsystem'
    // End of Start for SubSystem: '<S1>/Subscribe2'

    // Start for Enabled SubSystem: '<Root>/Subsystem1'
    // Start for Atomic SubSystem: '<S2>/Subscribe'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    etasetget_DW.obj.isInitialized = 0;
    etasetget_DW.objisempty = true;
    etasetget_DW.obj.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_2[i] = tmp_0[i];
    }

    tmp_2[11] = '\x00';
    Sub_etasetget_365.create_subscriber(tmp_2, etasetget_MessageQueueLen);

    // End of Start for MATLABSystem: '<S7>/SourceBlock'

    // Start for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S10>/Out1'
    etasetget_B.In1 = etasetget_P.Out1_Y0;

    // End of Start for SubSystem: '<S7>/Enabled Subsystem'
    // End of Start for SubSystem: '<S2>/Subscribe'

    // Start for Atomic SubSystem: '<S5>/Publish1'
    // Start for MATLABSystem: '<S9>/SinkBlock'
    etasetget_DW.obj_jp.isInitialized = 0;
    etasetget_DW.objisempty_l = true;
    etasetget_DW.obj_jp.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      tmp_1[i] = tmp[i];
    }

    tmp_1[7] = '\x00';
    Pub_etasetget_363.create_publisher(tmp_1, etasetget_MessageQueueLen);

    // End of Start for MATLABSystem: '<S9>/SinkBlock'
    // End of Start for SubSystem: '<S5>/Publish1'
    // End of Start for SubSystem: '<Root>/Subsystem1'
  }
}

// Model terminate function
void etasetget_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S1>/Subscribe2'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SourceBlock'

  if (etasetget_DW.obj_j.isInitialized == 1) {
    etasetget_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<S1>/Subscribe2'

  // Terminate for Enabled SubSystem: '<Root>/Subsystem1'
  // Terminate for Atomic SubSystem: '<S2>/Subscribe'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SourceBlock'

  if (etasetget_DW.obj.isInitialized == 1) {
    etasetget_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe'

  // Terminate for Atomic SubSystem: '<S5>/Publish1'
  // Start for MATLABSystem: '<S9>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S9>/SinkBlock'

  if (etasetget_DW.obj_jp.isInitialized == 1) {
    etasetget_DW.obj_jp.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S9>/SinkBlock'
  // End of Terminate for SubSystem: '<S5>/Publish1'
  // End of Terminate for SubSystem: '<Root>/Subsystem1'
}

//
// File trailer for generated code.
//
// [EOF]
//
