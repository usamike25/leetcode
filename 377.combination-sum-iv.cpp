/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution
{

public:
    map<int, int> dp;

    int recursion(vector<int> &nums, int target, int cur)
    {
        // basecase
        if (cur == target)
        {
            return 1;
        }
        if (cur > target)
        {
            return 0;
        }
        // Check if the current sum is already computed
        if (dp.find(cur) != dp.end())
        {
            return dp[cur];
        }

        int a = 0; // Initialize 'a' to accumulate the number of combinations
        for (int i = 0; i < nums.size(); i++)
        {
            a += recursion(nums, target, cur + nums[i]);
        }
        dp[cur] = a; // Memoize the result for the current sum
        return a;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        return recursion(nums, target, 0);
    }
};
// @lc code=end
