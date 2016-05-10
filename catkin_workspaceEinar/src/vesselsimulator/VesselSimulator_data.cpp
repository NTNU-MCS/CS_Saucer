//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: VesselSimulator_data.cpp
//
// Code generated for Simulink model 'VesselSimulator'.
//
// Model version                  : 1.21
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Sun Apr 10 13:39:52 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "VesselSimulator.h"
#include "VesselSimulator_private.h"

// Block parameters (auto storage)
P_VesselSimulator_T VesselSimulator_P = {
  //  Variable: C_nuParams
  //  Referenced by: '<S3>/Constant1'

  { 0.0, 9.51, 0.0, -9.51, 0.0, 0.0, 0.0, -0.0, 0.0 },

  //  Variable: D
  //  Referenced by: '<S3>/Gain1'

  { 1.9599, 0.0, 0.0, 0.0, 1.9599, 0.0, 0.0, 0.0, 0.19599 },

  //  Variable: D_nuParams
  //  Referenced by: '<S3>/Constant'

  { 7.0948, 0.0, 0.0, 0.0, 7.0948, 0.0, 0.0, 0.0, 0.70948000000000011 },

  //  Variable: Tr
  //  Referenced by: '<Root>/Thrust allocation Matrix'

  { 0.0, 1.0, 0.13735, 0.86602540378443871, -0.49999999999999978, 0.13735,
    -0.86602540378443849, -0.50000000000000044, 0.13735 },

  //  Variable: invM
  //  Referenced by: '<S3>/Gain'

  { 0.10515247108307045, 0.0, 0.0, 0.0, 0.10515247108307045, 0.0, 0.0, 0.0,
    8.6206896551724128 },

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S5>/Out1'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S4>/Constant'


  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },                                   // Computed Parameter: Constant_Value_j
                                       //  Referenced by: '<S6>/Constant'


  //  Expression: [0;0;0]
  //  Referenced by: '<S3>/Integrator1'

  { 0.0, 0.0, 0.0 },

  //  Expression: [0; 0; 0]
  //  Referenced by: '<S3>/Integrator2'

  { 0.0, 0.0, 0.0 }
};

//
// File trailer for generated code.
//
// [EOF]
//
