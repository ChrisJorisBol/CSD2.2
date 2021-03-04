#include "lpf.h"
#include <math.h>
LowPF::LowPF()
{
  //Constructor - LPF
}

LowPF::~LowPF()
{
  //Destructor - LowPF
}


float LowPF::calcNewSample(float sample)
{
  //to do, make this a better filter that uses fft maybe;
  //Samplesave, saves the sample, to add to the next sample
  //This should be a very barebones, lowpass filter
  static float sampleSave = 0;
  float sampleReturn = sample + sampleSave;
  sampleSave = sample;
  return sampleReturn;
}

float LowPF::decimalFilter(float sample)
{
  //This filters out static to find zerocrossing easier
  float roundSample = round(sample*100)/100;
  // return calcNewSample(roundSample);
  return roundSample;
}
