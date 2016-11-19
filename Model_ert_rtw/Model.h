/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Model.h
 *
 * Code generated for Simulink model 'Model'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Thu Nov 03 18:58:23 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Model_h_
#define RTW_HEADER_Model_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Model_COMMON_INCLUDES_
# define Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* Model_COMMON_INCLUDES_ */

#include "Model_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals for system '<S20>/Chart' */
typedef struct {
  real_T output;                       /* '<S20>/Chart' */
} rtB_Chart_Model;

/* Block states (auto storage) for system '<S20>/Chart' */
typedef struct {
  int32_T sfEvent;                     /* '<S20>/Chart' */
  uint8_T is_active_c7_vexarmcortexlib;/* '<S20>/Chart' */
  uint8_T is_c7_vexarmcortexlib;       /* '<S20>/Chart' */
} rtDW_Chart_Model;

/* Block signals (auto storage) */
typedef struct {
  real_T DataTypeConversion1;          /* '<S3>/Data Type Conversion1' */
  real_T DataTypeConversion1_e;        /* '<S5>/Data Type Conversion1' */
  real_T DataTypeConversion1_f;        /* '<S8>/Data Type Conversion1' */
  real_T Saturation;                   /* '<S10>/Saturation' */
  real_T Saturation_n;                 /* '<S12>/Saturation' */
  int32_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
  int32_T DataTypeConversion_d;        /* '<S14>/Data Type Conversion' */
  int32_T DataTypeConversion_o;        /* '<S15>/Data Type Conversion' */
  int32_T DataTypeConversion_c;        /* '<S16>/Data Type Conversion' */
  int32_T sfun_JoystickAnalog;         /* '<S10>/sfun_JoystickAnalog' */
  int32_T DataTypeConversion_a;        /* '<S9>/Data Type Conversion' */
  int32_T sfun_JoystickAnalog_h;       /* '<S12>/sfun_JoystickAnalog' */
  int32_T DataTypeConversion_h;        /* '<S11>/Data Type Conversion' */
  boolean_T sfun_JoystickDigital;      /* '<S19>/sfun_JoystickDigital' */
  boolean_T sfun_JoystickDigital_j;    /* '<S7>/sfun_JoystickDigital' */
  boolean_T sfun_JoystickDigital_o;    /* '<S3>/sfun_JoystickDigital' */
  boolean_T sfun_JoystickDigital_e;    /* '<S5>/sfun_JoystickDigital' */
  boolean_T sfun_JoystickDigital_a;    /* '<S8>/sfun_JoystickDigital' */
  boolean_T sfun_JoystickDigital_i;    /* '<S17>/sfun_JoystickDigital' */
  rtB_Chart_Model sf_Chart_l;          /* '<S24>/Chart' */
  rtB_Chart_Model sf_Chart_i;          /* '<S22>/Chart' */
  rtB_Chart_Model sf_Chart;            /* '<S20>/Chart' */
} BlockIO_Model;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  rtDW_Chart_Model sf_Chart_l;         /* '<S24>/Chart' */
  rtDW_Chart_Model sf_Chart_i;         /* '<S22>/Chart' */
  rtDW_Chart_Model sf_Chart;           /* '<S20>/Chart' */
} D_Work_Model;

/* Parameters for system: '<S20>/Chart' */
struct rtP_Chart_Model_ {
  real_T Chart_output0;                /* Expression: output0
                                        * Referenced by: '<S20>/Chart'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_Model_ {
  real_T Constant1_Value;              /* Expression: -50
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 120
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: -50
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 120
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: -100
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 120
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: .25
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: .25
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real_T UpGain_Gain;                  /* Expression: 100
                                        * Referenced by: '<S2>/Up Gain'
                                        */
  real_T DownGain_Gain;                /* Expression: -100
                                        * Referenced by: '<S2>/Down Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 127
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -128
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 127
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -128
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 127
                                        * Referenced by: '<S15>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_p;       /* Expression: -128
                                        * Referenced by: '<S15>/Saturation1'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T Saturation1_UpperSat_e;       /* Expression: 127
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_i;       /* Expression: -128
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 127
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: -128
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T LeftDriveReduction_Threshold; /* Expression: 0
                                        * Referenced by: '<S18>/Left Drive Reduction'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 127
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -128
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 127
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -128
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T RightDriveReduction_Threshold;/* Expression: 0
                                        * Referenced by: '<S18>/Right Drive Reduction'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 127
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -128
                                        * Referenced by: '<S11>/Saturation'
                                        */
  rtP_Chart_Model sf_Chart_l;          /* '<S24>/Chart' */
  rtP_Chart_Model sf_Chart_i;          /* '<S22>/Chart' */
  rtP_Chart_Model sf_Chart;            /* '<S20>/Chart' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Model {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_Model Model_P;

/* Block signals (auto storage) */
extern BlockIO_Model Model_B;

/* Block states (auto storage) */
extern D_Work_Model Model_DWork;

/* Model entry point functions */
extern void Model_initialize(void);
extern void Model_step(void);
extern void Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Model *const Model_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Model'
 * '<S1>'   : 'Model/Arm Motor'
 * '<S2>'   : 'Model/Arm Subsystem'
 * '<S3>'   : 'Model/Claw Button'
 * '<S4>'   : 'Model/Claw Subsystem'
 * '<S5>'   : 'Model/Corn Flap Button2'
 * '<S6>'   : 'Model/Corn Flap Subsystem'
 * '<S7>'   : 'Model/Down Button'
 * '<S8>'   : 'Model/Gamepad Button1'
 * '<S9>'   : 'Model/Left Drive Motor'
 * '<S10>'  : 'Model/Left Joystick'
 * '<S11>'  : 'Model/Right Drive Motor'
 * '<S12>'  : 'Model/Right Joystick'
 * '<S13>'  : 'Model/Seed Planter Subsystem'
 * '<S14>'  : 'Model/Servo Motor'
 * '<S15>'  : 'Model/Servo Motor1'
 * '<S16>'  : 'Model/Servo Motor2'
 * '<S17>'  : 'Model/Slow Button'
 * '<S18>'  : 'Model/Tank Drive System'
 * '<S19>'  : 'Model/Up Button'
 * '<S20>'  : 'Model/Claw Subsystem/Latch'
 * '<S21>'  : 'Model/Claw Subsystem/Latch/Chart'
 * '<S22>'  : 'Model/Corn Flap Subsystem/Latch'
 * '<S23>'  : 'Model/Corn Flap Subsystem/Latch/Chart'
 * '<S24>'  : 'Model/Seed Planter Subsystem/Latch'
 * '<S25>'  : 'Model/Seed Planter Subsystem/Latch/Chart'
 */
#endif                                 /* RTW_HEADER_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
