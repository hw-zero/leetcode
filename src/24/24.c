#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *node = NULL;
    struct ListNode *node1 = NULL;
    struct ListNode *node2 = NULL;

    if (NULL == head || NULL == head->next)
    {
        goto end;
    }

    node1 = head;
    node2 = head->next;

    /* note1 */
    head = head->next;

    while (NULL != node1 && NULL != node2)
    {
        if (NULL != node)
        {
            /* note2 */
            node->next = node2;
        }
        node1->next = node2->next;
        node2->next = node1;

        if (NULL == node1->next || NULL == node1->next->next)
        {
            goto end;
        }
        else
        {
            node = node1;
            node2 = node1->next->next;
            node1 = node1->next;
        }
    }

end:
    return head;
}

void test1()
{
    int i = 0;
    struct ListNode *head = NULL;
    struct ListNode list[4] = {{1, &list[1]}, {2, &list[2]}, {3, &list[3]}, {4, NULL}};

    head = swapPairs(&list[0]);

    while (head)
    {
        printf("[%d] %d\n", i, head->val);
        head = head->next;
        i++;
    }
}

int main(void)
{
    test1();

    return 0;
}