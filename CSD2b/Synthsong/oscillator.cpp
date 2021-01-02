#include "oscillator.h"
#include "math.h"
#include <chrono>
#include <thread>
#include <future>
Oscillator::Oscillator(double frequency, double samplerate) : frequency(frequency),
  samplerate(samplerate), amplitude(0.5), sample(0), phase(0), phasedelta(0)
{
  std::cout << "Oscillator - constructor\n";
}

Oscillator::~Oscillator() {
  std::cout << "Oscillator - destructor\n";
}

float Oscillator::getSample() {
  return sample;
}

double Oscillator::getPhasedelta(double frequency, double samplerate){
  this->phasedelta  = frequency/samplerate;
  return phasedelta;
}

//getters and setters
double Oscillator::setFrequency(double frequency)
{
  this->frequency = frequency;
  phasedelta = getPhasedelta(frequency, samplerate);
}

float Oscillator::getFrequency()
{
  // std::cout<<"frequency = "<<frequency;
  return frequency;
}

void Oscillator::calc()
{
}

void Oscillator::tick() {
  calc();
  phase += phasedelta;
  if (phase>1.0)
  {
    phase -= 1.0;
  }
}

void Oscillator::foo(double mel[])
{
  for(int x = 0; x<40; x++)
  {
    double frequency = mel[x];
    setFrequency(frequency);
    std::cout<<"frequency = "<<frequency<<"\n";
    //sleep as a timing mechanism.
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

  }
}
