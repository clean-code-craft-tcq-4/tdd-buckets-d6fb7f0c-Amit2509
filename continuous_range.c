#include <stdio.h>
#include <stdlib.h>
#include "continuous_range.h"
#include "SensorReading.h"

rangeT Range;

int CmpFuncForQSort (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void printCurrentRanges()
{
    printf("\nRange,  Readings");
    for( int i = 0 ; i < Range.TotalRanges; i++ ) 
    {   
        printf("\n%d-%d,  %d", Range.rangeMin[i],Range.rangeMax[i], Range.rangeCounts[i]);
    }
}

void separateRanges(int* CurrentValues, int numberOfCurrValues)
{
  int counter = 0;
  int newMinIndex = 0;
  Range.rangeMin[counter] = CurrentValues[newMinIndex];
  Range.rangeMax[counter] = CurrentValues[newMinIndex];
  Range.rangeCounts[counter] = 1;
  Range.TotalRanges = 1;
  for (int i=1; i<numberOfCurrValues; i++)
  {       
       if ((CurrentValues[i]-CurrentValues[i-1])>1)
       {
            newMinIndex = i;
            counter++;
            Range.rangeMin[counter] = CurrentValues[newMinIndex];
            Range.rangeMax[counter] = CurrentValues[i];
            Range.rangeCounts[counter] = 1;
            Range.TotalRanges = counter+1;
       }
       else
       {
            Range.rangeMin[counter] = CurrentValues[newMinIndex];
            Range.rangeMax[counter] = CurrentValues[i];
            Range.rangeCounts[counter]++;
       }
  }
}

void DetectRanges(int* CurrentValues, int numberOfCurrValues)
{
  qsort(CurrentValues, numberOfCurrValues, sizeof(int), CmpFuncForQSort);
  separateRanges(CurrentValues, numberOfCurrValues);
}

int DetectCurrentRanges(int* DigitalCurrentValues, int numOfDigitalValues, int* AnalogCurrentValues)
{
   int numOfAnalogValues = ReadCurrentSensor(DigitalCurrentValues, numOfDigitalValues, AnalogCurrentValues);
   if (numOfAnalogValues > 0)
   {
      DetectRanges(AnalogCurrentValues, numOfAnalogValues);
   }
   else
   {
      return ERROR_INVALID_VALUE;
   }
   return numOfAnalogValues;
}
