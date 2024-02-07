/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> dp_vector;
        dp_vector.push_back(0);
        int last_val = -1;
        // sort
        sort(nums.begin(), nums.end());

        // create map
        map<int, int> freq_map; // nr, #frequency

        for (int i = 0; i < nums.size(); i++)
        {
            freq_map[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (last_val == -1)
            {
                last_val = nums[i];
                dp_vector.push_back(nums[i] * freq_map[nums[i]]);
            }
            else if (last_val == nums[i])
            {
                continue;
            }
            else if (last_val + 1 < nums[i])
            {
                dp_vector.push_back(dp_vector.back() + nums[i] * freq_map[nums[i]]);
            }
            else
            {
                dp_vector.push_back(max(dp_vector.back(), dp_vector[dp_vector.size() - 2] + nums[i] * freq_map[nums[i]]));
            }
            last_val = nums[i];
        }
        return dp_vector.back();
    }
};
// @lc code=end
