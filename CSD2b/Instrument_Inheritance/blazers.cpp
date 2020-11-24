#include "blazers.h"



Blazers::Blazers(std::string sound, int pitchRange) : Instrument(sound, pitchRange)
{
  std::cout<<"Blazers :: Constructor = "
    << sound <<" "<< pitchRange << "\n";
}


Blazers::~Blazers()
{
  std::cout<<"Blazers :: Destructor\n";
}


void Blazers::dempen()
{
  std::cout<<"Het geluid van de blazers word nu gedempt. \n";
  this->sound = "mmp";
}
