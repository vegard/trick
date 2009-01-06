#ifndef DEVICE_HH
#define DEVICE_HH

#include <stdint.h>

class device {
public:
	device(unsigned int parameters, const char* parameter_names[],
		unsigned int inputs, const char* input_names[],
		unsigned int outputs, const char* output_names[]);
	virtual ~device();

public:
	/* XXX: Make input const */
	virtual void process(unsigned int n, int16_t* inputs[], int16_t* outputs[]) = 0;

	bool get_parameter(const char* name, unsigned int& num);
	void set_parameter_value(unsigned int p, int v);

protected:
	unsigned int	_parameters;
	const char**	_parameter_names;
	int*		_parameter_values;

	unsigned int	_inputs;
	const char**	_input_names;

	unsigned int	_outputs;
	const char**	_output_names;
};

#endif
