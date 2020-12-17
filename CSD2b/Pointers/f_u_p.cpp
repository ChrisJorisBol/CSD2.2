#include <iostream>
#include <cmath>
int number = 10;
void calc(int number)
{
  number = number + 5;
  std::cout << "Void Calc gives: " << number << "\n";
  std::cout << "Contents of variable number: ";
  std::cout << number << "\n";
}

int main()
{
  int number = 10;
  int* numberpointer;
  numberpointer = &number;
  std::cout << "The variable number has contents: ";
  std::cout << number << "\n";

  std::cout << "calculation = x + 5\n";

  std::cout << "By value\n";
  calc(10);

  std::cout << "The variable number has contents: ";
  std::cout << number << "\n";

  std::cout << "By pointer\n";
  calc(*numberpointer);

  std::cout << "The variable number has contents: ";
  std::cout << number << "\n";

  std::cout << "By reference\n";
  calc(number);

  std::cout << "The variable number has contents: ";
  std::cout << number << "\n";

  //
  // std::cout << "Raising the variable number to the power of 2 gives us: ";
  // std::cout << newNumber <<"\n";
  //
  // newNumber = pow((numberpointer++),2);
  // std::cout << "Raising the pointer numberPointer to the power of 2 gives us: ";
  // std::cout << newNumber <<"\n";
  //
  // newNumber = pow((10++), 2);
  // std::cout << "Raising the value of 10 to the power of 2 gives us: ";
  // std::cout << newNumber <<"\n";

}
