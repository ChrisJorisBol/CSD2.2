#pragma once


#include <iostream>

class LowPF{
public:
  LowPF();
  ~LowPF();
  float calcNewSample(float sample);
  float decimalFilter(float sample);
private:
  float sample;

};
