#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int is_invalid(int v)
{
    return (v < 0 || v > 9);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int v1 = 0;
    int v2 = 0;
    int pos = 0;
    struct ListNode *l = NULL;
    struct ListNode *old = NULL;
    struct ListNode *new = NULL;

    while (l1 || l2)
    {
        v1 = (NULL == l1) ? 0 : (l1->val);
        v2 = (NULL == l2) ? 0 : (l2->val);

        if (is_invalid(v1) || is_invalid(v2))
        {
            // printf("invalid value\n");
            return NULL;
        }

        if (!l)
        {
            l = (struct ListNode *)malloc(sizeof(struct ListNode));
            if (!l)
            {
                // printf("Fail to malloc\n");
                return NULL;
            }
            memset(l, 0, sizeof(struct ListNode));

            l->val = (v1 + v2) % 10;
            l->next = NULL;

            pos = (v1 + v2) / 10;
            old = l;
        }
        else
        {
            new = (struct ListNode *)malloc(sizeof(struct ListNode));
            if (!new)
            {
                // printf("Fail to malloc\n");
                return NULL;
            }
            memset(new, 0, sizeof(struct ListNode));

            old->next = new;

            new->val = (v1 + v2 + pos) % 10;
            new->next = NULL;

            pos = (v1 + v2 + pos) / 10;
            old = new;
        }

        l1 = (NULL == l1) ? NULL : (l1->next);
        l2 = (NULL == l2) ? NULL : (l2->next);
    }

    if (pos)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!new)
        {
            // printf("Fail to malloc\n");
            return NULL;
        }

        old->next = new;

        new->val = pos;
        new->next = NULL;
    }

    return l;
}

void test1()
{
    int i = 0;
    struct ListNode l1[3] = {{2, &l1[1]}, {4, &l1[2]}, {3, NULL}};
    struct ListNode l2[3] = {{5, &l2[1]}, {6, &l2[2]}, {4, NULL}};
    struct ListNode *l = NULL;

    l = addTwoNumbers(&l1[0], &l2[0]);
    while (l)
    {
        printf("[%d] value:%d\n", i, l->val);
        l = l->next;
        i++;
    }
}

void test2()
{
    int i = 0;
    struct ListNode l1[1] = {0, NULL};
    struct ListNode l2[1] = {0, NULL};
    struct ListNode *l = NULL;

    l = addTwoNumbers(&l1[0], &l2[0]);
    while (l)
    {
        printf("[%d] value:%d\n", i, l->val);
        l = l->next;
        i++;
    }
}

void test3()
{
    int i = 0;
    struct ListNode l1[6] = {{9, &l1[1]}, {9, &l1[2]}, {9, &l1[3]}, {9, &l1[4]}, {9, &l1[5]}, {9, NULL}};
    struct ListNode l2[4] = {{9, &l2[1]}, {9, &l2[2]}, {9, &l2[3]}, {9, NULL}};
    struct ListNode *l = NULL;

    l = addTwoNumbers(&l1[0], &l2[0]);
    while (l)
    {
        printf("[%d] value:%d\n", i, l->val);
        l = l->next;
        i++;
    }
}

int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}