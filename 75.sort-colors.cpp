/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // bucket sort
        map<int, int> hashMap;
        hashMap[0] = 0;
        hashMap[1] = 0;
        hashMap[2] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            hashMap[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < hashMap[i] ; j++)
            {
                nums[index] = i;
                index++;
            }
        }
        
    }
};
// @lc code=end
