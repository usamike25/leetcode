/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int r = height.size() - 1, l = 0; // pointers
        int max = 0;

        while (r > l)
        {
            int area = min(height[l], height[r]) * (r - l);
            if (area > max)
            {
                max = area;
            }
            if (height[l] >= height[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return max;
    }
};
// @lc code=end
