//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etasetget256Discretized2.h
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
#ifndef RTW_HEADER_etasetget256Discretized2_h_
#define RTW_HEADER_etasetget256Discretized2_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef etasetget256Discretized2_COMMON_INCLUDES_
# define etasetget256Discretized2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // etasetget256Discretized2_COMMON_INCLUDES_ 

#include "etasetget256Discretized2_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  real_T DiscretizedPath[10000];
  real_T tmp_data[10000];
  real_T DiscretizedPath_data[10000];
  real_T b_varargin_1_data[5000];
  int16_T varargin_1_data[10001];
  int16_T c_ii_data[10000];
  SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray In1;// '<S9>/In1'
  SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray varargout_2;
  real32_T Values[256];
  int16_T ii_data[256];
  boolean_T x[256];
  SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 In1_k;// '<S11>/In1'
  SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 varargout_2_m;
  SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 BusAssignment1;// '<S1>/Bus Assignment1' 
  real_T dv0[2];
  real_T counter;
  real_T y;                            // '<Root>/MATLAB Function1'
  SL_Bus_etasetget256Discretized2_std_msgs_Float64 In1_b;// '<S10>/In1'
  SL_Bus_etasetget256Discretized2_std_msgs_Float64 varargout_2_k;
  int32_T tmp_sizes[2];
  real32_T Values_c[2];
} B_etasetget256Discretized2_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S6>/SourceBlock'
  void *SourceBlock_PWORK_p;           // '<S5>/SourceBlock'
  void *SourceBlock_PWORK_c;           // '<S4>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S8>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S8>/SinkBlock'
  robotics_slros_internal_blo_p_T obj_j;// '<S6>/SourceBlock'
  robotics_slros_internal_blo_p_T obj_jz;// '<S5>/SourceBlock'
  robotics_slros_internal_blo_p_T obj_j4;// '<S4>/SourceBlock'
  boolean_T objisempty;                // '<S6>/SourceBlock'
  boolean_T objisempty_b;              // '<S5>/SourceBlock'
  boolean_T objisempty_p;              // '<S4>/SourceBlock'
  boolean_T objisempty_f;              // '<S8>/SinkBlock'
} DW_etasetget256Discretized2_T;

// Parameters (auto storage)
struct P_etasetget256Discretized2_T_ {
  SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                                     //  Referenced by: '<S9>/Out1'

  SL_Bus_etasetget256Discretized2_std_msgs_Float32MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S4>/Constant'

  SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                                                  //  Referenced by: '<S11>/Out1'

  SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                      //  Referenced by: '<S6>/Constant'

  SL_Bus_etasetget256Discretized2_geometry_msgs_Vector3 Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                                      //  Referenced by: '<S7>/Constant'

  real_T Constant_Value_o;             // Expression: 0
                                       //  Referenced by: '<Root>/Constant'

  real_T Constant_Value_bx;            // Expression: 0
                                       //  Referenced by: '<S1>/Constant'

  SL_Bus_etasetget256Discretized2_std_msgs_Float64 Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                                             //  Referenced by: '<S10>/Out1'

  SL_Bus_etasetget256Discretized2_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                    //  Referenced by: '<S5>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_etasetget256Discretiz_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_etasetget256Discretized2_T etasetget256Discretized2_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_etasetget256Discretized2_T etasetget256Discretized2_B;

// Block states (auto storage)
extern DW_etasetget256Discretized2_T etasetget256Discretized2_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void etasetget256Discretized2_initialize(void);
  extern void etasetget256Discretized2_step(void);
  extern void etasetget256Discretized2_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_etasetget256Discreti_T *const etasetget256Discretized2_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'etasetget256Discretized2'
//  '<S1>'   : 'etasetget256Discretized2/EtaSet'
//  '<S2>'   : 'etasetget256Discretized2/MATLAB Function'
//  '<S3>'   : 'etasetget256Discretized2/MATLAB Function1'
//  '<S4>'   : 'etasetget256Discretized2/Subscribe'
//  '<S5>'   : 'etasetget256Discretized2/Subscribe1'
//  '<S6>'   : 'etasetget256Discretized2/Subscribe2'
//  '<S7>'   : 'etasetget256Discretized2/EtaSet/Blank Message1'
//  '<S8>'   : 'etasetget256Discretized2/EtaSet/Publish1'
//  '<S9>'   : 'etasetget256Discretized2/Subscribe/Enabled Subsystem'
//  '<S10>'  : 'etasetget256Discretized2/Subscribe1/Enabled Subsystem'
//  '<S11>'  : 'etasetget256Discretized2/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_etasetget256Discretized2_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
