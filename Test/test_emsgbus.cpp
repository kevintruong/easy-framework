//
// Created by vutruong on 1/18/20.
//


#include "gtest/gtest.h"
#include "eMsgBus.h"

TEST(example, eMsgBus_register) {
    UInt32 msgId[] = {0x02, 0x09, 0x10, 0x11};
    eMsgBus_init();
    eMsgBus_register(0x001, (UInt32 *) &msgId, (UInt32) sizeof(msgId));
    eMsgBus_unregister(0x001);
}

