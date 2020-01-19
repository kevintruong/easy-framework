//
// Created by vutruong on 1/19/20.
//

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "eMem.h"

#ifdef MEMLEAK_DEBUG

#include "eMem_LeakDetect_Impl.h"
void *e_calloc(size_t nmemb, size_t size) {
    return (mleak_detect_calloc0(nmemb, size, __builtin_return_address(0)));
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    return (mleak_detect_realloc0(ptr, nmemb * size, __builtin_return_address(0)));
}

char *e_strdup(const char *str) {
    void *p;
    int lstr;

    lstr = strlen(str) + 1;
    p = mleak_detect_malloc0(lstr, __builtin_return_address(0));
    strncpy(p, str, lstr);

    return (p);
}

int e_vasprintf(char **ret, const char *format, va_list ap) {
    return mleak_detect_vasprintf0(ret, format, ap, __builtin_return_address(0));
}


void *e_recallocarray(void *ptr, size_t oldnmemb, size_t nmemb, size_t size) {
    void *ret;

    ret = mleak_detect_realloc0(ptr, nmemb * size, __builtin_return_address(0));

    if (ret != NULL && nmemb - oldnmemb > 0)
        memset(ret + oldnmemb * size, 0, (nmemb - oldnmemb) * size);

    return (ret);
}


char *
e_strndup(const char *str, size_t maxlen) {
    void *p;
    int lstr = 0;

    while (str[lstr] != '\0' && lstr < maxlen)
        lstr++;
    lstr++;

    p = mleak_detect_malloc0(lstr, __builtin_return_address(0));
    strncpy(p, str, lstr);

    return (p);
}


void *e_malloc(size_t size) {
    return (mleak_detect_malloc0(size, __builtin_return_address(0)));
}

int e_asprintf(char **ret, const char *format, ...) {
    va_list ap;
    int rv;

    va_start(ap, format);
    rv = mleak_detect_vasprintf0(ret, format, ap, __builtin_return_address(0));
    va_end(ap);

    return (rv);
}
void
e_free(void *mem) {
    freezero(mem, 0);
}


#else

void *e_malloc(size_t size) {
    return malloc(size);
}

void *e_calloc(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}


void *e_reallocarray(void *ptr, size_t nmemb, size_t size) {
    void *ret;
    ret = realloc(ptr, nmemb * size);
    return (ret);
}

char *e_strdup(const char *str) {
    return strdup(str);
}

int e_vasprintf(char **ret, const char *format, va_list ap) {
    return vasprintf(ret, format, ap);
}

int e_asprintf(char **ret, const char *format, ...) {
    va_list ap;
    int rv;

    va_start(ap, format);
    rv = vasprintf(ret, format, ap);
    va_end(ap);

    return (rv);
}

#endif
