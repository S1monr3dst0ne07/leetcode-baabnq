#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;

    int numsByteSize = sizeof(int) * numsSize;
    int* sorted = malloc(numsByteSize);
    memcpy(sorted, nums, numsByteSize);

    qsort(sorted, numsSize, sizeof(int), compare);

    int low = 0;
    int high = numsSize-1;
    
    int sum = 0;
    while ((sum = sorted[low] + sorted[high]) != target)
        if (sum > target) high -= 1;
        else              low  += 1;

    int indexLow  = -1;
    int indexHigh = -1;
    
    for (int i = 0; i < numsSize; i++)
        /**/ if (indexLow  == -1 && nums[i] == sorted[low] ) indexLow  = i;
        else if (indexHigh == -1 && nums[i] == sorted[high]) indexHigh = i;


    free(sorted);

    int* out = malloc(sizeof(int) * 2);
    out[0] = indexLow;
    out[1] = indexHigh;
    
    return out;
}
