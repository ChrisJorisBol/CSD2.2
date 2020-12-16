#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"
class Saw : public Oscillator
{
public:
  //Constructor and destructor
  Saw(double frequency, double samplerate);
  ~Saw();
  // go to next sample
  void calc();
  // double getPhasedelta(float frequency, double samplerate);
  //NOTE - do we need a setter for phase? for now -> not using one

};

#endif
