#include "hack.hpp"

void Hack::redirect(unsigned char *base, int nnop, void (*codecave)()) {
    DWORD old_protect;

    VirtualProtect((void *) base, nnop + 4, PAGE_EXECUTE_READWRITE, &old_protect);

    *base = JMP;
    *((DWORD *) (base + 1)) = (DWORD) (codecave) - (DWORD) base - 5;

    for (int i = 5; i <= nnop + 4; i++) {
        *(base + i) = NOP;
    }
}
