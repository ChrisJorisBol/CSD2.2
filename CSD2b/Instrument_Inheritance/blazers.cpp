#include "blazers.h"



Blazers::Blazers(std::string sound, int pitchRange) : Instrument(sound, pitchRange)
{
  // hulpmiddel om constructors gemaakt te zien worden
  // std::cout<<"Blazers    - Constructor || (Sound, pitchRange) ("
    // << sound <<", "<< pitchRange << ")\n";
}


Blazers::~Blazers()
{
  // hulpmiddel om destructors gemaakt te zien worden
  // std::cout<<"Blazers    - Destructor\n";
}


void Blazers::dempen()
{
  std::cout<<"Het geluid van de blazers word nu gedempt. \n";
  this->sound = "mmp";
}
