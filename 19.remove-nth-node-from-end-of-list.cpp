/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next)
        {
            return NULL;
        }

        // dummy node, two pointers
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        //init pointers
        ListNode *l = dummy;
        ListNode *r = head;

        for (int i = 0; i < n; i++)
        {
            r = r->next;
        }

        // find node
        while (r != NULL)
        {
            r = r->next;
            l = l->next;
        }

        // replace node
        l->next = l->next->next;
        return dummy->next;
    }
};
// @lc code=end
