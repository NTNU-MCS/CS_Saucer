//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: VesselSimulator.h
//
// Code generated for Simulink model 'VesselSimulator'.
//
// Model version                  : 1.27
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Wed Jun 22 13:00:06 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_VesselSimulator_h_
#define RTW_HEADER_VesselSimulator_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef VesselSimulator_COMMON_INCLUDES_
# define VesselSimulator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // VesselSimulator_COMMON_INCLUDES_

#include "VesselSimulator_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

// Block signals (auto storage)
typedef struct {
  real_T TH3[62];
  real_T y[62];
  real_T x[62];
  real_T y_m[52];
  real_T x_c[52];
  real_T dv0[9];
  real_T dv1[9];
  SL_Bus_VesselSimulator_geometry_msgs_Vector3 BusAssignment1;// '<S3>/Bus Assignment1' 
  real_T Product[3];                   // '<Root>/Product'
  real_T Gain[3];                      // '<S4>/Gain'
  real_T Product2[3];                  // '<S4>/Product2'
  real_T dv2[3];
  real_T dv3[3];
  real_T dv4[3];
  real_T tmp;
  real_T r;
  real_T rtb_ManualSwitch1_idx_0;
  real_T rtb_ManualSwitch1_idx_1;
  real_T rtb_ManualSwitch1_idx_2;
  SL_Bus_VesselSimulator_std_msgs_UInt16 In1;// '<S11>/In1'
  SL_Bus_VesselSimulator_std_msgs_UInt16 In1_i;// '<S10>/In1'
  SL_Bus_VesselSimulator_std_msgs_UInt16 In1_p;// '<S9>/In1'
} B_VesselSimulator_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SinkBlock_PWORK;               // '<S13>/SinkBlock'
  void *SourceBlock_PWORK;             // '<S8>/SourceBlock'
  void *SourceBlock_PWORK_n;           // '<S7>/SourceBlock'
  void *SourceBlock_PWORK_a;           // '<S6>/SourceBlock'
  robotics_slros_internal_block_T obj; // '<S8>/SourceBlock'
  robotics_slros_internal_block_T obj_d;// '<S7>/SourceBlock'
  robotics_slros_internal_block_T obj_dv;// '<S6>/SourceBlock'
  robotics_slros_internal_blo_a_T obj_o;// '<S13>/SinkBlock'
  boolean_T objisempty;                // '<S13>/SinkBlock'
  boolean_T objisempty_a;              // '<S8>/SourceBlock'
  boolean_T objisempty_p;              // '<S7>/SourceBlock'
  boolean_T objisempty_l;              // '<S6>/SourceBlock'
} DW_VesselSimulator_T;

// Continuous states (auto storage)
typedef struct {
  real_T Integrator1_CSTATE[3];        // '<S4>/Integrator1'
  real_T Integrator2_CSTATE[3];        // '<S4>/Integrator2'
} X_VesselSimulator_T;

// State derivatives (auto storage)
typedef struct {
  real_T Integrator1_CSTATE[3];        // '<S4>/Integrator1'
  real_T Integrator2_CSTATE[3];        // '<S4>/Integrator2'
} XDot_VesselSimulator_T;

// State disabled
typedef struct {
  boolean_T Integrator1_CSTATE[3];     // '<S4>/Integrator1'
  boolean_T Integrator2_CSTATE[3];     // '<S4>/Integrator2'
} XDis_VesselSimulator_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (auto storage)
struct P_VesselSimulator_T_ {
  real_T C_nuParams[9];                // Variable: C_nuParams
                                       //  Referenced by: '<S4>/Constant1'

  real_T D[9];                         // Variable: D
                                       //  Referenced by: '<S4>/Gain1'

  real_T D_nuParams[9];                // Variable: D_nuParams
                                       //  Referenced by: '<S4>/Constant'

  real_T MAPP1[62];                    // Variable: MAPP1
                                       //  Referenced by: '<S1>/Constant3'

  real_T MAPP2[52];                    // Variable: MAPP2
                                       //  Referenced by: '<S1>/Constant1'

  real_T MAPP3[46];                    // Variable: MAPP3
                                       //  Referenced by: '<S1>/Constant2'

  real_T Th1[62];                      // Variable: Th1
                                       //  Referenced by: '<S1>/Constant4'

  real_T Th2[52];                      // Variable: Th2
                                       //  Referenced by: '<S1>/Constant5'

  real_T Th3[46];                      // Variable: Th3
                                       //  Referenced by: '<S1>/Constant6'

  real_T Tr[9];                        // Variable: Tr
                                       //  Referenced by: '<Root>/Thrust allocation Matrix'

  real_T invM[9];                      // Variable: invM
                                       //  Referenced by: '<S4>/Gain'

  SL_Bus_VesselSimulator_geometry_msgs_Vector3 Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S12>/Constant'

  real_T Constant7_Value;              // Expression: 0.1
                                       //  Referenced by: '<S1>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                       //  Referenced by: '<S1>/Constant8'

  real_T Constant9_Value;              // Expression: 0
                                       //  Referenced by: '<S1>/Constant9'

  real_T Integrator1_IC[3];            // Expression: [0;0;0]
                                       //  Referenced by: '<S4>/Integrator1'

  real_T Integrator2_IC[3];            // Expression: [0; 0; 0]
                                       //  Referenced by: '<S4>/Integrator2'

  SL_Bus_VesselSimulator_std_msgs_UInt16 Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S9>/Out1'

  SL_Bus_VesselSimulator_std_msgs_UInt16 Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                          //  Referenced by: '<S6>/Constant'

  SL_Bus_VesselSimulator_std_msgs_UInt16 Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                                   //  Referenced by: '<S10>/Out1'

  SL_Bus_VesselSimulator_std_msgs_UInt16 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                          //  Referenced by: '<S7>/Constant'

  SL_Bus_VesselSimulator_std_msgs_UInt16 Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                   //  Referenced by: '<S11>/Out1'

  SL_Bus_VesselSimulator_std_msgs_UInt16 Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                          //  Referenced by: '<S8>/Constant'

  uint8_T ManualSwitch1_CurrentSetting;// Computed Parameter: ManualSwitch1_CurrentSetting
                                       //  Referenced by: '<S1>/Manual Switch1'

};

// Real-time Model Data Structure
struct tag_RTM_VesselSimulator_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  ModelData:
  //  The following substructure contains information regarding
  //  the data used in the model.

  struct {
    X_VesselSimulator_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[6];
    real_T odeF[3][6];
    ODE3_IntgData intgData;
  } ModelData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_VesselSimulator_T VesselSimulator_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_VesselSimulator_T VesselSimulator_B;

// Continuous states (auto storage)
extern X_VesselSimulator_T VesselSimulator_X;

// Block states (auto storage)
extern DW_VesselSimulator_T VesselSimulator_DW;

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
  extern void VesselSimulator_initialize(void);
  extern void VesselSimulator_step(void);
  extern void VesselSimulator_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_VesselSimulator_T *const VesselSimulator_M;

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
//  '<Root>' : 'VesselSimulator'
//  '<S1>'   : 'VesselSimulator/InverseMap180toU'
//  '<S2>'   : 'VesselSimulator/Subsystem'
//  '<S3>'   : 'VesselSimulator/U out1'
//  '<S4>'   : 'VesselSimulator/Vessel Dynamics'
//  '<S5>'   : 'VesselSimulator/InverseMap180toU/PWM-Mapping'
//  '<S6>'   : 'VesselSimulator/Subsystem/Subscribe1'
//  '<S7>'   : 'VesselSimulator/Subsystem/Subscribe2'
//  '<S8>'   : 'VesselSimulator/Subsystem/Subscribe3'
//  '<S9>'   : 'VesselSimulator/Subsystem/Subscribe1/Enabled Subsystem'
//  '<S10>'  : 'VesselSimulator/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S11>'  : 'VesselSimulator/Subsystem/Subscribe3/Enabled Subsystem'
//  '<S12>'  : 'VesselSimulator/U out1/Blank Message1'
//  '<S13>'  : 'VesselSimulator/U out1/Publish1'
//  '<S14>'  : 'VesselSimulator/Vessel Dynamics/C_nu1'
//  '<S15>'  : 'VesselSimulator/Vessel Dynamics/D_nu'
//  '<S16>'  : 'VesselSimulator/Vessel Dynamics/MATLAB Function'

#endif                                 // RTW_HEADER_VesselSimulator_h_

//
// File trailer for generated code.
//
// [EOF]
//
