/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //sliding window approch
        int max_ = nums[0];
        int cur_sum = nums[0];
        int l = 0, r = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_ = max(cur_sum, max_);
        }
        return max_;
    }
};
// @lc code=end

