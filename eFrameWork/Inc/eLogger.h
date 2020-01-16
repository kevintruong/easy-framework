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

static const LogLevel_t LogHeader[] = {
        {LOG_TRACE, "TRACE", "\x1b[94m"},
        {LOG_DEBUG, "DEBUG", "\x1b[36m"},
        {LOG_INFO,  "INFO",  "\x1b[32m"},
        {LOG_WARM,  "WARN",  "\x1b[33m"},
        {LOG_ERROR, "ERROR", "\x1b[36m"},
        {LOG_FATAL, "FATAL", "\x1b[35m"}
};
#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
}
#endif
#endif //EFRAMEWORK_ELOGGER_H
