#include <cassert>
#include <cstdio>
#include <cstring>

#include <stdint.h>

#include "instrument.hh"

instrument::instrument(unsigned int n, const char* parameter_names[]):
	_parameter_names(parameter_names)
{
	_parameters = n;
	_parameter_values = new int[_parameters];
}

instrument::~instrument()
{
	delete[] _parameter_values;
}

bool
instrument::get_parameter(const char* name, unsigned int& num)
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
instrument::set_parameter_value(unsigned int p, int v)
{
	assert(p < _parameters);

	fprintf(stderr, "[DEBUG] p[%u/%s] = %d\n", p, _parameter_names[p], v);

	_parameter_values[p] = v;
}
