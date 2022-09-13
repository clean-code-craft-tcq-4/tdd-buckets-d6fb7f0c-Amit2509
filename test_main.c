#include <stdio.h>
#include <assert.h>
#include "continuous_range.h"
#include "testRange.h"

int main()
{
  testseparateRanges();
  testDetectRanges();  
  testCmpFuncForQSort();
}
