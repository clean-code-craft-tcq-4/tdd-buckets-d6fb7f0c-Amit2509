#include <stdio.h>
#include <assert.h>
#include "testSensorReading.h"
#include "SensorReading.h"

void testConvertD2A()
{
   int currentValue;
   currentValue = ConvertD2A(1146);
   assert(currentValue == 3);
  
   currentValue = ConvertD2A(4096);
   assert(currentValue == ERROR_INVALID_VALUE);
   
   currentValue = ConvertD2A(-1);
   assert(currentValue == ERROR_INVALID_VALUE);
  
}


void testReadCurrentSensor()
{
  int CurrentDigital[] = {1228, 2047, 3685, 4096}; /*Total 4 samples. Last one is invalid*/
  int expectedAnalog[] = {3, 5, 9};                        /*Expecting Total 3 samples.*/
  int numOfCurrSample = sizeof(CurrentDigital)/sizeof(CurrentDigital[0]);
  int CurrentAnalog[numOfCurrSample];
  int numOfAnalogValues = ReadCurrentSensor(CurrentDigital, numOfCurrSample, CurrentAnalog);
  assert(numOfAnalogValues == 3);
  for(int i = 0; i < numOfAnalogValues; i++)
  {
     assert(CurrentAnalog[i] == expectedAnalog[i]);
  }  
}
