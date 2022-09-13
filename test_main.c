#include <stdio.h>
#include <assert.h>
#include "continuous_range.h"
#include "testRange.h"
#include "testSensorReading.h"

int main()
{
  testseparateRanges();
  testDetectRanges();  
  testCmpFuncForQSort();
  
  testConvertD2A();
  testReadCurrentSensor();
  
  testDetectCurrentRanges();
}
