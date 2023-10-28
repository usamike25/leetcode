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

        int max_seq = 0;
        int cur_seq = 0;
        set<int> nums_set;

        for (int i = 0; i < nums.size(); i++)
        {
            nums_set.insert(nums[i]);
        }

        for (const int &element : nums_set)
        {
            if (nums_set.count(element - 1) == 0)
            {
                cur_seq++;
                int x = 1;
                while (nums_set.count(element + x) != 0)
                {
                    x++;
                    cur_seq++;
                }
                if (cur_seq > max_seq)
                {
                    max_seq = cur_seq;
                }
            }
            cur_seq = 0;
        }
        return max_seq;
    }
};
// @lc code=end
