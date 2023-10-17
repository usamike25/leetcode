#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
class Solution:

    stack = []

    def evalRPN(self, tokens: List[str]) -> int:
        for i in tokens:
            if i not in ['+', '-', '*', '/']:
                self.stack.append(int(i))
            else:
                operator = i
                val2 = self.stack.pop()
                val1 = self.stack.pop()
                if operator == "+":
                    new_val = val1 + val2
                elif operator == "-":
                    new_val = val1 - val2
                elif operator == "*":
                    new_val = val1 * val2
                elif operator == "/":
                    new_val = int(val1 / val2)
                self.stack.append(new_val)

        return self.stack[-1]


# @lc code=end

