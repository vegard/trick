#include <cstdio>
#include <cmath>

#include "synth/file-writer.hh"
#include "synth/square.hh"

int main()
{
	file_writer* fw = new file_writer("output.raw");
	square* s = new square();

	unsigned int p_period;
	s->get_parameter("period", p_period);
	s->set_parameter_value(p_period,
		64 * 48000. / 13.75 / pow(2, 60. / 12));

	unsigned int p_volume;
	s->get_parameter("volume", p_volume);
	s->set_parameter_value(p_volume, 2048);

	int16_t buf[8192];
	int16_t* outputs[1] = {buf};
	int16_t* inputs[1] = {buf};
	s->process(8192, NULL, outputs);
	fw->process(8192, inputs, NULL);

	delete s;
	delete fw;

	return 0;
}

