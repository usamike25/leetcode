/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution
{
public:
    bool isAlienSorted(std::vector<std::string> &words, std::string order)
    {
        // Create dictionary to store the index of each character in the alien order
        std::map<char, int> alienDict;

        for (int i = 0; i < order.size(); i++)
        {
            alienDict[order[i]] = i;
        }

        // Convert characters in each word to their corresponding indices
        for (std::string &word : words)
        {
            for (char &c : word)
            {
                c = static_cast<char>(alienDict[c]);
            }
        }

        // Check if the vector of words is sorted based on the modified order
        return std::is_sorted(words.begin(), words.end());
    }
};

// @lc code=end
