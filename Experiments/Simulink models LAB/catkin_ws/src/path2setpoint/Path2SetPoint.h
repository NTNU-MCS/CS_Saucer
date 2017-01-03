//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Path2SetPoint.h
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
#ifndef RTW_HEADER_Path2SetPoint_h_
#define RTW_HEADER_Path2SetPoint_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Path2SetPoint_COMMON_INCLUDES_
# define Path2SetPoint_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // Path2SetPoint_COMMON_INCLUDES_

#include "Path2SetPoint_types.h"
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
  SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray In1;// '<S9>/In1'
  SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray varargout_2;
  real32_T Values[256];
  int16_T ii_data[256];
  boolean_T x[256];
  SL_Bus_Path2SetPoint_geometry_msgs_Vector3 In1_k;// '<S11>/In1'
  SL_Bus_Path2SetPoint_geometry_msgs_Vector3 varargout_2_m;
  SL_Bus_Path2SetPoint_geometry_msgs_Vector3 BusAssignment1;// '<S1>/Bus Assignment1' 
  real_T dv0[2];
  real_T counter;
  real_T y;                            // '<Root>/MATLAB Function1'
  SL_Bus_Path2SetPoint_std_msgs_Float64 In1_b;// '<S10>/In1'
  SL_Bus_Path2SetPoint_std_msgs_Float64 varargout_2_k;
  int32_T tmp_sizes[2];
  real32_T Values_c[2];
} B_Path2SetPoint_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S6>/SourceBlock'
  void *SourceBlock_PWORK_p;           // '<S5>/SourceBlock'
  void *SourceBlock_PWORK_c;           // '<S4>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S8>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S8>/SinkBlock'
  robotics_slros_internal_blo_c_T obj_j;// '<S6>/SourceBlock'
  robotics_slros_internal_blo_c_T obj_jz;// '<S5>/SourceBlock'
  robotics_slros_internal_blo_c_T obj_j4;// '<S4>/SourceBlock'
  boolean_T objisempty;                // '<S6>/SourceBlock'
  boolean_T objisempty_b;              // '<S5>/SourceBlock'
  boolean_T objisempty_p;              // '<S4>/SourceBlock'
  boolean_T objisempty_f;              // '<S8>/SinkBlock'
} DW_Path2SetPoint_T;

// Parameters (auto storage)
struct P_Path2SetPoint_T_ {
  SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                          //  Referenced by: '<S9>/Out1'

  SL_Bus_Path2SetPoint_std_msgs_Float32MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                 //  Referenced by: '<S4>/Constant'

  SL_Bus_Path2SetPoint_geometry_msgs_Vector3 Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                                       //  Referenced by: '<S11>/Out1'

  SL_Bus_Path2SetPoint_geometry_msgs_Vector3 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                              //  Referenced by: '<S6>/Constant'

  SL_Bus_Path2SetPoint_geometry_msgs_Vector3 Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                              //  Referenced by: '<S7>/Constant'

  real_T Constant_Value_o;             // Expression: 0
                                       //  Referenced by: '<Root>/Constant'

  real_T Constant_Value_bx;            // Expression: 0
                                       //  Referenced by: '<S1>/Constant'

  SL_Bus_Path2SetPoint_std_msgs_Float64 Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                                  //  Referenced by: '<S10>/Out1'

  SL_Bus_Path2SetPoint_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                         //  Referenced by: '<S5>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_Path2SetPoint_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_Path2SetPoint_T Path2SetPoint_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_Path2SetPoint_T Path2SetPoint_B;

// Block states (auto storage)
extern DW_Path2SetPoint_T Path2SetPoint_DW;

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
  extern void Path2SetPoint_initialize(void);
  extern void Path2SetPoint_step(void);
  extern void Path2SetPoint_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Path2SetPoint_T *const Path2SetPoint_M;

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
//  '<Root>' : 'Path2SetPoint'
//  '<S1>'   : 'Path2SetPoint/EtaSet'
//  '<S2>'   : 'Path2SetPoint/MATLAB Function'
//  '<S3>'   : 'Path2SetPoint/MATLAB Function1'
//  '<S4>'   : 'Path2SetPoint/Subscribe'
//  '<S5>'   : 'Path2SetPoint/Subscribe1'
//  '<S6>'   : 'Path2SetPoint/Subscribe2'
//  '<S7>'   : 'Path2SetPoint/EtaSet/Blank Message1'
//  '<S8>'   : 'Path2SetPoint/EtaSet/Publish1'
//  '<S9>'   : 'Path2SetPoint/Subscribe/Enabled Subsystem'
//  '<S10>'  : 'Path2SetPoint/Subscribe1/Enabled Subsystem'
//  '<S11>'  : 'Path2SetPoint/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_Path2SetPoint_h_

//
// File trailer for generated code.
//
// [EOF]
//
