/**************************************************************************/
/*! 
 @file     eFrameworkTestSuit.c
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
#include "CuTest.h"
#include "eOsal.h"


/******************************************************************************/
/*   			Local Constant and compile switch definition section								*/
/******************************************************************************/

/******************************************************************************/
/*  				Local Type definition section							  */
/******************************************************************************/

/******************************************************************************/
/*  								Local Macro definition section														*/
/******************************************************************************/

/******************************************************************************/
/*  								Local (static) variable definition section								*/
/******************************************************************************/

/******************************************************************************/
/*  								Local (static) function declaration section								*/
/******************************************************************************/

/******************************************************************************/
/*									Local function definition section 												*/
/******************************************************************************/

/******************************************************************************/
/*  						Global function definition section 														*/
/******************************************************************************/
#define DURATION_TEST_TIME 10000
void TestReturnTaskHandleInf(CuTest *tc)
{
	UInt32 count = 0;
	UInt32 false = 0;
	while (count < DURATION_TEST_TIME) {
		count++;
		eTaskHandleInf_t *thisTaskHandle = eOsalTaskHandle_RegisterInf();
		if (thisTaskHandle == NULL) {
			false++;
			continue;
		}
	}
	CuAssertIntEquals(tc, 0, false);
}

void Test_eOsalInit(CuTest *tc)
{
	Error_t errCode = eOsal_Init();
	CuAssertIntEquals_Msg(tc, "eOsalInit Failed", E_SUCCESS, errCode);
}
/**************************************************************************/
/*! 
 @brief  TODO template for code document
 @param  TODO
 @param
 @return TODO
 */
/**************************************************************************/
CuSuite* eFramework_GetTestSuite()
{
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(	suite, TestReturnTaskHandleInf);
	SUITE_ADD_TEST(	suite, Test_eOsalInit);
	return suite;
}
