#include "square.h"
#include "math.h"

Square::Square(float frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  // return phasedelta = frequency/samplerate;
  std::cout << "Square - constructor\n";
}

Square::~Square()
{
  std::cout << "Square - destructor\n";
}


void Square::tick(double phasedelta) {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += phasedelta;
  for(unsigned int i = 0; i<19; i++)
  {
    int x = (i*2)+1;
    // std::cout<< i ;
    sample += sin(M_PI * 2 * phase * x)/x;
  }
  // sampl  e = sin(M_PI * 2 * phase) + sin(M_PI * 2 * phase *3)/3 + sin(M_PI * 2 * phase*5)/5 + sin(M_PI * 2 * phase*7)/7 + sin(M_PI * 2 * phase*9)/9 + sin(M_PI * 2 * phase*11)/11 + sin(M_PI * 2 * phase*13)/13;
  if (phase>1.0)
  {
    phase -= 1.0;
  }
}
