/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> hash_map;
        vector<vector<string>> result;

        // create map
        for (string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            hash_map[key].push_back(s);
        }

        // extract groups
        for (auto &p : hash_map)
        {
            result.push_back(p.second);
        }
        return result;
    }
};
// @lc code=end
