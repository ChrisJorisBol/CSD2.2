#include "strijkers.h"



Strijkers::Strijkers(std::string sound, int pitchRange) : Instrument(sound, pitchRange)
{
  std::cout<<"Strijkers :: Constructor = "
    << sound << " " << pitchRange << "\n";
}


Strijkers::~Strijkers()
{
  std::cout<<"Strijkers :: Destructor\n";
}


void Strijkers::pluck()
{
  std::cout<<"Het geluid van de strijker veranderd naar staccato.\n";
  this->sound = "PLCK";
}
