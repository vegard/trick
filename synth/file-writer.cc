#include <cstdio>

#include <stdint.h>

#include "array.hh"
#include "synth/file-writer.hh"

enum {
	INPUT_MONO,
};

static const char* input_names[] = {
	"mono",
};

file_writer::file_writer(const char* filename):
	device(0, NULL,
		ARRAY_SIZE(input_names), input_names,
		0, NULL)
{
	/* XXX: Error handling */
	fp = fopen(filename, "w");
}

file_writer::~file_writer()
{
	fclose(fp);
}

void
file_writer::process(unsigned int n, int16_t* inputs[], int16_t* outputs[])
{
	/* XXX: Error handling */
	fwrite(inputs[INPUT_MONO], sizeof(int16_t), n, fp);
}
