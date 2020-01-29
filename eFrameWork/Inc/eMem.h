//
// Created by vutruong on 1/19/20.
//

#ifndef EFRAMEWORK_EMEM_H
#define EFRAMEWORK_EMEM_H
#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
extern "C" {
#endif

#include <stdio.h>

void *e_malloc(size_t size);

void *e_calloc(size_t nmemb, size_t size);

void *e_reallocarray(void *ptr, size_t nmemb, size_t size);

char *e_strdup(const char *str);

int e_vasprintf(char **ret, const char *format, va_list ap);

int e_asprintf(char **ret, const char *format, ...);

void e_free(void *mem);

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
}
#endif
#endif //EFRAMEWORK_EMEM_H
