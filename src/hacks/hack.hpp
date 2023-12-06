#ifndef __HACK_H__
#define __HACK_H__

#include <minwindef.h>

#define BUF_SIZE 256

/**
 * Base class of hacks.
 * 
 * @param hook_addr hook address where code cave is stored
 * @param ret_addr return address that code cave uses 
 *      for returning to original code
 * @param nnop number of nop instructions needed 
 *      for changing original code to hook code 
 */
class Hack {
private: 
    char *hook_instr[BUF_SIZE];
    char *orig_instr[BUF_SIZE];
    
    virtual __declspec(naked) void codecave();

public:
    Hack(DWORD hook_addr, DWORD ret_addr, int nnop);
    virtual void enable();
    virtual void disable();
};

#endif