#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator(double frequency, double samplerate) : frequency(frequency),
  samplerate(samplerate), amplitude(0.5), sample(0), phase(0), phasedelta(0)
{
  // return phasedelta = frequency/samplerate;
  std::cout << "Oscillator - constructor\n";
}

Oscillator::~Oscillator() {
  std::cout << "Oscillator - destructor\n";

}

float Oscillator::getSample() {
  return sample;
}

double Oscillator::getPhasedelta(double frequency, double samplerate){
  return phasedelta = frequency/samplerate;
}

//getters and setters
void Oscillator::setFrequency(double frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}



void Oscillator::tick(double phasedelta) {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += phasedelta;
  if (phase>1.0)
  {
    phase -= 1.0;
  }
}
