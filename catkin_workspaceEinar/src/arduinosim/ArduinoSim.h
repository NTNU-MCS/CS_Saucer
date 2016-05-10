//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ArduinoSim.h
//
// Code generated for Simulink model 'ArduinoSim'.
//
// Model version                  : 1.13
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sat Feb 20 18:11:47 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ArduinoSim_h_
#define RTW_HEADER_ArduinoSim_h_
#include <stddef.h>
#include <string.h>
#ifndef ArduinoSim_COMMON_INCLUDES_
# define ArduinoSim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // ArduinoSim_COMMON_INCLUDES_

#include "ArduinoSim_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  SL_Bus_ArduinoSim_std_msgs_Float64 In1;// '<S10>/In1'
  SL_Bus_ArduinoSim_std_msgs_Float64 In1_p;// '<S9>/In1'
  SL_Bus_ArduinoSim_std_msgs_Float64 In1_j;// '<S8>/In1'
  SL_Bus_ArduinoSim_std_msgs_Float64 varargout_2;
} B_ArduinoSim_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SinkBlock_PWORK;               // '<S14>/SinkBlock'
  void *SinkBlock_PWORK_i;             // '<S13>/SinkBlock'
  void *SinkBlock_PWORK_m;             // '<S12>/SinkBlock'
  void *SourceBlock_PWORK;             // '<S7>/SourceBlock'
  void *SourceBlock_PWORK_a;           // '<S6>/SourceBlock'
  void *SourceBlock_PWORK_k;           // '<S5>/SourceBlock'
  robotics_slros_internal_block_T obj; // '<S7>/SourceBlock'
  robotics_slros_internal_block_T obj_d;// '<S6>/SourceBlock'
  robotics_slros_internal_block_T obj_g;// '<S5>/SourceBlock'
  robotics_slros_internal_blo_j_T obj_i;// '<S14>/SinkBlock'
  robotics_slros_internal_blo_j_T obj_h;// '<S13>/SinkBlock'
  robotics_slros_internal_blo_j_T obj_ij;// '<S12>/SinkBlock'
  boolean_T objisempty;                // '<S14>/SinkBlock'
  boolean_T objisempty_i;              // '<S13>/SinkBlock'
  boolean_T objisempty_p;              // '<S12>/SinkBlock'
  boolean_T objisempty_g;              // '<S7>/SourceBlock'
  boolean_T objisempty_l;              // '<S6>/SourceBlock'
  boolean_T objisempty_h;              // '<S5>/SourceBlock'
} DW_ArduinoSim_T;

// Parameters (auto storage)
struct P_ArduinoSim_T_ {
  SL_Bus_ArduinoSim_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                             //  Referenced by: '<S8>/Out1'

  SL_Bus_ArduinoSim_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                    //  Referenced by: '<S5>/Constant'

  SL_Bus_ArduinoSim_std_msgs_Float64 Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                               //  Referenced by: '<S9>/Out1'

  SL_Bus_ArduinoSim_std_msgs_Float64 Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                      //  Referenced by: '<S6>/Constant'

  SL_Bus_ArduinoSim_std_msgs_Float64 Out1_Y0_b;// Computed Parameter: Out1_Y0_b
                                               //  Referenced by: '<S10>/Out1'

  SL_Bus_ArduinoSim_std_msgs_Float64 Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                      //  Referenced by: '<S7>/Constant'

  SL_Bus_ArduinoSim_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                      //  Referenced by: '<S11>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_ArduinoSim_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ArduinoSim_T ArduinoSim_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_ArduinoSim_T ArduinoSim_B;

// Block states (auto storage)
extern DW_ArduinoSim_T ArduinoSim_DW;

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
  extern void ArduinoSim_initialize(void);
  extern void ArduinoSim_step(void);
  extern void ArduinoSim_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ArduinoSim_T *const ArduinoSim_M;

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
//  '<Root>' : 'ArduinoSim'
//  '<S1>'   : 'ArduinoSim/Inv_PWM-Mapping'
//  '<S2>'   : 'ArduinoSim/PwmINn'
//  '<S3>'   : 'ArduinoSim/U_out'
//  '<S4>'   : 'ArduinoSim/inv_deadzone'
//  '<S5>'   : 'ArduinoSim/PwmINn/Subscribe'
//  '<S6>'   : 'ArduinoSim/PwmINn/Subscribe1'
//  '<S7>'   : 'ArduinoSim/PwmINn/Subscribe2'
//  '<S8>'   : 'ArduinoSim/PwmINn/Subscribe/Enabled Subsystem'
//  '<S9>'   : 'ArduinoSim/PwmINn/Subscribe1/Enabled Subsystem'
//  '<S10>'  : 'ArduinoSim/PwmINn/Subscribe2/Enabled Subsystem'
//  '<S11>'  : 'ArduinoSim/U_out/Blank Message1'
//  '<S12>'  : 'ArduinoSim/U_out/Publish1'
//  '<S13>'  : 'ArduinoSim/U_out/Publish2'
//  '<S14>'  : 'ArduinoSim/U_out/Publish3'

#endif                                 // RTW_HEADER_ArduinoSim_h_

//
// File trailer for generated code.
//
// [EOF]
//
