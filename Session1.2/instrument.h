#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <string>
#include <iostream>



using namespace std;


class Instrumentc
{
public:
  Instrumentc(string sound);
  ~Instrumentc();
  void play();
private:
  string sound;
};


#endif
