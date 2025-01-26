/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:

    

    int longestConsecutive(vector<int> &nums)
    {
        // O(n) solution: use a set to store all elements. Then iterate through the set and check if the current element is the start of a sequence. If it is, then keep incrementing the current element and check if the next element is in the set. If it is, then increment the length of the sequence. If it is not, then update the max length of the sequence.
        set<int> s(nums.begin(), nums.end());

        int max_len = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i] - 1) != s.end())
            {
                continue;
            }
            else
            {
                int curr_val = nums[i];
                int curr_len = 1;

                while (s.find(curr_val+1) != s.end())
                {
                    curr_val++;
                    curr_len++;
                }
                max_len = max(max_len, curr_len);
            }
        }

        return max_len;
    }
};
// @lc code=end
