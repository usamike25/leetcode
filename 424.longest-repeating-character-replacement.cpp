/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution
{
public:
    int find_max_char(map<char, int> count_map)
    {
        int maxValue = INT_MIN; // Initialize with smallest possible int value

        for (const auto &pair : count_map)
        {
            if (pair.second > maxValue)
            {
                maxValue = pair.second;
            }
        }
        return maxValue;
    }

    int characterReplacement(string s, int k)
    {
        map<char, int> count_map;
        int l = 0;
        int r = 0;

        count_map[s[0]] = 1;
        int cur_len = 1;
        int max_len = 1;
        while (r <= s.size() - 1)
        {

            if (cur_len - find_max_char(count_map) <= k)
            {
                max_len = max(cur_len, max_len);
                cur_len++;
                r++;
                count_map[s[r]]++;
            }
            else
            {
                cur_len--;
                count_map[s[l]]--;
                l++;
            }
        }
        return max_len;
    }
};
// @lc code=end
