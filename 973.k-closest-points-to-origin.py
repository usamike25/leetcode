#
# @lc app=leetcode id=973 lang=python3
#
# [973] K Closest Points to Origin
#

# @lc code=start
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        min_h = []
        res = []


        for x, y in points:
            dist = x ** 2 + y ** 2
            min_h.append([dist, x, y])
        
        heapq.heapify(min_h)

        for i in range(k):
            d,x,y = heapq.heappop(min_h)
            res.append([x,y])
        
        return res


        
# @lc code=end


