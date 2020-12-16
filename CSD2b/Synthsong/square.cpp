#include "square.h"
#include "math.h"

Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  // return phasedelta = frequency/samplerate;
  std::cout << "Square - constructor\n";
}

Square::~Square()
{
  std::cout << "Square - destructor\n";
}


void Square::calc() {
  double y =0;
  for(unsigned int i = 0; i<150; i++)
  {
    int x = (i*2)+1;
    y += (sin(M_PI * 2 * phase * x)/x);
  }
  sample = y;
  // std::cout <<sample;
   // sample = sin(M_PI * 2 * phase) + sin(M_PI * 2 * phase *3)/3 + sin(M_PI * 2 * phase*5)/5 + sin(M_PI * 2 * phase*7)/7 + sin(M_PI * 2 * phase*9)/9 + sin(M_PI * 2 * phase*11)/11 + sin(M_PI * 2 * phase*13)/13;
}
