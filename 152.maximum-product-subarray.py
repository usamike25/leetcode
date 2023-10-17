#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        solution = max(nums) #init to max 
        curMIN, curMAX = 1,1 #init to 1, because it is neutral in multiplications

        for n in nums:
            
            temp_curMAX = curMAX
            curMAX = max(n*curMAX, n*curMIN, n) #new max can be n times min or max or n
            curMIN = min(n*temp_curMAX, n*curMIN, n)

            #update result
            solution = max(solution, curMAX)

        return solution
# @lc code=end

