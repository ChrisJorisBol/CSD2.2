#include "strijkers.h"



Strijkers::Strijkers(std::string sound, int pitchRange) : Instrument(sound, pitchRange)
{
  // hulpmiddel om constructors gemaakt te zien worden
  // std::cout<<"Strijkers  - Constructor || (Sound, pitchRange) ("
  //   << sound <<", "<< pitchRange << ")\n";
}


Strijkers::~Strijkers()
{
  // hulpmiddel om deqstructors gemaakt te zien worden
  // std::cout<<"Strijkers  - Destructor\n";
}


void Strijkers::pluck()
{
  std::cout<<"Het geluid van de strijker veranderd naar staccato.\n";
  this->sound = "PLCK";
}
