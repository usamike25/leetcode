#
# @lc app=leetcode id=875 lang=python3
#
# [875] Koko Eating Bananas
#

# @lc code=start
class Solution:

    def canEatAllB(self, piles, k, h):
        tot_time =0
        for p in piles:
            tot_time += ceil((p/k))
        
        return True if tot_time <= h else False


    def minEatingSpeedBin(self, piles: List[int], h: int, l, r, arr, cur_min):


        if r  == l:
            return r if self.canEatAllB(piles,r,h) else r + 1

        k = floor((l+r)/2)

        if self.canEatAllB(piles,k,h):
            r = k-1
            cur_min = min(k , cur_min)
        else:
            l = k + 1
        
        return self.minEatingSpeedBin(piles, h, l, r, arr, cur_min)


    

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l =0
        r = max(piles)
        arr = [n for n in range(max(piles))]

        return self.minEatingSpeedBin(piles, h, l,r, arr, max(piles))
       
        
# @lc code=end

