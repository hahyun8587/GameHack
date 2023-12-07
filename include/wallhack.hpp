#ifndef WALLHACK_H
#define WALLHACK_H

#include "hack.hpp"
#include "hackenum.hpp"

/**
 * @brief Class that operates wallhack.
 * 
 * @param hook_addr hook address where redirection occurs
 * @param nnop number of nop instructions added 
 *      after the redirection instruction
 */
class WallHack : public Hack {
private:
    void (__stdcall *depth_func) (unsigned int);
    void __attribute__ ((naked)) codecave() final;

public:
    WallHack(DWORD hook_addr, int nnop) : Hack(hook_addr, nnop) {}
    static WallHack *getInstance(GameType type);
};

#endif