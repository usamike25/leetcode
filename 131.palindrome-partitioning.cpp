/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
public:
    bool is_palindrome(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void dfs(int i, string &s, vector<vector<string>> &res, vector<string> &cur)
    {
        // basecase
        if (i >= s.size())
        {
            res.push_back(cur);
            return;
        }
        for (int j = i; j < s.size(); j++)
        {
            if (is_palindrome(s, i, j))
            {
                string str = s.substr(i, j - i + 1);

                cur.push_back(str);

                // recursive call
                dfs(j + 1, s, res, cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(0, s, res, cur);
        return res;
    }
};
// @lc code=end
