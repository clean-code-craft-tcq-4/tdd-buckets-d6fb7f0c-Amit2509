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
