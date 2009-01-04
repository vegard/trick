#ifndef SQUARE_HH
#define SQUARE_HH

#include <stdint.h>

#include "instrument.hh"

class square: public instrument {
public:
	square();
	~square();

public:
	void generate(int16_t buf[], unsigned int n);

private:
	int offset;
};

#endif
