#ifndef TRICK_SYNTH_FILE_WRITER_HH
#define TRICK_SYNTH_FILE_WRITER_HH

#include <cstdio>

#include <stdint.h>

#include "synth/device.hh"

class file_writer: public device {
public:
	explicit file_writer(const char* filename);
	~file_writer();

public:
	void process(unsigned int n, int16_t* inputs[], int16_t* outputs[]);

private:
	FILE* fp;
};

#endif
