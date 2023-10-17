#
# @lc app=leetcode id=739 lang=python3
#
# [739] Daily Temperatures
#

# @lc code=start
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        #use a stack monotonic decreasing stack
        solution = [0] * len(temperatures)
        stack = [] # use tuple (value, index)

        for i in range(len(temperatures)):
            if not stack:
                stack.append((temperatures[i],i))
            else:
                while stack and stack[-1][0] < temperatures[i]:
                    top_stack_val, i_top_stack = stack.pop()
                    solution[i_top_stack] = i - i_top_stack

                stack.append((temperatures[i],i))
        
        return solution



        
# @lc code=end

