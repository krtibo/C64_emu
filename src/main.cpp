#include <iostream>
#include "cpu.h"
#include "mmu.h"
#include "debugger.h"
#include "opcode.h"
using namespace std;


int main( int argc, char** argv ){
    CPU * cpu = new CPU();
    MMU * mmu = new MMU();
    Debugger * debugger = new Debugger();
    Opcode * opcode = new Opcode();
    opcode->NOP(*cpu);
    int counter = 0;
    char str[10];

    // Read KERNAL ROM to its specific location in RAM.
    mmu->read_from_file("/rom/kernal.rom", 0xE000);

    debugger->init();

    while(debugger->render()) {
        sprintf(str, "%d", counter);
        debugger->lines_to_render->at(0) = str;
        debugger->lines_to_render->at(1) = opcode->last_opcode;
        ++counter;
    }

    
    delete cpu;
    delete mmu;
    delete debugger;
}

