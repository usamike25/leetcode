#
# @lc app=leetcode id=90 lang=python3
#
# [90] Subsets II
#

# @lc code=start
class Solution:

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:

        # sort input n log n
        nums.sort()
        sol = []


        def rec(i, cur_sol):

            if i >= len(nums):
                sol.append(cur_sol)
                return

            # include
            rec(i+1, cur_sol + [nums[i]])

            # not include
            while i+1 < len(nums) and nums[i] == nums[i+1]:
                i += 1

            rec(i+1, cur_sol)
        
        rec(0,[])

        return sol

        