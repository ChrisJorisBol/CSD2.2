#include "synth.h"


Synth::Synth()
{
  std::cout<<"Synth - Constructor\n";
}

Synth::~Synth()
{
  std::cout<<"Synth - Destructor\n";
}

void Synth::noteOn()
{
  output = true;
  // return output;
}

void Synth::noteOff()
{
  output = false;
  // return output;
}
//
// void Synth::addVoice(int voiceNumber)
// {
//   std::cin>> voiceNumber;
//
// }
//
// void Synth::removeVoice(int voiceNumber)

void Synth::assignVoice(std::string oscType, int voiceNumber)
{

}

void voiceHelp()
{
  std::cout<<"vul hier hulptekst in\n";
}
