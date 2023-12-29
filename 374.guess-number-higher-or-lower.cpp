/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        long long l = 1;
        long long r = n;

        while (true)
        {
            long long m = (r + l) / 2;
            if (guess(m) == 0)
            {
                return m;
            }
            else if (guess(m) == -1)
            {
                r = m - 1;
                
            }
            else
            {
                l = m + 1;
            }
        }
    }
};
// @lc code=end
