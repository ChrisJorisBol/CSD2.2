#include "zeroCrossing.h"
#include <iostream>
#include <cstring>
#include <math.h>


ZeroCrossing::ZeroCrossing()
{
  std::cout<<"Constructor - ZeroCrossing";
}

ZeroCrossing::~ZeroCrossing()
{
  std::cout<<"Destructor - ZeroCrossing";
}

bool ZeroCrossing::findZeroC(float sample)
{
  //negpos is the value determining wheter the sample is positive or negative
  //We use this to see if the sample goes from negative to positive
  //or vice versa, this allows us to find a zerocrossing
  // bool negPos = true;
  // bool zeroC = false;
  bool negPos;
  std::cout<<sample<<std::endl;
  // float sampletest=ceil(sample);
  // std::cout<<sampletest<<std::endl;
  float newSample = sample+1;
  if(sample>=0.99&&sample<=1.01)
  {
    // bool zeroC=true;
    // return zeroC;
    std::cout<<"MILGUH";
  }
}
