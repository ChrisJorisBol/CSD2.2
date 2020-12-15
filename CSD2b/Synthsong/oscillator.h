#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator
{
public:
  //Constructor and destructor
  Oscillator(float frequency, double samplerate);
  ~Oscillator();

  //return the current sample
  float getSample();
  // go to next sample
  void tick(double phasedelta);

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();
  double getPhasedelta(float frequency, double samplerate);
  //NOTE - do we need a setter for phase? for now -> not using one

protected:
  float amplitude;
  float frequency;
  float phase;
  // contains the current sample
  float sample;
  double samplerate;
  double phasedelta;
};

#endif
