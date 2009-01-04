.PHONY: all
all: trick

.PHONY: clean
clean:
	rm -rf trick

trick: main.cc synth/*.cc
	g++ -Wall -W -Werror -o $@ $^
