#include <Windows.h>
#include <iostream>
#include "wallhack.hpp"
#include "hackenum.hpp"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    //MessageBoxW(0, 0, 0, 0);
    
    if (fdwReason == DLL_PROCESS_ATTACH) {
        WallHack *wh;
    
        wh = WallHack::getInstance(ASSULT_CUBE);
        
        wh->redirect();

        //wh->enable();
    }
    
    return TRUE;
}
