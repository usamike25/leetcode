/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap;
      
        // fill heap
        for (int i = 0; i < stones.size(); i++)
        {
            maxHeap.push(stones[i]);
        }

        // smash stones
        while (maxHeap.size() > 1)
        {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            if (second < first)
            {
                maxHeap.push(first-second);
            }     
        }
        //if there was no element push 0 this will the also be returned
        maxHeap.push(0);
        return maxHeap.top();
    }
};
// @lc code=end
