/*
 * @lc app=leetcode id=73 lang=c
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    int m[matrixSize];
    int n[*matrixColSize];
    // Initialize arrays m and n
    for (int i = 0; i < matrixSize; i++)
        m[i] = 0;
    for (int j = 0; j < *matrixColSize; j++)
        n[j] = 0;

    // go trough matrix
    for (int i = 0; i < matrixSize; i++)
    {

        for (int j = 0; j < *matrixColSize; j++)
        {
            if (matrix[i][j] == 0)
            {
                m[i] = 1;
                n[j] = 1;
            }
        }
    }

    // go trough agin matrix
    for (int i = 0; i < matrixSize; i++)
    {

        if (m[i] == 1)
        {
            for (int j = 0; j < *matrixColSize; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // go trough agin matrix
    for (int j = 0; j < *matrixColSize; j++)
    {

        if (n[j] == 1)
        {
            for (int i = 0; i < matrixSize; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
// @lc code=end
