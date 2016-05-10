//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: etalisttoset.h
//
// Code generated for Simulink model 'etalisttoset'.
//
// Model version                  : 1.31
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Tue Apr 12 13:16:37 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_etalisttoset_h_
#define RTW_HEADER_etalisttoset_h_
#include <string.h>
#include <stddef.h>
#ifndef etalisttoset_COMMON_INCLUDES_
# define etalisttoset_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // etalisttoset_COMMON_INCLUDES_

#include "etalisttoset_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_etalisttoset_std_msgs_Float32MultiArray In1;// '<S7>/In1'
  SL_Bus_etalisttoset_std_msgs_Float32MultiArray varargout_2;
  real32_T Values[128];
  SL_Bus_etalisttoset_geometry_msgs_Vector3 In1_p;// '<S9>/In1'
  SL_Bus_etalisttoset_geometry_msgs_Vector3 varargout_2_m;
} B_etalisttoset_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S8>/SourceBlock'
  void *SourceBlock_PWORK_i;           // '<S3>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S6>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S6>/SinkBlock'
  robotics_slros_internal_blo_b_T obj_i;// '<S8>/SourceBlock'
  robotics_slros_internal_blo_b_T obj_l;// '<S3>/SourceBlock'
  boolean_T objisempty;                // '<S8>/SourceBlock'
  boolean_T objisempty_g;              // '<S3>/SourceBlock'
  boolean_T objisempty_o;              // '<S6>/SinkBlock'
} DW_etalisttoset_T;

// Parameters (auto storage)
struct P_etalisttoset_T_ {
  SL_Bus_etalisttoset_std_msgs_Float32MultiArray Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S7>/Out1'

  SL_Bus_etalisttoset_std_msgs_Float32MultiArray Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S3>/Constant'

  SL_Bus_etalisttoset_geometry_msgs_Vector3 Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                                      //  Referenced by: '<S9>/Out1'

  SL_Bus_etalisttoset_geometry_msgs_Vector3 Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                             //  Referenced by: '<S8>/Constant'

  SL_Bus_etalisttoset_geometry_msgs_Vector3 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                             //  Referenced by: '<S5>/Constant'

  real_T Constant_Value_h;             // Expression: 0
                                       //  Referenced by: '<S4>/Constant'

  real_T Constant_Value_c;             // Expression: 0
                                       //  Referenced by: '<S1>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_etalisttoset_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_etalisttoset_T etalisttoset_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_etalisttoset_T etalisttoset_B;

// Block states (auto storage)
extern DW_etalisttoset_T etalisttoset_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void etalisttoset_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void etalisttoset_SetEventsForThisBaseStep(boolean_T *eventFlags);
  extern void etalisttoset_initialize(void);
  extern void etalisttoset_step(int_T tid);
  extern void etalisttoset_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_etalisttoset_T *const etalisttoset_M;

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
//  '<Root>' : 'etalisttoset'
//  '<S1>'   : 'etalisttoset/EtaSet'
//  '<S2>'   : 'etalisttoset/MATLAB Function'
//  '<S3>'   : 'etalisttoset/Subscribe'
//  '<S4>'   : 'etalisttoset/Subsystem'
//  '<S5>'   : 'etalisttoset/EtaSet/Blank Message1'
//  '<S6>'   : 'etalisttoset/EtaSet/Publish1'
//  '<S7>'   : 'etalisttoset/Subscribe/Enabled Subsystem'
//  '<S8>'   : 'etalisttoset/Subsystem/Subscribe2'
//  '<S9>'   : 'etalisttoset/Subsystem/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_etalisttoset_h_

//
// File trailer for generated code.
//
// [EOF]
//
