//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etasetget.h
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
#ifndef RTW_HEADER_etasetget_h_
#define RTW_HEADER_etasetget_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef etasetget_COMMON_INCLUDES_
# define etasetget_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // etasetget_COMMON_INCLUDES_

#include "etasetget_types.h"
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
  SL_Bus_etasetget_std_msgs_Float32MultiArray In1;// '<S10>/In1'
  SL_Bus_etasetget_std_msgs_Float32MultiArray varargout_2;
  real_T b[128];
  real32_T Values[128];
  real32_T x[128];
  real32_T b_x[128];
  real32_T b_y[64];
  SL_Bus_etasetget_geometry_msgs_Vector3 In1_k;// '<S4>/In1'
  SL_Bus_etasetget_geometry_msgs_Vector3 varargout_2_m;
  SL_Bus_etasetget_geometry_msgs_Vector3 BusAssignment1;// '<S5>/Bus Assignment1' 
} B_etasetget_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S7>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S9>/SinkBlock'
  void *SourceBlock_PWORK_d;           // '<S3>/SourceBlock'
  robotics_slros_internal_block_T obj; // '<S7>/SourceBlock'
  robotics_slros_internal_block_T obj_j;// '<S3>/SourceBlock'
  robotics_slros_internal_blo_h_T obj_jp;// '<S9>/SinkBlock'
  boolean_T objisempty;                // '<S7>/SourceBlock'
  boolean_T objisempty_l;              // '<S9>/SinkBlock'
  boolean_T objisempty_a;              // '<S3>/SourceBlock'
} DW_etasetget_T;

// Parameters (auto storage)
struct P_etasetget_T_ {
  SL_Bus_etasetget_std_msgs_Float32MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                      //  Referenced by: '<S10>/Out1'

  SL_Bus_etasetget_std_msgs_Float32MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S7>/Constant'

  SL_Bus_etasetget_geometry_msgs_Vector3 Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                                   //  Referenced by: '<S4>/Out1'

  SL_Bus_etasetget_geometry_msgs_Vector3 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S3>/Constant'

  SL_Bus_etasetget_geometry_msgs_Vector3 Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                          //  Referenced by: '<S8>/Constant'

  real_T Constant_Value_ga;            // Expression: 0
                                       //  Referenced by: '<S5>/Constant'

  real_T Constant_Value_o;             // Expression: 0
                                       //  Referenced by: '<S1>/Constant'

  boolean_T Out1_Y0_o;                 // Computed Parameter: Out1_Y0_o
                                       //  Referenced by: '<S2>/Out1'

};

// Real-time Model Data Structure
struct tag_RTM_etasetget_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_etasetget_T etasetget_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_etasetget_T etasetget_B;

// Block states (auto storage)
extern DW_etasetget_T etasetget_DW;

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
  extern void etasetget_initialize(void);
  extern void etasetget_step(void);
  extern void etasetget_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_etasetget_T *const etasetget_M;

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
//  '<Root>' : 'etasetget'
//  '<S1>'   : 'etasetget/Subsystem'
//  '<S2>'   : 'etasetget/Subsystem1'
//  '<S3>'   : 'etasetget/Subsystem/Subscribe2'
//  '<S4>'   : 'etasetget/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S5>'   : 'etasetget/Subsystem1/EtaSet'
//  '<S6>'   : 'etasetget/Subsystem1/MATLAB Function'
//  '<S7>'   : 'etasetget/Subsystem1/Subscribe'
//  '<S8>'   : 'etasetget/Subsystem1/EtaSet/Blank Message1'
//  '<S9>'   : 'etasetget/Subsystem1/EtaSet/Publish1'
//  '<S10>'  : 'etasetget/Subsystem1/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_etasetget_h_

//
// File trailer for generated code.
//
// [EOF]
//
