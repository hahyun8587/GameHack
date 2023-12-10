#ifndef STATHACK_H
#define STATHACK_H

#include "hack.hpp"

class StatHack : public Hack {
private:
    void codecave1();

public:
    void modify(GameType type) final;
};

#endif