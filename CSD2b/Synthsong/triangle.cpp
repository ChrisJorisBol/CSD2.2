#include "triangle.h"
#include "math.h"

Triangle::Triangle(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  // return phasedelta = frequency/samplerate;
  // std::cout << "Triangle - constructor\n";
}

Triangle::~Triangle()
{
  // std::cout << "Triangle - destructor\n";
}


void Triangle::calc() {
  double y =0;
  int invert = 1;
  for(unsigned int i = 0; i<50; i++)
  {
    int n = (i*2)+1;
    //Bij een triangle waveform
    //moet elke andere harmonische geinverteerd worden in phase
    //vandaar invert = -1;
    if(i % 2 == 1){
      invert = -1;
    }
    y += sin(M_PI * 2 * phase * n*invert)*(1.0/(n*n));
    invert = 1;

  }
  sample = y;
}
