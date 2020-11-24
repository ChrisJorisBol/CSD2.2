#ifndef _BLAZERS_H_
#define _BLAZERS_H_
#include "instrument_inheritance.h"


class Blazers : public Instrument
{
public:
  Blazers(std::string sound, int pitchRange);
  ~Blazers();
  void dempen();
};

#endif
