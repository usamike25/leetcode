/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int m, int n)
    {

        if (m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size() || grid[m][n] == 0)
        {
            return 1;
        }
        if (grid[m][n] == -1)
        {
            return 0;
        }

        grid[m][n] = -1; // mark visited
        return dfs(grid, m + 1, n) + dfs(grid, m - 1, n) + dfs(grid, m, n + 1) + dfs(grid, m, n - 1);
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {

        int result = 0;


        // go trough grid and find island. then run dfs:

        for (int m = 0; m < grid.size(); m++)
        {
            for (int n = 0; n < grid[0].size(); n++)
            {
                if (grid[m][n] == 1)
                {
                    // run dfs
                    result = dfs(grid, m, n);
                    return result;
                }
            }
        }
        return result;
    }
};
// @lc code=end
