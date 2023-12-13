/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // two pointers

        int fast = 0;
        int slow = 0;

        // floyds algorithm to detect a cicle!
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (slow == fast)
            {
                break;
            }
        }

        // from where the fast and slow pointer intersect to the beginning of the cycle is the same distance as from the beginning to the beginning of the cicle!
        int slow2 = 0;
        while (true)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow2 == slow)
            {
                return slow;
            }
        }
    }
};
// @lc code=end
