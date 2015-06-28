/**************************************************************************/
/*! 
    @file     eTypes.h
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
#ifndef INC_EINCLUDE_ETYPES_H_
#define INC_EINCLUDE_ETYPES_H_
 
#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------------------------------
 * Types and defines:
 *-----------------------------------------------------------------------------*/
#ifndef False
    #define False           0
#endif

#ifndef True
    #define True            1
#endif

#ifndef Null
    #define Null            ((Void *) 0)
#endif

#undef NULL
#ifndef NULL
    #define NULL            (0)
#endif

/*****************************************************************************
 *      Standard Types
 *****************************************************************************/
#define Const const
typedef signed   char   Int8,   *pInt8;     /*  8 bit   signed integer */
typedef signed   short  Int16,  *pInt16;    /* 16 bit   signed integer */
typedef signed   int    Int32,  *pInt32;    /* 32 bit   signed integer */
typedef unsigned char   UInt8,  *pUInt8;    /*  8 bit unsigned integer */
typedef unsigned short  UInt16, *pUInt16;   /* 16 bit unsigned integer */
typedef unsigned int    UInt32, *pUInt32;   /* 32 bit unsigned integer */
typedef void            Void,   *pVoid;     /* Void (typeless) */
typedef float           Float,  *pFloat;    /* 32 bit floating point */
typedef double          Double, *pDouble;   /* 32/64 bit floating point */
typedef unsigned char   Bool,   *pBool;     /* Boolean (True/False) */
typedef char            Char,   *pChar;     /* character, character array ptr */
typedef char           *String, **pString;  /* Null terminated 8 bit char str, */
                                            /* Null term 8 bit char str ptr */
typedef char const     *ConstString;

typedef signed   long long int Int64,  *pInt64;  /* 64-bit integer    */
typedef unsigned long long int UInt64, *pUInt64; /* 64-bit bitmask */


#ifdef __cplusplus
}
#endif
#endif /* INC_EINCLUDE_ETYPES_H_ */
