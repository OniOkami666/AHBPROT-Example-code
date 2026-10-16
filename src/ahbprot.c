#include "ahbprot.h"
#include <stdio.h>
#include <unistd.h>
#include <gctypes.h>
#include <ogcsys.h>

bool is_ahbprot_disabled(void) {
    return (*(vu32*)0xCD800064 == 0xFFFFFFFF);
}

void display_ahbprot_state(void) {
    printf("AHBPROT check example code by OniOkami666\n");
    printf("Checking AHBPROT status...\n");
    sleep(2);

    printf("\r\x1b[2K");

    printf("-----------------------------\n");
    if (is_ahbprot_disabled()) {
        printf("AHBPROT Status: " TEXT_GREEN "DISABLED (Full Access)" TEXT_RESET "\n");
    } else {
        printf("AHBPROT Status: " TEXT_RED "ENABLED (Restricted Access)" TEXT_RESET "\n");
    }
    printf("-----------------------------\n");
}