#ifndef SQUARE_HH
#define SQUARE_HH

#include <stdint.h>

#include "device.hh"

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
