#include <cstdio>
#include <cmath>

#include "synth/square.hh"

int main()
{
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
	s->process(8192, NULL, outputs);

	FILE* f = fopen("output.raw", "w");
	fwrite(buf, sizeof(*buf), 8192, f);
	fclose(f);

	delete s;

	return 0;
}

