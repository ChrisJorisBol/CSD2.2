#ifndef _STRIJKERS_H_
#define _STRIJKERS_H_
#include "instrument_inheritance.h"


class Strijkers : public Instrument
{
public:
  Strijkers(std::string sound, int pitchRange);
  ~Strijkers();
  void pluck();
// private:
  // std::string timbre;
};


#endif
