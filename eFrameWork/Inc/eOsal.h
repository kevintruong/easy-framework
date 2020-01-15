/**************************************************************************/
/*! 
    @file     eOsal.h
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
#ifndef INC_EOSAL_H_
#define INC_EOSAL_H_

#ifdef __cplusplus
extern "C"
{
#endif
/******************************************************************************/
/*                            Include section                                 */
/******************************************************************************/
#include "eInclude.h"
#include "eOsalTaskHandle.h"
#include "eTimerHandler.h"

/******************************************************************************/
/*                            Type definition section                         */
/******************************************************************************/
typedef enum AppState_en {
    APP_REGISTER_INF_STATE,
    APP_COMPONENTS_INIT_STATE,
    APP_RUNNING_STATE
} AppState_t;
/******************************************************************************/
/*                            Macro definition section                        */
/******************************************************************************/

/******************************************************************************/
/*                       Function declaration section                         */
/******************************************************************************/
/******************************************************************************/
/*!
    @brief  TODO template for code document

    @param  None
    @return SUCCESS if none happen error
            Otherwise return error
*/
/******************************************************************************/
Error_t eOsal_Init(Void);
/******************************************************************************/
/*!
    @brief  Osal will polling what task is needded to process

    @param  None
    @return None
*/
/******************************************************************************/
Void eOsal_Schedule(Void);

Error_t eOsal_EnterPowerDownMode(Void);

#ifdef __cplusplus
}
#endif
#endif /* INC_EOSAL_H_ */
