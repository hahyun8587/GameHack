#include "hack.hpp"
#include "hackenum.hpp"

void Hack::redirect() {
    DWORD old_protect;

    VirtualProtect((void *) hook_addr, nnop + 4, PAGE_EXECUTE_READWRITE, &old_protect);

    *((unsigned char *) hook_addr) = JMP;
    *((DWORD *) (hook_addr + 1)) = (DWORD) (reinterpret_cast<void *>(&codecave)) - hook_addr - 5;

    for (int i = 5; i <= nnop + 4; i++) {
        *((unsigned char *) hook_addr + i) = NOP;
    }
}
