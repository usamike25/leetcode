/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // write binary search

        int r = nums.size() - 1;
        int l = 0;

        while (r > l)
        {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
            {
                r = m;
            }
            if (nums[m] < target)
            {
                l = m + 1;
            }
        }
        if (nums[r] == target)
        {
            return r;
        }

        else
        {

            return -1;
        }
    }
};
// @lc code=end
