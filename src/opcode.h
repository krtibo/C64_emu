#include <iostream>
#include "cpu.h"
using namespace std;

#ifndef OPCODE_H
#define OPCODE_H

class Opcode {

    typedef int (Opcode::*OPCODE)(CPU);
    OPCODE opcode_table[0xFF];
    

    public:

    char* last_opcode;
    Opcode();
    int NOP(CPU);

};
#endif