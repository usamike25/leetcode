/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size() - 1;
        bool start = false;

        // Skip the trailing spaces
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }

        // Count the length of the last word
        while (i >= 0 && s[i] != ' ')
        {
            len++;
            i--;
        }
        return len;
        
    }
};
// @lc code=end

