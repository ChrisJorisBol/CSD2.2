#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"
class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine(double frequency, double samplerate);
  ~Sine();
  // go to next sample
  void calc();
  // double getPhasedelta(float frequency, double samplerate);
  //NOTE - do we need a setter for phase? for now -> not using one

};

#endif
