/*
 * 人口最多的年份
 */
#include <stdio.h>

#define M   2
#define N   2

#define MIN_LOGSSIZE    1
#define MAX_LOGSSIZE    100
#define MIN_YEAR        1950
#define MAX_YEAR        2050

int isValidyear(int year)
{
    return (MIN_YEAR <= year && year <= MAX_YEAR);
}

int maximumPopulation(int** logs, int logsSize, int* logsColSize)
{
    int i = 0;
    int j = 0;
    int max = 0;
    int ret = MIN_YEAR;
    int p[MAX_YEAR - MIN_YEAR + 1] = {0};

    if (NULL == logs || NULL == logsColSize || logsSize < MIN_LOGSSIZE || logsSize > MAX_LOGSSIZE)
    {
        return -1;
    }

    for (i = 0; i < logsSize; i++)
    {
        if (0 == isValidyear(logs[i][0]) || 0 == isValidyear(logs[i][1]))
        {
            return -1;
        }

        for (j = logs[i][0] - MIN_YEAR; j < logs[i][1] - MIN_YEAR; j++)
        {
            p[j]++;
            
            if (p[j] > max)
            {
                max = p[j];
                ret = j + MIN_YEAR;
            }
        }
    }

    return ret;
}

void test1()
{
    int (*logs)[N] = {{1993, 1999}, {2000, 2010}};
    int logsSize = M;
    int logsColSize = N;
    int ret = 0;

    // printf("log[0][0]:%d, log[0][1]:%d\n", logs[0][0], logs[0][1]);

    ret = maximumPopulation(logs, logsSize, &logsColSize);
    printf("ret:%d\n", ret);
}

int main()
{
    test1();
    return 0;
}