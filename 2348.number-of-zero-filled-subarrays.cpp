/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long res = 0;
        int cur_len = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                cur_len++;
                res += cur_len;
            }
            else
            {
                cur_len = 0;
            }
        }
        return res;
    }
};
// @lc code=end
