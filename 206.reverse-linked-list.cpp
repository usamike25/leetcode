/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode *reverseList(ListNode *head)
    {

        // iterative
        ListNode *next;
        ListNode *prev = NULL;

        while (head != NULL) // stop when head is NULL
        {
            next = head->next; // update next
            head->next = prev; // link to previous
            prev = head;       // update previous
            head = next;       // update head
        }
        return prev; // return prev, because head will be NULL
    }
};
// @lc code=end
