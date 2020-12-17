#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include <iostream>
#include "oscillator.h"
class Triangle : public Oscillator
{
public:
  //Constructor and destructor
  Triangle(double frequency, double samplerate);
  ~Triangle();
  // go to next sample
  void calc();
  // double getPhasedelta(float frequency, double samplerate);
  //NOTE - do we need a setter for phase? for now -> not using one

};

#endif
