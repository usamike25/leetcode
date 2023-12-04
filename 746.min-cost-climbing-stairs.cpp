/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // bottom up approach
        cost.push_back(0);
        cost.push_back(0);

        for (int i = cost.size() - 4; i >= 0; i--)
        {
            // calc max cost
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }
        return min(cost[0], cost[1]);
    }
};
// @lc code=end
