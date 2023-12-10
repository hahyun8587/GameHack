#ifndef TRIGGERHACK_H
#define TRIGGERHACK_H

#include "hack.hpp"

class TriggerHack : public Hack {
private:
    int is_aimed;
    void __declspec(naked) codecave();
    INPUT mouse_leftdown;
    INPUT mouse_leftup;
    DWORD ori_call_addr;

public:
    TriggerHack();
    void modify(GameType type) final;
};

#endif
