#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
#

# @lc code=start
class MinStack:

    #we implement two stacks one normal stack and one min stack
    

    def __init__(self):
        self.stack = []
        self.min_stack = []
        

    def push(self, val: int) -> None:
        self.stack.append(val)

        if self.min_stack:
            self.min_stack.append(min(self.min_stack[-1],val))
        else:
            self.min_stack.append(val)

    def pop(self) -> None:
        
        self.stack.pop()
        self.min_stack.pop()
        

    def top(self) -> int:
        top = self.stack[-1]
        return top
        

    def getMin(self) -> int:
        top = self.min_stack[-1]
        return top 


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

