/*
 * Excel表列名称
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N   100

char * convertToTitle(int columnNumber)
{
    int i = 0;
    char *ret = NULL;
    int tmp = columnNumber;

    if (columnNumber <= 0)
    {
        return NULL;
    }

    ret = (char *)malloc(sizeof(char) * N);
    if (NULL == ret)
    {
        return NULL;
    }
    memset(ret, 0, sizeof(char) * N);

    /* 一定要加结束符，否则会报heap-over-flow的错误，因为程序不知道结束的地方，gcc加-fsanitize=address选项！ */
    i = N - 1;
    ret[i--] = '\0';

    while (tmp > 0)
    {
        /* 注意理清楚逻辑！ */
        if (0 == (tmp % 26))
        {
            ret[i--] = 'Z';
            tmp = tmp / 26 - 1;
        }
        else
        {
            ret[i--] = (tmp % 26) - 1 + 'A';
            tmp = tmp / 26;
        }  
    }

    /* 内存泄漏？ */
    return ret + i + 1;
}

void test1()
{
    int num = 701;
    char *str = NULL;

    str = convertToTitle(num);
    printf("str:%s\n", str);
}

int main()
{
    test1();

    return 0;
}