/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution
{
public:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int m, int n)
    {
        // basecase
        if (m < 0 || m >= grid2.size() || n < 0 || n >= grid2[0].size() || grid2[m][n] != 1)
        {
            return true;
        }

        bool res = true;

        // mark it as visited
        grid2[m][n] = 2;

        if (grid1[m][n] == 0)
        {
            res = false;
        }

        // recursive call
        res = dfs(grid1, grid2, m + 1, n) && res;
        res = dfs(grid1, grid2, m - 1, n) && res;
        res = dfs(grid1, grid2, m, n + 1) && res;
        res = dfs(grid1, grid2, m, n - 1) && res;

        
        return res;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int result = 0;

        // loop over grid2
        for (int m = 0; m < grid2.size(); m++)
        {
            for (int n = 0; n < grid2[0].size(); n++)
            {

                if (grid2[m][n] == 1 && dfs(grid1, grid2, m, n))
                {
                    result++;
                }
            }
        }
        return result;
    }
};
// @lc code=end
