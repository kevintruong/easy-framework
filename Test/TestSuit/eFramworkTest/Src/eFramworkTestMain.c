/**************************************************************************/
/*! 
    @file     eFramworkTestMain.c
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

/******************************************************************************/ 
/*                            Include section                                 */
/******************************************************************************/ 
#include <stdio.h>
#include "eInclude.h"
#include "CuTest.h"
#include "eOsal.h"
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



/******************************************************************************/ 
/*                  Local (static) function declaration section               */
/******************************************************************************/ 



/******************************************************************************/ 
/*                  Local function definition section                         */
/******************************************************************************/ 
CuSuite* eFramework_GetTestSuite();

/******************************************************************************/ 
/*              Global function definition section                            */
/******************************************************************************/
void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, eFramework_GetTestSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}
/**************************************************************************/
/*! 
    @brief  TODO template for code document  
    @param  TODO
    @param  
    @return TODO
*/
/**************************************************************************/
Int32 main(Void)
{
  RunAllTests();
  return 0;
}
