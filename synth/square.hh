#ifndef SQUARE_HH
#define SQUARE_HH

#include <stdint.h>

#include "instrument.hh"

class square: public instrument {
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
