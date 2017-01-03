//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Path2SetPoint.cpp
//
// Code generated for Simulink model 'Path2SetPoint'.
//
// Model version                  : 1.127
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Jun 22 12:52:02 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Path2SetPoint.h"
#include "Path2SetPoint_private.h"
#define Path2SetPoint_MessageQueueLen  (1)

// Block signals (auto storage)
B_Path2SetPoint_T Path2SetPoint_B;

// Block states (auto storage)
DW_Path2SetPoint_T Path2SetPoint_DW;

// Real-time model
RT_MODEL_Path2SetPoint_T Path2SetPoint_M_;
RT_MODEL_Path2SetPoint_T *const Path2SetPoint_M = &Path2SetPoint_M_;

// Forward declaration for local functions
static real_T Path2SetPoint_sum(const boolean_T x[256]);
static void Path2SetPoint_repmat(const real_T a[2], real_T varargin_1, real_T
  b_data[], int32_T b_sizes[2]);
static void Path2SetPoint_abs(const real_T x_data[], const int32_T x_sizes[2],
  real_T y_data[], int32_T y_sizes[2]);
static void Path2SetPoint_power(const real_T a_data[], const int32_T a_sizes[2],
  real_T y_data[], int32_T y_sizes[2]);
static void Path2SetPoint_sum_k(const real_T x_data[], const int32_T x_sizes[2],
  real_T y_data[], int32_T y_sizes[2]);
static real32_T Path2SetPoint_norm(const real32_T x[2]);

// Function for MATLAB Function: '<Root>/MATLAB Function'
static real_T Path2SetPoint_sum(const boolean_T x[256])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 255; k++) {
    y += (real_T)x[k + 1];
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
static void Path2SetPoint_repmat(const real_T a[2], real_T varargin_1, real_T
  b_data[], int32_T b_sizes[2])
{
  int32_T itilerow;
  int32_T varargin_1_idx_0;
  int16_T outsize_idx_0;
  outsize_idx_0 = (int16_T)(int32_T)varargin_1;
  b_sizes[0] = outsize_idx_0;
  b_sizes[1] = 2;
  if (!(outsize_idx_0 == 0)) {
    varargin_1_idx_0 = (int32_T)varargin_1;
    for (itilerow = 1; itilerow <= varargin_1_idx_0; itilerow++) {
      b_data[itilerow - 1] = a[0];
    }

    for (itilerow = 1; itilerow <= varargin_1_idx_0; itilerow++) {
      b_data[(varargin_1_idx_0 + itilerow) - 1] = a[1];
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
static void Path2SetPoint_abs(const real_T x_data[], const int32_T x_sizes[2],
  real_T y_data[], int32_T y_sizes[2])
{
  int32_T n;
  int32_T k;
  y_sizes[0] = (int16_T)x_sizes[0];
  y_sizes[1] = 2;
  n = x_sizes[0] << 1;
  for (k = 0; k + 1 <= n; k++) {
    y_data[k] = fabs(x_data[k]);
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
static void Path2SetPoint_power(const real_T a_data[], const int32_T a_sizes[2],
  real_T y_data[], int32_T y_sizes[2])
{
  int32_T n;
  int32_T k;
  y_sizes[0] = (int16_T)a_sizes[0];
  y_sizes[1] = 2;
  n = a_sizes[0] << 1;
  for (k = 0; k + 1 <= n; k++) {
    y_data[k] = a_data[k] * a_data[k];
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
static void Path2SetPoint_sum_k(const real_T x_data[], const int32_T x_sizes[2],
  real_T y_data[], int32_T y_sizes[2])
{
  int32_T ix;
  int32_T iy;
  int32_T ixstart;
  int32_T i;
  y_sizes[0] = 1;
  y_sizes[1] = (int16_T)x_sizes[1];
  if (x_sizes[1] == 0) {
    y_sizes[0] = 1;
    ix = y_sizes[1];
    for (iy = 0; iy < ix; iy++) {
      y_data[iy] = 0.0;
    }
  } else {
    ix = 1;
    iy = -1;
    for (i = 1; i <= x_sizes[1]; i++) {
      ixstart = ix;
      ix += 2;
      iy++;
      y_data[iy] = x_data[ixstart - 1] + x_data[ixstart];
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
static real32_T Path2SetPoint_norm(const real32_T x[2])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.17549435E-38F;
  absxk = (real32_T)fabs((real_T)x[0]);
  if (absxk > 1.17549435E-38F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.17549435E-38F;
    y = t * t;
  }

  absxk = (real32_T)fabs((real_T)x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * (real32_T)sqrt((real_T)y);
}

// Model step function
void Path2SetPoint_step(void)
{
  real32_T DistanceTraveledX;
  real32_T DistanceTraveledY;
  real32_T Niterations;
  int32_T idx;
  int32_T ixstart;
  int32_T n;
  int32_T c_ix;
  boolean_T guard1;
  boolean_T varargout_1;
  int32_T DiscretizedPath_sizes[2];
  int32_T tmp_sizes[2];

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   MATLABSystem: '<S4>/SourceBlock'

  varargout_1 = Sub_Path2SetPoint_404.get_latest_msg
    (&Path2SetPoint_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  if (varargout_1) {
    Path2SetPoint_B.In1 = Path2SetPoint_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  varargout_1 = Sub_Path2SetPoint_370.get_latest_msg
    (&Path2SetPoint_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  if (varargout_1) {
    Path2SetPoint_B.In1_k = Path2SetPoint_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  varargout_1 = Sub_Path2SetPoint_405.get_latest_msg
    (&Path2SetPoint_B.varargout_2_k);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'

  if (varargout_1) {
    Path2SetPoint_B.In1_b = Path2SetPoint_B.varargout_2_k;
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // MATLAB Function: '<Root>/MATLAB Function1'
  // MATLAB Function 'MATLAB Function1': '<S3>:1'
  // '<S3>:1:3'
  Path2SetPoint_B.y = Path2SetPoint_B.In1_b.Data;
  if (Path2SetPoint_B.In1_b.Data == 0.0) {
    // '<S3>:1:5'
    // '<S3>:1:6'
    Path2SetPoint_B.y = 0.25;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function1'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport2'

  // MATLAB Function 'MATLAB Function': '<S2>:1'
  // '<S2>:1:5'
  // save('TESTlist2Eta')
  // '<S2>:1:9'
  for (ixstart = 0; ixstart < 128; ixstart++) {
    Path2SetPoint_B.Values[ixstart] = Path2SetPoint_B.In1.Data[ixstart];
    Path2SetPoint_B.Values[ixstart + 128] = Path2SetPoint_B.In1.Data[128 +
      ixstart];
  }

  // '<S2>:1:11'
  for (ixstart = 0; ixstart < 256; ixstart++) {
    Path2SetPoint_B.x[ixstart] = (Path2SetPoint_B.Values[ixstart] == 1000.0F);
  }

  idx = 0;
  ixstart = 1;
  varargout_1 = false;
  while ((!varargout_1) && (ixstart < 257)) {
    guard1 = false;
    if (Path2SetPoint_B.x[ixstart - 1]) {
      idx++;
      Path2SetPoint_B.ii_data[idx - 1] = (int16_T)ixstart;
      if (idx >= 256) {
        varargout_1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ixstart++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  n = idx + 1;
  for (ixstart = 0; ixstart < idx; ixstart++) {
    Path2SetPoint_B.varargin_1_data[ixstart] = Path2SetPoint_B.ii_data[ixstart];
  }

  Path2SetPoint_B.varargin_1_data[idx] = 128;
  idx = Path2SetPoint_B.varargin_1_data[0];
  if (n > 1) {
    for (ixstart = 1; ixstart + 1 <= n; ixstart++) {
      if (Path2SetPoint_B.varargin_1_data[ixstart] < idx) {
        idx = Path2SetPoint_B.varargin_1_data[ixstart];
      }
    }
  }

  for (ixstart = 0; ixstart < 256; ixstart++) {
    Path2SetPoint_B.x[ixstart] = (Path2SetPoint_B.In1.Data[ixstart] == 0.0F);
  }

  if ((Path2SetPoint_B.In1.Data[0] == 0.0F) && (Path2SetPoint_sum
       (Path2SetPoint_B.x) == 256.0)) {
    // '<S2>:1:13'
    // '<S2>:1:14'
    Path2SetPoint_B.counter = 0.0;
    Path2SetPoint_B.y = 0.0;
  } else if (idx == 2) {
    // '<S2>:1:15'
    //     asl=1
    //     a=asl(2);
    // '<S2>:1:18'
    Path2SetPoint_B.counter = Path2SetPoint_B.Values[128];

    // '<S2>:1:19'
    Path2SetPoint_B.y = Path2SetPoint_B.Values[0];
  } else {
    // DiscretizedPath
    // '<S2>:1:23'
    Path2SetPoint_B.counter = 1.0;

    // '<S2>:1:24'
    memset(&Path2SetPoint_B.DiscretizedPath[0], 0, 10000U * sizeof(real_T));

    // '<S2>:1:25'
    for (ixstart = 0; ixstart <= idx - 3; ixstart++) {
      // '<S2>:1:25'
      // '<S2>:1:26'
      // '<S2>:1:27'
      DistanceTraveledX = Path2SetPoint_B.Values[ixstart + 1] -
        Path2SetPoint_B.Values[ixstart];

      // '<S2>:1:28'
      DistanceTraveledY = Path2SetPoint_B.Values[ixstart + 129] -
        Path2SetPoint_B.Values[ixstart + 128];

      // '<S2>:1:29'
      Path2SetPoint_B.Values_c[0] = Path2SetPoint_B.Values[ixstart + 1] -
        Path2SetPoint_B.Values[ixstart];
      Path2SetPoint_B.Values_c[1] = Path2SetPoint_B.Values[ixstart + 129] -
        Path2SetPoint_B.Values[ixstart + 128];
      Niterations = (real32_T)floor((real_T)(Path2SetPoint_norm
        (Path2SetPoint_B.Values_c) / 0.01F));

      // '<S2>:1:30'
      for (n = 0; n < (int32_T)Niterations; n++) {
        // '<S2>:1:30'
        // '<S2>:1:31'
        Path2SetPoint_B.DiscretizedPath[(int32_T)Path2SetPoint_B.counter - 1] =
          (1.0F + (real32_T)n) * DistanceTraveledX / Niterations +
          Path2SetPoint_B.Values[ixstart];

        // '<S2>:1:32'
        Path2SetPoint_B.DiscretizedPath[(int32_T)Path2SetPoint_B.counter + 4999]
          = (1.0F + (real32_T)n) * DistanceTraveledY / Niterations +
          Path2SetPoint_B.Values[ixstart + 128];

        // '<S2>:1:33'
        Path2SetPoint_B.counter++;

        // '<S2>:1:30'
      }

      // '<S2>:1:25'
    }

    // '<S2>:1:36'
    idx = 0;
    ixstart = 1;
    varargout_1 = false;
    while ((!varargout_1) && (ixstart < 10001)) {
      guard1 = false;
      if (Path2SetPoint_B.DiscretizedPath[ixstart - 1] == (rtInf)) {
        idx++;
        Path2SetPoint_B.c_ii_data[idx - 1] = (int16_T)ixstart;
        if (idx >= 10000) {
          varargout_1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ixstart++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    n = idx + 1;
    for (ixstart = 0; ixstart < idx; ixstart++) {
      Path2SetPoint_B.varargin_1_data[ixstart] =
        Path2SetPoint_B.c_ii_data[ixstart];
    }

    Path2SetPoint_B.varargin_1_data[idx] = 5000;
    idx = Path2SetPoint_B.varargin_1_data[0];
    if (n > 1) {
      for (ixstart = 1; ixstart + 1 <= n; ixstart++) {
        if (Path2SetPoint_B.varargin_1_data[ixstart] < idx) {
          idx = Path2SetPoint_B.varargin_1_data[ixstart];
        }
      }
    }

    if (1 > idx - 1) {
      idx = 0;
    } else {
      idx--;
    }

    // '<S2>:1:37'
    // %a=asl
    // '<S2>:1:40'
    // Discretizing PathVector
    // for i=1:64
    // AvstandDummy=(eta(1)-Values(i,1))^2+(eta(2)-Values(i,2))^2;
    //  if AvstandDummy<AvstandSaved
    //      AvstandDummy=AvstandSaved;
    //  NearestPointPos=i;
    //  end
    // end
    Path2SetPoint_B.dv0[0] = Path2SetPoint_B.In1_k.Y;
    Path2SetPoint_B.dv0[1] = Path2SetPoint_B.In1_k.X;
    Path2SetPoint_repmat(Path2SetPoint_B.dv0, (real_T)idx,
                         Path2SetPoint_B.tmp_data, Path2SetPoint_B.tmp_sizes);
    DiscretizedPath_sizes[0] = idx;
    DiscretizedPath_sizes[1] = 2;
    for (ixstart = 0; ixstart < idx; ixstart++) {
      Path2SetPoint_B.DiscretizedPath_data[ixstart] =
        Path2SetPoint_B.DiscretizedPath[ixstart] -
        Path2SetPoint_B.tmp_data[ixstart];
    }

    for (ixstart = 0; ixstart < idx; ixstart++) {
      Path2SetPoint_B.DiscretizedPath_data[ixstart + idx] =
        Path2SetPoint_B.DiscretizedPath[ixstart + 5000] -
        Path2SetPoint_B.tmp_data[ixstart + Path2SetPoint_B.tmp_sizes[0]];
    }

    Path2SetPoint_abs(Path2SetPoint_B.DiscretizedPath_data,
                      DiscretizedPath_sizes, Path2SetPoint_B.tmp_data,
                      Path2SetPoint_B.tmp_sizes);
    Path2SetPoint_power(Path2SetPoint_B.tmp_data, Path2SetPoint_B.tmp_sizes,
                        Path2SetPoint_B.DiscretizedPath_data,
                        DiscretizedPath_sizes);
    tmp_sizes[0] = 2;
    tmp_sizes[1] = DiscretizedPath_sizes[0];
    idx = DiscretizedPath_sizes[0];
    for (ixstart = 0; ixstart < idx; ixstart++) {
      Path2SetPoint_B.tmp_data[ixstart << 1] =
        Path2SetPoint_B.DiscretizedPath_data[ixstart];
      Path2SetPoint_B.tmp_data[1 + (ixstart << 1)] =
        Path2SetPoint_B.DiscretizedPath_data[ixstart + DiscretizedPath_sizes[0]];
    }

    Path2SetPoint_sum_k(Path2SetPoint_B.tmp_data, tmp_sizes,
                        Path2SetPoint_B.b_varargin_1_data,
                        Path2SetPoint_B.tmp_sizes);
    ixstart = 1;
    n = Path2SetPoint_B.tmp_sizes[1];
    Path2SetPoint_B.counter = Path2SetPoint_B.b_varargin_1_data[0];
    idx = 1;
    if (Path2SetPoint_B.tmp_sizes[1] > 1) {
      if (rtIsNaN(Path2SetPoint_B.b_varargin_1_data[0])) {
        c_ix = 2;
        varargout_1 = false;
        while ((!varargout_1) && (c_ix <= n)) {
          ixstart = c_ix;
          if (!rtIsNaN(Path2SetPoint_B.b_varargin_1_data[c_ix - 1])) {
            Path2SetPoint_B.counter = Path2SetPoint_B.b_varargin_1_data[c_ix - 1];
            idx = c_ix;
            varargout_1 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (ixstart < Path2SetPoint_B.tmp_sizes[1]) {
        while (ixstart + 1 <= n) {
          if (Path2SetPoint_B.b_varargin_1_data[ixstart] <
              Path2SetPoint_B.counter) {
            Path2SetPoint_B.counter = Path2SetPoint_B.b_varargin_1_data[ixstart];
            idx = ixstart + 1;
          }

          ixstart++;
        }
      }
    }

    // '<S2>:1:62'
    // '<S2>:1:64'
    Path2SetPoint_B.counter = (real_T)idx - rt_roundd_snf(Path2SetPoint_B.y /
      0.01);
    Path2SetPoint_B.y = 1.0;
    if (Path2SetPoint_B.counter > 1.0) {
      Path2SetPoint_B.y = Path2SetPoint_B.counter;
    }

    // '<S2>:1:65'
    Path2SetPoint_B.counter = Path2SetPoint_B.DiscretizedPath[(int32_T)
      Path2SetPoint_B.y + 4999];

    // '<S2>:1:66'
    Path2SetPoint_B.y = Path2SetPoint_B.DiscretizedPath[(int32_T)
      Path2SetPoint_B.y - 1];

    // etaset = u;11
    // HEADING:
    // end
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // BusAssignment: '<S1>/Bus Assignment1' incorporates:
  //   Constant: '<S1>/Constant'

  // '<S2>:1:71'
  Path2SetPoint_B.BusAssignment1.X = Path2SetPoint_B.counter;
  Path2SetPoint_B.BusAssignment1.Y = Path2SetPoint_B.y;
  Path2SetPoint_B.BusAssignment1.Z = Path2SetPoint_P.Constant_Value_bx;

  // Outputs for Atomic SubSystem: '<S1>/Publish1'
  // MATLABSystem: '<S8>/SinkBlock'
  Pub_Path2SetPoint_400.publish(&Path2SetPoint_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S1>/Publish1'
}

// Model initialize function
void Path2SetPoint_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(Path2SetPoint_M, (NULL));

  // block I/O
  (void) memset(((void *) &Path2SetPoint_B), 0,
                sizeof(B_Path2SetPoint_T));

  // states (dwork)
  (void) memset((void *)&Path2SetPoint_DW, 0,
                sizeof(DW_Path2SetPoint_T));

  {
    static const char_T tmp[9] = { '/', 'S', 'e', 't', 'P', 'o', 'i', 'n', 't' };

    static const char_T tmp_0[13] = { '/', 'S', 'e', 't', 'P', 'o', 'i', 'n',
      't', 'D', 'i', 's', 't' };

    static const char_T tmp_1[9] = { '/', 'P', 'o', 's', 'i', 't', 'i', 'o', 'n'
    };

    static const char_T tmp_2[5] = { '/', 'P', 'a', 't', 'h' };

    char_T tmp_3[14];
    char_T tmp_4[10];
    char_T tmp_5[6];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    Path2SetPoint_DW.obj_j4.isInitialized = 0;
    Path2SetPoint_DW.objisempty_p = true;
    Path2SetPoint_DW.obj_j4.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      tmp_5[i] = tmp_2[i];
    }

    tmp_5[5] = '\x00';
    Sub_Path2SetPoint_404.create_subscriber(tmp_5, Path2SetPoint_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SourceBlock'

    // Start for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S9>/Out1'
    Path2SetPoint_B.In1 = Path2SetPoint_P.Out1_Y0;

    // End of Start for SubSystem: '<S4>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Subscribe2'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    Path2SetPoint_DW.obj_j.isInitialized = 0;
    Path2SetPoint_DW.objisempty = true;
    Path2SetPoint_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_4[i] = tmp_1[i];
    }

    tmp_4[9] = '\x00';
    Sub_Path2SetPoint_370.create_subscriber(tmp_4, Path2SetPoint_MessageQueueLen);

    // End of Start for MATLABSystem: '<S6>/SourceBlock'

    // Start for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S11>/Out1'
    Path2SetPoint_B.In1_k = Path2SetPoint_P.Out1_Y0_g;

    // End of Start for SubSystem: '<S6>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe2'

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    Path2SetPoint_DW.obj_jz.isInitialized = 0;
    Path2SetPoint_DW.objisempty_b = true;
    Path2SetPoint_DW.obj_jz.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[13] = '\x00';
    Sub_Path2SetPoint_405.create_subscriber(tmp_3, Path2SetPoint_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'

    // Start for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S10>/Out1'
    Path2SetPoint_B.In1_b = Path2SetPoint_P.Out1_Y0_c;

    // End of Start for SubSystem: '<S5>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe1'

    // Start for Atomic SubSystem: '<S1>/Publish1'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    Path2SetPoint_DW.obj.isInitialized = 0;
    Path2SetPoint_DW.objisempty_f = true;
    Path2SetPoint_DW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_4[i] = tmp[i];
    }

    tmp_4[9] = '\x00';
    Pub_Path2SetPoint_400.create_publisher(tmp_4, Path2SetPoint_MessageQueueLen);

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of Start for SubSystem: '<S1>/Publish1'
  }
}

// Model terminate function
void Path2SetPoint_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (Path2SetPoint_DW.obj_j4.isInitialized == 1) {
    Path2SetPoint_DW.obj_j4.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SourceBlock'

  if (Path2SetPoint_DW.obj_j.isInitialized == 1) {
    Path2SetPoint_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (Path2SetPoint_DW.obj_jz.isInitialized == 1) {
    Path2SetPoint_DW.obj_jz.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S1>/Publish1'
  // Start for MATLABSystem: '<S8>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SinkBlock'

  if (Path2SetPoint_DW.obj.isInitialized == 1) {
    Path2SetPoint_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
