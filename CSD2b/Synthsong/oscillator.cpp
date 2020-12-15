#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator(float frequency, double samplerate) : frequency(frequency),
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

double Oscillator::getPhasedelta(float frequency, double samplerate){
  return phasedelta = frequency/samplerate;
}

//getters and setters
void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}
