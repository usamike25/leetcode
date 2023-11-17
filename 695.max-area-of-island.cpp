/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int m, int n, set<pair<int, int>> &visited)
    {
        // check if in bounds
        if (m < 0 || m >= grid.size() || n < 0 || n >= grid[0].size() || grid[m][n] == 0)
        {
            return 0;
        }

        // check if visited

        pair<int, int> pairToCheck = make_pair(m, n);

        if (visited.find(pairToCheck) != visited.end())
        {
            return 0;
        }

        // Adding elements
        visited.insert(make_pair(m, n));

        return 1 + dfs(grid, m + 1, n, visited) + dfs(grid, m - 1, n, visited) + dfs(grid, m, n + 1, visited) + dfs(grid, m, n - 1, visited);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        set<pair<int, int>> visited;

        int max = 0;

        

        for (int m = 0; m < rows; m++)
        {
            for (int n = 0; n < cols; n++)
            {
                // Pair to check
                pair<int, int> pairToCheck = make_pair(m, n);

                if (visited.find(pairToCheck) != visited.end())
                {
                    continue;
                }
                if (grid[m][n] == 0)
                {
                    continue;
                }
                else if (grid[m][n] == 1)
                {
                    int island_size = dfs(grid, m, n, visited);
                    if (island_size > max)
                    {
                        max = island_size;
                    }
                }
            }
        }
        return max;
    }
};
// @lc code=end
