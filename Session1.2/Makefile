all: instrument

main.o : main.cpp instrument.h
	g++ -c main.cpp

instrument.o : instrument.cpp instrument.h
	g++ -c instrument.cpp

instrument : main.o instrument.o
	g++ -o instrument main.o instrument.o


clean:
	rm -f *.o instrument
