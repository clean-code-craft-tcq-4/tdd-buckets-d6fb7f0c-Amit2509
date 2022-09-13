#include <stdio.h>
#include <math.h>
#include "SensorReading.h"

int ConvertD2A(int digital)
{
  float analog = (float) (digital*10)/4095;
  return (int)round(analog);
}
