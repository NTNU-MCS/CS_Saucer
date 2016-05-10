//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: LidarMapSim.h
//
// Code generated for Simulink model 'LidarMapSim'.
//
// Model version                  : 1.65
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Apr 27 17:41:22 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_LidarMapSim_h_
#define RTW_HEADER_LidarMapSim_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef LidarMapSim_COMMON_INCLUDES_
# define LidarMapSim_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // LidarMapSim_COMMON_INCLUDES_

#include "LidarMapSim_types.h"

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
  SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid In1;// '<S8>/In1'
  SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid varargout_2;
  SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid BusAssignment1;// '<Root>/Bus Assignment1' 
  int8_T y[16384];                     // '<Root>/2Vector'
  int8_T y_o[16384];                   // '<Root>/2Matrix'
  int8_T rtb_y_o_m[128];
  SL_Bus_LidarMapSim_geometry_msgs_Vector3 In1_i;// '<S10>/In1'
  SL_Bus_LidarMapSim_geometry_msgs_Vector3 varargout_2_c;
} B_LidarMapSim_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S9>/SourceBlock'
  void *SourceBlock_PWORK_c;           // '<S6>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S5>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S5>/SinkBlock'
  robotics_slros_internal_blo_b_T obj_f;// '<S9>/SourceBlock'
  robotics_slros_internal_blo_b_T obj_m;// '<S6>/SourceBlock'
  boolean_T objisempty;                // '<S9>/SourceBlock'
  boolean_T objisempty_l;              // '<S6>/SourceBlock'
  boolean_T objisempty_k;              // '<S5>/SinkBlock'
} DW_LidarMapSim_T;

// Parameters (auto storage)
struct P_LidarMapSim_T_ {
  real_T REFMAP[16384];                // Variable: REFMAP
                                       //  Referenced by: '<Root>/Constant'

  SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid Out1_Y0;// Computed Parameter: Out1_Y0
                                                    //  Referenced by: '<S8>/Out1'

  SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid Constant_Value;// Computed Parameter: Constant_Value
                                                           //  Referenced by: '<S6>/Constant'

  SL_Bus_LidarMapSim_nav_msgs_OccupancyGrid Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                             //  Referenced by: '<S3>/Constant'

  SL_Bus_LidarMapSim_geometry_msgs_Vector3 Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                     //  Referenced by: '<S10>/Out1'

  SL_Bus_LidarMapSim_geometry_msgs_Vector3 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                            //  Referenced by: '<S9>/Constant'

  real_T Gain_Gain;                    // Expression: -1
                                       //  Referenced by: '<S7>/Gain'

  real_T Constant_Value_be;            // Expression: 0
                                       //  Referenced by: '<S7>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_LidarMapSim_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_LidarMapSim_T LidarMapSim_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_LidarMapSim_T LidarMapSim_B;

// Block states (auto storage)
extern DW_LidarMapSim_T LidarMapSim_DW;

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
  extern void LidarMapSim_initialize(void);
  extern void LidarMapSim_step(void);
  extern void LidarMapSim_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_LidarMapSim_T *const LidarMapSim_M;

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
//  '<Root>' : 'LidarMapSim'
//  '<S1>'   : 'LidarMapSim/2Matrix'
//  '<S2>'   : 'LidarMapSim/2Vector'
//  '<S3>'   : 'LidarMapSim/Blank Message1'
//  '<S4>'   : 'LidarMapSim/LidarUpdate1'
//  '<S5>'   : 'LidarMapSim/Publish2'
//  '<S6>'   : 'LidarMapSim/Subscribe'
//  '<S7>'   : 'LidarMapSim/Subsystem'
//  '<S8>'   : 'LidarMapSim/Subscribe/Enabled Subsystem'
//  '<S9>'   : 'LidarMapSim/Subsystem/Subscribe2'
//  '<S10>'  : 'LidarMapSim/Subsystem/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_LidarMapSim_h_

//
// File trailer for generated code.
//
// [EOF]
//
