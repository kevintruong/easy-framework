/**************************************************************************/
/*! 
    @file     eTask.h
    @author   KEVIN
    @section LICENSE
    Software License Agreement (BSD License)
    Copyright (c) 2015 KEVIN
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
#ifndef INC_ETASK_H_
#define INC_ETASK_H_

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************/
/* 										  			Include section 																*/
/******************************************************************************/
#include "eInclude.h"

/******************************************************************************/
/* 										  			Type definition section													*/
/******************************************************************************/

typedef Error_t (*TaskHandleFn)(Void *);                /*<<<! Function pointer point to the method process the task*/
typedef Error_t (*TaskSuspendFn)(Void *);                /*<<<! Function pointer point to the method process the task*/
typedef Error_t (*TaskResumeFn)(Void *);                /*<<<! Function pointer point to the method process the task*/



typedef enum TaskPrority_en {
    LOW_LEVEL,
    NORMAL_LEVEL,
    HIGH_LEVEL,
    HIGHEST_LEVEL
} TaskPriority_t;

typedef struct eTask_st {
    UInt32 TaskId;                    /*<<<! TaskId of a task */
    TaskPriority_t TaskPriority;    /*<<<! Priority of task */
    Bool IsTriggerProcess;            /*<<<! Flag to know the task is trigger to process or not */
    TaskHandleFn taskHandle;        /*<<<! Function pointer point to Function process a task  */
    TaskResumeFn taskResume;        /*<<<! Resume current task */
    TaskSuspendFn taskSuspend;        /*<<<! suspend the task.  */
} eTask_t;

/******************************************************************************/
/* 										  			Macro definition section												*/
/******************************************************************************/

/******************************************************************************/
/* 							  			 Function declaration section													*/
/******************************************************************************/


#ifdef __cplusplus
}
#endif
#endif /* INC_ETASK_H_ */
