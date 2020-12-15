#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"
class Square : public Oscillator
{
public:
  //Constructor and destructor
  Square(float frequency, double samplerate);
  ~Square();
  // go to next sample
  void tick(double phasedelta);
  // double getPhasedelta(float frequency, double samplerate);
  //NOTE - do we need a setter for phase? for now -> not using one

};

#endif
