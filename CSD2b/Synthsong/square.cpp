#include "square.h"
#include "math.h"

Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  // std::cout << "Square - constructor\n";

}

Square::~Square()
{
  // std::cout << "Square - destructor\n";
}


void Square::calc() {
  double y =0;
  for(unsigned int i = 0; i<50; i++)
  {
    //Alleen oneven harmonischen
    int n = (i*2)+1;
    //Iteratief de samples per harmonic bij elkaar optellen
    y += (sin(M_PI * 2 * phase * n)/n);
  }
  sample = y;

}
