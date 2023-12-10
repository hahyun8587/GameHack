#include "stathack.hpp"

void StatHack::modify(GameType type) {
    switch (type) {
        case ASSULT_CUBE:
            unsigned char *ac_client_base;
            unsigned char *hook_base;
            DWORD old_protect;

            ac_client_base = (unsigned char *) GetModuleHandleA("ac_client.exe");

            hook_base = ac_client_base + 0x637E9;
    
            VirtualProtect((void *) hook_base, 1, PAGE_EXECUTE_READWRITE, &old_protect);

            *hook_base = NOP;
            *(hook_base + 1) = NOP;

            DWORD *static_base;
            DWORD *dynamic_base;
            DWORD *health;

            static_base = (DWORD *) 0x0019F648;
            dynamic_base = static_base + 2;
            health = (DWORD *) (*dynamic_base + 278 + 4);

            //VirtualProtect((void *) health, 3, PAGE_EXECUTE_READWRITE, &old_protect);

            *health = 200;

            //redirect(ac_client_base + 0x29D1F, 0, (void (*)()) &codecave1);
            
            break;
    }       
}

void __declspec(naked) StatHack::codecave1() {
    __asm__ __volatile__ (
        //"sub %edi, 0x04(%ebx)\n"
        "mov %edi, %eax\n"
        "mov %ebp, %esp\n"
        "pop %ebp\n"
        "push $0x00429D24\n"
        "ret"
    );
}