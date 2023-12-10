#ifndef WALLHACK_H
#define WALLHACK_H

#include "hack.hpp"
#include "hackenum.hpp"

/**
 * @brief Class that operates wallhack.
 */
class WallHack : public Hack {
private:
    void (__stdcall *depth_func) (unsigned int);
    void __attribute__ ((naked)) codecave() final;

public:
    static WallHack *getInstance(GameType type);  
};

#endif