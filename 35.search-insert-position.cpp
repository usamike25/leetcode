/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // binary search
        int r = nums.size() - 1;
        int l = 0;
        int m;

        while (r > l)
        {
            m = l + (r - l) / 2;
            if (nums[m] >= target)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        if (nums[r] == target)
        {
            return r;
        }
        else if (nums[r] < target)
        {
            return r + 1;
        }
        else
        {
            return r;
        }
    }
};
// @lc code=end
