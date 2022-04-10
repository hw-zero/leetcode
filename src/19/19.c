#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

/*
 * 需要重点考虑以下情况:
 * 1. 待删除的节点不在链表中
 * 2. 删除第一个节点
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *node = head;
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    if (!head || n < 1 || n > 30)
    {
        // printf("Invalid arg\n");
        return NULL;
    }

    while (n > 0)
    {
        // 待删除的节点不在链表中
        if (NULL == fast)
        {
            return NULL;
        }

        fast = fast->next;
        n--;
    }

    // 删除第一个节点
    if (NULL == fast)
    {
        return head->next;
    }

    while (fast != NULL)
    {
        node = slow;
        fast = fast->next;
        slow = slow->next;
    }

    node->next = node->next->next;

    return head;
}