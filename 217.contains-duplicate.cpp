/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // init map
        map<int, int> countMap;

        // loop
        for (int i = 0; i < nums.size(); i++)
        {
            // check if count is bigger than 1
            if (countMap[nums[i]])
            {
                return true;
            }
            countMap[nums[i]]++;
        }
        return false;
    }
};
// @lc code=end
