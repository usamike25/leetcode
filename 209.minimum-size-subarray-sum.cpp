/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // use a sliding window
        int left = 0;
        int right;
        int cur_sum;
        int min_len = nums.size() + 1;

        for (left; left < nums.size(); left++)
        {
            cur_sum = nums[left];
            right = left + 1;

            while (right <= nums.size() - 1 && cur_sum < target)
            {
                cur_sum += nums[right];
                right++;
            }
            if(cur_sum >= target){
                min_len = min(min_len, right - left);
            }
        }
        return min_len == nums.size()+1? 0: min_len;
    }
};
// @lc code=end
