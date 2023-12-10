#include <Windows.h>
#include <iostream>
#include "hack.hpp"
#include "stathack.hpp"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    //MessageBoxW(0, 0, 0, 0);
    
    if (fdwReason == DLL_PROCESS_ATTACH) {
        StatHack *sh = new StatHack();

        sh->modify(ASSULT_CUBE);    
    }
    
    return TRUE;
}
