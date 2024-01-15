#
# @lc app=leetcode id=191 lang=python3
#
# [191] Number of 1 Bits
#

# @lc code=start
class Solution:
    def hammingWeight(self, n: int) -> int:
        total = 0
        while n:
            total += n % 2
            n = n >> 1 # bitshift to the right by 1


        return total
# @lc code=end

