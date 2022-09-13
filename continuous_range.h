#include <stdio.h>

#define MAX_POSSIBLE_RANGES    20

typedef struct
{
    int rangeMin[10];
    int rangeMax[10];
    int rangeCounts[10];
    int TotalRanges;
}rangeT;

rangeT Range;
void separateRanges(int* SortedCurrentValues, int numberOfCurrValues)
void DetectRanges(int* CurrentValues, int numberOfCurrValues);
