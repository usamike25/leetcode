/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // binary search

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int m = (r + l) / 2;

            if (nums[m] == target)
            {
                return m;
            }
            // check where we are
            if (nums[l] <= nums[m]) // left
            {
                if (target > nums[m] || target < nums[l])
                {
                    // search right
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            else // right
            {
                if (target < nums[m] || target > nums[r])
                {
                    // search l
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
