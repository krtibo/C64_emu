#include <stdint.h>
#include <fstream>

#ifndef MMU_H
#define MMU_H

using namespace std;

class MMU {
	
	uint8_t RAM[65536];

	public:
	void write(uint16_t addr, uint8_t value);
	uint8_t read(uint16_t addr);
	void read_from_file(char* path, uint16_t address);
};

#endif