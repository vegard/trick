#ifndef INSTRUMENT_HH
#define INSTRUMENT_HH

#include <stdint.h>

class instrument {
public:
	instrument(unsigned int n, const char* parameter_names[]);
	virtual ~instrument();

public:
	virtual void generate(int16_t buf[], unsigned int n) = 0;

	bool get_parameter(const char* name, unsigned int& num);
	void set_parameter_value(unsigned int p, int v);

protected:
	unsigned int	_parameters;
	const char**	_parameter_names;
	int*		_parameter_values;
};

#endif
