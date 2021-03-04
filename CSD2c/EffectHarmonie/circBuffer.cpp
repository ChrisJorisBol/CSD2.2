#include "circBuffer.h"
#include <iostream>
#include <cstring>

CircBuffer::CircBuffer() : CircBuffer(0) {}

CircBuffer::CircBuffer(uint size) : m_size(size), m_readH(0), m_writeH(0)
{
	allocateBuffer();
}


CircBuffer::~CircBuffer()
{
	releaseBuffer();
}

void CircBuffer::resetSize(uint size)
{
	m_size = size;
	releaseBuffer();
	allocateBuffer();
}

void CircBuffer::allocateBuffer()
{
	// allocate buffer and set all samples to 0
	m_buffer = (float*)malloc(m_size * sizeof(float));
	memset(m_buffer, 0, m_size * sizeof(float));
}

void CircBuffer::releaseBuffer()
{
  // free data allocated with memset
  free(m_buffer);
}

void CircBuffer::setDistanceRW(uint distanceRW)
{
  // store new distance between R & W heads and update rhead position
	m_distanceRW = distanceRW;
  m_readH = m_writeH - m_distanceRW + m_size;
  wrapH(m_readH);
}

uint CircBuffer::getDistanceRW()
{
  return m_distanceRW;
}

void CircBuffer::setDistanceExtraRW(uint distanceExtraRW)
{
	m_distanceExtraRW = distanceExtraRW;
	m_extraReadH = m_writeH - m_distanceExtraRW + m_size;
	wrapExtraH(m_extraReadH);
}

uint CircBuffer::getDistanceExtraRW()
{
	return m_distanceExtraRW;
}

void CircBuffer::setEnvelopeValue(uint value)
{
	envelopeValue = value;
}

float CircBuffer::getEnvelopeValue()
{
	// static int values[]={0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
	return envelopeValue;
}

uint CircBuffer::calcDistance(uint readhead)
{
	//calculate the distance to see if we need extra wrapping
	//as to not go past the writehead.

	int distance;
	distance = m_writeH-readhead;

	if(distance<=170)
	{

	}
	if(distance<0)
	{
		distance = (readhead-m_size) * -1 + m_writeH;
	}
	std::cout<<"distance  = "<<distance<<std::endl;
	//a thousand samples in the buffer is actually only 250 different samples
	//that get read at normal speed
	if(distance < 1280 && wrapExtraRH == 1)
	{
		readhead-=320;
	}
	// if(distance>=190)
	// {
	// 	setEnvelopeValue(calcEnvelopeValue/10);
	// }
	if(distance < 1280 && wrapExtraRH == 0)
	{
		int y = 320-readhead;
		readhead = m_size-y;
	}
	return readhead;
}




void CircBuffer::logRWPos()
{
	std::cout << "\n______________________ CircBuffer ______________________________\n";
	std::cout << "Read head position: " << m_readH << "\n";
	std::cout << "Write head position: " << m_writeH << "\n";
	std::cout << "_________________________________________________________________\n";
}

void CircBuffer::logDistanceRW()
{
	std::cout << "\n______________________ CircBuffer ______________________________\n";
	std::cout << "Distance between read and write head: " << m_distanceRW << "\n";
	std::cout << "_________________________________________________________________\n";
}


void CircBuffer::logSize()
{
	std::cout << "\n______________________ CircBuffer ______________________________\n";
	std::cout << "Buffer size: " << m_size << "\n";
	std::cout << "_________________________________________________________________\n";
}

void CircBuffer::logAllSettings()
{
	std::cout << "\n______________________ CircBuffer ______________________________\n";
	std::cout << "Read head position: " << m_readH << "\n";
	std::cout << "Write head position: " << m_writeH << "\n";
  std::cout << "Distance between read and write head: " << m_distanceRW << "\n";
  std::cout << "Buffer size: " << m_size << "\n";
	std::cout << "_________________________________________________________________\n";
}


void CircBuffer::logAllValues()
{
	std::cout << "\n______________________ CircBuffer ______________________________\n";
	std::cout << "CircBuffer - buffer contains: \n";
	for (int i = 0; i < m_size - 1; i++)
	{
		std::cout << m_buffer[i] << ", ";
	}
	std::cout << m_buffer[m_size - 1] << "\n";
	std::cout << "_________________________________________________________________\n";
}
