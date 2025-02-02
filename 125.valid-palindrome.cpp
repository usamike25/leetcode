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
        // using two poimters
        int l = 0;
        int r = s.size() - 1;


        while (l != r && l < r)
        {
            if (!isalnum(s[l]))
            {
                l++;
                continue;
            }
            else if (!isalnum(s[r]))
            {
                r--;
                continue;
            }

            else if (tolower(s[l])!= tolower(s[r]))
            {
                return false;
            }
            else
            {
                l++;
                r--;
            }
        }

        return true;
    }
};
// @lc code=end
