#include <iostream>
#include <thread>
#include <unistd.h> // sleep


/*
  This function is being performed by thread 1 and 2
*/
void threadfunction(int id)
{
  for(int i=0; i<5; i++){
    std::cout << "I am thread # " << id << std::endl;
    sleep(id);
  } // for
} // threadfunction()



int main()
{
  /*
    Create some two threads that call a named function and one thread
      calling a lambda function
  */
  std::thread t1(threadfunction,1);
  std::thread t2(threadfunction,2);
  std::thread t3([] { std::cout << "Lambda says hello\n"; });

  t1.join(); // wait for this thread to finish
  t2.detach(); // let this thread run free
  t3.join(); // wait for this thread to finish

  std::cout << "Main thread ends\n";

  return 0;
} // main()
