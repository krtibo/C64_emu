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

    debugger->lines_pool->push_back("wow");
    debugger->lines_pool->push_back("yay");
    debugger->lines_pool->push_back("kek");
    debugger->lines_pool->push_back("lol");
    debugger->lines_pool->push_back(opcode->last_opcode);
    debugger->lines_pool->push_back(str);

    while(debugger->render()) {
        sprintf(str, "%d", counter);
        
        debugger->lines_pool->at(debugger->lines_pool->size()-1) = str;
        debugger->lines_pool->at(debugger->lines_pool->size()-2) = opcode->last_opcode;
        ++counter;
    }

    delete cpu;
    delete mmu;
    delete debugger;
}

