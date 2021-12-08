#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
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
    setupCallbacks();
    pspDebugScreenInit();


    pspDebugScreenPrintf("2!");
}