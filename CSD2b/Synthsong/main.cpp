#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <signal.h>
#include "writeToFile.h"
#include "melodygen.h"
#include "jack_module.h"
#include "math.h"
#include "oscillator.h"
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "triangle.h"
#include "RtMidi.h"
#include <unistd.h>
//Doesnt do anything yet, but may be neccessary for midi control.
//Some global variables
int createplay = 1;
int timing = 500;
int amountNotes = 0;
double frequency = 500;
bool create = true;
int mtof = 0;
bool done = false;
float decayTimer = 2;

static void finish( int /*ignore*/ ){ done = true; }

void usage( void ) {
  // Error function in case of incorrect command-line
  // argument specifications.
  std::cout << "\nusage: qmidiin <port>\n";
  std::cout << "where port = the device to use (first / default = 0).\n\n";
  exit( 0 );
}



int main(int argc,char **argv)
{
  //some Non-global
  int optionWave = 1;
  int midiKeys = 1;
  // WriteToFile fileWriter_output("data_output_sin.csv", true);
  // create a JackModule instance
  int amountVoices = 1;
  std::cout<<"Welcome to your very own synthesizer!\n";
  std::cout<<"Before we get started you need to setup some things.\n";
  std::cout<<"Would you like the synth to create it's own melody or would you like to play around?\n";
  while(1)
  {
    std::cout<<"1 = Create me a melody, 2 = Play yourself ";
    std::cin>>createplay;
    if(std::cin.good())
    {
      if (createplay < 0)
      {
        std::cout<<"\nThat's a negative integer. Please enter an integer 1 or 2 ";
      }
      else if (createplay > 2)
      {
        std::cout<<"\nThat integer is a little high. Try again.";
      }
      else
      {
        if (createplay == 1)
        {
          create = true;
        }
        else
        {
          create = false;
        }
        break;
      }

    }
    else
    {
      std::cout<<"That's not an integer.\n";
      std::cin.clear();
      std::cin.ignore(INT8_MAX, '\n');
    }
  }
  while(create)
  {
    std::cout<<"\nHow many notes would you like the melody to be?\n";
    std::cin>>amountNotes;
    if(std::cin.good())
    {
      if(amountNotes < 0)
      {
        std::cout<<"\nThat's a negative integer. Please enter an integer 1 or above.";
      }
      else
      {
        break;
      }
    }
    else
    {
      std::cout<<"That's not an integer.\n";
      std::cin.clear();
      std::cin.ignore(INT8_MAX, '\n');
    }
  }
  while(create)
  {
    std::cout<<"What tempo do you want the melody to be? (milliseconds) ";
    std::cin>>timing;
    if(std::cin.good())
    {
      if(timing<0)
      {
        std::cout<<"\nThat's a negative integer. Please enter an integer 1 or above.\n";
      }
      else
      {
        break;
      }
    }
    else
    {
      std::cout<<"That's not an integer.\n";
      std::cin.clear();
      std::cin.ignore(INT8_MAX, '\n');
    }
  }

  while(!create)
  {
    std::cout<<"How many voices would you like for your synth? (1-12) ";
    std::cin>>amountVoices;
    if(std::cin.good())
    {
      if(amountVoices < 0)
      {
        std::cout<<"That's a negative integer. Please enter an integer 1 to 6.\n";
      }
      else if (amountVoices > 12)
      {
        std::cout<<"\nThat integer is a little high. Please enter an integer 1 to 6.\n";
      }
      else
      {
        break;
      }
    }
    else
    {
      std::cout<<"That's not an integer.\n";
      std::cin.clear();
      std::cin.ignore(INT8_MAX, '\n');
    }
  }

  std::cout<<"What kind of Waveform would you like to use?\n"<<"Sine, Square, Saw or Triangle (1-4) ";
  while(1)
  {
    std::cin>>optionWave;
    if(std::cin.good())
    {
      if(optionWave < 0)
      {
        std::cout<<"\nThat's a negative integer. Please enter an integer 1 or above.";
      }
      else if(optionWave > 4)
      {
        std::cout<<"\nThat integer is a little high. Please enter an integer 1 to 4.";
      }
      else
      {
        break;
      }
    }
    else
    {
      std::cout<<"That's not an integer.\n";
      std::cin.clear();
      std::cin.ignore(INT8_MAX, '\n');
    }
  }
  //WORKING
  while(!create)
  {
    std::cout<<"Would you like to play with midi or keyboard? (1 = midi, 2 = keys) ";
    std::cin>>midiKeys;
    if(std::cin.good())
    {
      if(midiKeys<0)
      {
        std::cout<<"\nThat's a negative integer. Please enter an integer 1 or 2.\n";
      }
      else if(midiKeys>2)
      {
        std::cout<<"\nThat integer is a little high. Please enter an integer 1 or 2.\n";
      }
      else
      {
        break;
      }
    }
    else
    {
      std::cout<<"That's not an integer.\n";
      std::cin.clear();
      std::cin.ignore(INT8_MAX, '\n');
    }
  }
  //WORKING
  while(!create)
  {
    std::cout<<"What kind of decay would you like to play with?\n(0.5 = 2 seconds, 1 = 1 Second, 2 = half a second)\n";
    std::cout<<"NOTE:: Anything above 0 works ";
    std::cin>>decayTimer;
    if(std::cin.good())
    {
      if(decayTimer<0)
      {
        std::cout<<"\nThat's a negative integer. Please enter an integer 1 or 2.\n";
      }
      else
      {
        if(midiKeys==1){
          std::cout<<"\nHave fun playing! You can press CTRL-C to exit.\n";
        }
        else{
          std::cout<<"\nHave fun playing! You can press Q to exit.\n";
          break;
        }
      }
    }
    else
    {
      std::cout<<"That's not an integer.\n";
      std::cin.clear();
      std::cin.ignore(INT8_MAX, '\n');
    }
  }
  //Creating the neccessary components for the synth to function.
  //mem[] will be used to store midi notes, so the right oscillator will turn OFF
  //when the noteOff comes in through midi.
  int mem[amountVoices];
  float decay[amountVoices];
  JackModule jack;
  float amplitude[amountVoices];
  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Melodygen melody;
  double* mel = melody.generate(amountNotes);

  std::vector<Sine> sine;

  std::vector<Square> square;

  std::vector<Saw> saw;

  std::vector<Triangle> triangle;

  std::thread voices[amountVoices];
  for(int i = 0; i<amountVoices; ++i)
  {
    //Selecting the waveform in the terminal select the corresponding if statement
    //Using a vector u can create multiple instances of classes iteratively;
    if(optionWave==1){
      sine.emplace_back(frequency, samplerate);
      voices[i] = std::thread(&Oscillator::timer, std::addressof(sine[i]),std::ref(mel),timing, amountNotes);
      mem[i]=0;
      decay[i] = 0;
    }
    else if(optionWave==2)
    {
      square.emplace_back(frequency, samplerate);
      voices[i] = std::thread(&Oscillator::timer, std::addressof(square[i]),std::ref(mel),timing, amountNotes);
      mem[i]=0;
      decay[i] = 0;
    }
    else if(optionWave==3)
    {
      saw.emplace_back(frequency, samplerate);
      voices[i] = std::thread(&Oscillator::timer, std::addressof(saw[i]),std::ref(mel),timing, amountNotes);
      mem[i]=0;
      decay[i] = 0;
    }
    else if(optionWave==4)
    {
      triangle.emplace_back(frequency, samplerate);
      voices[i] = std::thread(&Oscillator::timer, std::addressof(triangle[i]),std::ref(mel),timing, amountNotes);
      mem[i]=0;
      decay[i] = 0;
    }
  }



  jack.onProcess = [&sine,&square,&saw,&triangle,&decay,&amplitude,&amountVoices,&optionWave](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
    {

    for(unsigned int i = 0; i < nframes; i++) {
      double output =0;
      // fileWriter_output.write(std::to_string(sine.getSample()*amplitude) + "\n");
      for(int y = 0; y < amountVoices; y++)
      {
        if(optionWave==1){
          amplitude[y]=sine[y].getAmplitude();
          if(amplitude[y]>0.0)
          {
            amplitude[y] = amplitude[y]-decay[y];
            sine[y].setAmplitude(amplitude[y],1);
          }
          output +=sine[y].getSample()*amplitude[y];
        }
        else if(optionWave==2){
          amplitude[y]=square[y].getAmplitude();
          if(amplitude[y]>0.0)
          {
            amplitude[y] = amplitude[y]-decay[y];
            square[y].setAmplitude(amplitude[y],1);
          }
          output +=square[y].getSample()*amplitude[y];
        }
        else if(optionWave==3){
          amplitude[y]=saw[y].getAmplitude();
          if(amplitude[y]>0.0)
          {
            amplitude[y] = amplitude[y]-decay[y];
            saw[y].setAmplitude(amplitude[y],1);
          }
          output +=saw[y].getSample()*amplitude[y];
        }
        else if(optionWave==4){
          amplitude[y]=triangle[y].getAmplitude();
          if(amplitude[y]>0.0)
          {
            amplitude[y] = amplitude[y]-decay[y];
            triangle[y].setAmplitude(amplitude[y],1);
          }
          output +=triangle[y].getSample()*amplitude[y];
        }

      }
      //
      outBuf[i] = output;
      //tick() is the same for all Waveforms.
      //calc() is the function that differs from waveform to waveform.
      for(int t = 0; t<amountVoices; t++)
      {
        if(optionWave==1)
        {
        sine[t].tick();
        }
        else if(optionWave==2)
        {
        square[t].tick();
        }
        else if(optionWave==3)
        {
        saw[t].tick();
        }
        else if(optionWave==4)
        {
        triangle[t].tick();
        }

      }
    }

    return 0;
  };

  jack.autoConnect();

  //RtMidiIn is a library I found online that lets you use midi.
  RtMidiIn *midiin = 0;
  std::vector<unsigned char> message;
  int nBytes, i;
  double stamp;

  // Minimal command-line check.
  if ( argc > 2 ) usage();

  // RtMidiIn constructor
  try {
    midiin = new RtMidiIn();
  }
  catch ( RtMidiError &error ) {
    error.printMessage();
    exit( EXIT_FAILURE );
  }

  // Check available ports vs. specified.
  unsigned int port = 0;
  unsigned int nPorts = midiin->getPortCount();
  if ( argc == 2 ) port = (unsigned int) atoi( argv[1] );
  if ( port >= nPorts ) {
    delete midiin;
    std::cout << "Invalid port specifier!\n";
    usage();
  }

  try {
    midiin->openPort( port );
  }
  catch ( RtMidiError &error ) {
    error.printMessage();

  }

  // Don't ignore sysex, timing, or active sensing messages.
  midiin->ignoreTypes( false, false, false );

  // Install an interrupt handler function.
  done = false;
  (void) signal(SIGINT, finish);

  // Periodically check input queue.
  // std::cout << "Reading MIDI from port " << midiin->getPortName() << " ... quit with Ctrl-C.\n";
  while (midiKeys==1) {
    if(done){
      break;
    }
    stamp = midiin->getMessage( &message );
    nBytes = message.size();
    if(nBytes > 2){
      //176 from midi are the control knobs, this is a reset in case
      //the notes don't go off or other troubles.
      if(message[0]==176)
      {
        for(int i = 0; i<amountVoices;i++)
        {
          mem[i]=0;
        }
      }
      if(optionWave==1){
    //THIS IS FOR TURNING NOTES OFF 128 IN MIDI = NOTE OFF
        for(int i =0; i <amountVoices; i++)
        {
          if(message[0]==128)
          {
            if(mem[i]==message[1])
            {
              sine[i].setAmplitude(0,1);
              mem[i]=0;
              break;
            }
          }
    //THIS IS FOR TURNING NOTES ON 144 IN MIDI = NOTE ON
          else if(message[0]==144)
          {
            if(mem[i]==0)
            {
              frequency = melody.mtoF(message[1]);
              sine[i].setFrequency(frequency);
              sine[i].setAmplitude(message[2],0);
              decay[i] = (sine[i].getAmplitude())/(samplerate/decayTimer);
              mem[i] = message[1];
              break;
            }
          }
        }
      }
        if(optionWave==2){
          for(int i =0; i <amountVoices; i++)
          {
            if(message[0]==128)
            {
              if(mem[i]==message[1])
              {
                square[i].setAmplitude(0,1);
                mem[i]=0;
                break;
              }
            }
            else if(message[0]==144)
            {
              if(mem[i]==0)
              {
                frequency = melody.mtoF(message[1]);
                square[i].setFrequency(frequency);
                square[i].setAmplitude(message[2],0);
                decay[i] = (square[i].getAmplitude())/(samplerate/decayTimer);
                mem[i] = message[1];
                break;
              }
            }
          }
        }
        if(optionWave==3){
          for(int i =0; i <amountVoices; i++)
          {
            if(message[0]==128)
            {
              if(mem[i]==message[1])
              {
                saw[i].setAmplitude(0,1);
                mem[i]=0;
                break;
              }
            }
            else if(message[0]==144)
            {
              if(mem[i]==0)
              {
                frequency = melody.mtoF(message[1]);
                saw[i].setFrequency(frequency);
                saw[i].setAmplitude(message[2],0);
                decay[i] = (saw[i].getAmplitude())/(samplerate/decayTimer);
                mem[i] = message[1];
                break;
              }
            }
          }
        }
        if(optionWave==4){
        //THIS IS FOR TURNING NOTES OFF


          for(int i =0; i <amountVoices; i++)
          {
            if(message[0]==128)
            {
              if(mem[i]==message[1])
              {
                triangle[i].setAmplitude(0,1);
                mem[i]=0;
                break;
              }
            }
            else if(message[0]==144)
            {
              if(mem[i]==0)
              {
                frequency = melody.mtoF(message[1]);
                triangle[i].setFrequency(frequency);
                triangle[i].setAmplitude(message[2],0);
                decay[i] = (triangle[i].getAmplitude())/(samplerate/decayTimer);
                mem[i] = message[1];
                break;
              }
            }
          }
      }
    }
    // Sleep for 10 milliseconds.
    usleep(10000.0);
  }
  int octaves = 3;
  while(midiKeys==2)
  {

    system("stty raw");
    char var = getchar();
    if(var=='a')
    {
      frequency = melody.mtoF(24+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='s')
    {
      frequency = melody.mtoF(26+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='d')
    {
      frequency = melody.mtoF(28+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='f')
    {
      frequency = melody.mtoF(29+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='g')
    {
      frequency = melody.mtoF(31+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='h')
    {
      frequency = melody.mtoF(33+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='j')
    {
      frequency = melody.mtoF(35+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='k')
    {
      frequency = melody.mtoF(36+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='l')
    {
      frequency = melody.mtoF(38+(12*octaves));
      sine[0].setFrequency(frequency);
      sine[0].setAmplitude(1,1);
      decay[0] = (sine[0].getAmplitude())/(samplerate/decayTimer);
    }
    if(var=='x')
    {
      octaves+=1;
    }
    if(var=='z')
    {
      octaves-=1;
    }
    if(var=='q')
    {
      system("stty -raw");
      midiKeys ==0;
      break;

    }
  }
  for(int i = 0; i<amountVoices;i++)
  {
    voices[i].join();
  }
  //end the program

  delete midiin;
  return 0;
  } // main()
