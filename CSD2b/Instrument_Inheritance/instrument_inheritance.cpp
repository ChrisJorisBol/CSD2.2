#include <iostream>

#include "instrument_inheritance.h"



Instrument::Instrument(std::string sound, int pitchRange)
{
  this->sound = sound;
  std::cout << "Instrument :: Constructor\n";
}

Instrument::~Instrument()
{
  std::cout << "Instrument :: Destructor\n";
}


void Instrument::play()
{
  std::cout<<"Playing "<<sound<<"\n";
}
