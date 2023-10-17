/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> lis(nums.size(), 1); // Initialize all values to 1 as it is the smallest possible val

        for (int i = nums.size() - 2; i >= 0; i--) 
        { // Start from the second last element
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                {
                    lis[i] = max(lis[i], 1 + lis[j]); // Update the lis_map
                }
            }
        }

        return *max_element(lis.begin(), lis.end()); // Find and return the maximum value in lis
    }
};
// @lc code=end
