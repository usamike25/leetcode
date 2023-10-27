/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{

public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // init array
        vector<int> myArray(nums.size(), 1); // init vector to size len nums and all vals to 1

        int prefix = 1;
        int postfix = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            myArray[i] = prefix;
            prefix *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            myArray[i] *= postfix;
            postfix *= nums[i];
        }
        return myArray;
    }
};
// @lc code=end
