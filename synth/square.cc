#include <cstdio>

#include <stdint.h>

#include "square.hh"

enum {
	PARAMETER_PERIOD,
	PARAMETER_VOLUME,
};

/* Argh, where did C99-style initializers go for C++? */
static const char* parameter_names[] = {
	"period",
	"volume",
};

enum {
	OUTPUT_MONO,
};

static const char* output_names[] = {
	"mono",
};

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

square::square():
	instrument(ARRAY_SIZE(parameter_names), parameter_names,
		0, NULL,
		ARRAY_SIZE(output_names), output_names),
	amplitude(0),
	offset(0)
{
}

square::~square()
{
}

void
square::process(unsigned int n, int16_t* inputs[], int16_t* outputs[])
{
	int period = _parameter_values[PARAMETER_PERIOD];
	int volume = _parameter_values[PARAMETER_VOLUME];

	/* Create local copies of state variables */
	int amplitude = this->amplitude;
	int offset = this->offset;

	int16_t* buf = outputs[OUTPUT_MONO];
	for (unsigned int i = 0; i < n; ++i) {
		buf[i] = amplitude;

		offset += 64;
		if (offset > period) {
			if (amplitude < 0)
				amplitude = volume;
			else
				amplitude = -volume;

			offset -= period;
		}
	}

	/* Restore state variables */
	this->amplitude = amplitude;
	this->offset = offset;
}
