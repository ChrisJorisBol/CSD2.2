#include "sine.h"
#include "math.h"

Sine::Sine(float frequency) {
  // initialize members
  this->frequency = frequency;
  amplitude = 0.5;
  sample = 0;
  phase = 0;
  std::cout << "Sine - constructor\n";
}



Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}


float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // TODO - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / SAMPLERATE;
  // sample = sin(M_PI * 2 * phase)+ sin(M_PI * 3 * phase) + sin(M_PI * 5 * phase) + sin(M_PI * 7 * phase) + sin(M_PI * 9 * phase) + sin(M_PI * 11 * phase) + sin(M_PI * 13 * phase) + sin(M_PI * 15 * phase) + sin(M_PI * 17 * phase)+ sin(M_PI * 19 * phase);
  sample = sin(M_PI *2*phase);
  // sample = sin(M_PI * 2 * phase)+ sin(M_PI* 2 * 3 * phase)/3 + sin(M_PI* 2 * 5 * phase)/5 + sin(M_PI* 2 * 7 * phase)/7 + sin(M_PI* 2 * 9 * phase)/9 + sin(M_PI* 2 * 11 * phase)/11 + sin(M_PI* 2 * 13 * phase)/13 + sin(M_PI* 2 * 15 * phase)/15;
    // sample += sin(M_PI * 2 * phase+3)+ sin(M_PI* 2 * 3 * phase+3)/3 + sin(M_PI* 2 * 5 * phase+3)/5 + sin(M_PI* 2 * 7 * phase+3)/7 + sin(M_PI* 2 * 9 * phase+3)/9 + sin(M_PI* 2 * 11 * phase+3)/11 + sin(M_PI* 2 * 13 * phase+3)/13 + sin(M_PI* 2 * 15 * phase+3)/15;
}
//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
