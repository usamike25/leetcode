#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        solution = []
        
        #dfs 
        subset = []
        def dfs(i):
            #basecase
            if i >= len(nums):
                solution.append(subset.copy())
                return
            
            #create other subsets
            #dfs(i+1)

            subset.append(nums[i])
            dfs(i+1)

            subset.pop()
            dfs(i+1)


        dfs(0)

        return solution


        
# @lc code=end

