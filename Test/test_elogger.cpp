//
// Created by vutruong on 1/18/20.
//


#include <eMem.h>
#include "gtest/gtest.h"
#include "eLogger.h"

TEST(example, initial_elogger) {
    eLoggerConfig_t logConfig = {
            LOG_DEBUG, "KevinTruong", NULL, NULL};
    eLogger_t *thisLogger = eLogger_create(&logConfig);
    eLogger_log(thisLogger, LOG_FATAL, "%s-%s-%d %s", __FUNCTION__, __FILE_NAME__, __LINE__, "Helloworld");
    eLogger_log(thisLogger, LOG_DEBUG, "%s-%d %s", __FILE_NAME__, __LINE__, "Helloworld");
    eLogger_log(thisLogger, LOG_ERROR, "%s-%d %s", __FILE_NAME__, __LINE__, "Helloworld");
    e_free(thisLogger);
}
