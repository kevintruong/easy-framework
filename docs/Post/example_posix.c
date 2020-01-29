//
// Created by vutruong on 1/29/20.
//
#include "stdio.h"
#include <stdlib.h>

extern char text_start;
extern char data_start;
extern char __bss_start;


extern char etext, edata, end;

int main(void) {
    printf("First address past:\n");
    printf("    program text (text_start)      %10p\n", &text_start);
    printf("    initialized data (data_start)  %10p\n", &data_start);
    printf("    bss () \t  %10p\n", &__bss_start);

    exit(0);

}