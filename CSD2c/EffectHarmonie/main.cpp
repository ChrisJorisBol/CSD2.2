#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "circBuffer.h"
#include "zeroCrossing.h"
#include "lpf.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

// 10 seconds if samplerate = 44100
#define MAX_DELAY_SIZE 441000

#define PI_2 6.28318530717959

// Run program and set delaytime as argument (in seconds)

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;
  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();

  // transform delay time in seconds to delay time in number of samples
  // instantiate circular buffer, 2x larger then delay time and set delay
  CircBuffer circBuffer(441000);
  circBuffer.setDistanceRW(50);
  circBuffer.setDistanceExtraRW(441);
  // circBuffer.setDistanceExtraRWO(441);
  // circBuffer.setDistanceExtraRWOL(441);
  circBuffer.logAllSettings();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&circBuffer](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // write input to delay
      //Writing multiple times allows sample skipping
      //Usage of this allows intervals besides an octave.
      circBuffer.write(inBuf[i]);
      circBuffer.tick();
      circBuffer.write(inBuf[i]);
      circBuffer.tick();
      circBuffer.write(inBuf[i]);
      circBuffer.tick();
      circBuffer.write(inBuf[i]);
      outBuf[i] = circBuffer.readExtraRH()* 0.5;


      circBuffer.tick();
      // circBuffer.tickReadHead();
      //Below is the tick for the fifth
      circBuffer.tickExtraRH();
      // //Below is the tick for an octave higher
      // circBuffer.tickExtraRHO();
      // //Below is the tick for an octave lower
      // circBuffer.tickExtraRHOL();
    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

  //end the program
  return 0;
} // main()
