#ifndef EFRAMEWORK_ELOGGER_H
#define EFRAMEWORK_ELOGGER_H
#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
extern "C" {
#endif
#define MAX_STRING_LENGTH 255
#define MAX_DEBUG_STRING 1024

#include <stdio.h>
#include "eInclude.h"

typedef enum LogMode_en {
    LOG_MODE_FILE,
    LOG_MODE_CONSOLE,
    LOG_MODE_FILE_CONSOLE,
    LOG_MODE_NULL
} LogMode_t;

typedef struct Formatter_st {
    LogMode_t m_mode;
    Char m_format[MAX_STRING_LENGTH];
} Formatter_t;

typedef enum LogLevelType_en {
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARM,
    LOG_ERROR,
    LOG_FATAL
} LogLevelType_t;

typedef struct LogLevel {
    LogLevelType_t m_type;
    Char m_header[32];
    Char m_color[32];
} LogLevel_t;

typedef char *(*formatterFn)(const Char *format, va_list args);

typedef void (*emitterFn)(const Char *);

typedef void (*logDbFn)(char *format, ...);

typedef struct eLoggerConfig_st {
    LogLevelType_t m_type;
    Char m_name[MAX_STRING_LENGTH];
    formatterFn m_formatterFn;
    emitterFn m_emittorFn;
} eLoggerConfig_t;


typedef struct eLogger_st {
    eLoggerConfig_t *m_config;
} eLogger_t;


eLogger_t *eLogger_create(eLoggerConfig_t *loggerConfig);
Error_t eLogger_log(eLogger_t *thisloger, LogLevelType_t loglevel, const Char *fmt, ...);

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
}
#endif
#endif //EFRAMEWORK_ELOGGER_H
