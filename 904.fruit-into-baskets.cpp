/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        // greedy sliding window approach
        int max_ = 0;
   
        map<int, int> fruits_map; // type, count
        int l = 0;

        for (int r = 0; r < fruits.size(); r++)
        {
            fruits_map[fruits[r]]++;
           

            while (fruits_map.size() > 2)
            {
                // shrink
                fruits_map[fruits[l]]--;
                if (fruits_map[fruits[l]] == 0)
                {
                    fruits_map.erase(fruits[l]);
                }
                l++;
            }
            max_ = max(max_, r - l+1);
        }
        return max_;
    }
};
// @lc code=end
