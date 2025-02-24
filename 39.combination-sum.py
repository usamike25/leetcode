#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#

# @lc code=start
class Solution:
   

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        return_list = []
        curr_sol = []

        def backtrack(index, cur_sum):
            # basecase
            if cur_sum > target:
                return
            if cur_sum == target:
                return_list.append(curr_sol[:])
                return
            if index >= len(candidates):
                return
            
            # lets add the left solution excluding the current index value
            backtrack(index+1, cur_sum)

            # append current index to solution set
            curr_sol.append(candidates[index])

            # use current index with allready given curr_sol
            backtrack(index, cur_sum + candidates[index])

            # delete from the right, last adde dvalue
            curr_sol.pop()
        
        backtrack(0,0)
        return return_list
            

            



# @lc code=end

