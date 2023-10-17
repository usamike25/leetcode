#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#

# @lc code=start
class Solution:
    solution = []

    def combinationSum_rec(self, candidates: List[int], target: int, i, current_solution):

        #basecases
        current_sum = sum(current_solution)
        if current_sum == target:
            self.solution.append(list(current_solution))
            return
        if current_sum > target or i >= len(candidates):
            return
        

        #recursive call

        #add i #i is not incremented here!
        
        self.combinationSum_rec(candidates, target, i, current_solution + [candidates[i]])
        # do not add i
        self.combinationSum_rec(candidates, target, i+1, current_solution)



    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        self.solution = []  # Reset the solution list for each call
        self.combinationSum_rec(candidates, target, 0, [])


        return self.solution
# @lc code=end

