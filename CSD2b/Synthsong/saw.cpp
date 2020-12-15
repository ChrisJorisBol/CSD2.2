#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  // return phasedelta = frequency/samplerate;
  std::cout << "Saw - constructor\n";
}

Saw::~Saw()
{
  std::cout << "Saw - destructor\n";
}


void Saw::tick(double phasedelta) {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += phasedelta;
  for(unsigned int i = 1; i<80; i++)
  {
    sample += (sin(M_PI * 2 * phase * i))/i;
  }
  // sample = sin(M_PI * 2 * phase);
  if (phase>1.0)
  {
    phase -= 1.0;
  }
}
