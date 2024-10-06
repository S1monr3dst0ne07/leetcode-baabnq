

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int* end1 = nums1 + nums1Size;
    int* end2 = nums2 + nums2Size;


    int size = nums1Size + nums2Size;
    bool isOdd = size & 1;
    int pivot = size >> 1;

    int last = 0;
    int this = 0;

    for (int l = 0; l < pivot+1; l++)
    {
        last = this;

        /**/ if (nums1 >= end1) this = *nums2++;
        else if (nums2 >= end2) this = *nums1++;

        else if (*nums1 < *nums2) this = *nums1++;
        else                      this = *nums2++;

    }


    return isOdd ? this : (double)(last + this) / 2.0;
}