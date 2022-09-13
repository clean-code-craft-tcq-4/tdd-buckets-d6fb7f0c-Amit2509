#include <stdio.h>
#include <math.h>
#include "SensorReading.h"

int ConvertD2A_1(int digital)
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

int ConvertD2A_2(int digital)
{
  if ((digital < 0) || (digital> 1022))
  {
    return ERROR_INVALID_VALUE;
  }
  else
  {
    float analog = (float) ((digital-511)*15)/511;
    return (int)round(analog);
  }
}

static int (*ConverterD2A[])(int) = {ConvertD2A_1, ConvertD2A_2};

int ReadCurrentSensor(int* Digital, int numOfDigitalValues, int* Analog, int sensorID)
{
  int analog;
  int numOfAnalogValues = 0;
  for(int i = 0; i < numOfDigitalValues; i++)
  {
    analog = ConvertD2A[sensorID](Digital[i]);
    if(analog != ERROR_INVALID_VALUE)
    {
      Analog[numOfAnalogValues] = abs(analog);
      numOfAnalogValues++;
    }
  }
  return numOfAnalogValues;
}
