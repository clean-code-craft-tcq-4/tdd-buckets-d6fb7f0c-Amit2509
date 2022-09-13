#include <stdio.h>
#include <assert.h>
#include "continuous_range.h"

int main()
{
  int currentSample[] = {3, 3, 5, 4, 10, 11, 12};
  int numberOfCurrSample = sizeof(currentSample)/sizeof(currentSample[0]);
  DetectRanges(currentSample);
  assert (Range.rangeMin[0] == 3);
  assert (Range.rangeMax[0] == 5);
  assert (Range.rangeCounts[0] == 4);
  assert (Range.TotalRanges == 2);
}
