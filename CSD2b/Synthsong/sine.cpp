#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  // return phasedelta = frequency/samplerate;
  std::cout << "Sine - constructor\n";
}

Sine::~Sine()
{
  std::cout << "Sine - destructor\n";
}


void Sine::tick(double phasedelta) {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += phasedelta;
  sample = sin(M_PI * 2 * phase);
  if (phase>1.0)
  {
    phase -= 1.0;
  }
}
