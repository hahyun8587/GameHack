#ifndef TRIGGERHACK_H
#define TRIGGERHACK_H

#include "hack.hpp"

class TriggerHack : public Hack {
private:
    INPUT mouse_leftdown;
    INPUT mouse_leftup;
    DWORD ori_call_addr;
    DWORD is_aimed;
    void __declspec(naked) codecave();

public:
    TriggerHack();
    void modify(GameType type) final;
};

#endif
