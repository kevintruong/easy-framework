#include "eLogger.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>


/************************************************************************************/
/*                                DEFINE SECTION                                    */
/************************************************************************************/


/************************************************************************************/
/*                                MACRO DEFINE                                      */
/************************************************************************************/


/************************************************************************************/
/*                                STACIC VARIABLE                                   */
/************************************************************************************/
static const LogLevel_t LogHeader[] = {
        {LOG_TRACE, "TRACE", "\033[94m"},
        {LOG_DEBUG, "DEBUG", "\033[36m"},
        {LOG_INFO,  "INFO",  "\033[32m"},
        {LOG_WARM,  "WARN",  "\033[33m"},
        {LOG_ERROR, "ERROR", "\033[36m"},
        {LOG_FATAL, "FATAL", "\033[35m"}
};

/************************************************************************************/
/*                                STACIC FUNCTION DECLARE                           */
/************************************************************************************/
Char *eLogger_standardFormatter(const Char *fmt, va_list args) {
    /* Get current time */
    Char *buff = (Char *) calloc(1, MAX_DEBUG_STRING);
    vsnprintf(buff, MAX_DEBUG_STRING, fmt, args);
    return buff;
}

Void eLogger_standardEmitter(const Char *dbString) {
    fprintf(stdout, "%s\n", dbString);
}

/************************************************************************************/
/*                                STATIC FUNCTION IMPLEMENTATION                    */
/************************************************************************************/


/************************************************************************************/
/*                                GLOBAL FUNCTION DEFINE                             */
/************************************************************************************/
eLogger_t *eLogger_create(eLoggerConfig_t *loggerConfig) {
    eLogger_t *thisLogger = (eLogger_t *) calloc(1, sizeof(eLogger_t));
    if (thisLogger == NULL) {
        return NULL;
    }
    thisLogger->m_config = loggerConfig;
    if (!thisLogger->m_config->m_emittorFn) {
        thisLogger->m_config->m_emittorFn = eLogger_standardEmitter;
    }
    if (!thisLogger->m_config->m_formatterFn) {
        thisLogger->m_config->m_formatterFn = eLogger_standardFormatter;
    }
    return thisLogger;
}


Error_t eLogger_log(eLogger_t *thisloger, LogLevelType_t loglevel, const Char *fmt, ...) {

    char buf[16];
    Char *buffer;
    time_t t;
    struct tm *lt;
    va_list args;

    if (loglevel <= thisloger->m_config->m_type) {
        return E_SUCCESS;
    }

    buffer = (Char *) calloc(1, MAX_DEBUG_STRING);
    if (!buffer) {
        return E_ERR_NULL_MEMALLOCFUNC;
    }

    t = time(NULL);
    lt = localtime(&t);
    buf[strftime(buf, sizeof(buf), "%H:%M:%S", lt)] = '\0';

    snprintf(buffer, MAX_DEBUG_STRING, "%s %s%-5s \033[0m", buf,
             LogHeader[loglevel].m_color,
             LogHeader[loglevel].m_header);

    va_start(args, fmt);
    Char *formattedDbStr = thisloger->m_config->m_formatterFn(fmt, args);
    va_end(args);
    strcat(buffer, formattedDbStr);
    thisloger->m_config->m_emittorFn(buffer);
    free(buffer);
    free(formattedDbStr);
    return E_SUCCESS;
}
