/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        // greedy solution

        // first sort -> O(n*log(n))

        // then use two pointers -> O(n)

        sort(people.begin(), people.end());

        int l = 0;
        int r = people.size() - 1;
        int count = 0;

        while (l <= r)
        {
            if (l == r)
            {
                count++;
                break;
            }
            
            if (people[l] + people[r] <= limit)
            {
                count++;
                l++;
                r--;
            }
            else
            {
                count++;
                r--;
            }
            
            
        }
        return count;
    }
};
// @lc code=end
