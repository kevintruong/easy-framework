/**************************************************************************/
/*! 
    @file     eMacro.h
    @author   KEVIN
		@email		kevin.truong.ds@gmail.com
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
#ifndef EINCLUDE_EMACRO_H_
#define EINCLUDE_EMACRO_H_
 
#ifdef __cplusplus
extern "C"
{
#endif

#define MAX_UINT32 (0xFFFFFFFF)

#define MACRO_CHAR_TO_INT32(a,b,c,d)     \
    ((UInt32) ((UInt8) (a) << 24 | (UInt8) (b) << 16 | (UInt8) (c) << 8 | (UInt8) (d)))

#define MACRO_MAX( __x, __y )  ((__x) > (__y) ? (__x) : (__y))

#define MACRO_MIN( __x, __y ) ((__x) < (__y) ? (__x) : (__y))

#define MACRO_ABS( __x ) (((__x) > 0) ? (__x) : -(__x))

/* The value __x or the bound __y or __z if outside them */
#define MACRO_LIMIT( __x, __y, __z ) MAX( MIN( (__x), MAX( (__y), (__z) )), MIN( (__y), (__z) ))

#define ASSERT(__x, __y) {while(__x == __y);}

#define ASSERT_IFNOT(__x, __y) {while(__x != __y);}

#define UNUSED_PARAMETER(param) ((void)(param))

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

#ifndef ABS
#define ABS MACRO_ABS
#endif

#ifndef LIMIT
#define LIMIT MACRO_LIMIT
#endif


#ifndef ASSERT
#define ASSERT(a,b)
#endif

#ifdef assert
#undef assert
#endif
#define assert(e) if(!(e))while(1)

#define UNUSED_PARAM(param)	((void)(param))

#define INFINITE            0xFFFFFFFF  // Infinite timeout

#define SWAP_16(x) ((((x) >> 8)&0xFF) | (((x) << 8)&0xFF00))
#define SWAP_32(x) ((((x) >> 24)&0xFF) | (((x) >> 8) & 0x0000FF00)\
                        |(((x) << 8) & 0x00FF0000) | (((x) << 24)& 0xFF000000))

#define BYTE_0(x) ((UInt8)(x))
#define BYTE_1(x) ((UInt8)(x>>8))
#define BYTE_2(x) ((UInt8)(x>>16))
#define BYTE_3(x) ((UInt8)(x>>24))

#define BE3BytesToInt32(buff)	((Int32)(((((Int8*)(buff))[0] << 16) & 0x00FF0000) | 			\
								((((Int8*)(buff))[1] << 8) & 0x0000FF00) | 				\
								(((Int8*)(buff))[2] & 0x000000FF)|						\
								((((Int8*)(buff))[0] < 0) ? 0xFF000000 : 0x00000000)))
#define Int32ToBE3Bytes(num, buff) 		\
	do{									\
		(buff)[0] = ((num) >> 16) & 0xFF; \
		(buff)[1] = ((num) >> 8) & 0xFF; 	\
		(buff)[2] = (num) & 0xFF; 		\
	}while(0)

#define	TO_BCD_8(x)		(((x) % 10) | ((((x) / 10) %10) << 4))
#define	TO_BCD_16(x)	(((x) % 10) | ((((x) / 10) %10) << 4) 								\
						| ((((x) / 100) %10) << 8) | ((((x) / 1000) %10) << 12))
#define	TO_BCD_32(x)	(((x) % 10) | ((((x) / 10) %10) << 4) 								\
						| ((((x) / 100) %10) << 8) | ((((x) / 1000) %10) << 12)				\
						| ((((x) / 10000) %10) << 16) | ((((x) / 100000) %10) << 20)		\
						| ((((x) / 1000000) %10) << 24) | ((((x) / 10000000) %10) << 28))

#define	CHECK_ERROR(func)				\
	do{									\
		errCode = func;					\
		if (errCode != SUCCESS){	\
			goto cleanup;				\
		}								\
	}while(0)

#define CHECK_POINTER(ptr) \
	do{											 \
		if (NULL == ptr)     	 \
		{											 \
			errCode = ERR_NULL_MEMALLOCFUNC  					\
			return errCode;														\
		}																						\
	}																							\
	while(0)

#ifdef __cplusplus
}
#endif
#endif /* EINCLUDE_EMACRO_H_ */
