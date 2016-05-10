//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etasetgett.cpp
//
// Code generated for Simulink model 'etasetgett'.
//
// Model version                  : 1.60
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Fri Apr 29 12:52:27 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "etasetgett.h"
#include "etasetgett_private.h"
#define etasetgett_MessageQueueLen     (1)

// Block signals (auto storage)
B_etasetgett_T etasetgett_B;

// Block states (auto storage)
DW_etasetgett_T etasetgett_DW;

// Real-time model
RT_MODEL_etasetgett_T etasetgett_M_;
RT_MODEL_etasetgett_T *const etasetgett_M = &etasetgett_M_;

// Model step function
void etasetgett_step(void)
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

  varargout_1 = Sub_etasetgett_370.get_latest_msg(&etasetgett_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S2>/Enable'

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'
  //   Inport: '<S4>/In1'
  //   MATLABSystem: '<S7>/SourceBlock'

  if (varargout_1) {
    etasetgett_B.In1_k = etasetgett_B.varargout_2_m;

    // Outputs for Atomic SubSystem: '<S2>/Subscribe'
    // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
    //   Inport: '<S4>/In1'
    //   MATLABSystem: '<S7>/SourceBlock'

    varargout_1 = Sub_etasetgett_365.get_latest_msg(&etasetgett_B.varargout_2);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    if (varargout_1) {
      etasetgett_B.In1 = etasetgett_B.varargout_2;
    }

    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S2>/Subscribe'

    // SignalConversion: '<S6>/TmpSignal ConversionAt SFunction Inport2' incorporates:
    //   Constant: '<S1>/Constant'
    //   Inport: '<S10>/In1'
    //   MATLAB Function: '<S2>/MATLAB Function'
    //   MATLABSystem: '<S7>/SourceBlock'

    rtb_TmpSignalConversionAtSFunct[0] = etasetgett_B.In1_k.X;
    rtb_TmpSignalConversionAtSFunct[1] = etasetgett_B.In1_k.Y;
    rtb_TmpSignalConversionAtSFunct[2] = etasetgett_P.Constant_Value_o;

    // MATLAB Function: '<S2>/MATLAB Function'
    // MATLAB Function 'Subsystem1/MATLAB Function': '<S6>:1'
    // save('EtaTolistSTUFF')
    // '<S6>:1:3'
    // '<S6>:1:6'
    // save('TESTlist2Eta')
    // '<S6>:1:9'
    for (ix = 0; ix < 128; ix++) {
      etasetgett_B.Values[ix] = etasetgett_B.In1.Data[ix];
      etasetgett_B.Values[ix + 128] = etasetgett_B.In1.Data[128 + ix];
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
      iy = ix << 7;
      for (i = 0; i < 128; i++) {
        etasetgett_B.b[iy + i] = rtb_TmpSignalConversionAtSFunct[1 - ix];
      }
    }

    for (ix = 0; ix < 256; ix++) {
      mtmp = (real32_T)fabs((real_T)(etasetgett_B.Values[ix] - (real32_T)
        etasetgett_B.b[ix]));
      etasetgett_B.x[ix] = mtmp * mtmp;
    }

    for (ix = 0; ix < 128; ix++) {
      etasetgett_B.b_x[ix << 1] = etasetgett_B.x[ix];
      etasetgett_B.b_x[1 + (ix << 1)] = etasetgett_B.x[ix + 128];
    }

    ix = 0;
    iy = -1;
    for (i = 0; i < 128; i++) {
      ixstart = ix;
      ix += 2;
      iy++;
      etasetgett_B.b_y[iy] = etasetgett_B.b_x[ixstart + 1] +
        etasetgett_B.b_x[ixstart];
    }

    ix = 1;
    mtmp = etasetgett_B.b_y[0];
    iy = -2;
    if (rtIsNaNF(etasetgett_B.b_y[0])) {
      i = 2;
      varargout_1 = false;
      while ((!varargout_1) && (i < 129)) {
        ix = i;
        if (!rtIsNaNF(etasetgett_B.b_y[i - 1])) {
          mtmp = etasetgett_B.b_y[i - 1];
          iy = i - 3;
          varargout_1 = true;
        } else {
          i++;
        }
      }
    }

    if (ix < 128) {
      while (ix + 1 < 129) {
        if (etasetgett_B.b_y[ix] < mtmp) {
          mtmp = etasetgett_B.b_y[ix];
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
    etasetgett_B.BusAssignment1.X = etasetgett_B.Values[ix + 127];
    etasetgett_B.BusAssignment1.Y = etasetgett_B.Values[ix - 1];
    etasetgett_B.BusAssignment1.Z = etasetgett_P.Constant_Value_ga;

    // Outputs for Atomic SubSystem: '<S5>/Publish1'
    // MATLABSystem: '<S9>/SinkBlock'
    Pub_etasetgett_363.publish(&etasetgett_B.BusAssignment1);

    // End of Outputs for SubSystem: '<S5>/Publish1'
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  // End of Outputs for SubSystem: '<S1>/Subscribe2'
}

// Model initialize function
void etasetgett_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(etasetgett_M, (NULL));

  // block I/O
  (void) memset(((void *) &etasetgett_B), 0,
                sizeof(B_etasetgett_T));

  // states (dwork)
  (void) memset((void *)&etasetgett_DW, 0,
                sizeof(DW_etasetgett_T));

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
    etasetgett_DW.obj_j.isInitialized = 0;
    etasetgett_DW.objisempty_a = true;
    etasetgett_DW.obj_j.isInitialized = 1;
    tmp_3[0] = '/';
    tmp_3[1] = 'E';
    tmp_3[2] = 't';
    tmp_3[3] = 'a';
    tmp_3[4] = '\x00';
    Sub_etasetgett_370.create_subscriber(tmp_3, etasetgett_MessageQueueLen);

    // Start for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S4>/Out1'
    etasetgett_B.In1_k = etasetgett_P.Out1_Y0_g;

    // End of Start for SubSystem: '<S3>/Enabled Subsystem'
    // End of Start for SubSystem: '<S1>/Subscribe2'

    // Start for Enabled SubSystem: '<Root>/Subsystem1'
    // Start for Atomic SubSystem: '<S2>/Subscribe'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    etasetgett_DW.obj.isInitialized = 0;
    etasetgett_DW.objisempty = true;
    etasetgett_DW.obj.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_2[i] = tmp_0[i];
    }

    tmp_2[11] = '\x00';
    Sub_etasetgett_365.create_subscriber(tmp_2, etasetgett_MessageQueueLen);

    // End of Start for MATLABSystem: '<S7>/SourceBlock'

    // Start for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S10>/Out1'
    etasetgett_B.In1 = etasetgett_P.Out1_Y0;

    // End of Start for SubSystem: '<S7>/Enabled Subsystem'
    // End of Start for SubSystem: '<S2>/Subscribe'

    // Start for Atomic SubSystem: '<S5>/Publish1'
    // Start for MATLABSystem: '<S9>/SinkBlock'
    etasetgett_DW.obj_jp.isInitialized = 0;
    etasetgett_DW.objisempty_l = true;
    etasetgett_DW.obj_jp.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      tmp_1[i] = tmp[i];
    }

    tmp_1[7] = '\x00';
    Pub_etasetgett_363.create_publisher(tmp_1, etasetgett_MessageQueueLen);

    // End of Start for MATLABSystem: '<S9>/SinkBlock'
    // End of Start for SubSystem: '<S5>/Publish1'
    // End of Start for SubSystem: '<Root>/Subsystem1'
  }
}

// Model terminate function
void etasetgett_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S1>/Subscribe2'
  // Start for MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S3>/SourceBlock'

  if (etasetgett_DW.obj_j.isInitialized == 1) {
    etasetgett_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<S1>/Subscribe2'

  // Terminate for Enabled SubSystem: '<Root>/Subsystem1'
  // Terminate for Atomic SubSystem: '<S2>/Subscribe'
  // Start for MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S7>/SourceBlock'

  if (etasetgett_DW.obj.isInitialized == 1) {
    etasetgett_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe'

  // Terminate for Atomic SubSystem: '<S5>/Publish1'
  // Start for MATLABSystem: '<S9>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S9>/SinkBlock'

  if (etasetgett_DW.obj_jp.isInitialized == 1) {
    etasetgett_DW.obj_jp.isInitialized = 2;
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
