#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include "gfx.hpp"   

// PSP kernel module info
PSP_MODULE_INFO("Test1", 0, 1, 0 );

/*start of exit callback function*/ 
int exit_callback(int arg1, int arg2, void* common){
    sceKernelExitGame();
    return 0;
}

//Callback thread
int callbackThread(SceSize args, void* argp){
    int cbid;
    
    cbid = sceKernelCreateCallback("Exit Callback", exit_callback, nullptr);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
   
    return 0;
}
//Sets up the callback thread and returns its thread id
int setupCallbacks() {
    int thid = 0;
    thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, nullptr);
    if (thid >=0){
        sceKernelStartThread(thid,  0, nullptr);
    }

    return thid;
}
/*End of callback function*/

//main program
auto main() -> int{
    setupCallbacks();       //Menu Button or exit button
    GFX::init();

    while(1){
        GFX::clear(0xFFFFCA82); //#82CAFFFF RGBA(#AARRGGBB) in HEX -> 0xFFFFCA82 -> 0xAABBGGRR

        GFX::drawRect(10, 10, 30, 30, 0xFF00FFFF); //0xFF00FFFF -> 0xAABBGGRR

        GFX::swapBuffers();
        sceDisplayWaitVblankStart();
    }
   /*Debug buttons
    pspDebugScreenInit();   //shows debug screen
   
    //Controller support for full range
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    SceCtrlData ctrlData;

    
    while (1){

        sceCtrlReadBufferPositive(&ctrlData, 1);    //polls for data

        if(ctrlData.Buttons & PSP_CTRL_CROSS){
            pspDebugScreenPrintf("Cross Pressed!\n");
        }
        
        if(ctrlData.Buttons & PSP_CTRL_CIRCLE){
            pspDebugScreenPrintf("Circle Pressed!\n");
        }
        
        if(ctrlData.Buttons & PSP_CTRL_SQUARE){
            pspDebugScreenPrintf("Square Pressed!\n");
        }
        
        if(ctrlData.Buttons & PSP_CTRL_TRIANGLE){
            pspDebugScreenPrintf("Triangle Pressed!\n");
        }

    }
    */
}