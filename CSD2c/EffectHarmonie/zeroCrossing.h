#pragma once


class ZeroCrossing{
public:

  ZeroCrossing();
  ~ZeroCrossing();

  bool findZeroC(float sample);

private:
  float sample;
  // bool negPos;
};
