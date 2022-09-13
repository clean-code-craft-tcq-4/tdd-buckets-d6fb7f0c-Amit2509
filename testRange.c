#include <stdio.h>
#include <assert.h>
#include "testRange.h"
#include "continuous_range.h"


void testCmpFuncForQSort()
{
  int result;
  int a,b;
  a = 2;
  b = 3;
  result = CmpFuncForQSort (&a, &b);
  assert (result == -1);
  
  a = 5;
  b = 2;
  result = CmpFuncForQSort (&a, &b);
  assert (result == 3);
  
  a = 4;
  b = 4;
  result = CmpFuncForQSort (&a, &b);
  assert (result == 0);
}


void testseparateRanges()
{
  int currentSample[] = {4, 5};
  int numberOfCurrSample = sizeof(currentSample)/sizeof(currentSample[0]);
  separateRanges(currentSample, numberOfCurrSample);
  assert (Range.rangeMin[0] == 4);
  assert (Range.rangeMax[0] == 5);
  assert (Range.rangeCounts[0] == 2);
  assert (Range.TotalRanges == 1);
  
  
  currentSample[0] = -4;
  numberOfCurrSample = sizeof(currentSample)/sizeof(currentSample[0]);
  separateRanges(currentSample, numberOfCurrSample);
  assert (Range.rangeMin[0] == -4);
  assert (Range.rangeMax[0] == -4);
  assert (Range.rangeCounts[0] == 1);
  assert (Range.rangeMin[1] == 5);
  assert (Range.rangeMax[1] == 5);
  assert (Range.rangeCounts[1] == 1);
  assert (Range.TotalRanges == 2);
}


void testDetectRanges()
{
  int currentSample[] = {3, 3, 5, 4, 10, 11, 12};
  int numberOfCurrSample = sizeof(currentSample)/sizeof(currentSample[0]);
  DetectRanges(currentSample, numberOfCurrSample);
  printCurrentRanges();
  assert (Range.rangeMin[0] == 3);
  assert (Range.rangeMax[0] == 5);
  assert (Range.rangeCounts[0] == 4);
  
  assert (Range.rangeMin[1] == 10);
  assert (Range.rangeMax[1] == 12);
  assert (Range.rangeCounts[1] == 3);
  
  assert (Range.TotalRanges == 2);
}

void testDetectCurrentRanges()
{
  int currentSampleDigital[] = {1228, 1228, 2047, 1638, 4095, 3685, 3276};
  int numberOfCurrSample = sizeof(currentSampleDigital)/sizeof(currentSampleDigital[0]);
  int currentAnalog[numberOfCurrSample];
  DetectCurrentRanges(currentSampleDigital, numberOfCurrSample, currentAnalog);
  printCurrentRanges();
  assert (Range.rangeMin[0] == 3);
  assert (Range.rangeMax[0] == 5);
  assert (Range.rangeCounts[0] == 4);
  
}
