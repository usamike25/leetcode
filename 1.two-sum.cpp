/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> solution; // solution vector

        map<int, int> nums_map; // value, key

        // Build the hash table
        for (int i = 0; i < nums.size(); i++)
            if (nums_map.count(target - nums[i])) // count checks key
            {
                return {i, nums_map[target - nums[i]]};
            }
            else
            {
                nums_map[nums[i]] = i;
            }

        return {};
    }
};
// @lc code=end
