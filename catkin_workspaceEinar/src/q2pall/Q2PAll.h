//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Q2PAll.h
//
// Code generated for Simulink model 'Q2PAll'.
//
// Model version                  : 1.66
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Apr 20 14:43:07 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Q2PAll_h_
#define RTW_HEADER_Q2PAll_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef Q2PAll_COMMON_INCLUDES_
# define Q2PAll_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // Q2PAll_COMMON_INCLUDES_

#include "Q2PAll_types.h"
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
  SL_Bus_Q2PAll_qualisys_Subject In1;  // '<S12>/In1'
  SL_Bus_Q2PAll_qualisys_Subject varargout_2;
  SL_Bus_Q2PAll_geometry_msgs_Vector3 BusAssignment1;// '<S1>/Bus Assignment1'
  SL_Bus_Q2PAll_geometry_msgs_Vector3 BusAssignment1_i;// '<S2>/Bus Assignment1' 
  real_T Product3_m;                   // '<S9>/Product3'
} B_Q2PAll_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S4>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S8>/SinkBlock'
  void *SinkBlock_PWORK_k;             // '<S6>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S8>/SinkBlock'
  robotics_slros_internal_block_T obj_l;// '<S6>/SinkBlock'
  robotics_slros_internal_blo_e_T obj_h;// '<S4>/SourceBlock'
  boolean_T objisempty;                // '<S4>/SourceBlock'
  boolean_T objisempty_k;              // '<S8>/SinkBlock'
  boolean_T objisempty_a;              // '<S6>/SinkBlock'
} DW_Q2PAll_T;

// Parameters (auto storage)
struct P_Q2PAll_T_ {
  SL_Bus_Q2PAll_qualisys_Subject Out1_Y0;// Computed Parameter: Out1_Y0
                                         //  Referenced by: '<S12>/Out1'

  SL_Bus_Q2PAll_qualisys_Subject Constant_Value;// Computed Parameter: Constant_Value
                                                //  Referenced by: '<S4>/Constant'

  SL_Bus_Q2PAll_geometry_msgs_Vector3 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                       //  Referenced by: '<S5>/Constant'

  SL_Bus_Q2PAll_geometry_msgs_Vector3 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                       //  Referenced by: '<S7>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_Q2PAll_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_Q2PAll_T Q2PAll_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_Q2PAll_T Q2PAll_B;

// Block states (auto storage)
extern DW_Q2PAll_T Q2PAll_DW;

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
  extern void Q2PAll_initialize(void);
  extern void Q2PAll_step(void);
  extern void Q2PAll_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Q2PAll_T *const Q2PAll_M;

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
//  '<Root>' : 'Q2PAll'
//  '<S1>'   : 'Q2PAll/Eta'
//  '<S2>'   : 'Q2PAll/EulerAng'
//  '<S3>'   : 'Q2PAll/Quaternions to Rotation Angles'
//  '<S4>'   : 'Q2PAll/Subscribe2'
//  '<S5>'   : 'Q2PAll/Eta/Blank Message1'
//  '<S6>'   : 'Q2PAll/Eta/Publish1'
//  '<S7>'   : 'Q2PAll/EulerAng/Blank Message1'
//  '<S8>'   : 'Q2PAll/EulerAng/Publish1'
//  '<S9>'   : 'Q2PAll/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S10>'  : 'Q2PAll/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S11>'  : 'Q2PAll/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S12>'  : 'Q2PAll/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_Q2PAll_h_

//
// File trailer for generated code.
//
// [EOF]
//
