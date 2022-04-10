#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = NULL;
    struct ListNode *old = NULL;
    struct ListNode *new = NULL;

    if (!l1 && !l2)
    {
        return NULL;
    }

    while (l1 || l2)
    {
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!new)
        {
            return NULL;
        }
        new->val = 0;
        new->next = NULL;

        if (!head)
        {
            head = new;
        }

        if (old)
        {
            old->next = new;
        }

        if (!l1)
        {
            new->val = l2->val;
            l2 = l2->next;
            goto _next;
        }

        if (!l2)
        {
            new->val = l1->val;
            l1 = l1->next;
            goto _next;
        }

        if (l1->val <= l2->val)
        {
            new->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            new->val = l2->val;
            l2 = l2->next;
        }

_next:
        old = new;
    }

    return head;
}