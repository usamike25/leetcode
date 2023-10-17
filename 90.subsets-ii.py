#
# @lc app=leetcode id=90 lang=python3
#
# [90] Subsets II
#

# @lc code=start
class Solution:

    solution = []
    nums = []

    def recursion(self, i, current_array):
        #basecase
        if i >= len(self.nums):
            self.solution.append(current_array)
            return


        #to include or not to include
        #include
        self.recursion(i+1, current_array + [self.nums[i]])

        #not include
        i_not_include = i
        value = self.nums[i]
        while self.nums[i_not_include] == value:
            i_not_include += 1
            if i_not_include >= len(self.nums):
                self.solution.append(current_array)
                return

        self.recursion(i_not_include, current_array)


    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        #sort the array
        self.solution = []
        self.nums = sorted(nums)

        self.recursion(0, [])

        return self.solution
        







# @lc code=end

