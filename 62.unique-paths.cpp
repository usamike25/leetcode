/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> grid(m, vector<int>(n));

        for (int row = m - 1; row >= 0; row--)
        {
            for (int col = n - 1; col >= 0; col--)
            {
                if (row + 1 < m && col + 1 < n)
                {
                    grid[row][col] = grid[row + 1][col] + grid[row][col + 1];
                }
                else if (row + 1 >= m && col + 1 < n)
                {
                    grid[row][col] = grid[row][col + 1];
                }

                else if (row + 1 < m && col + 1 >= n)
                {
                    grid[row][col] = grid[row + 1][col];
                }
                else if (row + 1 >= m && col + 1 >= n)
                {
                    grid[row][col] = 1;
                }
            }
        }
        return grid[0][0];
    }
};
// @lc code=end
