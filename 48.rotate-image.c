/*
 * @lc app=leetcode id=48 lang=c
 *
 * [48] Rotate Image
 */

// @lc code=start

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{

    // initialize right and lefft spot
    int l = 0;
    int r = matrixSize - 1;

    // run untill l<r
    while (l < r)
    {
        for (int i = 0; i < r - l; i++) // run loop as many times as the size of the colum or row -1
        {
            // top is equal to l because we have a squares
            int top = l;
            int bottom = r;

            // saver top left
            int temp1 = matrix[top][l + i];

            // move bottom l to top l
            matrix[top][l + i] = matrix[bottom - i][l];

            // move bottom r to bottom l
            matrix[bottom - i][l] = matrix[bottom][r - i];

            // move top right to bottom right
            matrix[bottom][r - i] = matrix[top + i][r];

            // mover top l to top r
            matrix[top + i][r] = temp1;
        }

        //
        r--;
        l++;
    }
}
// @lc code=end
