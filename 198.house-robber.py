#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        # last tow houses:
        r1, r2 = 0, 0

        #iterate trough houses
        for n in nums:
            #compute max rob up until n
            temp = max(n+r1, r2)
            r1 = r2
            r2 = temp
        return r2

        
# @lc code=end

