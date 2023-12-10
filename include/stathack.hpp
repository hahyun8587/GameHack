#ifndef STATHACK_H
#define STATHACK_H

#include "hack.hpp"

class StatHack : public Hack {
public:
    void modify(GameType type) final;
};

#endif