#include "opcode.h"

Opcode::Opcode() {
    for(unsigned int i=0; i<0xFF; i++) {
        opcode_table[i] = &Opcode::NOP;
    }
}

int Opcode::NOP(CPU cpu) {
    this->last_opcode = "NOP";
    return 2;
}