#include "hack.hpp"
#include "util/instruction.hpp"

void Hack::redirect() {
    unsigned char *hook_instr = (unsigned char *) hook_addr;

    *hook_instr = Instruction::JMP;
    *((DWORD *) (hook_instr + 1)) = (DWORD) codecave - hook_addr + 5;

    for (int i = 5; i <= nnop + 4; i++) {
        *(hook_instr + i) = Instruction::NOP;
    }
}
