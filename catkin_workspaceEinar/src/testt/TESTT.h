//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TESTT.h
//
// Code generated for Simulink model 'TESTT'.
//
// Model version                  : 1.55
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Thu Apr  7 20:04:11 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_TESTT_h_
#define RTW_HEADER_TESTT_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef TESTT_COMMON_INCLUDES_
# define TESTT_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // TESTT_COMMON_INCLUDES_

#include "TESTT_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  int16_T f_data[16384];
  SL_Bus_TESTT_nav_msgs_OccupancyGrid In1;// '<S9>/In1'
  SL_Bus_TESTT_nav_msgs_OccupancyGrid varargout_2;
  SL_Bus_TESTT_nav_msgs_OccupancyGrid BusAssignment1;// '<Root>/Bus Assignment1' 
  int8_T y[16384];                     // '<Root>/2Vector'
  int8_T y_o[16384];                   // '<Root>/2Matrix'
  SL_Bus_TESTT_geometry_msgs_PoseWithCovarianceStamped In1_h;// '<S11>/In1'
  SL_Bus_TESTT_geometry_msgs_PoseWithCovarianceStamped varargout_2_m;
  int8_T rtb_y_o_c[128];
} B_TESTT_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S10>/SourceBlock'
  void *SourceBlock_PWORK_c;           // '<S7>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S6>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S6>/SinkBlock'
  robotics_slros_internal_blo_c_T obj_n;// '<S10>/SourceBlock'
  robotics_slros_internal_blo_c_T obj_m;// '<S7>/SourceBlock'
  boolean_T objisempty;                // '<S10>/SourceBlock'
  boolean_T objisempty_l;              // '<S7>/SourceBlock'
  boolean_T objisempty_k;              // '<S6>/SinkBlock'
} DW_TESTT_T;

// Parameters (auto storage)
struct P_TESTT_T_ {
  real_T REFMAP[16384];                // Variable: REFMAP
                                       //  Referenced by: '<Root>/Constant'

  SL_Bus_TESTT_nav_msgs_OccupancyGrid Out1_Y0;// Computed Parameter: Out1_Y0
                                              //  Referenced by: '<S9>/Out1'

  SL_Bus_TESTT_nav_msgs_OccupancyGrid Constant_Value;// Computed Parameter: Constant_Value
                                                     //  Referenced by: '<S7>/Constant'

  SL_Bus_TESTT_nav_msgs_OccupancyGrid Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                       //  Referenced by: '<S4>/Constant'

  SL_Bus_TESTT_geometry_msgs_PoseWithCovarianceStamped Out1_Y0_a;// Computed Parameter: Out1_Y0_a
                                                                 //  Referenced by: '<S11>/Out1'

  SL_Bus_TESTT_geometry_msgs_PoseWithCovarianceStamped Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                      //  Referenced by: '<S10>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_TESTT_T {
  const char_T * volatile errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_TESTT_T TESTT_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_TESTT_T TESTT_B;

// Block states (auto storage)
extern DW_TESTT_T TESTT_DW;

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
  extern void TESTT_initialize(void);
  extern void TESTT_step(void);
  extern void TESTT_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_TESTT_T *const TESTT_M;

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
//  '<Root>' : 'TESTT'
//  '<S1>'   : 'TESTT/2Matrix'
//  '<S2>'   : 'TESTT/2Vector'
//  '<S3>'   : 'TESTT/2Vector1'
//  '<S4>'   : 'TESTT/Blank Message1'
//  '<S5>'   : 'TESTT/LidarUpdate1'
//  '<S6>'   : 'TESTT/Publish2'
//  '<S7>'   : 'TESTT/Subscribe'
//  '<S8>'   : 'TESTT/Subsystem1'
//  '<S9>'   : 'TESTT/Subscribe/Enabled Subsystem'
//  '<S10>'  : 'TESTT/Subsystem1/Subscribe'
//  '<S11>'  : 'TESTT/Subsystem1/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_TESTT_h_

//
// File trailer for generated code.
//
// [EOF]
//
