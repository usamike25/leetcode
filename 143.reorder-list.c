/*
 * @lc app=leetcode id=143 lang=c
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode *head)
{
    if (head->next == NULL)
    {
        return;
    }

    // find mid
    struct ListNode *slow = head, *fast = head->next, *mid;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    mid = slow;

    // reverse second half
    struct ListNode *prev = NULL, *curr = mid->next, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    mid->next = NULL;

    // merge lists
    struct ListNode *r = prev;
    struct ListNode *l = head;
    while (r != NULL)
    {
        // perform merge
        struct ListNode *temp1 = l->next;
        struct ListNode *temp2 = r->next;

        l->next = r;
        r->next = temp1;

        l = temp1;
        r = temp2;
    }
}
// @lc code=end
