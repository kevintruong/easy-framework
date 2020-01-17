#ifndef EFRAMEWORK_ELOGGER_H
#define EFRAMEWORK_ELOGGER_H
#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
extern "C" {
#endif
#define MAX_STRING_LENGTH 255

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

typedef char *(*formatterFn)(char *format, ...);

typedef void (*emitterFn)(char *);

typedef void (*logDbFn)(char *format, ...);

typedef struct eLoggerConfig_st {
    LogLevelType_t m_type;
    Char m_name[MAX_STRING_LENGTH];
    formatterFn m_formatterFn;
    emitterFn m_emittorFn;
} eLoggerConfig_t;

typedef struct eLoggerDb_st {
    logDbFn debug;
    logDbFn warn;
    logDbFn info;
} eLoggerDb_t;


Error_t eLogger_create(eLoggerConfig_t *loggerConfig);

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
}
#endif
#endif //EFRAMEWORK_ELOGGER_H
