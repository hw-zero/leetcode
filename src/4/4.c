#include <stdio.h>

int is_invalid(int size)
{
    return (size < 0 || size > 1000);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i = 0;
    int j = 0;
    int mid = 0;
    int flag = 0;       /* 偶数取1, 奇数取0 */
    int num[2] = {0};
    double ret = 0.0;

    if (!nums1 ||  !nums2 || is_invalid(nums1Size) || is_invalid(nums2Size) /* || ... */)
    {
        // printf("invalid arg\n");
        return 0.0;
    }

    flag = ((nums1Size + nums2Size) % 2 == 0) ? 1 : 0;
    mid = (nums1Size + nums2Size) / 2 + 1;

    while (i + j < mid)
    {
        num[0] = num[1];

        if (i > nums1Size - 1)
        {
            num[1] = nums2[j];
            j++;
            continue;
        }

        if (j > nums2Size - 1)
        {
            num[1] = nums1[i];
            i++;
            continue;
        }

        if (nums1[i] <= nums2[j])
        {
            num[1] = nums1[i];
            i++;
        }
        else
        {
            num[1] = nums2[j];
            j++;
        }
    }

    if (flag)
    {
        ret = (double)(((double)num[0] + (double)num[1]) / 2);
    }
    else
    {
        ret = (double)num[1];
    }

    return ret;
}