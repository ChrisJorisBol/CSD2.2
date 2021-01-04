#include "melodygen.h"
#include <cstdlib>
#include "math.h"

Melodygen::Melodygen()
{
  // std::cout<<"Melodygen - Constructor\n";
}


Melodygen::~Melodygen()
{
  // std::cout<<"Melodygen - Destructor\n";
}


double* Melodygen::generate(int amount)
{
  double* melody = new double[amount];
  for(int i = 0; i<amount; i++)
  {
    int y = (rand() % 7);
    double toonladder[8] = {0,2,3,5,7,8,10,12};
    y = toonladder[y];
    y+=60;
    melody[i]= y;
    mtoF(melody[i]);
    melody[i]=mtoF(melody[i]);
  }
  return melody;
}


float Melodygen::mtoF(int midiNote)
{
  float n = midiNote - 69;
  // float inbetween = n/12;
  // std::cout<<"this is the power of 2^(n/12) = "<<inbetween<<"\n";
  double freqFromMidi = pow(2, (n/12))*440;
  return freqFromMidi;
  // std::cout<<"the frequency of midi note - "<< midiNote<< " equals = "<<freqFromMidi<<"\n";
}
