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


void Melodygen::generate(int amount)
{
  float melody[amount];
  for(int i = 0; i<amount; i++)
  {
    int y = (rand() % 11) + 70;
    melody[i]= y;
    std::cout<<"before conversion melody[i] = "<<melody[i]<<"\n";
    mtoF(melody[i]);
    melody[i]=mtoF(melody[i]);
    std::cout<<"after conversion melody[i] = "<<melody[i]<<"\n";
  }

}


float Melodygen::mtoF(int midiNote)
{
  float n = midiNote - 69;
  float inbetween = n/12;
  // std::cout<<"this is the power of 2^(n/12) = "<<inbetween<<"\n";
  double freqFromMidi = pow(2, inbetween)*440;
  return freqFromMidi;
  // std::cout<<"the frequency of midi note - "<< midiNote<< " equals = "<<freqFromMidi<<"\n";
}
