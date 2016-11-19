/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Model.c
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

#include "Model.h"
#include "Model_private.h"
#include "Model_dt.h"

/* Named constants for Chart: '<S20>/Chart' */
#define Model_CALL_EVENT               (-1)
#define Model_IN_NO_ACTIVE_CHILD       ((uint8_T)0U)
#define Model_IN_init                  ((uint8_T)1U)
#define Model_IN_wait                  ((uint8_T)2U)

/* Block signals (auto storage) */
BlockIO_Model Model_B;

/* Block states (auto storage) */
D_Work_Model Model_DWork;

/* Real-time model */
RT_MODEL_Model Model_M_;
RT_MODEL_Model *const Model_M = &Model_M_;

/*
 * System initialize for atomic system:
 *    '<S20>/Chart'
 *    '<S22>/Chart'
 *    '<S24>/Chart'
 */
void Model_Chart_Init(rtB_Chart_Model *localB, rtDW_Chart_Model *localDW)
{
  localDW->sfEvent = Model_CALL_EVENT;
  localDW->is_active_c7_vexarmcortexlib = 0U;
  localDW->is_c7_vexarmcortexlib = Model_IN_NO_ACTIVE_CHILD;
  localB->output = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S20>/Chart'
 *    '<S22>/Chart'
 *    '<S24>/Chart'
 */
void Model_Chart(real_T rtu_trigger, rtB_Chart_Model *localB, rtDW_Chart_Model
                 *localDW, rtP_Chart_Model *localP)
{
  /* Gateway: Utilities/Latch/Chart */
  localDW->sfEvent = Model_CALL_EVENT;

  /* During: Utilities/Latch/Chart */
  if (localDW->is_active_c7_vexarmcortexlib == 0U) {
    /* Entry: Utilities/Latch/Chart */
    localDW->is_active_c7_vexarmcortexlib = 1U;

    /* Entry Internal: Utilities/Latch/Chart */
    /* Transition: '<S21>:1' */
    localB->output = localP->Chart_output0;
    localDW->is_c7_vexarmcortexlib = Model_IN_init;
  } else if (localDW->is_c7_vexarmcortexlib == Model_IN_init) {
    /* During 'init': '<S21>:4' */
    if (rtu_trigger != 0.0) {
      /* Transition: '<S21>:6' */
      localB->output = !(localB->output != 0.0);
      localDW->is_c7_vexarmcortexlib = Model_IN_wait;
    }
  } else {
    /* During 'wait': '<S21>:5' */
    if (rtu_trigger == 0.0) {
      /* Transition: '<S21>:7' */
      localDW->is_c7_vexarmcortexlib = Model_IN_init;
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Model_step(void)
{
  real_T rtb_Saturation;

  /* S-Function (sfun_vexgetJSdigital): '<S19>/sfun_JoystickDigital' */

  /* Get Joystick Digital Input using the PROS API. Channel # is the Button Group # (2nd param). */
  Model_B.sfun_JoystickDigital = joystickGetDigital((unsigned char) 1, (unsigned
    char) 5, (unsigned char) 4);

  /* S-Function (sfun_vexgetJSdigital): '<S7>/sfun_JoystickDigital' */

  /* Get Joystick Digital Input using the PROS API. Channel # is the Button Group # (2nd param). */
  Model_B.sfun_JoystickDigital_j = joystickGetDigital((unsigned char) 1,
    (unsigned char) 5, (unsigned char) 1.0);

  /* Sum: '<S2>/Add' incorporates:
   *  DataTypeConversion: '<S19>/Data Type Conversion1'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  Gain: '<S2>/Down Gain'
   *  Gain: '<S2>/Up Gain'
   */
  rtb_Saturation = Model_P.UpGain_Gain * (real_T)Model_B.sfun_JoystickDigital +
    Model_P.DownGain_Gain * (real_T)Model_B.sfun_JoystickDigital_j;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Saturation > Model_P.Saturation_UpperSat) {
    rtb_Saturation = Model_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < Model_P.Saturation_LowerSat) {
      rtb_Saturation = Model_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  rtb_Saturation = rt_roundd_snf(rtb_Saturation);
  if (rtIsNaN(rtb_Saturation) || rtIsInf(rtb_Saturation)) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = fmod(rtb_Saturation, 4.294967296E+9);
  }

  Model_B.DataTypeConversion = rtb_Saturation < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Saturation : (int32_T)(uint32_T)rtb_Saturation;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (sfun_vexsetmotor): '<S1>/sfun_SetMotor' */

  /* Set H-Bridge Motor speed using the PROS API */
  motorSet((unsigned char) 4, (int) Model_B.DataTypeConversion);

  /* S-Function (sfun_vexgetJSdigital): '<S3>/sfun_JoystickDigital' */

  /* Get Joystick Digital Input using the PROS API. Channel # is the Button Group # (2nd param). */
  Model_B.sfun_JoystickDigital_o = joystickGetDigital((unsigned char) 1,
    (unsigned char) 6, (unsigned char) 4);

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  Model_B.DataTypeConversion1 = Model_B.sfun_JoystickDigital_o;

  /* Chart: '<S20>/Chart' */
  Model_Chart(Model_B.DataTypeConversion1, &Model_B.sf_Chart,
              &Model_DWork.sf_Chart, (rtP_Chart_Model *)&Model_P.sf_Chart);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  if (Model_B.sf_Chart.output > Model_P.Switch_Threshold) {
    rtb_Saturation = Model_P.Constant_Value;
  } else {
    rtb_Saturation = Model_P.Constant1_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Saturate: '<S14>/Saturation1' */
  if (rtb_Saturation > Model_P.Saturation1_UpperSat) {
    rtb_Saturation = Model_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation < Model_P.Saturation1_LowerSat) {
      rtb_Saturation = Model_P.Saturation1_LowerSat;
    }
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
   *  Saturate: '<S14>/Saturation1'
   */
  rtb_Saturation = rt_roundd_snf(rtb_Saturation);
  if (rtIsNaN(rtb_Saturation) || rtIsInf(rtb_Saturation)) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = fmod(rtb_Saturation, 4.294967296E+9);
  }

  Model_B.DataTypeConversion_d = rtb_Saturation < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Saturation : (int32_T)(uint32_T)rtb_Saturation;

  /* End of DataTypeConversion: '<S14>/Data Type Conversion' */

  /* S-Function (sfun_vexsetservo): '<S14>/sfun_SetServo' */

  /* Set Servo Motor speed using the PROS API. Same API is used for setting motor speed and servo angle. */
  motorSet((unsigned char)7, (int)Model_B.DataTypeConversion_d);

  /* S-Function (sfun_vexgetJSdigital): '<S5>/sfun_JoystickDigital' */

  /* Get Joystick Digital Input using the PROS API. Channel # is the Button Group # (2nd param). */
  Model_B.sfun_JoystickDigital_e = joystickGetDigital((unsigned char) 1,
    (unsigned char) 7, (unsigned char) 4.0);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  Model_B.DataTypeConversion1_e = Model_B.sfun_JoystickDigital_e;

  /* Chart: '<S22>/Chart' */
  Model_Chart(Model_B.DataTypeConversion1_e, &Model_B.sf_Chart_i,
              &Model_DWork.sf_Chart_i, (rtP_Chart_Model *)&Model_P.sf_Chart_i);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  if (Model_B.sf_Chart_i.output > Model_P.Switch_Threshold_e) {
    rtb_Saturation = Model_P.Constant_Value_d;
  } else {
    rtb_Saturation = Model_P.Constant1_Value_l;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Saturate: '<S15>/Saturation1' */
  if (rtb_Saturation > Model_P.Saturation1_UpperSat_o) {
    rtb_Saturation = Model_P.Saturation1_UpperSat_o;
  } else {
    if (rtb_Saturation < Model_P.Saturation1_LowerSat_p) {
      rtb_Saturation = Model_P.Saturation1_LowerSat_p;
    }
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
   *  Saturate: '<S15>/Saturation1'
   */
  rtb_Saturation = rt_roundd_snf(rtb_Saturation);
  if (rtIsNaN(rtb_Saturation) || rtIsInf(rtb_Saturation)) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = fmod(rtb_Saturation, 4.294967296E+9);
  }

  Model_B.DataTypeConversion_o = rtb_Saturation < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Saturation : (int32_T)(uint32_T)rtb_Saturation;

  /* End of DataTypeConversion: '<S15>/Data Type Conversion' */

  /* S-Function (sfun_vexsetservo): '<S15>/sfun_SetServo' */

  /* Set Servo Motor speed using the PROS API. Same API is used for setting motor speed and servo angle. */
  motorSet((unsigned char)6, (int)Model_B.DataTypeConversion_o);

  /* S-Function (sfun_vexgetJSdigital): '<S8>/sfun_JoystickDigital' */

  /* Get Joystick Digital Input using the PROS API. Channel # is the Button Group # (2nd param). */
  Model_B.sfun_JoystickDigital_a = joystickGetDigital((unsigned char) 1,
    (unsigned char) 8, (unsigned char) 4.0);

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  Model_B.DataTypeConversion1_f = Model_B.sfun_JoystickDigital_a;

  /* Chart: '<S24>/Chart' */
  Model_Chart(Model_B.DataTypeConversion1_f, &Model_B.sf_Chart_l,
              &Model_DWork.sf_Chart_l, (rtP_Chart_Model *)&Model_P.sf_Chart_l);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   */
  if (Model_B.sf_Chart_l.output > Model_P.Switch_Threshold_d) {
    rtb_Saturation = Model_P.Constant_Value_e;
  } else {
    rtb_Saturation = Model_P.Constant1_Value_g;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Saturate: '<S16>/Saturation1' */
  if (rtb_Saturation > Model_P.Saturation1_UpperSat_e) {
    rtb_Saturation = Model_P.Saturation1_UpperSat_e;
  } else {
    if (rtb_Saturation < Model_P.Saturation1_LowerSat_i) {
      rtb_Saturation = Model_P.Saturation1_LowerSat_i;
    }
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
   *  Saturate: '<S16>/Saturation1'
   */
  rtb_Saturation = rt_roundd_snf(rtb_Saturation);
  if (rtIsNaN(rtb_Saturation) || rtIsInf(rtb_Saturation)) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = fmod(rtb_Saturation, 4.294967296E+9);
  }

  Model_B.DataTypeConversion_c = rtb_Saturation < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Saturation : (int32_T)(uint32_T)rtb_Saturation;

  /* End of DataTypeConversion: '<S16>/Data Type Conversion' */

  /* S-Function (sfun_vexsetservo): '<S16>/sfun_SetServo' */

  /* Set Servo Motor speed using the PROS API. Same API is used for setting motor speed and servo angle. */
  motorSet((unsigned char)5, (int)Model_B.DataTypeConversion_c);

  /* Saturate: '<S10>/Saturation' */
  if (0.0 > Model_P.Saturation_UpperSat_d) {
    Model_B.Saturation = Model_P.Saturation_UpperSat_d;
  } else if (0.0 < Model_P.Saturation_LowerSat_l) {
    Model_B.Saturation = Model_P.Saturation_LowerSat_l;
  } else {
    Model_B.Saturation = 0.0;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* S-Function (sfun_vexgetJSanalog): '<S10>/sfun_JoystickAnalog' */

  /* Get Analog Input using the PROS API */
  Model_B.sfun_JoystickAnalog = joystickGetAnalog((unsigned char)1, (unsigned
    char)3);

  /* S-Function (sfun_vexgetJSdigital): '<S17>/sfun_JoystickDigital' */

  /* Get Joystick Digital Input using the PROS API. Channel # is the Button Group # (2nd param). */
  Model_B.sfun_JoystickDigital_i = joystickGetDigital((unsigned char) 1,
    (unsigned char) 7, (unsigned char) 4.0);

  /* Switch: '<S18>/Left Drive Reduction' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   *  DataTypeConversion: '<S17>/Data Type Conversion1'
   *  Gain: '<S18>/Gain2'
   */
  if ((real_T)Model_B.sfun_JoystickDigital_i >
      Model_P.LeftDriveReduction_Threshold) {
    rtb_Saturation = Model_P.Gain2_Gain * (real_T)Model_B.sfun_JoystickAnalog;
  } else {
    rtb_Saturation = Model_B.sfun_JoystickAnalog;
  }

  /* End of Switch: '<S18>/Left Drive Reduction' */

  /* Saturate: '<S9>/Saturation' */
  if (rtb_Saturation > Model_P.Saturation_UpperSat_k) {
    rtb_Saturation = Model_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Saturation < Model_P.Saturation_LowerSat_e) {
      rtb_Saturation = Model_P.Saturation_LowerSat_e;
    }
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  rtb_Saturation = rt_roundd_snf(rtb_Saturation);
  if (rtIsNaN(rtb_Saturation) || rtIsInf(rtb_Saturation)) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = fmod(rtb_Saturation, 4.294967296E+9);
  }

  Model_B.DataTypeConversion_a = rtb_Saturation < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Saturation : (int32_T)(uint32_T)rtb_Saturation;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* S-Function (sfun_vexsetmotor): '<S9>/sfun_SetMotor' */

  /* Set H-Bridge Motor speed using the PROS API */
  motorSet((unsigned char) 2, (int) Model_B.DataTypeConversion_a);

  /* Saturate: '<S12>/Saturation' */
  if (0.0 > Model_P.Saturation_UpperSat_a) {
    Model_B.Saturation_n = Model_P.Saturation_UpperSat_a;
  } else if (0.0 < Model_P.Saturation_LowerSat_d) {
    Model_B.Saturation_n = Model_P.Saturation_LowerSat_d;
  } else {
    Model_B.Saturation_n = 0.0;
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* S-Function (sfun_vexgetJSanalog): '<S12>/sfun_JoystickAnalog' */

  /* Get Analog Input using the PROS API */
  Model_B.sfun_JoystickAnalog_h = joystickGetAnalog((unsigned char)1, (unsigned
    char)2);

  /* Switch: '<S18>/Right Drive Reduction' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  DataTypeConversion: '<S17>/Data Type Conversion1'
   *  Gain: '<S18>/Gain1'
   */
  if ((real_T)Model_B.sfun_JoystickDigital_i >
      Model_P.RightDriveReduction_Threshold) {
    rtb_Saturation = Model_P.Gain1_Gain * (real_T)Model_B.sfun_JoystickAnalog_h;
  } else {
    rtb_Saturation = Model_B.sfun_JoystickAnalog_h;
  }

  /* End of Switch: '<S18>/Right Drive Reduction' */

  /* Saturate: '<S11>/Saturation' */
  if (rtb_Saturation > Model_P.Saturation_UpperSat_i) {
    rtb_Saturation = Model_P.Saturation_UpperSat_i;
  } else {
    if (rtb_Saturation < Model_P.Saturation_LowerSat_a) {
      rtb_Saturation = Model_P.Saturation_LowerSat_a;
    }
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  rtb_Saturation = rt_roundd_snf(rtb_Saturation);
  if (rtIsNaN(rtb_Saturation) || rtIsInf(rtb_Saturation)) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = fmod(rtb_Saturation, 4.294967296E+9);
  }

  Model_B.DataTypeConversion_h = rtb_Saturation < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Saturation : (int32_T)(uint32_T)rtb_Saturation;

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* S-Function (sfun_vexsetmotor): '<S11>/sfun_SetMotor' */

  /* Set H-Bridge Motor speed using the PROS API */
  motorSet((unsigned char) 3, (int) Model_B.DataTypeConversion_h);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, Model_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(Model_M)!=-1) &&
        !((rtmGetTFinal(Model_M)-Model_M->Timing.taskTime0) >
          Model_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Model_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Model_M)) {
      rtmSetErrorStatus(Model_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Model_M->Timing.clockTick0)) {
    ++Model_M->Timing.clockTickH0;
  }

  Model_M->Timing.taskTime0 = Model_M->Timing.clockTick0 *
    Model_M->Timing.stepSize0 + Model_M->Timing.clockTickH0 *
    Model_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Model_M, 0,
                sizeof(RT_MODEL_Model));
  rtmSetTFinal(Model_M, -1);
  Model_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  Model_M->Sizes.checksums[0] = (2584680145U);
  Model_M->Sizes.checksums[1] = (1649992434U);
  Model_M->Sizes.checksums[2] = (612749690U);
  Model_M->Sizes.checksums[3] = (858420318U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    Model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Model_M->extModeInfo,
      &Model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Model_M->extModeInfo, Model_M->Sizes.checksums);
    rteiSetTPtr(Model_M->extModeInfo, rtmGetTPtr(Model_M));
  }

  /* block I/O */
  (void) memset(((void *) &Model_B), 0,
                sizeof(BlockIO_Model));

  /* states (dwork) */
  (void) memset((void *)&Model_DWork, 0,
                sizeof(D_Work_Model));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* SystemInitialize for Chart: '<S20>/Chart' */
  Model_Chart_Init(&Model_B.sf_Chart, &Model_DWork.sf_Chart);

  /* SystemInitialize for Chart: '<S22>/Chart' */
  Model_Chart_Init(&Model_B.sf_Chart_i, &Model_DWork.sf_Chart_i);

  /* SystemInitialize for Chart: '<S24>/Chart' */
  Model_Chart_Init(&Model_B.sf_Chart_l, &Model_DWork.sf_Chart_l);
}

/* Model terminate function */
void Model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
