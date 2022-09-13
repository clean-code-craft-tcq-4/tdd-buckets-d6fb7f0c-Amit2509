#include <stdio.h>

#define MAX_POSSIBLE_RANGES    20

typedef struct
{
    int rangeMin[MAX_POSSIBLE_RANGES];
    int rangeMax[MAX_POSSIBLE_RANGES];
    int rangeCounts[MAX_POSSIBLE_RANGES];
    int TotalRanges;
}rangeT;

extern rangeT Range;
void separateRanges(int* SortedCurrentValues, int numberOfCurrValues);
void DetectRanges(int* CurrentValues, int numberOfCurrValues);
