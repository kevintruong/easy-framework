//
// Created by vutruong on 1/18/20.
//
#ifndef EFRAMEWORK_EMSGBUS_H
#define EFRAMEWORK_EMSGBUS_H

#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
extern "C" {
#endif


#include "eInclude.h"

/**
 * Base data struct for eMsg
 */
typedef struct eMsg_st {
    UInt32 m_srcTaskId;
    UInt32 m_desTaskId;
    UInt32 m_msgId;
    struct eMsg_st *m_next;
} eMsg_t;

/**
 *
 * @return
 */
Error_t eMsgBus_init();

Error_t eMsgBus_deinit();

Error_t eMsgBus_handler(Void *obj);

/**
 *
 * @param taskId
 * @param msgIdList
 * @return
 */
Error_t eMsgBus_register(UInt32 taskId, UInt32 *msgIdList, UInt32 size);

/**
 *
 * @param taskId
 * @return
 */
Error_t eMsgBus_unregister(UInt32 taskId);

#endif //EFRAMEWORK_EMSGBUS_H
#ifdef __cplusplus /* If this is a C++ compiler, use C linkage */
}
#endif
