#include "wallhack.hpp"

WallHack *WallHack::getInstance(GameType type) {
    WallHack *wh;

    switch (type) {
        case ASSULT_CUBE:
            HMODULE hmd;
            FARPROC proc_addr;
            
            hmd = GetModuleHandleA("opengl32.dll");
            proc_addr = GetProcAddress(hmd, "glDrawElement");
            wh = new WallHack((DWORD) proc_addr + 0x16, 1);
            wh->depth_func = (void (__stdcall *) (unsigned int)) GetProcAddress(
                    hmd, "glDepthFunc");
            wh->ret_addr = (DWORD) proc_addr + 0x1C;

            break;
    }

    return wh;
}

void __attribute__ ((naked)) WallHack::codecave() {
    asm (
        "pushal"  
    );
    
    if (flag) {
        depth_func(GL_ALWAYS);
    } else {
        depth_func(GL_LEQUAL);
    }
    
    asm (
        "popal\n\t"
        "movl 0xA18(%esi), %esi\n\t"
        "jmp 0x70B0600C"
    );
}
