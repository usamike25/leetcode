#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#

# @lc code=start
class Solution:
   

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        res = []


        # backtrack
        def recursion(i, cur_res):
            if sum(cur_res) > target or i >= len(candidates):
                return
            if sum(cur_res) == target:
                res.append(cur_res)
                return

            
            # continnue with curr index
            recursion(i, cur_res + [candidates[i]])

            # conntinue without curr index
            recursion(i+1, cur_res)
        
        recursion(0,[])
        
        return res




            



# @lc code=end

