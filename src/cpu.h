#include <stdint.h>
#include <string>
#include <fstream>

using namespace std;

#ifndef CPU_H
#define CPU_H

class CPU {
	uint8_t  A, 
			 X, 
			 Y, 
			 SP = 0x0100, 
			 P; // N V 1 B D I Z C

	/* P Processor status flag register:
	 * N - Negative flag
	 * V - oVerflow flag
	 * 1 - unused flag, always 1
	 * B - Break flag
	 * D - Decimal mode flag
	 * I - Interrupt disable flag
	 * Z - Zero flag
	 * C - Carry flag */

	uint16_t PC = 0xFCE2; 

	/* KERNAL routine, stored at 0xFFFC - 0xFFFD
	 * Later it may be a better idea to read this 
	 * address from there. */
	
	public:

	/* By default, the 1 kB of screen RAM resides 
	in memory at 1024-2023 ($0400-$07E7). */

	CPU();

};

#endif