/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> Map;

        // fill map
        for (int i = 0; i < nums.size(); i++)
        {
            Map[nums[i]]++;
        }

        // now lest create a bucket sort
        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto &pair : Map)
        {
            buckets[pair.second].push_back(pair.first);
        }

        // itterate backwards
        vector<int> solution;
        for (int i = buckets.size()-1; i >= 0; i--)
        {
            // basecase
            if (solution.size() >= k)
            {
                break;
            }
            if (!buckets[i].empty())
            {
                solution.insert(solution.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return solution;
    }
};

// @lc code=end
