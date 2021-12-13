    #include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h> 
#include <pspctrl.h>  
#include "common/callback.h"
#define VERS 1
#define REVS 0

PSP_MODULE_INFO("PSP Test3", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

#define printf pspDebugScreenPrintf     //replace debug with print

int main(void)
{
    pspDebugScreenInit();   //intialise debug screen
    setupExitCallback();    //enables Exit Callback

    int running = isRunning();

    //Controller support for full range
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    SceCtrlData buttonInput;

    while(running)
    {
        running = isRunning();
        pspDebugScreenSetXY(0,0);
        sceCtrlReadBufferPositive(&buttonInput, 1);    //polls for data

        printf("Check Buttons\n");
        printf("Analog X = %d ", buttonInput.Lx);
        printf("Analog Y = %d\n", buttonInput.Ly);
        
        if(buttonInput.Buttons & PSP_CTRL_START)   printf("Start\n");
        if(buttonInput.Buttons & PSP_CTRL_SELECT)   printf("Select\n");

        if(buttonInput.Buttons & PSP_CTRL_CROSS)    printf("Cross\n");
        if(buttonInput.Buttons & PSP_CTRL_CIRCLE)   printf("Circle\n");
        if(buttonInput.Buttons & PSP_CTRL_SQUARE)   printf("Square\n");
        if(buttonInput.Buttons & PSP_CTRL_TRIANGLE) printf("Triangle\n");

        if(buttonInput.Buttons & PSP_CTRL_UP)    printf("Up\n");
        if(buttonInput.Buttons & PSP_CTRL_DOWN)   printf("Down\n");
        if(buttonInput.Buttons & PSP_CTRL_LEFT)   printf("Left\n");
        if(buttonInput.Buttons & PSP_CTRL_RIGHT) printf("Right\n");
        
        if(buttonInput.Buttons & PSP_CTRL_LTRIGGER)    printf("Left Trigger\n");
        if(buttonInput.Buttons & PSP_CTRL_RTRIGGER)   printf("Right Trigger\n");

        if(buttonInput.Buttons & PSP_CTRL_SCREEN)   printf("Screen\n");
        if(buttonInput.Buttons & PSP_CTRL_NOTE)     printf("Note\n");
        if(buttonInput.Buttons & PSP_CTRL_VOLDOWN)    printf("Volume Down\n");
        if(buttonInput.Buttons & PSP_CTRL_VOLUP)   printf("Volume Up\n");

        sceDisplayWaitVblankStart(); //Wait for Vertical blank to start
    }
        return 0;
}