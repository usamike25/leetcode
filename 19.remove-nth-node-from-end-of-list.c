/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
// /**
//  * Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     struct ListNode *next;
// };

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    if (head == NULL)
        return NULL;
    // go trough list and update two pointers
    struct ListNode *r = head;
    struct ListNode *l = head;
    // init r
    struct ListNode *temp = head;

    while (n > 0 && temp != NULL)
    {
        temp = temp->next;
        n--;
    }
    if (temp == NULL)
    {
        // This means we need to delete the head.
        head = head->next;
        return head;
    }5

    // for (int i = 0; i < n; i++)
    // {
    //     temp = head->next;
    // }
    r = temp;
    // temp = head;

    // go trough list
    while (r->next != NULL)
    {
        r = r->next;
        l = l->next;
    }

    // remove node
    l->next = l->next->next;

    return head;
}
// @lc code=end
