#include "melodygen.h"
#include <cstdlib>
#include "math.h"

Melodygen::Melodygen()
{
  std::cout<<"Melodygen - Constructor\n";
}


Melodygen::~Melodygen()
{
  std::cout<<"Melodygen - Destructor\n";
}


float* Melodygen::generate(int amount)
{
  float* melody = new float[amount];
  for(int i = 0; i<amount; i++)
  {
    int y = (rand() % 11) + 70;
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
