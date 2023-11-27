/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode *head)
    {
        // find middele node
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse untill slow pointer
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while (head != slow)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        // find max
        int maximum = 0;
        head = prev;
        while (head != NULL && slow != NULL)
        {
            if (!maximum)
            {
                maximum = head->val + slow->val;
            }
            else
            {
                maximum =max(maximum, head->val + slow->val);
            }
            head = head->next;
            slow = slow->next;
        }
        return maximum;
    }
};
// @lc code=end
