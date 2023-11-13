/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        set<ListNode *> nodeSet;

        while (headA)
        {
            nodeSet.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (nodeSet.count(headB) > 0)
            {
                return headB;
            }

            headB = headB->next;
        }
        return NULL;
    }
};
// @lc code=end
