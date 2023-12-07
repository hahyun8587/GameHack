#ifndef HACKTYPE_H
#define HACKTYPE_H

enum Instruction {
    JMP = 0xE9,
    NOP = 0x90
};

enum GameType {
    ASSULT_CUBE
};

enum DepthTestFlag {
    GL_ALWAYS = 0x207,
    GL_LEQUAL = 0x203
};

#endif