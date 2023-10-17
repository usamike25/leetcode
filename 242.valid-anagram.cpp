/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        // create map

        map<char, int> char_map_s; // char, amount

        map<char, int> char_map_t; // char, amount

        // fill map
        for (int i = 0; i < s.size(); i++)
        {
            char_map_s[s[i]]++;
            char_map_t[t[i]]++;
        }

        // compare
        return char_map_s == char_map_t;
    }
};
// @lc code=end
