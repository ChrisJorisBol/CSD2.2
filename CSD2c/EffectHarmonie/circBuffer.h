#pragma once
#include "zeroCrossing.h"
#include <iostream>
#include "lpf.h"
typedef unsigned int uint;

class CircBuffer : public ZeroCrossing, LowPF{
public:
	/*
	 * size: the number of samples in the buffer
	 */

	CircBuffer();
	CircBuffer(uint size);
	~CircBuffer();

	void resetSize(uint size);
	// setter and getter for the distance between read and write head
	void setDistanceRW(uint distanceRW);
  uint getDistanceRW();
	void setDistanceExtraRW(uint distanceExtraRW);
	uint getDistanceExtraRW();
	// float readExtra(float sample);
	// write and read values at write / read head
	inline void write(float val)
	{
		m_buffer[m_writeH] = val;
	}
	inline float read()
	{
		sample = m_buffer[m_readH];
		sample = decimalFilter(sample);
		// std::cout<<sample<<std::endl;
		bool zeroC = findZeroC(sample);
		// if(zeroC == true)
		// {
		// 	std::cout<<"ZeroCrossing found";
		// }
		return sample;
	}

  // method to set a step in time --> move to next sample
  inline void tick() {
    incrWriteH();
		incrReadH();
  }
	inline void tickExtraRH(){
		incrExtraReadH();
	}

	// debug methods
	void logRWPos();
  void logDistanceRW();
  void logSize();
  void logAllSettings();
	void logAllValues();

private:
  // increase write and read heads with 1 or more samples and wrap if necessary
	inline void incrWriteH() {
		m_writeH++;
		wrapH(m_writeH);
	}

	inline void incrReadH() {
		m_readH++;
		wrapH(m_readH);
	}

	inline void incrExtraReadH()
	{
		m_readH++;
		wrapH(m_extraReadH);
	}

  // wrap a head if necessary
  inline void wrapH(uint& head) {
    if (head >= m_size) head -= m_size;
  }

  // allocate and release methods --> are needed when altering the buffer size
  void allocateBuffer();
  void releaseBuffer();
	float* m_buffer;
	uint m_size;
	float sample;
	// read and write heads, delay size
	uint m_readH;
	uint m_writeH;
	uint m_extraReadH;
	uint m_distanceRW;
	uint m_distanceExtraRW;
};
