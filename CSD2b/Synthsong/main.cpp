#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "oscillator.h"
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "triangle.h"
#include <limits>
#include <sstream>
#include "writeToFile.h"
#include "melodygen.h"
#include "timer.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */
double sinephasedelta = 0;
double sawphasedelta = 0;
double squarephasedelta = 0;
double trianglephasedelta = 0;
int noteOn = 1;
int main(int argc,char **argv)
{
  // WriteToFile fileWriter_output("data_output_sin.csv", true);
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  //Create an oscillator with a frequency
  Melodygen melody;
  float* mel = melody.generate(10);
  Timer timer;
  timer.pulse();

  Saw saw(400,samplerate);
  Square square(100,samplerate);
  Triangle triangle(175,samplerate);
  Sine sine(200, samplerate);


  double sineFreq = sine.getFrequency();
  double squareFreq = square.getFrequency();
  double sawFreq = saw.getFrequency();
  double triangleFreq = triangle.getFrequency();
  //simplifying the calculation by seperation
  sinephasedelta = sine.getPhasedelta(sineFreq, samplerate);
  squarephasedelta = square.getPhasedelta(squareFreq,samplerate);
  sawphasedelta = saw.getPhasedelta(sawFreq,samplerate);
  trianglephasedelta = triangle.getPhasedelta(triangleFreq,samplerate);
  //assign a function to the JackModule::onProces

  jack.onProcess = [&sine,&saw,&triangle,&square,&sinephasedelta,&sawphasedelta, &squarephasedelta, &trianglephasedelta](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
    {
    static float amplitude = 0.1;
    for(unsigned int i = 0; i < nframes; i++) {
      // fileWriter_output.write(std::to_string(sine.getSample()*amplitude) + "\n");

        outBuf[i] = (triangle.getSample()+square.getSample()+saw.getSample()+sine.getSample())*amplitude*noteOn;
        //.tick is the same for all Waveforms
        sine.tick(sinephasedelta);
        square.tick(squarephasedelta);
        saw.tick(sawphasedelta);
        triangle.tick(trianglephasedelta);


      //the waveforms turns unique by the different calculations.

    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    char var = getchar();
    if(var == 'p')
    {
      noteOn = 0;
    }
    if(var =='o')
    {
      noteOn = 1;
    }
    if(var=='f')
    {
      std::cout<<"enter which oscillator you'd like to change (1, 2, 3 or 4)\n"<<"Where 1 = Sinewave, 2 = Squarewave, 3 = Sawwave, 4 = Trianglewave";
      std::cin>> var;
      if(var=='1')
      {
        std::cout<<"Enter the frequency for the Sinewave";
        std::cin>> sineFreq;
        sinephasedelta = sine.getPhasedelta(sineFreq, samplerate);

      }
      if(var=='2')
      {
        std::cout<<"Enter the frequency for the Squarewave";
        std::cin>> squareFreq;
        squarephasedelta = square.getPhasedelta(squareFreq, samplerate);

      }
      if(var=='3')
      {
        std::cout<<"Enter the frequency for the Sawwave";
        std::cin>> sawFreq;
        sawphasedelta = saw.getPhasedelta(sawFreq, samplerate);
      }
      if(var=='4')
      {
        std::cout<<"Enter the frequency for the Trianglewave";
        std::cin>> triangleFreq;
        trianglephasedelta = triangle.getPhasedelta(triangleFreq, samplerate);
      }

    }
    if(var=='q')
    {
      jack.end();
      break;
      running = false;
    }

        // running = false;
        // jack.end();
        // break;

  }
  // std::cout<<"test";
  //end the program
  return 0;
} // main()
