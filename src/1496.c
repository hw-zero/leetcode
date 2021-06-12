/*
 * 判断路径是否相交
 */
#include <stdio.h>

#define True    0
#define False   -1

bool isPathCrossing(char * path)
{
    int cur[2] = {0, 0};
    
}

void test1()
{
    int ret = -1;
    char *path = "";

    ret = isPathCrossing(path);
    printf("ret is %d\n", ret);
}

int main()
{
    test1();

    return 0;
}