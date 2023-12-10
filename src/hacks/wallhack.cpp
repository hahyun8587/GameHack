#include "wallhack.hpp"

WallHack *WallHack::getInstance(GameType type) {
    WallHack *wh = new WallHack();

    switch (type) {
        case ASSULT_CUBE:
            HMODULE hmd;
            unsigned char *proc_code;
            
            hmd = GetModuleHandleA("opengl32.dll");
            proc_code = (unsigned char *) GetProcAddress(hmd, "glDrawElement");
            
            wh->hook_code = proc_code + 0x16;
            wh->ret_addr = (DWORD) proc_code + 0x1C;
            wh->nnop = 1;
            wh->depth_func = (void (__stdcall *) (unsigned int)) GetProcAddress(
                    hmd, "glDepthFunc");

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
