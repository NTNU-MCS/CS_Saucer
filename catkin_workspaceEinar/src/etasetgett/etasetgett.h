//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etasetgett.h
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
#ifndef RTW_HEADER_etasetgett_h_
#define RTW_HEADER_etasetgett_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef etasetgett_COMMON_INCLUDES_
# define etasetgett_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // etasetgett_COMMON_INCLUDES_

#include "etasetgett_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_etasetgett_std_msgs_Float32MultiArray In1;// '<S10>/In1'
  SL_Bus_etasetgett_std_msgs_Float32MultiArray varargout_2;
  real_T b[256];
  real32_T Values[256];
  real32_T x[256];
  real32_T b_x[256];
  real32_T b_y[128];
  SL_Bus_etasetgett_geometry_msgs_Vector3 In1_k;// '<S4>/In1'
  SL_Bus_etasetgett_geometry_msgs_Vector3 varargout_2_m;
  SL_Bus_etasetgett_geometry_msgs_Vector3 BusAssignment1;// '<S5>/Bus Assignment1' 
} B_etasetgett_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S7>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S9>/SinkBlock'
  void *SourceBlock_PWORK_d;           // '<S3>/SourceBlock'
  robotics_slros_internal_block_T obj; // '<S7>/SourceBlock'
  robotics_slros_internal_block_T obj_j;// '<S3>/SourceBlock'
  robotics_slros_internal_blo_k_T obj_jp;// '<S9>/SinkBlock'
  boolean_T objisempty;                // '<S7>/SourceBlock'
  boolean_T objisempty_l;              // '<S9>/SinkBlock'
  boolean_T objisempty_a;              // '<S3>/SourceBlock'
} DW_etasetgett_T;

// Parameters (auto storage)
struct P_etasetgett_T_ {
  SL_Bus_etasetgett_std_msgs_Float32MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S10>/Out1'

  SL_Bus_etasetgett_std_msgs_Float32MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S7>/Constant'

  SL_Bus_etasetgett_geometry_msgs_Vector3 Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                                    //  Referenced by: '<S4>/Out1'

  SL_Bus_etasetgett_geometry_msgs_Vector3 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                           //  Referenced by: '<S3>/Constant'

  SL_Bus_etasetgett_geometry_msgs_Vector3 Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                           //  Referenced by: '<S8>/Constant'

  real_T Constant_Value_ga;            // Expression: 0
                                       //  Referenced by: '<S5>/Constant'

  real_T Constant_Value_o;             // Expression: 0
                                       //  Referenced by: '<S1>/Constant'

  boolean_T Out1_Y0_o;                 // Computed Parameter: Out1_Y0_o
                                       //  Referenced by: '<S2>/Out1'

};

// Real-time Model Data Structure
struct tag_RTM_etasetgett_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_etasetgett_T etasetgett_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_etasetgett_T etasetgett_B;

// Block states (auto storage)
extern DW_etasetgett_T etasetgett_DW;

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
  extern void etasetgett_initialize(void);
  extern void etasetgett_step(void);
  extern void etasetgett_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_etasetgett_T *const etasetgett_M;

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
//  '<Root>' : 'etasetgett'
//  '<S1>'   : 'etasetgett/Subsystem'
//  '<S2>'   : 'etasetgett/Subsystem1'
//  '<S3>'   : 'etasetgett/Subsystem/Subscribe2'
//  '<S4>'   : 'etasetgett/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S5>'   : 'etasetgett/Subsystem1/EtaSet'
//  '<S6>'   : 'etasetgett/Subsystem1/MATLAB Function'
//  '<S7>'   : 'etasetgett/Subsystem1/Subscribe'
//  '<S8>'   : 'etasetgett/Subsystem1/EtaSet/Blank Message1'
//  '<S9>'   : 'etasetgett/Subsystem1/EtaSet/Publish1'
//  '<S10>'  : 'etasetgett/Subsystem1/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_etasetgett_h_

//
// File trailer for generated code.
//
// [EOF]
//
