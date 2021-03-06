#include <iostream>

int main()
{
  //Created an integer called foo
  int foo = 36;
  std::cout << "int foo = " << foo << "\n";
  //Foo is stored in a location in the memory with an adres.
  //This location can be read with the syntax of &variable_name.
  std::cout << "memory allocation of foo = " << &foo << "\n";
  //It's even possible to give another variable, in this case bar
  //of type integer pointer (int*) the adres.
  int* bar = &foo;
  std::cout << "variable bar = &foo \nbar = " << bar << "\n";
  //After which we can read what *bar points to
  //and give that value to a new variable.
  int var = *bar;
  std::cout << "variable var = *bar \nvar =  " << var << "\n";
}
