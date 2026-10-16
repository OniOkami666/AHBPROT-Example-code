#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include "ahbprot.h"

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

int main(int argc, char **argv) {
    VIDEO_Init();

    
    rmode = VIDEO_GetPreferredMode(NULL);

    
    xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

    
    CON_Init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * 2);

    
    VIDEO_Configure(rmode);
    VIDEO_SetNextFramebuffer(xfb);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();
    if (rmode->viTVMode & VI_INTERLACE)
        VIDEO_WaitVSync();

    
    display_ahbprot_state();

    while(1) {
        WPAD_ScanPads();

        u32 pressed = WPAD_ButtonsDown(0);
        if (pressed & WPAD_BUTTON_HOME) {
            printf("Exiting...");
            sleep(2);
            exit(0);
        }

        VIDEO_WaitVSync();
    }

    return 0;
}