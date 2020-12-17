#include <iostream>
#include <string>
#include <thread>

void tf(std::string name)
{
  std::cout<<"Hello I am a thread and my name is "<<name<<"\n";
}


int main()
{
  std::thread thread1(tf, "Balthazar");
  std::thread thread2(tf, "Bern");
  std::thread thread3(tf, "Brup");
  thread1.join();
  thread2.detach();
  thread3.join();
  std::cout<<"This is the end of the line\n";
  return 0;


};
