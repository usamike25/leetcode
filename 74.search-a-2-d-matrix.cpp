/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // binary search,  but twiche

        // check rows first
        int l = 0, r = matrix.size() - 1;

        while (l < r)
        {
            int m = (r + l) / 2;
            if (matrix[m][0] == target)
            {
                return true;
            }

            if (matrix[m][0] < target && target < matrix[m + 1][0])
            {
                l = m;
                break;
            }
            if (matrix[m][0] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        // check column
        int row = l;
        l = 0;
        r = matrix[0].size() - 1;

        while (l <= r)
        {
            int m = (r + l) / 2;
            if (matrix[row][m] == target)
            {
                return true;
            }
            else if (matrix[row][m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return false;
    }
};
// @lc code=end
