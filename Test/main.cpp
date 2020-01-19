//
// Created by vutruong on 1/18/20.
//

#include "gtest/gtest.h"
extern char text_start;


int main(int argc, char **argv) {
    printf("value of text_start %x",&text_start);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}