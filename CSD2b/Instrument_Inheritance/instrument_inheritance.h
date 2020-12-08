#ifndef _INSTRUMENT_INHERITANCE_H_
#define _INSTRUMENT_INHERITANCE_H_


class Instrument
{
public:
  Instrument(std::string sound, int pitchRange);
  ~Instrument();
  void play();
  void midi();

protected:
  std::string sound;
  int pitchRange;

};

#endif
