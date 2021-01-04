#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "oscillator.h"
#include <string>
class Synth
{
public:
  Synth();
  ~Synth();

  void noteOn();
  void noteOff();
  void addVoice(int voiceNumber);
  // void removeVoice(int oscNumber);
  void assignVoice(std::string oscType, int voiceNumber);
  void voiceHelp();
private:
  int voices;
  int voiceNumber;
  int oscNumber;
  std::string oscType;
  bool output;

};

#endif
