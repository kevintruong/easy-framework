//
// Created by vutruong on 1/18/20.
// Peer to peer message delivery
// publish/subscribe message delivery
// check desTaskId is specific => peer to peer
// otherwise, publish/subscribe

#include "eMsgBus.h"
#include "qlibc/qlibc.h"
#include <stdlib.h>
#include <string.h>

typedef struct SubMsgIdList_st {
    UInt32 m_taskId;
    UInt32 *m_msgIdList;
    UInt32 m_size;
} SubMsgIdList_t;

qqueue_t *msgQueue;
qlist_t *subList;

Error_t eMsgBus_init() {
    msgQueue = qqueue(0);
    subList = qlist(0);
    return E_SUCCESS;
}

Error_t eMsgBus_deinit() {
    return E_SUCCESS;
}

Error_t eMsgBus_handler(Void *obj) {
    return E_SUCCESS;
}

/**
 * Each task will register a list of msgId it could receive.
 * the eMsgBus will deliver the msgId match with MsgId  which is already registered by a taskId
 * @param taskId
 * @param msgIdList
 * @return
 */
Error_t eMsgBus_register(UInt32 taskId, UInt32 *msgIdList, UInt32 size) {
    SubMsgIdList_t *msgIdListObj = (SubMsgIdList_t *) calloc(1, sizeof(msgIdList));
    msgIdListObj->m_msgIdList = (UInt32 *) calloc(1, size);
    memcpy(msgIdListObj->m_msgIdList, msgIdList, size);
    msgIdListObj->m_size = size;
    msgIdListObj->m_taskId = taskId;
    subList->addfirst(subList, msgIdListObj, sizeof(SubMsgIdList_t));
    free(msgIdListObj->m_msgIdList);
    free(msgIdListObj);
    return E_SUCCESS;
}

Error_t eMsgBus_unregister(UInt32 taskId) {
    SubMsgIdList_t *subMsgId;
    int index;
    qlist_obj_t obj;

    memset((void *) &obj, 0, sizeof(obj));  // must be cleared before call
    index = 0;
    while (subList->getnext(subList, &obj, false) == true) {
        subMsgId = (SubMsgIdList_t *) obj.data;
        if (subMsgId->m_taskId == taskId) {
            subList->removeat(subList, index);
        }
        ++index;
    }
    return E_SUCCESS;
}

Error_t eMsgBus_pushMsg(eMsg_t *msgObj) {
    return E_SUCCESS;
}


