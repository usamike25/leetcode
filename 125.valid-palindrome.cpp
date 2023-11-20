/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        // init two pointers
        int start = 0;
        int end = s.size() - 1;
        while (start <= end)
        {

            // check if not numeric
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }

            // check if the same
            if (tolower(s[start]) == tolower(s[end]))
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
