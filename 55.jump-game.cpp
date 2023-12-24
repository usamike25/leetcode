/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // greedy solution O(n)

        // work from the back
        int i = nums.size() - 1;

        for (int x = nums.size() - 2; x >= 0; x--)
        {
            if (nums[x]>= i-x)
            {
                i = x;
            }
        }

        return i == 0 ? true : false;
        }
};
// @lc code=end

