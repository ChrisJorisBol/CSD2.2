# all: instrument_inheritance
#
# main.o : main.cpp instrument_inheritance.h
# 	g++ -c main.cpp
#
# blazers.o : blazers.cpp instrument_inheritance.h
# 	g++ -c blazers.cpp
# instrument_inheritance.o : instrument_inheritance.cpp instrument_inheritance.h
# 	g++ -c instrument_inheritance.cpp
#
# instrument_inheritance : main.o instrument_inheritance.o blazers.o
# 	g++ -o instrument_inheritance main.o instrument_inheritance.o
#
#
# clean:
# 	rm -f *.o instrument_inheritance


CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE= instrument_inheritance.o blazers.o strijkers.o main.o

example: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f example *.o
