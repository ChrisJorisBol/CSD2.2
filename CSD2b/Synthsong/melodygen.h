#ifndef _MELODYGEN_H_
#define _MELODYGEN_H_
#include <iostream>


class Melodygen
{
public:
  Melodygen();
  ~Melodygen();
  double* generate(int amount);
  float mtoF(int midiNote);
private:
  int amount;
  int midiNote;
};

#endif
