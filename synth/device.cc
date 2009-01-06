#include <cassert>
#include <cstdio>
#include <cstring>

#include <stdint.h>

#include "device.hh"

device::device(unsigned int parameters, const char* parameter_names[],
	unsigned int inputs, const char* input_names[],
	unsigned int outputs, const char* output_names[]):
	_parameter_names(parameter_names),
	_input_names(input_names),
	_output_names(output_names)
{
	_parameters = parameters;
	_parameter_values = new int[_parameters];

	_inputs = inputs;
	_outputs = outputs;
}

device::~device()
{
	delete[] _parameter_values;
}

bool
device::get_parameter(const char* name, unsigned int& num)
{
	for (unsigned int i = 0; i < _parameters; ++i) {
		if (!strcmp(_parameter_names[i], name)) {
			num = i;
			return true;
		}
	}

	return false;
}

void
device::set_parameter_value(unsigned int p, int v)
{
	assert(p < _parameters);

	fprintf(stderr, "[DEBUG] p[%u/%s] = %d\n", p, _parameter_names[p], v);

	_parameter_values[p] = v;
}
