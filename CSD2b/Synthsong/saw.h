#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"
class Saw : public Oscillator
{
public:
  //Constructor and destructor
  Saw(float frequency, double samplerate);
  ~Saw();
  // go to next sample
  void tick(double phasedelta);
  // double getPhasedelta(float frequency, double samplerate);
  //NOTE - do we need a setter for phase? for now -> not using one

};

#endif
