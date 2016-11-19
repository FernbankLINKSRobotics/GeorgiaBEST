#ifndef _MW_CUSTOM_RTOS_HEADER_H_
#define _MW_CUSTOM_RTOS_HEADER_H_
#define MW_BASERATE_PRIORITY           40
#define MW_BASERATE_PERIOD             0.2
#define MW_NUMBER_SUBRATES             0
#define MW_NUMBER_APERIODIC_TASKS      0
#define MW_IS_CONCURRENT               0

extern void exitTask(int sig);
extern void terminateTask(void *arg);
extern void baseRateTask(void *arg);
extern void subrateTask(void *arg);

#define MW_NEEDS_BACKGROUND_TASK
#define MW_BACKGROUNDTASK_PRIORITY     41

extern void backgroundTask(void *arg);
extern TaskHandle backgroundThread;
extern TaskHandle schedulerThread;
extern TaskHandle baseRateThread;
extern TaskHandle subRateThread[];
extern Semaphore stopSem;
extern Semaphore baserateTaskSem;
extern Semaphore subrateTaskSem[];
extern int taskId[];
extern int subratePriority[];

#endif
