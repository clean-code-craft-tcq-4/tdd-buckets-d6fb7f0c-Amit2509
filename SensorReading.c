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
    return (int)round(analog);
  }
}

int ReadCurrentSensor(int* Digital, int numOfDigitalValues, int* Analog)
{
  int analog;
  int numOfAnalogValues = 0;
  for(int i=0; i < numOfDigitalValues; i++)
  {
    analog = ConvertD2A(Digital);
    if(analog != ERROR_INVALID_VALUE)
    {
      Analog[numOfAnalogValues] = analog;
      numOfAnalogValues++;
    }
  }
  return numOfAnalogValues;
}
