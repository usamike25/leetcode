#
# @lc app=leetcode id=40 lang=python3
#
# [40] Combination Sum II
#

# @lc code=start
class Solution:
    candidates = []
    target = 0
    solution = []
    
    def recursion_dfs(self, current_list, i):


        #basecas
        if sum(current_list) == self.target:
            self.solution.append(current_list)
            return
        elif sum(current_list) > self.target:
            return
        elif len(self.candidates) <= i: # i must be smaller
            return

        #recusion

        #include
        self.recursion_dfs(current_list + [self.candidates[i]], i+1)


        #do not include
        i_not_include = i
        value = self.candidates[i]
        while i_not_include < len(self.candidates) and self.candidates[i_not_include] == value:
            i_not_include += 1

        self.recursion_dfs(current_list , i_not_include)




    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        #sort
        self.candidates = sorted(candidates)
        self.target = target
        self.solution = []

        self.recursion_dfs([], 0)

        return self.solution


# @lc code=end

