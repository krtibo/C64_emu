#include <iostream>
#include "cpu.h"
#include "mmu.h"
#include "debugger.h"
using namespace std;

int main( int argc, char** argv ){
    CPU * cpu = new CPU();
    MMU * mmu = new MMU();
    Debugger * debugger = new Debugger();

    // Read KERNAL ROM to its specific location in RAM.
    mmu->read_from_file("/rom/kernal.rom", 0xE000);

    debugger->init();
    debugger->run();

    delete cpu;
    delete mmu;
    delete debugger;
}