//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS_Controller.h
//
// Code generated for Simulink model 'ROS_Controller'.
//
// Model version                  : 1.24
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sun Apr 10 13:42:56 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ROS_Controller_h_
#define RTW_HEADER_ROS_Controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ROS_Controller_COMMON_INCLUDES_
# define ROS_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // ROS_Controller_COMMON_INCLUDES_

#include "ROS_Controller_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

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
  real_T R[9];                         // '<S9>/MATLAB Function1'
  real_T R_t[9];                       // '<S9>/MATLAB Function'
  real_T R_c[9];                       // '<S1>/Rotation Matrix'
  real_T dv0[9];
  SL_Bus_ROS_Controller_geometry_msgs_Vector3 In1;// '<S17>/In1'
  SL_Bus_ROS_Controller_geometry_msgs_Vector3 In1_i;// '<S15>/In1'
  SL_Bus_ROS_Controller_geometry_msgs_Vector3 BusAssignment1;// '<S7>/Bus Assignment1' 
  real_T Integrator2[3];               // '<S5>/Integrator2'
  real_T Gain1[3];                     // '<S1>/Gain1'
  real_T Product1[3];                  // '<S9>/Product1'
  real_T Sum1[3];                      // '<S9>/Sum1'
  real_T Sum4[3];                      // '<S9>/Sum4'
  real_T Saturation4[3];               // '<S5>/Saturation4'
  real_T Sum3[3];                      // '<S5>/Sum3'
  real_T w_n[3];                       // '<S5>/w_n'
  real_T Gain[3];                      // '<S9>/Gain'
  real_T nframetobframe[3];            // '<S9>/{n} frame to {b} frame'
  real_T Gain1_m[3];                   // '<S9>/Gain1'
  real_T Sum2[3];                      // '<S1>/Sum2'
  real_T dv1[3];
  real_T dv2[3];
  real_T dv3[3];
  real_T dv4[3];
  real_T dv5[3];
  real_T Saturation5;                  // '<S6>/Saturation5'
  real_T Saturation6;                  // '<S6>/Saturation6'
  real_T Saturation7;                  // '<S6>/Saturation7'
} B_ROS_Controller_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T TimeStampA;                   // '<S1>/Derivative'
  real_T LastUAtTimeA[3];              // '<S1>/Derivative'
  real_T TimeStampB;                   // '<S1>/Derivative'
  real_T LastUAtTimeB[3];              // '<S1>/Derivative'
  void *SinkBlock_PWORK;               // '<S20>/SinkBlock'
  void *SourceBlock_PWORK;             // '<S16>/SourceBlock'
  void *SourceBlock_PWORK_f;           // '<S14>/SourceBlock'
  robotics_slros_internal_block_T obj; // '<S16>/SourceBlock'
  robotics_slros_internal_block_T obj_o;// '<S14>/SourceBlock'
  robotics_slros_internal_blo_b_T obj_i;// '<S20>/SinkBlock'
  boolean_T objisempty;                // '<S20>/SinkBlock'
  boolean_T objisempty_m;              // '<S16>/SourceBlock'
  boolean_T objisempty_i;              // '<S14>/SourceBlock'
} DW_ROS_Controller_T;

// Continuous states (auto storage)
typedef struct {
  real_T TransferFcn5_CSTATE;          // '<S6>/Transfer Fcn5'
  real_T TransferFcn6_CSTATE;          // '<S6>/Transfer Fcn6'
  real_T TransferFcn7_CSTATE;          // '<S6>/Transfer Fcn7'
  real_T Integrator2_CSTATE[3];        // '<S5>/Integrator2'
  real_T Integrator_CSTATE[3];         // '<S9>/Integrator'
  real_T Integrator1_CSTATE[3];        // '<S9>/Integrator1'
  real_T Integrator1_CSTATE_d[3];      // '<S1>/Integrator1'
  real_T Integrator2_CSTATE_n[3];      // '<S9>/Integrator2'
  real_T Integrator_CSTATE_a[3];       // '<S5>/Integrator'
  real_T Integrator1_CSTATE_i[3];      // '<S5>/Integrator1'
} X_ROS_Controller_T;

// State derivatives (auto storage)
typedef struct {
  real_T TransferFcn5_CSTATE;          // '<S6>/Transfer Fcn5'
  real_T TransferFcn6_CSTATE;          // '<S6>/Transfer Fcn6'
  real_T TransferFcn7_CSTATE;          // '<S6>/Transfer Fcn7'
  real_T Integrator2_CSTATE[3];        // '<S5>/Integrator2'
  real_T Integrator_CSTATE[3];         // '<S9>/Integrator'
  real_T Integrator1_CSTATE[3];        // '<S9>/Integrator1'
  real_T Integrator1_CSTATE_d[3];      // '<S1>/Integrator1'
  real_T Integrator2_CSTATE_n[3];      // '<S9>/Integrator2'
  real_T Integrator_CSTATE_a[3];       // '<S5>/Integrator'
  real_T Integrator1_CSTATE_i[3];      // '<S5>/Integrator1'
} XDot_ROS_Controller_T;

// State disabled
typedef struct {
  boolean_T TransferFcn5_CSTATE;       // '<S6>/Transfer Fcn5'
  boolean_T TransferFcn6_CSTATE;       // '<S6>/Transfer Fcn6'
  boolean_T TransferFcn7_CSTATE;       // '<S6>/Transfer Fcn7'
  boolean_T Integrator2_CSTATE[3];     // '<S5>/Integrator2'
  boolean_T Integrator_CSTATE[3];      // '<S9>/Integrator'
  boolean_T Integrator1_CSTATE[3];     // '<S9>/Integrator1'
  boolean_T Integrator1_CSTATE_d[3];   // '<S1>/Integrator1'
  boolean_T Integrator2_CSTATE_n[3];   // '<S9>/Integrator2'
  boolean_T Integrator_CSTATE_a[3];    // '<S5>/Integrator'
  boolean_T Integrator1_CSTATE_i[3];   // '<S5>/Integrator1'
} XDis_ROS_Controller_T;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (auto storage)
struct P_ROS_Controller_T_ {
  real_T C_nuParams[9];                // Variable: C_nuParams
                                       //  Referenced by: '<S9>/Constant3'

  real_T D[9];                         // Variable: D
                                       //  Referenced by: '<S9>/Constant1'

  real_T D_nuParams[9];                // Variable: D_nuParams
                                       //  Referenced by: '<S9>/Constant2'

  real_T InitialPos[3];                // Variable: InitialPos
                                       //  Referenced by: '<S9>/Integrator'

  real_T K2[9];                        // Variable: K2
                                       //  Referenced by: '<S9>/Gain'

  real_T K3[9];                        // Variable: K3
                                       //  Referenced by: '<S9>/Gain1'

  real_T K4[9];                        // Variable: K4
                                       //  Referenced by: '<S9>/Gain2'

  real_T Kd[9];                        // Variable: Kd
                                       //  Referenced by: '<S1>/Gain2'

  real_T Ki[9];                        // Variable: Ki
                                       //  Referenced by: '<S1>/Gain1'

  real_T Kp[9];                        // Variable: Kp
                                       //  Referenced by: '<S1>/Gain'

  real_T Sat2Low[3];                   // Variable: Sat2Low
                                       //  Referenced by: '<S5>/Saturation4'

  real_T Sat2Up[3];                    // Variable: Sat2Up
                                       //  Referenced by: '<S5>/Saturation4'

  real_T Tr[9];                        // Variable: Tr
                                       //  Referenced by: '<S6>/Thrust allocation Matrix'

  real_T invM[9];                      // Variable: invM
                                       //  Referenced by: '<S9>/Constant'

  real_T invT[9];                      // Variable: invT
                                       //  Referenced by: '<S9>/Gain3'

  real_T invThrustAloc[9];             // Variable: invThrustAloc
                                       //  Referenced by: '<S6>/Inverse thrust allocation Matrix'

  real_T wni[9];                       // Variable: wni
                                       //  Referenced by: '<S5>/w_n'

  real_T wniCeta2[9];                  // Variable: wniCeta2
                                       //  Referenced by: '<S5>/ciwni'

  real_T wnisquared[9];                // Variable: wnisquared
                                       //  Referenced by:
                                       //    '<S5>/w_n1'
                                       //    '<S5>/w_n2'

  SL_Bus_ROS_Controller_geometry_msgs_Vector3 Out1_Y0;// Computed Parameter: Out1_Y0
                                                      //  Referenced by: '<S15>/Out1'

  SL_Bus_ROS_Controller_geometry_msgs_Vector3 Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S14>/Constant'

  SL_Bus_ROS_Controller_geometry_msgs_Vector3 Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                        //  Referenced by: '<S17>/Out1'

  SL_Bus_ROS_Controller_geometry_msgs_Vector3 Constant_Value_k;// Computed Parameter: Constant_Value_k
                                                               //  Referenced by: '<S16>/Constant'

  SL_Bus_ROS_Controller_geometry_msgs_Vector3 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                               //  Referenced by: '<S19>/Constant'

  real_T TransferFcn5_A;               // Computed Parameter: TransferFcn5_A
                                       //  Referenced by: '<S6>/Transfer Fcn5'

  real_T TransferFcn5_C;               // Computed Parameter: TransferFcn5_C
                                       //  Referenced by: '<S6>/Transfer Fcn5'

  real_T TransferFcn6_A;               // Computed Parameter: TransferFcn6_A
                                       //  Referenced by: '<S6>/Transfer Fcn6'

  real_T TransferFcn6_C;               // Computed Parameter: TransferFcn6_C
                                       //  Referenced by: '<S6>/Transfer Fcn6'

  real_T TransferFcn7_A;               // Computed Parameter: TransferFcn7_A
                                       //  Referenced by: '<S6>/Transfer Fcn7'

  real_T TransferFcn7_C;               // Computed Parameter: TransferFcn7_C
                                       //  Referenced by: '<S6>/Transfer Fcn7'

  real_T Integrator2_IC[3];            // Expression: [0;0;0]
                                       //  Referenced by: '<S5>/Integrator2'

  real_T Integrator1_IC;               // Expression: 0
                                       //  Referenced by: '<S9>/Integrator1'

  real_T Integrator1_IC_h[3];          // Expression: [0;0;0]
                                       //  Referenced by: '<S1>/Integrator1'

  real_T Integrator1_UpperSat[3];      // Expression: [1;1;1]
                                       //  Referenced by: '<S1>/Integrator1'

  real_T Integrator1_LowerSat[3];      // Expression: [-1;-1;-1]
                                       //  Referenced by: '<S1>/Integrator1'

  real_T Constant_Value_b;             // Expression: 0
                                       //  Referenced by: '<S3>/Constant'

  real_T Integrator2_IC_j[3];          // Expression: [0;0;0]
                                       //  Referenced by: '<S9>/Integrator2'

  real_T Constant_Value_bw;            // Expression: 0
                                       //  Referenced by: '<S4>/Constant'

  real_T Integrator_IC[3];             // Expression: [0;0;0]
                                       //  Referenced by: '<S5>/Integrator'

  real_T Integrator1_IC_e[3];          // Expression: [0 ;0; 0]
                                       //  Referenced by: '<S5>/Integrator1'

  real_T Saturation5_UpperSat;         // Expression: 4
                                       //  Referenced by: '<S6>/Saturation5'

  real_T Saturation5_LowerSat;         // Expression: -4
                                       //  Referenced by: '<S6>/Saturation5'

  real_T Saturation6_UpperSat;         // Expression: 4
                                       //  Referenced by: '<S6>/Saturation6'

  real_T Saturation6_LowerSat;         // Expression: -4
                                       //  Referenced by: '<S6>/Saturation6'

  real_T Saturation7_UpperSat;         // Expression: 4
                                       //  Referenced by: '<S6>/Saturation7'

  real_T Saturation7_LowerSat;         // Expression: -4
                                       //  Referenced by: '<S6>/Saturation7'

};

// Real-time Model Data Structure
struct tag_RTM_ROS_Controller_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  ModelData:
  //  The following substructure contains information regarding
  //  the data used in the model.

  struct {
    X_ROS_Controller_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[24];
    real_T odeF[3][24];
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

  extern P_ROS_Controller_T ROS_Controller_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_ROS_Controller_T ROS_Controller_B;

// Continuous states (auto storage)
extern X_ROS_Controller_T ROS_Controller_X;

// Block states (auto storage)
extern DW_ROS_Controller_T ROS_Controller_DW;

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
  extern void ROS_Controller_initialize(void);
  extern void ROS_Controller_step(void);
  extern void ROS_Controller_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ROS_Controller_T *const ROS_Controller_M;

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
//  '<Root>' : 'ROS_Controller'
//  '<S1>'   : 'ROS_Controller/DPcontroller'
//  '<S2>'   : 'ROS_Controller/NonlinearPassiveObs'
//  '<S3>'   : 'ROS_Controller/Subsystem'
//  '<S4>'   : 'ROS_Controller/Subsystem1'
//  '<S5>'   : 'ROS_Controller/ThirdOrderFossen 1'
//  '<S6>'   : 'ROS_Controller/ThrustDynamics'
//  '<S7>'   : 'ROS_Controller/U out'
//  '<S8>'   : 'ROS_Controller/DPcontroller/Rotation Matrix'
//  '<S9>'   : 'ROS_Controller/NonlinearPassiveObs/Subsystem'
//  '<S10>'  : 'ROS_Controller/NonlinearPassiveObs/Subsystem/Correalis matrix'
//  '<S11>'  : 'ROS_Controller/NonlinearPassiveObs/Subsystem/Dampening matrix'
//  '<S12>'  : 'ROS_Controller/NonlinearPassiveObs/Subsystem/MATLAB Function'
//  '<S13>'  : 'ROS_Controller/NonlinearPassiveObs/Subsystem/MATLAB Function1'
//  '<S14>'  : 'ROS_Controller/Subsystem/Subscribe2'
//  '<S15>'  : 'ROS_Controller/Subsystem/Subscribe2/Enabled Subsystem'
//  '<S16>'  : 'ROS_Controller/Subsystem1/Subscribe2'
//  '<S17>'  : 'ROS_Controller/Subsystem1/Subscribe2/Enabled Subsystem'
//  '<S18>'  : 'ROS_Controller/ThrustDynamics/Torque Saturation'
//  '<S19>'  : 'ROS_Controller/U out/Blank Message1'
//  '<S20>'  : 'ROS_Controller/U out/Publish1'

#endif                                 // RTW_HEADER_ROS_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
