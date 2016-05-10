//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mindistfromscan2.h
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
#ifndef RTW_HEADER_mindistfromscan2_h_
#define RTW_HEADER_mindistfromscan2_h_
#include <stddef.h>
#include <string.h>
#ifndef mindistfromscan2_COMMON_INCLUDES_
# define mindistfromscan2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // mindistfromscan2_COMMON_INCLUDES_

#include "mindistfromscan2_types.h"
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
  SL_Bus_mindistfromscan2_sensor_msgs_LaserScan In1;// '<S7>/In1'
  SL_Bus_mindistfromscan2_sensor_msgs_LaserScan varargout_2;
} B_mindistfromscan2_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S6>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S4>/SinkBlock'
  void *SinkBlock_PWORK_h;             // '<S3>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S4>/SinkBlock'
  robotics_slros_internal_block_T obj_k;// '<S3>/SinkBlock'
  robotics_slros_internal_blo_j_T obj_c;// '<S6>/SourceBlock'
  boolean_T objisempty;                // '<S6>/SourceBlock'
  boolean_T objisempty_f;              // '<S4>/SinkBlock'
  boolean_T objisempty_fg;             // '<S3>/SinkBlock'
} DW_mindistfromscan2_T;

// Parameters (auto storage)
struct P_mindistfromscan2_T_ {
  SL_Bus_mindistfromscan2_sensor_msgs_LaserScan Out1_Y0;// Computed Parameter: Out1_Y0
                                                        //  Referenced by: '<S7>/Out1'

  SL_Bus_mindistfromscan2_sensor_msgs_LaserScan Constant_Value;// Computed Parameter: Constant_Value
                                                               //  Referenced by: '<S6>/Constant'

  SL_Bus_mindistfromscan2_std_msgs_Float32 Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                            //  Referenced by: '<S1>/Constant'

  SL_Bus_mindistfromscan2_std_msgs_Float64 Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                            //  Referenced by: '<S2>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_mindistfromscan2_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_mindistfromscan2_T mindistfromscan2_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_mindistfromscan2_T mindistfromscan2_B;

// Block states (auto storage)
extern DW_mindistfromscan2_T mindistfromscan2_DW;

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
  extern void mindistfromscan2_initialize(void);
  extern void mindistfromscan2_step(void);
  extern void mindistfromscan2_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_mindistfromscan2_T *const mindistfromscan2_M;

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
//  '<Root>' : 'mindistfromscan2'
//  '<S1>'   : 'mindistfromscan2/Blank Message1'
//  '<S2>'   : 'mindistfromscan2/Blank Message2'
//  '<S3>'   : 'mindistfromscan2/Publish1'
//  '<S4>'   : 'mindistfromscan2/Publish2'
//  '<S5>'   : 'mindistfromscan2/ReadDist'
//  '<S6>'   : 'mindistfromscan2/Subscribe1'
//  '<S7>'   : 'mindistfromscan2/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_mindistfromscan2_h_

//
// File trailer for generated code.
//
// [EOF]
//
