#include <cstdio>

#include <stdint.h>

#include "square.hh"

enum {
	PARAMETER_PERIOD,
	PARAMETER_VELOCITY,
};

/* Argh, where did C99-style initializers go for C++? */
static const char* parameter_names[] = {
	"period",
	"velocity",
};

square::square():
	instrument(sizeof(parameter_names) / sizeof(*parameter_names),
		parameter_names)
{
}

square::~square()
{
}

void
square::generate(int16_t buf[], unsigned int n)
{
	/* Create local copies of parameters */
	int period = _parameter_values[PARAMETER_PERIOD];
	int velocity = _parameter_values[PARAMETER_VELOCITY];
	int offset = this->offset;

	for (unsigned int i = 0; i < n; ++i) {
		buf[i] = velocity;

		offset += 64;
		if (offset > period) {
			velocity = -velocity;
			offset -= period;
		}
	}

	/* Restore parameters */
	_parameter_values[PARAMETER_VELOCITY] = velocity;
	this->offset = offset;
}
