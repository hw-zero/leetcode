/*
 * 二进制求和
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_STR_LEN     1
#define MAX_STR_LEN     10000

char * addBinary(char * a, char * b)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp = 0;
    char *ret = NULL;
    int len_a = 0;
    int len_b = 0;
    int max_len = 0;

    if (NULL == a || NULL == b)
    {
        return NULL;
    }

    len_a = strlen(a);
    len_b = strlen(b);

    if (len_a < MIN_STR_LEN || len_a > MAX_STR_LEN || len_b < MIN_STR_LEN || len_b > MAX_STR_LEN)
    {
        return NULL;
    }

    max_len = len_a > len_b ? len_a : len_b;

    ret = (char *)malloc((max_len + 2) * sizeof(char));
    if (NULL == ret)
    {
        return NULL;
    }
    memset(ret, 0, max_len + 2);

    i = len_a - 1;
    j = len_b - 1;
    k = max_len + 1;

    ret[k--] = '\0';

    while (i >= 0 || j >= 0)
    {
        /* 相当于将a和b补齐到一样的长度，注意字符和数字之间的转换 */
        tmp += (i >= 0) ? (a[i] - '0') : 0;
        tmp += (j >= 0) ? (b[j] - '0') : 0;
        ret[k--] = (tmp % 2) + '0';
        tmp /= 2;
        i--;
        j--;
    }

    ret[0] = tmp + '0';

    /* 巧妙处理第0位，内存泄漏？？ */
    return ret + (1 - tmp);
}

void test1()
{
    char *a = "1010";
    char *b = "1011";
    char *c = addBinary(a, b);

    printf("%s\n", c);
}

int main()
{
    test1();

    return 0;
}