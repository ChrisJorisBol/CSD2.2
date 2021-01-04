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
  void setFrequency(double frequency);
  float getFrequency();
  void setAmplitude(float amplitude, bool option);
  float getAmplitude();
  double getPhasedelta(double frequency, double samplerate);
  //this is a bit of a weird function as of now
  void timer(double mel[], int timing, int len);
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
  int timing;
  int len;
  bool option;
  // float mel[];
};

#endif
