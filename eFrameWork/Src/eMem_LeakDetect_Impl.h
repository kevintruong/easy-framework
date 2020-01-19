//
// Created by vutruong on 1/19/20.
//

#ifndef EFRAMEWORK_EMEM_LEAKDETECT_IMPL_H
#define EFRAMEWORK_EMEM_LEAKDETECT_IMPL_H

#include "eInclude.h"
#include <stdio.h>


void *mleak_detect_malloc0(size_t size, void *caller);

void *mleak_detect_realloc0(void *ptr, size_t size, void *caller);

void *mleak_detect_calloc0(size_t nmemb, size_t size, void *caller);

int mleak_detect_vasprintf0(char **ret, const char *format, va_list ap, void *caller);

void freezero(void *mem, size_t size);


#endif //EFRAMEWORK_EMEM_LEAKDETECT_IMPL_H
