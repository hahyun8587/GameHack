#include <Windows.h>
#include <iostream>
#include "hack.hpp"
#include "stathack.hpp"
//#include "triggerhack.hpp"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    //MessageBoxW(0, 0, 0, 0);
    
    if (fdwReason == DLL_PROCESS_ATTACH) {
        StatHack *th = new StatHack();

        th->modify(ASSULT_CUBE);    
    }
    
    return TRUE;
}
