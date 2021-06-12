/*
 * x的平方根
 */
#include <stdio.h>

int mySqrt(int x)
{
    int i = 0;

    if (x < 0)
    {
        return -1;
    }

    while (i <= x)
    {
        printf("i=%d\n", i);
        if (i * i < x)
        {
            i++;
        }
        else if (i * i == x)
        {
            return i;
        }
        else
        {
            return i - 1;
        }
    }

    return i;
}

void test1()
{
    int x = 2147483647;
    int ret = 0;

    ret = mySqrt(x);
    printf("ret:%d\n", ret);
}

int main()
{
    test1();

    return 0;
}