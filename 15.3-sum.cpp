/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // sort vector
        sort(nums.begin(), nums.end());
        int k, j;
        vector<vector<int>> res;

        // loop over array
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                // use two pointer approach

                j = i + 1;
                k = nums.size() - 1;
                while (j < k)
                {
                    int s = nums[i] + nums[j] + nums[k];
                    if (s > 0)
                    {
                        k--;
                    }
                    else if (s < 0)
                
                    {
                        j++;
                    }
                    else

                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                        while (j < k && nums[j] == nums[j + 1])
                        {
                            j++;
                        }
                        while (j < k && nums[k] == nums[k - 1])
                        {
                            k--;
                        }
                        j++; // Move past the last encountered unique number
                        k--; // Move past the last encountered unique number
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
