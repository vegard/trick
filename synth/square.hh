#ifndef TRICK_SYNTH_SQUARE_HH
#define TRICK_SYNTH_SQUARE_HH

#include <stdint.h>

#include "synth/device.hh"

class square: public device {
public:
	square();
	~square();

public:
	void process(unsigned int n, int16_t* inputs[], int16_t* outputs[]);

private:
	int amplitude;
	int offset;
};

#endif
