/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // use bfs with a queue

        // also use a set to keep track of fresh oranges

        int time = 0;
        int fresh = 0;
        int result = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // init queue
        queue<pair<int, int>> q;

        // loop to keep track of fresh and add rotten to queue
        for (int m = 0; m < grid.size(); m++)
        {
            for (int n = 0; n < grid[0].size(); n++)
            {
                if (grid[m][n] == 1)
                {
                    fresh++;
                }
                if (grid[m][n] == 2)
                {
                    q.push(make_pair(m, n));
                }
            }
        }

        // run bfs
        while (!q.empty() && fresh > 0)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> frontPair = q.front();
                q.pop();

                for (int j = 0; j < dirs.size(); j++)
                {
                    int x = frontPair.first + dirs[j][0];
                    int y = frontPair.second + dirs[j][1];

                    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1)
                    {
                        continue;
                    }
                    if (grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
            if (!q.empty())
            {
                result++; // Increment time if there are still oranges to rot
            }
        }
        if (fresh == 0)
        {
            return result;
        }
        return -1;
    }
};
// @lc code=end
