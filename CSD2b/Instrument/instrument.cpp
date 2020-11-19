#include <iostream>
#include <string>
#include "instrument.h"

using namespace std;

Instrumentc::Instrumentc(string sound)
{
  this->sound = sound;
  std::cout << "\nConstructor\n";
}

Instrumentc::~Instrumentc()
{
  std::cout << "\nDestructor\n";
}


void Instrumentc::play()
{
  std::cout<<"\n"<<sound<<"\n";
}
