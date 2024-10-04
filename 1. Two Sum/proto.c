
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;

    int* sorted = malloc(sizeof(int) * numsSize);
    memcpy(sorted, nums, sizeof(int) * numsSize);

    qsort(sorted, numsSize, sizeof(int), compare);

    int low = 0;
    int high = numsSize-1;
    
    int x = 0;
    while ((x = sorted[low] + sorted[high]) != target)
    {
        if (x > target) high -= 1;
        else            low  += 1;
    }

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
