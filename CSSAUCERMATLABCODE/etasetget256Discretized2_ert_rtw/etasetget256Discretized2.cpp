//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etasetget256Discretized2.cpp
//
// Code generated for Simulink model 'etasetget256Discretized2'.
//
// Model version                  : 1.122
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Tue May 10 13:32:34 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "etasetget256Discretized2.h"
#include "etasetget256Discretized2_private.h"
#define etasetget256Dis_MessageQueueLen (1)

// Block signals (auto storage)
B_etasetget256Discretized2_T etasetget256Discretized2_B;

// Block states (auto storage)
DW_etasetget256Discretized2_T etasetget256Discretized2_DW;

// Real-time model
RT_MODEL_etasetget256Discreti_T etasetget256Discretized2_M_;
RT_MODEL_etasetget256Discreti_T *const etasetget256Discretized2_M =
  &etasetget256Discretized2_M_;

// Forward declaration for local functions
static real_T etasetget256Discretized2_sum(const boolean_T x[256]);
static void etasetget256Discretized2_repmat(const real_T a[2], real_T varargin_1,
  real_T b_data[], int32_T b_sizes[2]);
static void etasetget256Discretized2_abs(const real_T x_data[], const int32_T
  x_sizes[2], real_T y_data[], int32_T y_sizes[2]);
static void etasetget256Discretized2_power(const real_T a_data[], const int32_T
  a_sizes[2], real_T y_data[], int32_T y_sizes[2]);
static void etasetget256Discretized2_sum_k(const real_T x_data[], const int32_T
  x_sizes[2], real_T y_data[], int32_T y_sizes[2]);
static real32_T etasetget256Discretized2_norm(const real32_T x[2]);

// Function for MATLAB Function: '<Root>/MATLAB Function'
static real_T etasetget256Discretized2_sum(const boolean_T x[256])
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
static void etasetget256Discretized2_repmat(const real_T a[2], real_T varargin_1,
  real_T b_data[], int32_T b_sizes[2])
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
static void etasetget256Discretized2_abs(const real_T x_data[], const int32_T
  x_sizes[2], real_T y_data[], int32_T y_sizes[2])
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
static void etasetget256Discretized2_power(const real_T a_data[], const int32_T
  a_sizes[2], real_T y_data[], int32_T y_sizes[2])
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
static void etasetget256Discretized2_sum_k(const real_T x_data[], const int32_T
  x_sizes[2], real_T y_data[], int32_T y_sizes[2])
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
static real32_T etasetget256Discretized2_norm(const real32_T x[2])
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
void etasetget256Discretized2_step(void)
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

  varargout_1 = Sub_etasetget256Discretized2_404.get_latest_msg
    (&etasetget256Discretized2_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  if (varargout_1) {
    etasetget256Discretized2_B.In1 = etasetget256Discretized2_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   MATLABSystem: '<S6>/SourceBlock'

  varargout_1 = Sub_etasetget256Discretized2_370.get_latest_msg
    (&etasetget256Discretized2_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  if (varargout_1) {
    etasetget256Discretized2_B.In1_k = etasetget256Discretized2_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   MATLABSystem: '<S5>/SourceBlock'

  varargout_1 = Sub_etasetget256Discretized2_405.get_latest_msg
    (&etasetget256Discretized2_B.varargout_2_k);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'

  if (varargout_1) {
    etasetget256Discretized2_B.In1_b = etasetget256Discretized2_B.varargout_2_k;
  }

  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // MATLAB Function: '<Root>/MATLAB Function1'
  // MATLAB Function 'MATLAB Function1': '<S3>:1'
  // '<S3>:1:3'
  etasetget256Discretized2_B.y = etasetget256Discretized2_B.In1_b.Data;
  if (etasetget256Discretized2_B.In1_b.Data == 0.0) {
    // '<S3>:1:5'
    // '<S3>:1:6'
    etasetget256Discretized2_B.y = 0.25;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function1'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport2'

  // MATLAB Function 'MATLAB Function': '<S2>:1'
  // '<S2>:1:5'
  // save('TESTlist2Eta')
  // '<S2>:1:9'
  for (ixstart = 0; ixstart < 128; ixstart++) {
    etasetget256Discretized2_B.Values[ixstart] =
      etasetget256Discretized2_B.In1.Data[ixstart];
    etasetget256Discretized2_B.Values[ixstart + 128] =
      etasetget256Discretized2_B.In1.Data[128 + ixstart];
  }

  // '<S2>:1:11'
  for (ixstart = 0; ixstart < 256; ixstart++) {
    etasetget256Discretized2_B.x[ixstart] =
      (etasetget256Discretized2_B.Values[ixstart] == 1000.0F);
  }

  idx = 0;
  ixstart = 1;
  varargout_1 = false;
  while ((!varargout_1) && (ixstart < 257)) {
    guard1 = false;
    if (etasetget256Discretized2_B.x[ixstart - 1]) {
      idx++;
      etasetget256Discretized2_B.ii_data[idx - 1] = (int16_T)ixstart;
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
    etasetget256Discretized2_B.varargin_1_data[ixstart] =
      etasetget256Discretized2_B.ii_data[ixstart];
  }

  etasetget256Discretized2_B.varargin_1_data[idx] = 128;
  idx = etasetget256Discretized2_B.varargin_1_data[0];
  if (n > 1) {
    for (ixstart = 1; ixstart + 1 <= n; ixstart++) {
      if (etasetget256Discretized2_B.varargin_1_data[ixstart] < idx) {
        idx = etasetget256Discretized2_B.varargin_1_data[ixstart];
      }
    }
  }

  for (ixstart = 0; ixstart < 256; ixstart++) {
    etasetget256Discretized2_B.x[ixstart] =
      (etasetget256Discretized2_B.In1.Data[ixstart] == 0.0F);
  }

  if ((etasetget256Discretized2_B.In1.Data[0] == 0.0F) &&
      (etasetget256Discretized2_sum(etasetget256Discretized2_B.x) == 256.0)) {
    // '<S2>:1:13'
    // '<S2>:1:14'
    etasetget256Discretized2_B.counter = 0.0;
    etasetget256Discretized2_B.y = 0.0;
  } else if (idx == 2) {
    // '<S2>:1:15'
    //     asl=1
    //     a=asl(2);
    // '<S2>:1:18'
    etasetget256Discretized2_B.counter = etasetget256Discretized2_B.Values[128];

    // '<S2>:1:19'
    etasetget256Discretized2_B.y = etasetget256Discretized2_B.Values[0];
  } else {
    // DiscretizedPath
    // '<S2>:1:23'
    etasetget256Discretized2_B.counter = 1.0;

    // '<S2>:1:24'
    memset(&etasetget256Discretized2_B.DiscretizedPath[0], 0, 10000U * sizeof
           (real_T));

    // '<S2>:1:25'
    for (ixstart = 0; ixstart <= idx - 3; ixstart++) {
      // '<S2>:1:25'
      // '<S2>:1:26'
      // '<S2>:1:27'
      DistanceTraveledX = etasetget256Discretized2_B.Values[ixstart + 1] -
        etasetget256Discretized2_B.Values[ixstart];

      // '<S2>:1:28'
      DistanceTraveledY = etasetget256Discretized2_B.Values[ixstart + 129] -
        etasetget256Discretized2_B.Values[ixstart + 128];

      // '<S2>:1:29'
      etasetget256Discretized2_B.Values_c[0] =
        etasetget256Discretized2_B.Values[ixstart + 1] -
        etasetget256Discretized2_B.Values[ixstart];
      etasetget256Discretized2_B.Values_c[1] =
        etasetget256Discretized2_B.Values[ixstart + 129] -
        etasetget256Discretized2_B.Values[ixstart + 128];
      Niterations = (real32_T)floor((real_T)(etasetget256Discretized2_norm
        (etasetget256Discretized2_B.Values_c) / 0.01F));

      // '<S2>:1:30'
      for (n = 0; n < (int32_T)Niterations; n++) {
        // '<S2>:1:30'
        // '<S2>:1:31'
        etasetget256Discretized2_B.DiscretizedPath[(int32_T)
          etasetget256Discretized2_B.counter - 1] = (1.0F + (real32_T)n) *
          DistanceTraveledX / Niterations +
          etasetget256Discretized2_B.Values[ixstart];

        // '<S2>:1:32'
        etasetget256Discretized2_B.DiscretizedPath[(int32_T)
          etasetget256Discretized2_B.counter + 4999] = (1.0F + (real32_T)n) *
          DistanceTraveledY / Niterations +
          etasetget256Discretized2_B.Values[ixstart + 128];

        // '<S2>:1:33'
        etasetget256Discretized2_B.counter++;

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
      if (etasetget256Discretized2_B.DiscretizedPath[ixstart - 1] == (rtInf)) {
        idx++;
        etasetget256Discretized2_B.c_ii_data[idx - 1] = (int16_T)ixstart;
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
      etasetget256Discretized2_B.varargin_1_data[ixstart] =
        etasetget256Discretized2_B.c_ii_data[ixstart];
    }

    etasetget256Discretized2_B.varargin_1_data[idx] = 5000;
    idx = etasetget256Discretized2_B.varargin_1_data[0];
    if (n > 1) {
      for (ixstart = 1; ixstart + 1 <= n; ixstart++) {
        if (etasetget256Discretized2_B.varargin_1_data[ixstart] < idx) {
          idx = etasetget256Discretized2_B.varargin_1_data[ixstart];
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
    etasetget256Discretized2_B.dv0[0] = etasetget256Discretized2_B.In1_k.Y;
    etasetget256Discretized2_B.dv0[1] = etasetget256Discretized2_B.In1_k.X;
    etasetget256Discretized2_repmat(etasetget256Discretized2_B.dv0, (real_T)idx,
      etasetget256Discretized2_B.tmp_data, etasetget256Discretized2_B.tmp_sizes);
    DiscretizedPath_sizes[0] = idx;
    DiscretizedPath_sizes[1] = 2;
    for (ixstart = 0; ixstart < idx; ixstart++) {
      etasetget256Discretized2_B.DiscretizedPath_data[ixstart] =
        etasetget256Discretized2_B.DiscretizedPath[ixstart] -
        etasetget256Discretized2_B.tmp_data[ixstart];
    }

    for (ixstart = 0; ixstart < idx; ixstart++) {
      etasetget256Discretized2_B.DiscretizedPath_data[ixstart + idx] =
        etasetget256Discretized2_B.DiscretizedPath[ixstart + 5000] -
        etasetget256Discretized2_B.tmp_data[ixstart +
        etasetget256Discretized2_B.tmp_sizes[0]];
    }

    etasetget256Discretized2_abs(etasetget256Discretized2_B.DiscretizedPath_data,
      DiscretizedPath_sizes, etasetget256Discretized2_B.tmp_data,
      etasetget256Discretized2_B.tmp_sizes);
    etasetget256Discretized2_power(etasetget256Discretized2_B.tmp_data,
      etasetget256Discretized2_B.tmp_sizes,
      etasetget256Discretized2_B.DiscretizedPath_data, DiscretizedPath_sizes);
    tmp_sizes[0] = 2;
    tmp_sizes[1] = DiscretizedPath_sizes[0];
    idx = DiscretizedPath_sizes[0];
    for (ixstart = 0; ixstart < idx; ixstart++) {
      etasetget256Discretized2_B.tmp_data[ixstart << 1] =
        etasetget256Discretized2_B.DiscretizedPath_data[ixstart];
      etasetget256Discretized2_B.tmp_data[1 + (ixstart << 1)] =
        etasetget256Discretized2_B.DiscretizedPath_data[ixstart +
        DiscretizedPath_sizes[0]];
    }

    etasetget256Discretized2_sum_k(etasetget256Discretized2_B.tmp_data,
      tmp_sizes, etasetget256Discretized2_B.b_varargin_1_data,
      etasetget256Discretized2_B.tmp_sizes);
    ixstart = 1;
    n = etasetget256Discretized2_B.tmp_sizes[1];
    etasetget256Discretized2_B.counter =
      etasetget256Discretized2_B.b_varargin_1_data[0];
    idx = 1;
    if (etasetget256Discretized2_B.tmp_sizes[1] > 1) {
      if (rtIsNaN(etasetget256Discretized2_B.b_varargin_1_data[0])) {
        c_ix = 2;
        varargout_1 = false;
        while ((!varargout_1) && (c_ix <= n)) {
          ixstart = c_ix;
          if (!rtIsNaN(etasetget256Discretized2_B.b_varargin_1_data[c_ix - 1]))
          {
            etasetget256Discretized2_B.counter =
              etasetget256Discretized2_B.b_varargin_1_data[c_ix - 1];
            idx = c_ix;
            varargout_1 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (ixstart < etasetget256Discretized2_B.tmp_sizes[1]) {
        while (ixstart + 1 <= n) {
          if (etasetget256Discretized2_B.b_varargin_1_data[ixstart] <
              etasetget256Discretized2_B.counter) {
            etasetget256Discretized2_B.counter =
              etasetget256Discretized2_B.b_varargin_1_data[ixstart];
            idx = ixstart + 1;
          }

          ixstart++;
        }
      }
    }

    // '<S2>:1:62'
    // '<S2>:1:64'
    etasetget256Discretized2_B.counter = (real_T)idx - rt_roundd_snf
      (etasetget256Discretized2_B.y / 0.01);
    etasetget256Discretized2_B.y = 1.0;
    if (etasetget256Discretized2_B.counter > 1.0) {
      etasetget256Discretized2_B.y = etasetget256Discretized2_B.counter;
    }

    // '<S2>:1:65'
    etasetget256Discretized2_B.counter =
      etasetget256Discretized2_B.DiscretizedPath[(int32_T)
      etasetget256Discretized2_B.y + 4999];

    // '<S2>:1:66'
    etasetget256Discretized2_B.y = etasetget256Discretized2_B.DiscretizedPath
      [(int32_T)etasetget256Discretized2_B.y - 1];

    // etaset = u;11
    // HEADING:
    // end
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // BusAssignment: '<S1>/Bus Assignment1' incorporates:
  //   Constant: '<S1>/Constant'

  // '<S2>:1:71'
  etasetget256Discretized2_B.BusAssignment1.X =
    etasetget256Discretized2_B.counter;
  etasetget256Discretized2_B.BusAssignment1.Y = etasetget256Discretized2_B.y;
  etasetget256Discretized2_B.BusAssignment1.Z =
    etasetget256Discretized2_P.Constant_Value_bx;

  // Outputs for Atomic SubSystem: '<S1>/Publish1'
  // MATLABSystem: '<S8>/SinkBlock'
  Pub_etasetget256Discretized2_400.publish
    (&etasetget256Discretized2_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S1>/Publish1'
}

// Model initialize function
void etasetget256Discretized2_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus(etasetget256Discretized2_M, (NULL));

  // block I/O
  (void) memset(((void *) &etasetget256Discretized2_B), 0,
                sizeof(B_etasetget256Discretized2_T));

  // states (dwork)
  (void) memset((void *)&etasetget256Discretized2_DW, 0,
                sizeof(DW_etasetget256Discretized2_T));

  {
    static const char_T tmp[7] = { '/', 'E', 't', 'a', 'S', 'e', 't' };

    static const char_T tmp_0[15] = { '/', 'E', 't', 'a', 'S', 'e', 't', 'D',
      'i', 's', 't', 'a', 'n', 'c', 'e' };

    static const char_T tmp_1[11] = { '/', 'E', 't', 'a', 'S', 'e', 't', 'L',
      'i', 's', 't' };

    char_T tmp_2[8];
    char_T tmp_3[16];
    char_T tmp_4[5];
    char_T tmp_5[12];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    etasetget256Discretized2_DW.obj_j4.isInitialized = 0;
    etasetget256Discretized2_DW.objisempty_p = true;
    etasetget256Discretized2_DW.obj_j4.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp_5[i] = tmp_1[i];
    }

    tmp_5[11] = '\x00';
    Sub_etasetget256Discretized2_404.create_subscriber(tmp_5,
      etasetget256Dis_MessageQueueLen);

    // End of Start for MATLABSystem: '<S4>/SourceBlock'

    // Start for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S9>/Out1'
    etasetget256Discretized2_B.In1 = etasetget256Discretized2_P.Out1_Y0;

    // End of Start for SubSystem: '<S4>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // Start for Atomic SubSystem: '<Root>/Subscribe2'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    etasetget256Discretized2_DW.obj_j.isInitialized = 0;
    etasetget256Discretized2_DW.objisempty = true;
    etasetget256Discretized2_DW.obj_j.isInitialized = 1;
    tmp_4[0] = '/';
    tmp_4[1] = 'E';
    tmp_4[2] = 't';
    tmp_4[3] = 'a';
    tmp_4[4] = '\x00';
    Sub_etasetget256Discretized2_370.create_subscriber(tmp_4,
      etasetget256Dis_MessageQueueLen);

    // Start for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S11>/Out1'
    etasetget256Discretized2_B.In1_k = etasetget256Discretized2_P.Out1_Y0_g;

    // End of Start for SubSystem: '<S6>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe2'

    // Start for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    etasetget256Discretized2_DW.obj_jz.isInitialized = 0;
    etasetget256Discretized2_DW.objisempty_b = true;
    etasetget256Discretized2_DW.obj_jz.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      tmp_3[i] = tmp_0[i];
    }

    tmp_3[15] = '\x00';
    Sub_etasetget256Discretized2_405.create_subscriber(tmp_3,
      etasetget256Dis_MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'

    // Start for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // VirtualOutportStart for Outport: '<S10>/Out1'
    etasetget256Discretized2_B.In1_b = etasetget256Discretized2_P.Out1_Y0_c;

    // End of Start for SubSystem: '<S5>/Enabled Subsystem'
    // End of Start for SubSystem: '<Root>/Subscribe1'

    // Start for Atomic SubSystem: '<S1>/Publish1'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    etasetget256Discretized2_DW.obj.isInitialized = 0;
    etasetget256Discretized2_DW.objisempty_f = true;
    etasetget256Discretized2_DW.obj.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      tmp_2[i] = tmp[i];
    }

    tmp_2[7] = '\x00';
    Pub_etasetget256Discretized2_400.create_publisher(tmp_2,
      etasetget256Dis_MessageQueueLen);

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of Start for SubSystem: '<S1>/Publish1'
  }
}

// Model terminate function
void etasetget256Discretized2_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Start for MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S4>/SourceBlock'

  if (etasetget256Discretized2_DW.obj_j4.isInitialized == 1) {
    etasetget256Discretized2_DW.obj_j4.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Start for MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S6>/SourceBlock'

  if (etasetget256Discretized2_DW.obj_j.isInitialized == 1) {
    etasetget256Discretized2_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S5>/SourceBlock'

  if (etasetget256Discretized2_DW.obj_jz.isInitialized == 1) {
    etasetget256Discretized2_DW.obj_jz.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S1>/Publish1'
  // Start for MATLABSystem: '<S8>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S8>/SinkBlock'

  if (etasetget256Discretized2_DW.obj.isInitialized == 1) {
    etasetget256Discretized2_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
