/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "main.h"
#include "vex_init.h"
#include "pros_wrapper.h"
#include "pros_rtos_init.h"

/* Function prototype declaration*/
void exitTask(int sig);
void terminateTask(void *arg);
void baseRateTask(void *arg);
void subrateTask(void *arg);
volatile boolean_T runModel = true;
Semaphore stopSem;
Semaphore baserateTaskSem;
TaskHandle schedulerThread;
TaskHandle baseRateThread;
TaskHandle backgroundThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(Model_M) == (NULL)) && !rtmGetStopRequested
    (Model_M);
  while (runModel) {
    mw_osSemaphoreWaitEver(&baserateTaskSem);

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(Model_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Model_M, true);
      }

      if (rtmGetStopRequested(Model_M) == true) {
        rtmSetErrorStatus(Model_M, "Simulation finished");
        break;
      }
    }

    Model_step();

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    runModel = (rtmGetErrorStatus(Model_M) == (NULL)) && !rtmGetStopRequested
      (Model_M);
  }

  runModel = 0;
  terminateTask(arg);
  taskDelete((void *)0);
}

void exitTask(int sig)
{
  rtmSetErrorStatus(Model_M, "stopping the model");
}

void terminateTask(void *arg)
{
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  {
    int ret;
    runModel = 0;

    /* Wait for background task to complete */
    ret = mw_osThreadJoin(backgroundThread, (void *)&threadJoinStatus);
    CHECK_STATUS(ret, 0, "mw_osThreadJoin");
  }

  rtExtModeShutdown(1);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Model_terminate();
  mw_osSemaphoreRelease(&stopSem);
}

void backgroundTask(int sig)
{
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(Model_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Model_M, true);
      }
    }
  }
}

int main(int argc, char **argv)
{
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(Model_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Initialize model */
  Model_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(Model_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(Model_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(Model_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization funcation */
  prosRTOSInit(0.2, 0);

  /* Wait for stop semaphore */
  mw_osSemaphoreWaitEver(&stopSem);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
