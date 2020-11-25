#include "blazers.h"
#include "strijkers.h"
#include <string>
#include <limits>
int note = 0;
int x = 0;
int main()
{
  std::cout <<"_________________________\n"
           << "Welcome to my INHERITANCE\n"
           << "\nTo make proper use of all functions make sure your terminal size is large enough.\n\n";
  std::cout << "Today's ensemble will be comprising of 2 trumpets and 2 Violins\n";

  Blazers myTrumpet1("mWaaaaAaap", 30);
  Blazers myTrumpet2("MwaaAhaaaP", 30);
  Strijkers myViolin1("iIiiiIIiiiiiie", 45);
  Strijkers myViolin2("IiiiiIIiIIiiiI", 45);

  std::cout << "To assist you, here's a list of some of the more common Midi-Notes";
    myTrumpet1.midi();

  std::cout << "\nThese aren't all the notes, they range from 21(A0) to 108(C8)\n\n";
  std::cout << "Also keep in mind that the trumpet and violin both have different pitchranges.\n\n"
            << "The trumpet has a range of almost 3 octaves from F#3(54) up to C6(84)\n"
            << "The violin has a range of almost 5 octaves from G3(55) up to E7(100)\n\n";

  std::cout << "Please enter the note you want played here: ";
  std::cin >> note;

  bool running = true;
  while(running)
  {
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
      std::cout<< "You have entered the wrong input\n"
               << "Please use an integer ranging from 21-108\n"
               << "Note = ";
      std::cin >> note;
    }

    if(!std::cin.fail())
    {
      if(note>20 && note<109)
      {
        running=false;
        break;
      }

      else
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
        std::cout<< "Please use an integer ranging from 21-108\n"
                 << "Note = ";
        std::cin >> note;
      }
    }
  }


  if(note<54 || note > 84){
    std::cout << "The trumpets can't play this note :(\n";
  }
  else {
    myTrumpet1.play();
    myTrumpet2.play();
  }
  if(note<55 || note > 100){
    std::cout << "The violions can't play this note :(\n";
  }
  else {
    myViolin1.play();
    myViolin2.play();
  }
  // myHoorn.midi();
  // myHoorn.play();
  // myViool.play();
  // myHoorn.dempen();
  // myViool.pluck();
  // myHoorn.play();
  // myViool.play();
  return 0;
}
