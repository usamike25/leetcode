/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution
{
public:
    bool canEatAllBananas(vector<int> &piles, int h, int k)
    {
        int tot_time = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            tot_time += ceil(piles[i] / k);
        }

        return tot_time <= h ? true : false;
    }

    int minEatingSpeedBin(vector<int> &piles, int h, int l, int r)

    {
        if (l == r)
        {
            return
        }

        // bin search solution
        int k = floor((l + r) / 2);
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        // bin search solution
        int l = 0;
        int r = piles.size();

        vector<int> arr(k + 1);
        for (int i = 0; i <= k; i++)
        {
            arr[i] = i;
        }

        return minEatingSpeedBin(piles, h, l, r);
    }
};
// @lc code=end
