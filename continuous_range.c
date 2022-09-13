#include <stdio.h>
#include <stdlib.h>
#include "continuous_range.h"

int CmpFuncForQSort (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void separateRanges(int* CurrentValues, int numberOfCurrValues)
{
  int counter = 0;
  int newMinIndex = 0;
  Range.rangeMin[counter] = CurrentValues[newMinIndex];
  Range.rangeMax[counter] = CurrentValues[newMinIndex];
  Range.rangeCounts[counter] = 1;
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