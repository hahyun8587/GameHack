#ifndef HACK_H
#define HACK_H

#include <minwindef.h>

/**
 * @brief Base class of hacks.
 * 
 * @param hook_addr hook address where redirection occurs
 * @param nnop number of nop instructions added 
 *      after the redirection instruction
 */
class Hack {
private:     
    DWORD hook_addr;
    int nnop; 
    bool flag;

    /**
     * @brief Operates hack.
     */
    virtual void __declspec(naked) codecave() {}

public:    
    Hack(DWORD hook_addr, int nnop) 
        : hook_addr(hook_addr), nnop(nnop), flag(false) {}

    /**
     * @brief Enables hack.
     */
    void enable() { flag = true }

    /**
     * @brief Disables hack. 
     */
    void disable() { flag = false }

    /**
    * @brief Redirects original code to `codecave`.
    */
    void redirect();
};

#endif