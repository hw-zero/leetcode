/*
 * 两数之和 II - 输入有序数组
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_NUM_SIZE    1
#define MAX_NUM_SIZE    30000
#define MIN_TARGET      -1000
#define MAX_TARGET      1000
#define MIN_NUM         -1000
#define MAX_NUM         1000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int left = 0;
    int right = numbersSize - 1;
    int *ret = NULL;

    if (NULL == numbers || NULL == returnSize 
        || target < MIN_TARGET || target > MAX_TARGET
        || numbersSize < MIN_NUM_SIZE || numbersSize > MAX_NUM_SIZE)
    {
        return NULL;
    }

    *returnSize = 2;

    ret = (int *)malloc(sizeof(int) * (*returnSize));
    if (NULL == ret)
    {
        return NULL;
    }
    memset(ret, 0, sizeof(int) * (*returnSize));

    while (left < right)
    {
        if (numbers[left] < MIN_NUM || numbers[left] > MAX_NUM 
            || numbers[right] < MIN_NUM || numbers[right] > MAX_NUM)
        {
            return NULL;
        }
        
        if (numbers[left] + numbers[right] > target)
        {
            right--;
        }
        else if (numbers[left] + numbers[right] == target)
        {
            ret[0] = left + 1;
            ret[1] = right + 1;
            break;
        }
        else
        {
            left++;
        }
    }

    return ret;
}

void test1()
{
#define N   4

    int nums[N] = {2, 7, 11, 15};
    int target = 9;
    int *ans = NULL;
    int returnSize = 0;

    ans = twoSum(nums, N, target, &returnSize);
    printf("ans[0]:%d, ans[1]:%d\n", ans[0], ans[1]);

    /* 在主调函数里释放内存 */
    if (NULL != ans)
    {
        free(ans);
        ans = NULL;
    }
}

int main()
{
    test1();
    return 0;
}