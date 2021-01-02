CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z -pthread
LDFLAGS= -ljack -pthread

all: Synthesizer

Synthesizer : jack_module.o main.o synth.o oscillator.o sine.o square.o	saw.o triangle.o melodygen.o writeToFile.o
	$(CC) -o $@ $(CFLAGS) jack_module.o main.o synth.o oscillator.o sine.o square.o saw.o triangle.o melodygen.o writeToFile.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
