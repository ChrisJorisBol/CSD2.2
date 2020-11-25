#include <iostream>

#include "instrument_inheritance.h"



Instrument::Instrument(std::string sound, int pitchRange)
{
  //Zorgt ervoor dat de sounds uniek zijn voor de aangemaakte member van class Instrument
  this->sound = sound;
  // hulpmiddel om constructors gemaakt te zien worden
  // std::cout << "Instrument - Constructor\n";
}

Instrument::~Instrument()
{
  // std::cout << "Instrument - Destructor\n";
}


void Instrument::play()
{
  std::cout<<"PLAYING|| "<<sound<<"\n";
}


void Instrument::midi()
{
  std::cout<<"\n\n"
  << "||MIDI NOTE <> NOTE NAME ||| MIDI NOTE <> NOTE NAME ||| MIDI NOTE <> NOTE NAME ||| \n"
  << "||     59   ==    B3     | |      71   ==    B4     | |      83   ==    B5     | |\n"
  << "||     57   ==    A3     | |      69   ==    A4     | |      81   ==    A5     | |\n"
  << "||     55   ==    G3     | |      67   ==    G4     | |      79   ==    G5     | |\n"
  << "||     53   ==    F3     | |      65   ==    F4     | |      77   ==    F5     | |\n"
  << "||     52   ==    E3     | |      64   ==    E4     | |      76   ==    E5     | |\n"
  << "||     50   ==    D3     | |      62   ==    D4     | |      74   ==    D5     | |\n"
  << "||     48   ==    C3     | |      60   ==    C4     | |      72   ==    C5     | |\n";

}
