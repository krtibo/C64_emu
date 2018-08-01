#include "mmu.h"

void MMU::write(uint16_t addr, uint8_t value) {
	this->RAM[addr] = value;
}

uint8_t MMU::read(uint16_t addr) {
	return this->RAM[addr];
}

void MMU::read_from_file(char* path, uint16_t address) {
	ifstream infile(path);
	char buffer[8192];

	// get length of file
	infile.seekg(0, infile.end);
	size_t length = infile.tellg();
	infile.seekg(0, infile.beg);

	// don't overflow the buffer
	if (length > sizeof (buffer))
	    length = sizeof (buffer);

	// read file
	infile.read(buffer, length);

	// copy to specified address
	for(unsigned int i=0; i<length; ++i) 
		this->write(address + i, (uint8_t)buffer[i]);

}