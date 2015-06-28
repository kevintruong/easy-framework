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

/******************************************************************************/ 
/*   			Local Constant and compile switch definition section								*/
/******************************************************************************/
#ifndef DEBUG
#define DEBUG 3
#else
#if defined(DEBUG) && DEBUG > 0
 #define DEBUG_PRINT(fmt, args...) fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, \
    __FILE__, __LINE__, __func__, ##args)
#else
 #define DEBUG_PRINT(fmt, args...) /* Don't do anything in release builds */
#endif
#endif
/******************************************************************************/ 
/*  										Local Type definition section													*/
/******************************************************************************/
typedef struct TodoTaskList_st
{
	struct eTask_st *curTask;			/*<<<! Pointer to task data  */
	struct TodoTaskList_st* pNextTask;	/*<<<! Pointer to next element of taskList  */
}TodoTaskList_t;

/******************************************************************************/ 
/*  								Local Macro definition section														*/
/******************************************************************************/ 



/******************************************************************************/ 
/*  								Local (static) variable definition section								*/
/******************************************************************************/ 
TodoTaskList_t* eTodoTaskList;		/*<<<! Container hold all task element */
eTaskHandleInf_t * taskHandle;			/*<<<! return interface to access container */

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
eTaskHandleInf_t *eOsalTaskHandle_Init(Void)
{
	if (taskHandle)
	{
		return taskHandle;
	}
	else
	{
		eTodoTaskList = malloc(sizeof(TodoTaskList_t));
		if (NULL == eTodoTaskList)
		{
			DEBUG_PRINT("Can not allocate memory for TaskListContainer");
			return NULL;
		}
		taskHandle = malloc(sizeof(eTaskHandleInf_t));
		if (NULL == eTodoTaskList)
		{
			DEBUG_PRINT("Cannot allocate memory for TaskHandle Interface");
			return NULL;
		}
		// TODO need to assign the implementation to interface
		taskHandle->Add = eOsalTaskHandle_Add;
		taskHandle->Remove = eOsalTaskHandle_Remove;
		taskHandle->Sort = eOsalTaskHandle_Sort;
		return taskHandle;
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
	//TODO implement add new task to task list
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
	//TODO implement add remove task
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
