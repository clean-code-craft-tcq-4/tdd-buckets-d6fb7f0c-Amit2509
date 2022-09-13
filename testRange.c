#include <stdio.h>
#include <assert.h>
#include "continuous_range.h"

int main()
{
  int currentSample[] = {3, 3, 5, 4, 10, 11, 12};
  int numOfRanges = DetectRanges(currentSample);
  assert (numOfRanges == 2);

}
