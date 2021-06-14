/*
 * 去掉最低工资和最高工资后的工资平均值
 */
#include <stdio.h>

#define MIN_SALARAY_SIZE    3 
#define MAX_SALARAY_SIZE    100
#define MIN_SALARAY         1000
#define MAX_SALARAY         1000000

double average(int* salary, int salarySize)
{
    int i = 0;
    int max = salary[0];
    int min = salary[0];
    unsigned long sum = 0;
    double avg = 0;

    if (salarySize < MIN_SALARAY_SIZE || salarySize > MAX_SALARAY_SIZE)
    {
        return -1;
    }

    for (i = 0; i < salarySize; i++)
    {
        if (salary[i] < MIN_SALARAY || salary[i] > MAX_SALARAY)
        {
            return -1;
        }

        sum += salary[i];
        max = (salary[i] > max) ? salary[i] : max;
        min = (salary[i] < min) ? salary[i] : min;
    }

    sum = sum - max - min;
    /* 注意一定要进行类型转换，否则test1测试不通过 */
    avg = (double)sum / (double)(salarySize - 2);

    printf("max:%d, min:%d, sum:%lu, avg:%f\n", max, min, sum, avg);

    return avg;
}

int test1()
{
    int salary[20] = {48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000};
    double avg = 0;

    avg = average(salary, 20);
    printf("test1: avg is %f\n", avg);

    return 0;
}

int main(void)
{
    test1();
    // test2();
    // test3();

    return 0;
}