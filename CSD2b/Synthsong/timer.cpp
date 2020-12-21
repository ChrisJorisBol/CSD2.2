#include "timer.h"
#include <chrono> //for high_resolution_clock, now, duration
#include <ctime>


Timer::Timer()
{
  std::cout<<"Timer - Constructor\n";
}

Timer::~Timer()
{
  std::cout<<"Timer - Destructor\n";
}

void Timer::pulse()
{
  // std::chrono::time_point<std::chrono::system_clock> start, end;
  // clock_t start = clock();
  // std::cout<<"This is the clock start"<<start<<"\n";
  // clock_t end = 500+start;
  // std::cout<<"This is the clock end"<<end<<"\n";

  
    // clock_t start = std::chrono::system_clock::now();

  //   end = std::chrono::system_clock::now();
  //
  //   std::chrono::duration<double> elapsed_seconds = end - start;
  //   std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  //
  //   std::cout << "finished computation at " << std::ctime(&end_time)
  //             << "elapsed time: " << elapsed_seconds.count() << "s\n";
  // //             std::chrono::time_point t1 = std::chrono::high_resolution_clock::now();
  // std::cout<<"timepoint 0 = "<<t1<<"\n";
}
