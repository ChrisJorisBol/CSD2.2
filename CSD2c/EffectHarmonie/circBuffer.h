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
	// Calculate the distance for extra wrapping purposes
	uint calcDistance(uint readhead);
	void setEnvelopeValue(uint value);
	float getEnvelopeValue();

	// float readExtra(float sample);
	// write and read values at write / read head
	inline void write(float val)
	{
		m_buffer[m_writeH] = val;
	}
	inline float read()
	{
		sample = m_buffer[m_readH];

		return sample;
	}
	inline float readExtraRH(uint i)
	{
		sample = m_buffer[m_extraReadH];

		// if(count < 10)
		// {
		// 	sample = sample*0.1;
		// }
		// sample = calcNewSample(decimalFilter(sample));
		return sample;
	}

  inline void tick() {
    incrWriteH();
  }
	inline void tickReadHead()
	{
		incrReadH();
	}
	inline void tickExtraRH(uint i){
		incrExtraReadH(i);
	}
	// inline void tickExtraRHO(){
	// 	incrExtraReadHO();
	// }
	// inline void tickExtraRHOL(){
	// 	incrExtraReadHOL();
	// }

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
	//Extra readhead, is used for a different note
	inline void incrExtraReadH(uint i)
	{
		static int tertsArray[] = {1,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1};
		// int fifthArray[] = {1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2};
		int x = (i%16);
		m_extraReadH += tertsArray[x];
		wrapExtraH(m_extraReadH);
		m_extraReadH = calcDistance(m_extraReadH);

	}
	// inline void incrExtraReadHO()
	// {
	// 	//skips 6 samples to aquire a fifth
	// 	//8 for an octave
	// 	//2 for an lower octave
	// 	m_extraReadHO++;
	// 	m_extraReadHO++;
	// 	m_extraReadHO++;
	// 	m_extraReadHO++;
	// 	m_extraReadHO++;
	// 	m_extraReadHO++;
	// 	m_extraReadHO++;
	// 	m_extraReadHO++;
	// 	wrapExtraHO(m_extraReadHO);
	// 	calcDistance(m_extraReadHO);
	// }
	// inline void incrExtraReadHOL()
	// {
	// 	//skips 6 samples to aquire a fifth
	// 	//8 for an octave
	// 	//2 for an lower octave
	// 	m_extraReadHOL++;
	// 	m_extraReadHOL++;
	// 	wrapExtraHOL(m_extraReadHOL);
	// 	calcDistance(m_extraReadHOL);
	// }

  // wrap a head if necessary
  inline void wrapH(uint& head) {
    if (head >= m_size)
		{
			head -= m_size;
		}
	}

	inline void wrapExtraH(uint& head){
		if (head >= m_size)
		{
			head -= m_size;
			wrapExtraRH = 0;
		}
		//As long as the threshold isn't reached at a 4th of the buffer size
		//We assume that we need to place the writehead near the end of the buffer
		//instead of risking placing the readhead before the starting point of the buffer
		else if(head >= 1280)
		{
			wrapExtraRH = 1;
		}
	}

  // allocate and release methods --> are needed when altering the buffer size
  void allocateBuffer();
  void releaseBuffer();
	float* m_buffer;
	int distance;
	uint m_size;
	float sample;
	uint i;
	uint value;
	uint envelopeValue;
	// read and write heads, delay size
	uint m_readH;
	uint readhead;
	uint wrapExtraWH;
	uint wrapExtraRH;
	uint wrapExtraRHO;
	uint wrapExtraRHOL;
	uint m_writeH;
	uint m_extraReadH;
	uint m_extraReadHO;
	uint m_extraReadHOL;
	uint m_distanceRW;
	uint m_distanceExtraRW;
};
