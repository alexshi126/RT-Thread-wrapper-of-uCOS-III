/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-07-06     Meco Man     the first verion
 */
/*
*********************************************************************************************************
*                                              uC/OS-III
*                                        The Real-Time Kernel
*
*                    Copyright 2009-2020 Silicon Laboratories Inc. www.silabs.com
*
*                                 SPDX-License-Identifier: APACHE-2.0
*
*               This software is subject to an open source license and is distributed by
*                Silicon Laboratories Inc. pursuant to the terms of the Apache License,
*                    Version 2.0 available at www.apache.org/licenses/LICENSE-2.0.
*
*********************************************************************************************************
*/ 
/*
************************************************************************************************************************
*                                                      uC/OS-III
*                                                 The Real-Time Kernel
*
*                                  (c) Copyright 2009-2012; Micrium, Inc.; Weston, FL
*                           All rights reserved.  Protected by international copyright laws.
*
*                                                  APPLICATION HOOKS
*
* File    : OS_APP_HOOKS.C
* By      : JJL
* Version : V3.03.00
*
* LICENSING TERMS:
* ---------------
*           uC/OS-III is provided in source form for FREE short-term evaluation, for educational use or
*           for peaceful research.  If you plan or intend to use uC/OS-III in a commercial application/
*           product then, you need to contact Micrium to properly license uC/OS-III for its use in your
*           application/product.   We provide ALL the source code for your convenience and to help you
*           experience uC/OS-III.  The fact that the source is provided does NOT mean that you can use
*           it commercially without paying a licensing fee.
*
*           Knowledge of the source code may NOT be used to develop a similar product.
*
*           Please help us continue to provide the embedded community with the finest software available.
*           Your honesty is greatly appreciated.
*
*           You can contact us at www.micrium.com, or by phone at +1 (954) 217-2036.
************************************************************************************************************************
*/

#include <os.h>
#include <os_app_hooks.h>

/*
************************************************************************************************************************
*                                              SET ALL APPLICATION HOOKS
*
* Description: Set ALL application hooks.
*
* Arguments  : none.
*
* Note(s)    : none
************************************************************************************************************************
*/

void  App_OS_SetAllHooks (void)
{
#if OS_CFG_APP_HOOKS_EN > 0u
    CPU_SR_ALLOC();

    CPU_CRITICAL_ENTER();
    OS_AppTaskCreateHookPtr = App_OS_TaskCreateHook;
    OS_AppTaskDelHookPtr    = App_OS_TaskDelHook;
    OS_AppIdleTaskHookPtr   = App_OS_IdleTaskHook;
    OS_AppStatTaskHookPtr   = App_OS_StatTaskHook;
    
    OS_AppTaskReturnHookPtr = App_OS_TaskReturnHook;
    OS_AppTaskSwHookPtr     = App_OS_TaskSwHook;
    OS_AppTimeTickHookPtr   = App_OS_TimeTickHook;    
    CPU_CRITICAL_EXIT();
#endif
}

/*
************************************************************************************************************************
*                                             CLEAR ALL APPLICATION HOOKS
*
* Description: Clear ALL application hooks.
*
* Arguments  : none.
*
* Note(s)    : none
************************************************************************************************************************
*/

void  App_OS_ClrAllHooks (void)
{
#if OS_CFG_APP_HOOKS_EN > 0u
    CPU_SR_ALLOC();

    CPU_CRITICAL_ENTER();
    OS_AppTaskCreateHookPtr = (OS_APP_HOOK_TCB)0;
    OS_AppTaskDelHookPtr    = (OS_APP_HOOK_TCB)0;
    OS_AppIdleTaskHookPtr   = (OS_APP_HOOK_VOID)0; 
    OS_AppStatTaskHookPtr   = (OS_APP_HOOK_VOID)0;
    
    OS_AppTaskReturnHookPtr = (OS_APP_HOOK_TCB)0;
    OS_AppTaskSwHookPtr     = (OS_APP_HOOK_VOID)0;
    OS_AppTimeTickHookPtr   = (OS_APP_HOOK_VOID)0;    
    CPU_CRITICAL_EXIT();
#endif
}

/*
************************************************************************************************************************
*                                            APPLICATION TASK CREATION HOOK
*
* Description: This function is called when a task is created.
*
* Arguments  : p_tcb   is a pointer to the task control block of the task being created.
*
* Note(s)    : none
************************************************************************************************************************
*/

void  App_OS_TaskCreateHook (OS_TCB  *p_tcb)
{
    CPU_VAL_UNUSED(p_tcb);

}

/*
************************************************************************************************************************
*                                            APPLICATION TASK DELETION HOOK
*
* Description: This function is called when a task is deleted.
*
* Arguments  : p_tcb   is a pointer to the task control block of the task being deleted.
*
* Note(s)    : none
************************************************************************************************************************
*/

void  App_OS_TaskDelHook (OS_TCB  *p_tcb)
{
    CPU_VAL_UNUSED(p_tcb);

}

/*
************************************************************************************************************************
*                                              APPLICATION IDLE TASK HOOK
*
* Description: This function is called by the idle task.  This hook has been added to allow you to do such things as
*              STOP the CPU to conserve power.
*
* Arguments  : none
*
* Note(s)    : none
************************************************************************************************************************
*/

void  App_OS_IdleTaskHook (void)
{

}

/*
************************************************************************************************************************
*                                           APPLICATION STATISTIC TASK HOOK
*
* Description: This function is called every second by uC/OS-III's statistics task.  This allows your application to add
*              functionality to the statistics task.
*
* Arguments  : none
*
* Note(s)    : none
************************************************************************************************************************
*/

void  App_OS_StatTaskHook (void)
{

}


/*--------------------------以下uCOS钩子函数由RT-Thread钩子函数接管,不再使用------------------------------------------*/

/*
************************************************************************************************************************
*                                             APPLICATION TASK RETURN HOOK
*
* Description: This function is called if a task accidentally returns.  In other words, a task should either be an
*              infinite loop or delete itself when done.
*
* Arguments  : p_tcb     is a pointer to the OS_TCB of the task that is returning.
*
* Note(s)    : none
************************************************************************************************************************
*/

void  App_OS_TaskReturnHook (OS_TCB  *p_tcb)
{
    CPU_VAL_UNUSED(p_tcb);
}

/*
************************************************************************************************************************
*                                             APPLICATION TASK SWITCH HOOK
*
* Description: This function is called when a task switch is performed.  This allows you to perform other operations
*              during a context switch.
*
* Arguments  : none
*
* Note(s)    : 1) Interrupts are disabled during this call.
*              2) It is assumed that the global pointer 'OSTCBHighRdyPtr' points to the TCB of the task that will be
*                 'switched in' (i.e. the highest priority task) and, 'OSTCBCurPtr' points to the task being switched out
*                 (i.e. the preempted task).
************************************************************************************************************************
*/

void  App_OS_TaskSwHook (void)
{

}

/*
************************************************************************************************************************
*                                                APPLICATION TICK HOOK
*
* Description: This function is called every tick.
*
* Arguments  : none
*
* Note(s)    : 1) This function is assumed to be called from the Tick ISR.
************************************************************************************************************************
*/

void  App_OS_TimeTickHook (void)
{

}
