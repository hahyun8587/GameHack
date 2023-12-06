#ifndef WALLHACK_H
#define WALLHACK_H

#include "hack.hpp"

class WallHack : public Hack {
private:
    void __declspec(naked) codecave() final;

public:
    WallHack(DWORD hook_addr, int nnop) : Hack(hook_addr, nnop) {}
};

#endif