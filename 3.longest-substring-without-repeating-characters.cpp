/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }

        unordered_set<char> mySet; // Change set<int> to unordered_set<char>
        int max_length = 0;
        int l = 0, r = 0;

        while (r < s.size())
        {
            // If the character is not in the set, extend the window to the right
            if (mySet.find(s[r]) == mySet.end())
            {
                mySet.insert(s[r]);
                r++;
                max_length = max(max_length, r - l); // Update max_length based on window size
            }
            // If the character is in the set, shrink the window from the left
            else
            {
                mySet.erase(s[l]);
                l++;
            }
        }
        return max_length;
    }
};




// @lc code=end
