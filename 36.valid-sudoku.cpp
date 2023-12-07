/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        map<int, set<int>> row_map;
        map<int, set<int>> col_map;
        map<pair<int, int>, set<int>> square_map;

        // lets fill the values
        for (int m = 0; m < board.size(); m++) // row
        {
            for (int n = 0; n < board[0].size(); n++) // col
            {
                if (board[m][n] != '.')
                {
                    // check if it is allready  in the set
                    if (row_map[m].find(board[m][n]) == row_map[m].end())
                    {
                        row_map[m].insert(board[m][n]);
                    }
                    else
                    {
                        return false;
                    }

                    if (col_map[n].find(board[m][n]) == col_map[n].end())
                    {
                        col_map[n].insert(board[m][n]);
                    }
                    else
                    {
                        return false;
                    }

                    if (square_map[{m / 3, n / 3}].find(board[m][n]) == square_map[{m / 3, n / 3}].end())
                    {
                        square_map[{m / 3, n / 3}].insert(board[m][n]);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
