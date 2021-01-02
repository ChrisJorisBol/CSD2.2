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
#include <thread>
#include <chrono>

//Doesnt do anything yet, but may be neccessary for midi control.
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
  double* mel = melody.generate(40);
  std::cout<<"melodygen geeft mel[5] = "<<mel[5]<<"\n";


  Saw saw(400,samplerate);
  Square square(100,samplerate);
  Triangle triangle(175,samplerate);
  Sine sine(200, samplerate);


  //Creating threads to change the frequency on a timing with a sleep function.
  //TODO change thread names
  
  std::thread th1(&Oscillator::foo, std::addressof(sine),std::ref(mel));
  std::thread th2(&Oscillator::foo, std::addressof(saw),std::ref(mel));

  jack.onProcess = [&sine,&saw,&triangle,&square](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
    {
    static float amplitude = 0.1;
    for(unsigned int i = 0; i < nframes; i++) {
      // fileWriter_output.write(std::to_string(sine.getSample()*amplitude) + "\n");

        outBuf[i] = (triangle.getSample()+square.getSample()+saw.getSample()+sine.getSample())*amplitude*noteOn;
        //tick() is the same for all Waveforms.
        //calc() is the function that differs from waveform to waveform.
        sine.tick();
        // square.tick();
        // saw.tick();
        // triangle.tick();
    }

    return 0;
  };

  jack.autoConnect();
  th1.join();
  th2.join();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    double frequency = 0;
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
        std::cin>> frequency;
        sine.setFrequency(frequency);

      }
      // if(var=='2')
      // {
      //   std::cout<<"Enter the frequency for the Squarewave";
      //   std::cin>> squareFreq;
      //   squarephasedelta = square.getPhasedelta(squareFreq, samplerate);
      //
      // }
      // if(var=='3')
      // {
      //   std::cout<<"Enter the frequency for the Sawwave";
      //   std::cin>> sawFreq;
      //   sawphasedelta = saw.getPhasedelta(sawFreq, samplerate);
      // }
      // if(var=='4')
      // {
      //   std::cout<<"Enter the frequency for the Trianglewave";
      //   std::cin>> triangleFreq;
      //   trianglephasedelta = triangle.getPhasedelta(triangleFreq, samplerate);
      // }

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
