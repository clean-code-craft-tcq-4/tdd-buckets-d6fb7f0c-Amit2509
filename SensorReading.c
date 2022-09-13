#include <stdio.h>
#include "SensorReading.h"

int ConvertD2A(int digital)
{
  int analog = (int) round(10*digital/4095);
  return analog;
}
