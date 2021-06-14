/*
 * x的平方根
 */
#include <stdio.h>

/* 暴力法 */
// int mySqrt(int x)
// {
//     int i = 0;

//     if (x < 0)
//     {
//         return -1;
//     }

//     while (i < 46340)
//     {
//         if (i * i < x)
//         {
//             i++;
//         }
//         else if (i * i == x)
//         {
//             return i;
//         }
//         else
//         {
//             return i - 1;
//         }
//     }

//     /* 特殊处理边界值，如x=2147395599 */
//     return i * i > x ? (i - 1) : i;
// }

/* 二分法 */
int mySqrt(int x)
{
    int left = 1;
    int right = x / 2;
    int mid = 0;

    if (x < 0)
    {
        return -1;
    }
    else if (0 == x)
    {
        return 0;
    }
    else if (1 == x)
    {
        return 1;
    }

    while (left <= right)
    {
        mid = (left + right) / 2;
        /* 注意用除法避免溢出问题 */
        if (mid > x / mid)
        {
            right = mid - 1;
        }
        else if (mid < x / mid)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    /* 注意返回(int)right */
    return (int)right;
}

void test1()
{
    int x = 0x7fffffff;
    int ret = 0;

    ret = mySqrt(x);
    printf("ret:%d\n", ret);
}

int main()
{
    test1();

    return 0;
}