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
        // use a sliding window
        int max_ = 0, l = 0, total = 0;

        map<int, int> hash_map; // key trype, val is count

        for (int r = 0; r < fruits.size(); r++)
        {
            // add r to map
            hash_map[fruits[r]]++;
            total++;

            // check valid map
            while (hash_map.size() > 2)
            {
                // delete l
                hash_map[fruits[l]]--;
                total--;

                // chech if key is 0 and delete
                if (hash_map[fruits[l]] <= 0)
                {
                    hash_map.erase(fruits[l]);
                }
                l++;
            }

            // update max
            max_ = max(max_, total);
        }

        return max_;
    }
};
// @lc code=end
