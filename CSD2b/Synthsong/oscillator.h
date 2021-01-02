#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator
{
public:
  //Constructor and destructor
  Oscillator(double frequency, double samplerate);
  ~Oscillator();

  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  double setFrequency(double frequency);
  float getFrequency();
  double getPhasedelta(double frequency, double samplerate);
  void foo(double mel[]);
  virtual void calc();
  //NOTE - do we need a setter for phase? for now -> not using one

protected:
  float amplitude;
  double frequency;
  double phase;
  // contains the current sample
  float sample;
  double samplerate;
  double phasedelta;
  // float mel[];
};

#endif
