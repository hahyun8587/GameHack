#ifndef HACK_H
#define HACK_H

#include <Windows.h>
#include "hackenum.hpp"

/**
 * @brief Base class of hacks.
 */
class Hack {
protected:  
    DWORD ret_addr;
    bool flag = 0;

    /**
    * @brief Redirects original instruction to `codecave`.
    * @param base base pointer of instruction to be redirected
    * @param nnop number of nop instructions to be added
    */
    void redirect(unsigned char *base, int nnop, void (*codecave)());

public:    
    /**
     * @brief Enables hack.
     */
    void enable() { flag = true; }

    /**
     * @brief Disables hack. 
     */
    void disable() { flag = false; }

    /**
     * @brief Modifies original instructions based on given `type`.
     * @param type the type of game
     */
    virtual void modify(GameType type) {};
};

#endif