#include "triggerhack.hpp"

TriggerHack::TriggerHack() {
    memset(&mouse_leftdown, 0, sizeof(INPUT));
    
    mouse_leftdown.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    memset(&mouse_leftup, 0, sizeof(INPUT));
    
    mouse_leftup.mi.dwFlags = MOUSEEVENTF_LEFTUP;
}

void TriggerHack::modify(GameType type) {
    switch (type) {
        case ASSULT_CUBE:
            unsigned char *ac_client_base;

            ac_client_base = (unsigned char *)  GetModuleHandleA("ac_client.exe");
            ori_call_addr = (DWORD) ac_client_base + 0x607C0;
            ret_addr = (DWORD) ac_client_base + 0xADA2;

            //redirect(ac_client_base + 0xAD9D, 0, (void (*)()) &codecave);

            break;
    }
}

void __declspec(naked) TriggerHack::codecave() {
    __asm__ __volatile__(
        "call %1\n\t"
        "pushal\n\t"
        "mov %%eax, %0"
        : "=r" (is_aimed) : "r" (ori_call_addr)
    );

    if (is_aimed) {
        SendInput(1, &mouse_leftdown, sizeof(INPUT));
    } else {
        SendInput(1, &mouse_leftdown, sizeof(INPUT));
    }

    __asm__ __volatile__(
        "popal\n\t"
        "mov %%ebp, %%esp\n\t"
        "pop %%ebp\n\t"
        "jmp %0"
        : : "r" (ret_addr)
    );
}
