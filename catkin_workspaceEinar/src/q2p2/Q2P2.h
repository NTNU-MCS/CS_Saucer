//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Q2P2.h
//
// Code generated for Simulink model 'Q2P2'.
//
// Model version                  : 1.64
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Mon Apr 11 11:33:13 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Q2P2_h_
#define RTW_HEADER_Q2P2_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Q2P2_COMMON_INCLUDES_
# define Q2P2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // Q2P2_COMMON_INCLUDES_

#include "Q2P2_types.h"
#include "rt_defines.h"
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
  SL_Bus_Q2P2_qualisys_Subject In1;    // '<S10>/In1'
  SL_Bus_Q2P2_qualisys_Subject varargout_2;
  SL_Bus_Q2P2_geometry_msgs_Vector3 In1_b;// '<S12>/In1'
  SL_Bus_Q2P2_geometry_msgs_Vector3 varargout_2_m;
  SL_Bus_Q2P2_geometry_msgs_Vector3 BusAssignment1;// '<S1>/Bus Assignment1'
} B_Q2P2_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S11>/SourceBlock'
  void *SourceBlock_PWORK_a;           // '<S3>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S6>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S6>/SinkBlock'
  robotics_slros_internal_blo_h_T obj_j;// '<S11>/SourceBlock'
  robotics_slros_internal_blo_h_T obj_h;// '<S3>/SourceBlock'
  boolean_T objisempty;                // '<S11>/SourceBlock'
  boolean_T objisempty_j;              // '<S3>/SourceBlock'
  boolean_T objisempty_a;              // '<S6>/SinkBlock'
} DW_Q2P2_T;

// Parameters (auto storage)
struct P_Q2P2_T_ {
  SL_Bus_Q2P2_qualisys_Subject Out1_Y0;// Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S10>/Out1'

  SL_Bus_Q2P2_qualisys_Subject Constant_Value;// Computed Parameter: Constant_Value
                                              //  Referenced by: '<S3>/Constant'

  SL_Bus_Q2P2_geometry_msgs_Vector3 Out1_Y0_g;// Computed Parameter: Out1_Y0_g
                                              //  Referenced by: '<S12>/Out1'

  SL_Bus_Q2P2_geometry_msgs_Vector3 Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                     //  Referenced by: '<S11>/Constant'

  SL_Bus_Q2P2_geometry_msgs_Vector3 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                     //  Referenced by: '<S5>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_Q2P2_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_Q2P2_T Q2P2_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_Q2P2_T Q2P2_B;

// Block states (auto storage)
extern DW_Q2P2_T Q2P2_DW;

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
  extern void Q2P2_initialize(void);
  extern void Q2P2_step(void);
  extern void Q2P2_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Q2P2_T *const Q2P2_M;

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
//  '<Root>' : 'Q2P2'
//  '<S1>'   : 'Q2P2/Eta'
//  '<S2>'   : 'Q2P2/Quaternions to Rotation Angles'
//  '<S3>'   : 'Q2P2/Subscribe2'
//  '<S4>'   : 'Q2P2/Subsystem1'
//  '<S5>'   : 'Q2P2/Eta/Blank Message1'
//  '<S6>'   : 'Q2P2/Eta/Publish1'
//  '<S7>'   : 'Q2P2/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S8>'   : 'Q2P2/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S9>'   : 'Q2P2/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S10>'  : 'Q2P2/Subscribe2/Enabled Subsystem'
//  '<S11>'  : 'Q2P2/Subsystem1/Subscribe2'
//  '<S12>'  : 'Q2P2/Subsystem1/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_Q2P2_h_

//
// File trailer for generated code.
//
// [EOF]
//
