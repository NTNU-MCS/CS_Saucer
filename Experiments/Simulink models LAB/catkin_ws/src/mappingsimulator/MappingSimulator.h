//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MappingSimulator.h
//
// Code generated for Simulink model 'MappingSimulator'.
//
// Model version                  : 1.130
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Jun 22 14:54:41 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_MappingSimulator_h_
#define RTW_HEADER_MappingSimulator_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MappingSimulator_COMMON_INCLUDES_
# define MappingSimulator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slros_initialize.h"
#endif                                 // MappingSimulator_COMMON_INCLUDES_

#include "MappingSimulator_types.h"
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
  int32_T f_data[65536];
  SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid In1;// '<S3>/In1'
  SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid varargout_2;
  SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid BusAssignment1;// '<S2>/Bus Assignment1' 
  int8_T y[65536];                     // '<S2>/2Vector'
  int8_T y_o[65536];                   // '<S2>/2Matrix'
  real_T RREG[361];
  int16_T d_data[361];
  int8_T rtb_y_o_m[256];
  SL_Bus_MappingSimulator_geometry_msgs_Vector3 In1_i;// '<S13>/In1'
  SL_Bus_MappingSimulator_geometry_msgs_Vector3 varargout_2_c;
  real_T Radangle;
} B_MappingSimulator_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S12>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S10>/SinkBlock'
  void *SinkBlock_PWORK_c;             // '<S9>/SinkBlock'
  void *SourceBlock_PWORK_c;           // '<S1>/SourceBlock'
  robotics_slros_internal_block_T obj; // '<S12>/SourceBlock'
  robotics_slros_internal_block_T obj_m;// '<S1>/SourceBlock'
  robotics_slros_internal_blo_f_T obj_o;// '<S10>/SinkBlock'
  robotics_slros_internal_blo_f_T obj_e;// '<S9>/SinkBlock'
  boolean_T objisempty;                // '<S12>/SourceBlock'
  boolean_T objisempty_k;              // '<S10>/SinkBlock'
  boolean_T objisempty_kk;             // '<S9>/SinkBlock'
  boolean_T objisempty_l;              // '<S1>/SourceBlock'
} DW_MappingSimulator_T;

// Parameters (auto storage)
struct P_MappingSimulator_T_ {
  int8_T REFMAP[65536];                // Variable: REFMAP
                                       //  Referenced by: '<S2>/Constant'

  SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid Out1_Y0;// Computed Parameter: Out1_Y0
                                                         //  Referenced by: '<S3>/Out1'

  SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid Constant_Value;// Computed Parameter: Constant_Value
                                                                //  Referenced by: '<S1>/Constant'

  SL_Bus_MappingSimulator_nav_msgs_OccupancyGrid Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                                  //  Referenced by: '<S6>/Constant'

  SL_Bus_MappingSimulator_geometry_msgs_Vector3 Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                          //  Referenced by: '<S13>/Out1'

  SL_Bus_MappingSimulator_geometry_msgs_Vector3 Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                                 //  Referenced by: '<S12>/Constant'

  real_T Gain_Gain;                    // Expression: -1
                                       //  Referenced by: '<S11>/Gain'

  real_T Constant_Value_be;            // Expression: 0
                                       //  Referenced by: '<S11>/Constant'

  SL_Bus_MappingSimulator_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                            //  Referenced by: '<S7>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_MappingSimulator_T {
  const char_T *errorStatus;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_MappingSimulator_T MappingSimulator_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_MappingSimulator_T MappingSimulator_B;

// Block states (auto storage)
extern DW_MappingSimulator_T MappingSimulator_DW;

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
  extern void MappingSimulator_initialize(void);
  extern void MappingSimulator_step(void);
  extern void MappingSimulator_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_MappingSimulator_T *const MappingSimulator_M;

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
//  '<Root>' : 'MappingSimulator'
//  '<S1>'   : 'MappingSimulator/Subscribe'
//  '<S2>'   : 'MappingSimulator/Subsystem1'
//  '<S3>'   : 'MappingSimulator/Subscribe/Enabled Subsystem'
//  '<S4>'   : 'MappingSimulator/Subsystem1/2Matrix'
//  '<S5>'   : 'MappingSimulator/Subsystem1/2Vector'
//  '<S6>'   : 'MappingSimulator/Subsystem1/Blank Message1'
//  '<S7>'   : 'MappingSimulator/Subsystem1/Blank Message2'
//  '<S8>'   : 'MappingSimulator/Subsystem1/Lidar Dont See Wall'
//  '<S9>'   : 'MappingSimulator/Subsystem1/Publish1'
//  '<S10>'  : 'MappingSimulator/Subsystem1/Publish2'
//  '<S11>'  : 'MappingSimulator/Subsystem1/Subsystem'
//  '<S12>'  : 'MappingSimulator/Subsystem1/Subsystem/Subscribe2'
//  '<S13>'  : 'MappingSimulator/Subsystem1/Subsystem/Subscribe2/Enabled Subsystem'

#endif                                 // RTW_HEADER_MappingSimulator_h_

//
// File trailer for generated code.
//
// [EOF]
//
