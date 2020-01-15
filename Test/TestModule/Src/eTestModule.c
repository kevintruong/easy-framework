/**************************************************************************/
/*! 
 @file     eTestModule.c
 @author   kevin
 @email   kevin.truong.ds@gmail.com
 @section LICENSE
 Software License Agreement (BSD License)
 Copyright (c) 2015 kevin
 All rights reserved.
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 3. Neither the name of the copyright holders nor the
 names of its contributors may be used to endorse or promote products
 derived from this software without specific prior written permission.
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**************************************************************************/

/******************************************************************************/
/*                            Include section                                 */
/******************************************************************************/
#include <stdio.h>
#include "eInclude.h"
#include "../Inc/eTestModule.h"
#include "eOsalTaskHandle.h"

/******************************************************************************/
/*        Local Constant and compile switch definition section                */
/******************************************************************************/

/******************************************************************************/
/*                      Local Type definition section                         */
/******************************************************************************/

/******************************************************************************/
/*                  Local Macro definition section                            */
/******************************************************************************/

/******************************************************************************/
/*                  Local (static) variable definition section                */
/******************************************************************************/
eTask_t *pTestModuleTask;
/******************************************************************************/
/*                  Local (static) function declaration section               */
/******************************************************************************/
Void eTestModule_TaskProcessing(Void *Object);
Error_t TestModuleTaskConfigure();
/******************************************************************************/
/*                  Local function definition section                         */
/******************************************************************************/
Error_t TestModuleTaskConfigure(){
  if(!pTestModuleTask)
  {
    return E_ERR_NULL_MEMALLOCFUNC;
  }
  pTestModuleTask->IsTriggerProcess = False;
  pTestModuleTask->TaskId = pTestModuleTask;
  pTestModuleTask->taskHandle = eTestModule_TaskProcessing;
  pTestModuleTask->taskSuspend = NULL;
  pTestModuleTask->taskResume = NULL;
  pTestModuleTask->TaskPriority = NORMAL_LEVEL;
  return E_SUCCESS;
}
Void eTestModule_TaskProcessing(Void *Object)
{
  printf("Hello, I'm Test Module Processing \n");
  return;
}
/******************************************************************************/
/*              Global function definition section                            */
/******************************************************************************/

/**************************************************************************/
/*! 
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
Error_t eTestModule_Init()
{
  Error_t errCode = E_SUCCESS;
  pTestModuleTask = malloc(sizeof(eTask_t));
  if (!pTestModuleTask)
  {
    return errCode = E_ERR_NULL_MEMALLOCFUNC;
  }
  TestModuleTaskConfigure();

  eTaskHandleInf_t *pTaskHandlerInf = eOsalTaskHandle_RegisterInf();

  pTaskHandlerInf->Add(pTestModuleTask);
  return errCode;
}


Error_t eTestModule_Init1()
{
  Error_t errCode = E_SUCCESS;
  eTask_t *ptestModule1;
  ptestModule1 = malloc(sizeof(eTask_t));
  if (!pTestModuleTask)
  {
    return errCode = E_ERR_NULL_MEMALLOCFUNC;
  }
  ptestModule1->IsTriggerProcess = True;
  ptestModule1->taskHandle = eTestModule_TaskProcessing;
  ptestModule1->TaskId = ptestModule1;

  eTaskHandleInf_t *pTaskHandlerInf = eOsalTaskHandle_RegisterInf();

  pTaskHandlerInf->Add(ptestModule1);
  return errCode;
}

Error_t eTestModule_Deinit()
{
  Error_t errCode = E_SUCCESS;

  return errCode;
}
