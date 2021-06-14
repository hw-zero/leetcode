/*
 * 第一个错误的版本
 */
#include <stdio.h>

#define BAD_VER 1702766719
#define bool    int
#define true    1
#define false   0

bool isBadVersion(int n)
{
    return (n >= BAD_VER) ? true : false;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    int left = 1;
    int right = n;
    int mid = 0;

    while (left <= right)
    {
        /* 合理解决溢出问题，不应使用mid=(left+right)/2 */
        mid = left + (right - left) / 2;
        // printf("mid:%ld\n", mid);
        if (true == isBadVersion(mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return (int)((left > right) ? left : mid);
}

void test1()
{
    int n = 2126753390;
    int ret = 0;

    ret = firstBadVersion(n);
    printf("ret:%d\n", ret);
}

int main()
{
    test1();
    return 0;
}