#include "sine.h"
#include "math.h"

Sine::Sine(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  // return phasedelta = frequency/samplerate;
  // std::cout << "Sine - constructor\n";
}

Sine::~Sine()
{
  // std::cout << "Sine - destructor\n";
}


void Sine::calc() {
  sample = sin(M_PI * 2 * phase)*sin(M_PI * 4 * phase);
}
