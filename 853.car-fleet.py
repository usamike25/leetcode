#
# @lc app=leetcode id=853 lang=python3
#
# [853] Car Fleet
#

# @lc code=start
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        if not position:
            return 0

        #sort 
        pos_speed_list = [(p,s) for p,s in zip(position,speed)]
            
        pos_speed_list = sorted(pos_speed_list, reverse=True)
        
        stack = []
        
        for pos, spd in pos_speed_list:
            stack.append((target-pos)/spd)

            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()
        
        return len(stack)
                


# @lc code=end

