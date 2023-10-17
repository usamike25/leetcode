#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

# @lc code=start
class Solution:
    solution = []

    def generateParenthesis_rec(self, n, open_, close_, parenthesis):
        #basecase
        if open_ == n and n == close_+1:
            parenthesis += ")" 
            self.solution.append(parenthesis)
            return

        if n > open_:
            self.generateParenthesis_rec(n,open_+1,close_,parenthesis +"(")

        if open_ > close_:
            self.generateParenthesis_rec(n,open_,close_+1,parenthesis +")")


    def generateParenthesis(self, n: int) -> List[str]:
        self.solution = []
        self.generateParenthesis_rec(n, 0, 0, "")

        res = self.solution
        self.solution = []
        return res
        




        
# @lc code=end

