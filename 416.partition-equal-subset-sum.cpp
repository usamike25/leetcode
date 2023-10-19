/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // basecase odd nr of nums
        if (accumulate(nums.begin(), nums.end(), 0) % 2 == 1)
        {
            return false;
        }

        // use a bottom up dp approach
        set<int> mySet; // init set

        mySet.insert(0); // insert 0

        int target = accumulate(nums.begin(), nums.end(), 0) / 2;

        // loop trough nums backwards
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // create all possible pairs

            set<int> nextSet; // create a set because w cannot change the set during itteration
            for (auto it = mySet.begin(); it != mySet.end(); ++it)
            {
                nextSet.insert(*it + nums[i]); // it needs dereferencing
                nextSet.insert(*it); // it needs dereferencing
            }
            mySet = nextSet;
        }

        if (mySet.find(target) != mySet.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
