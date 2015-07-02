/**************************************************************************/
/*! 
 @file     eOsalTaskHandle.c
 @author   kevin
 @email		kevin.truong.ds@gmail.com
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
/* 										  			Include section 																*/
/******************************************************************************/
#include <eOsalTaskHandle.h>
#include "eInclude.h"
#include "eTask.h"
#include <malloc.h>
#include <stdio.h>

/******************************************************************************/
/*   			Local Constant and compile switch definition section								*/
/******************************************************************************/

#define DEBUG 3

#if defined(DEBUG) && DEBUG > 0
// #define DEBUG_PRINT(args...) printf("DEBUG: %s:%d:%s(): ",__FILE__, __LINE__, __func__, ##args)
#define DEBUG_PRINT 						printf
#else
#define DEBUG_PRINT(fmt, args...) /* Don't do anything in release builds */
#endif
/******************************************************************************/
/*  										Local Type definition section													*/
/******************************************************************************/

/******************************************************************************/
/*  								Local Macro definition section														*/
/******************************************************************************/

/******************************************************************************/
/*  								Local (static) variable definition section								*/
/******************************************************************************/
TodoTaskList_t* eTodoTaskList; /*<<<! Container hold all task element */
eTaskHandleInf_t * taskHandleInf; /*<<<! return interface to access container */

/******************************************************************************/
/*  								Local (static) function declaration section								*/
/******************************************************************************/
/**************************************************************************/
/*!
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
Error_t eOsalTaskHandle_Add(eTask_t* newTask);
/**************************************************************************/
/*!
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
Error_t eOsalTaskHandle_Remove(UInt32 taskId);
/**************************************************************************/
/*!
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
Error_t eOsalTaskHandle_Sort(Void);

/******************************************************************************/
/*									Local function definition section 												*/
/******************************************************************************/

/******************************************************************************/
/*  						Global function definition section 														*/
/******************************************************************************/

/**************************************************************************/
/*! 
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
eTaskHandleInf_t *eOsalTaskHandle_RegisterInf(Void)
{
	if (taskHandleInf) {
		return taskHandleInf;
	}
	else {
		if (!eTodoTaskList) {
			eTodoTaskList = malloc(sizeof(TodoTaskList_t));
			if (!eTodoTaskList) {
				DEBUG_PRINT("Can not allocate memory for TaskListContainer");
				return NULL;
			}
		}

		taskHandleInf = malloc(sizeof(eTaskHandleInf_t));
		if (NULL == eTodoTaskList) {
			DEBUG_PRINT("Cannot allocate memory for TaskHandle Interface");
			return NULL;
		}

		taskHandleInf->Add = eOsalTaskHandle_Add;
		taskHandleInf->Remove = eOsalTaskHandle_Remove;
		taskHandleInf->Sort = eOsalTaskHandle_Sort;
		return taskHandleInf;
	}
}

/**************************************************************************/
/*!
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
Error_t eOsalTaskHandle_Add(eTask_t* newTask)
{
	Error_t errorCode = E_SUCCESS;
	TodoTaskList_t *cur = eTodoTaskList;

	if (!cur)
	{
		eOsal_Init();
	}
	if (!cur->curTask)
	{
		cur->curTask = newTask;
		cur->pNextTask = NULL;
		return E_SUCCESS;
	}

	while (cur->pNextTask != NULL) {
		cur = cur->pNextTask;
	}
	cur->pNextTask = malloc(sizeof(TodoTaskList_t));
	if (!cur->pNextTask) {
		return E_ERR_NULL_MEMALLOCFUNC;
	}
	cur->pNextTask->curTask = newTask;
	cur->pNextTask->pNextTask = NULL;

	//TODO implement add new task to task list
	DEBUG_PRINT("Add new Task with TaskID: %8x\n",
							newTask->TaskId);
	return errorCode;
}

/**************************************************************************/
/*!
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
Error_t eOsalTaskHandle_Remove(UInt32 taskId)
{
	Error_t errorCode = E_SUCCESS;
	TodoTaskList_t *current = eTodoTaskList;

	if (!current->curTask) {
		return E_ERR_NULL_MEMALLOCFUNC;
	}
	do
	{
		if (current->pNextTask->curTask->TaskId == taskId)
		{
			TodoTaskList_t *tmp = current->pNextTask->pNextTask;
			realloc(current->pNextTask,0x0);
			current->pNextTask = tmp;
			return errorCode;
		}
		else
		{
			current = current->pNextTask;
			continue;
		}
	}while(current->pNextTask->curTask);

	errorCode = E_ERROR;
	return errorCode;
}

/**************************************************************************/
/*!
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
Error_t eOsalTaskHandle_Sort(Void)
{
	Error_t errorCode = E_SUCCESS;
	//TODO implement sort Task
	return errorCode;
}

TodoTaskList_t *eOsalTaskHandle_GetTasksList()
{
	if (!eTodoTaskList) {
		eTodoTaskList = malloc(sizeof(TodoTaskList_t));
	}
	return eTodoTaskList;
}
