#include "hack.hpp"
#include "stathack.hpp"
//#include "triggerhack.hpp"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        StatHack *sh = new StatHack();

        sh->modify(ASSULT_CUBE);    
    }
    
    return TRUE;
}
