/*
 * 二进制求和
 */
#include <stdio.h>
#include <string.h>

int titleToNumber(char * columnTitle)
{
    int i = 0;
    int j = 0;
    int tmp = 1;
    int sum = 0;

    if (NULL == columnTitle)
    {
        return -1;
    }

    i = strlen(columnTitle) - 1;
    sum = columnTitle[i--] - 'A' + 1;

    for (; i >= 0; i--)
    {
        if (columnTitle[i] < 'A' || columnTitle[i] > 'Z')
        {
            return -1;
        }
    
        tmp = tmp * 26;
        sum += tmp * (columnTitle[i] - 'A' + 1);
    }
    
    return sum;
}

void test1()
{
    char *str = "ZY";
    int ret = 0;

    ret = titleToNumber(str);
    printf("ret:%d\n", ret);
}

int main()
{
    test1();

    return 0;
}