/*
 * 数组异或操作
 */
#include <stdio.h>

#define MIN_NUM_LEN     1
#define MAX_NUM_LEN     1000
#define MIN_START       0
#define MAX_START       1000

int xorOperation(int n, int start)
{
    int i = 0;
    int ret = start;

    if (n < MIN_NUM_LEN || n > MAX_NUM_LEN || start < MIN_START || start > MAX_START)
    {
        return -1;
    }

    for (i = 1; i < n; i++)
    {
        ret ^= start + 2 * i;
    }
    
    // printf("ret = %d\n", ret);

    return ret;
}

void test1()
{
    int ret = 0;
    int n = 10;
    int start = 5;

    ret = xorOperation(n, start);
    printf("ret = %d\n", ret);
}

int main()
{
    test1();

    return 0;
}