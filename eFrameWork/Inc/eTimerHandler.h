/**************************************************************************/
/*! 
    @file     eTimerHandler.h
    @author   kevin
    @email    kevin.truong.ds@gmail.com
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
#ifndef EFRAMEWORK_INC_ETIMERHANDLER_H_
#define EFRAMEWORK_INC_ETIMERHANDLER_H_

#ifdef __cplusplus
extern "C"
{
#endif


/******************************************************************************/
/*                            Include section                                 */
/******************************************************************************/
#include "eInclude.h"
#include "eTimer.h"
/******************************************************************************/
/*                            Type definition section                         */
/******************************************************************************/
typedef Error_t (*AddNewTimer)(eTimer_t *);

typedef Error_t (*RemoveATimer)(UInt32);

typedef struct TimerHandleQueue_st {
    eTimer_t *pCurTimer;
    struct TimerHandleQueue_st *pNextTimer;
} TimerHandlerQueue_t;

typedef struct TimerHandlerQueue_Inf_st {
    AddNewTimer add;
    RemoveATimer remove;
} TimerHandleQueueInf_st;

/******************************************************************************/
/*                            Macro definition section                        */
/******************************************************************************/

/******************************************************************************/
/*                       Function declaration section                         */
/******************************************************************************/
TimerHandleQueueInf_st *eTimerHandlerRegisterInf();


#ifdef __cplusplus
}
#endif
#endif /* EFRAMEWORK_INC_ETIMERHANDLER_H_ */
