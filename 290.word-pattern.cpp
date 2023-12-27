/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {

        map<char, string> myMap;
        set<string> mySet;
        int index = 0;

        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;

        

        while (ss >> word)
        {
            words.push_back(word);
        }
        if (pattern.size() != words.size())
        {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++)
        {
            if (!myMap.count(pattern[i]))
            {
                if (mySet.count(words[index]) > 0)
                {
                    return false;
                }
                mySet.insert(words[index]);

                myMap[pattern[i]] = words[index];
            }
            else if (myMap[pattern[i]] != words[index])
            {
                return false;
            }
            index++;
        }

       
        return true;
    }
};
// @lc code=end
