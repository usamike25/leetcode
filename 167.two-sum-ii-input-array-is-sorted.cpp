/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // we use a two pointer solution
        int r = 0;
        int l = numbers.size() - 1;
        vector<int> solution;

        while (r < l)
        {
            if (numbers[r] + numbers[l] == target)
            {
                solution.push_back(r + 1);
                solution.push_back(l + 1);
                break;
            }

            if (numbers[r] + numbers[l] > target)
            {
                l--;
            }
            else
            {
                r++;
            }
        }

        return solution;
    }
};
// @lc code=end
