//
// Created by vutruong on 1/18/20.
//

#include "gtest/gtest.h"

extern char text_start;
extern char rodata_start;
extern char data_start;
extern char __bss_start;


int main(int argc, char **argv) {
    printf("value of text_start 0x%2x\n", &text_start);
    printf("value of rodata_start 0x%2x\n", &rodata_start);
    printf("value of data_start 0x%2x\n", &data_start);
    printf("value of bss_start 0x%2x\n", &__bss_start);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}