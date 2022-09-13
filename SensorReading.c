#include <stdio.h>
#include <math.h>
#include "SensorReading.h"

int ConvertD2A(int digital)
{
  if ((digital < 0) || (digital> 4095))
  {
    return ERROR_INVALID_VALUE;
  }
  else
  {
    float analog = (float) (digital*10)/4095;
  }
  return (int)round(analog);
}
