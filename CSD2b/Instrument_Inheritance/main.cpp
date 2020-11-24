#include "blazers.h"
#include "strijkers.h"

int main()
{
  Blazers myHoorn("Zuiver Hoorngeluid", 24);
  Strijkers myViool("Zuiver Vioolgeluid", 36);
  myHoorn.play();
  myViool.play();
  myHoorn.dempen();
  myViool.pluck();
  myHoorn.play();
  myViool.play();
  return 0;
}
