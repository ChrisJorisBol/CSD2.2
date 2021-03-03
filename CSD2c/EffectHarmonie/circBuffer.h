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
	uint calcDistance(uint readhead);
	// float readExtra(float sample);
	// write and read values at write / read head
	inline void write(float val)
	{
		m_buffer[m_writeH] = val;
	}
	inline float read()
	{
		sample = m_buffer[m_readH];
		// sample = decimalFilter(sample);
		// std::cout<<sample<<std::endl;
		// bool zeroC = findZeroC(sample);
		// if(zeroC == true)
		// {
		// 	std::cout<<"ZeroCrossing found";
		// }
		return sample;
	}
	inline float readExtraRH()
	{
		sample = m_buffer[m_extraReadH];
		return sample;
	}
	// inline float readExtraRHO()
	// {
	// 	sample = m_buffer[m_extraReadHO];
	// 	return sample;
	// }
	// inline float readExtraRHOL()
	// {
	// 	sample = m_buffer[m_extraReadHOL];
	// 	return sample;
	// }

  // method to set a step in time --> move to next sample
  inline void tick() {
    incrWriteH();
  }
	inline void tickReadHead()
	{
		incrReadH();
	}
	inline void tickExtraRH(){
		incrExtraReadH();
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
		m_readH++;

		wrapH(m_readH);
	}

	inline void incrExtraReadH()
	{
		//skips 6 samples to aquire a fifth
		//8 for an octave
		//2 for an lower octave
		m_extraReadH++;
		m_extraReadH++;
		m_extraReadH++;
		m_extraReadH++;
		m_extraReadH++;
		m_extraReadH++;
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
		else if(head >= (m_size/4))
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
