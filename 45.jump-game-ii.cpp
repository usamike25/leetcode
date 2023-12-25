/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // dynamic programming solution
        int n = nums.size();
        vector<int> minJumps(n, n); // Initialize with a large number representing unreachable
        minJumps[n - 1] = 0;        // No jumps needed for the last element

        for (int i = n - 2; i >= 0; --i)
        {
            int furthestJump = min(i + nums[i], n - 1);
            for (int j = i + 1; j <= furthestJump; ++j)
            {
                minJumps[i] = min(minJumps[i], minJumps[j] + 1);
            }
        }
        return minJumps[0];
    }
};
// @lc code=end
