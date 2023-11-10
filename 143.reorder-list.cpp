/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head)
    {
        // find fiddle with a fast and a slow pointer
        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now lets create two lists

        ListNode *m = slow->next, *m_next = nullptr, *m_prev = nullptr;
        while (m)
        {
            m_next = m->next;
            m->next = m_prev;
            m_prev = m;
            m = m_next;
        }
        ListNode *head2 = m_prev;
        slow->next = nullptr;

        // merge
        ListNode *p1 = head;
        ListNode *p2 = head2;

        while (p2)
        {
            ListNode *temp1 = p1->next;
            ListNode *temp2 = p2->next;

            p1->next = p2;
            p2->next = temp1;

            p1 = temp1;
            p2 = temp2;
        }
    }
};
// @lc code=end
