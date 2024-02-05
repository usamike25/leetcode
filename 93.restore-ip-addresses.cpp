/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution
{
public:
    string s;
    vector<string> res;

    bool is_valid_nr(string nr)
    {
        // check leading 0
        bool valid = true;
        int int_i = stoi(string(1, nr[0]));
        if (int_i == 0 && nr.size() != 1)
        {
            valid = false;
        }

        // check if nr is inbound
        int nr_int = stoi(nr);

        if (nr_int > 255)
        {
            valid = false;
        }

        return valid;
    }
    void backtrack(int i, int dots, string curIP)
    {
        // basecase
        if (dots == 4 and i == Solution::s.size())
        {
            // append valid IP
            curIP.pop_back();
            Solution::res.push_back(curIP);
            return;
        }
        if (dots > 4)
        {
            return;
        }

        string nr;

        for (int j = i; j < std::min(i + 3, static_cast<int>(Solution::s.size())); j++)
        {
            nr += Solution::s[j];
            if (is_valid_nr(nr))
            {
                backtrack(j + 1, dots + 1, curIP + nr + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        Solution::s = s;

        if (Solution::s.size() > 12)
        {
            return Solution::res;
        }
        backtrack(0, 0, "");
        return Solution::res;
    }
};
// @lc code=end
