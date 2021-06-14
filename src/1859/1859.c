/*
 * 将句子排序
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_SEQ     1
#define MAX_SEQ     9
#define MIN_STR_LEN 2
#define MAX_STR_LEN 200

int isValidchar(char c)
{
    return ((' ' == c) || ('a' <= c && c <= 'z') 
        || ('A' <= c && c <= 'Z') || ('1' <= c && c <= '9'));
}

char * sortSentence(char * s)
{
    int i = 0;
    int str_len = 0;
    int cur_seq = MIN_SEQ;
    int max_seq = MIN_SEQ;
    char *ret = NULL;
    char *tmp = s;
    int cur_wlen = 0;
    int off = 0;

    if (NULL == s)
    {
        return NULL;
    }

    str_len = strlen(s);
    if (str_len < MIN_STR_LEN || str_len > MAX_STR_LEN)
    {
        return NULL;
    }

    ret = (char *)malloc(sizeof(char) * (str_len + 1));
    if (NULL == ret)
    {
        return NULL;
    }
    memset(ret, 0, sizeof(char) * (str_len + 1));

    ret[str_len] = '\0';

    for (i = 0; i < str_len; i++)
    {
        if (1 != isValidchar(s[i]))
        {
            return NULL;
        }

        if ('1' <= s[i] && s[i] <= '9')
        {
            max_seq = ((s[i] - '0') > max_seq) ? (s[i] - '0') : max_seq;
        }
    }

    for (cur_seq = MIN_SEQ; cur_seq <= max_seq; cur_seq++)
    {
        /* 重新执行时需要恢复初始化！ */
        tmp = s;
        cur_wlen = 0;

        for (i = 0; i < str_len; i++)
        {
            // printf("cur_seq:%d, i:%d, cur_len:%d, off:%d\n", cur_seq, i, cur_wlen, off);

            if (cur_seq == s[i] - '0')
            {
                memcpy(ret + off, tmp, cur_wlen);
                /* 特殊处理最后一个单词 */
                ret[off + cur_wlen] = cur_seq == max_seq ? '\0' : ' ';
                off += cur_wlen + 1;
                break;
            }
        
            if (' ' == s[i])
            {
                tmp = &s[i + 1];
                cur_wlen = 0;
                continue;
            }

            cur_wlen++;
        }
    }

    ret[off] = '\0';

    return ret;
}

void test1()
{
    char *str = "not8 a3 are7 am2 you6 I1 and5 boy4";
    char *ret = NULL;

    ret = sortSentence(str);
    printf("ret:%s\n", ret);

    if (NULL != ret)
    {
        free(ret);
        ret = NULL;
    }
}

int main()
{
    test1();
    return 0;
}