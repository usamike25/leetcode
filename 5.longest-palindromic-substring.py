#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        solution = ""
        sol_lengt = 0


        #check odd:
        for i in range(len(s)):
            l,r = i,i

            while r < len(s) and l >= 0 and s[r] == s[l]: # r needs to be smaller than len s, because index starts at 0
                
                if (r+1-l) > sol_lengt:
                    solution = s[l:r+1]
                    sol_lengt = (r+1-l)
                l -= 1
                r += 1

            #check even:
            l,r = i,i+1

            while r < len(s) and l >= 0 and s[r] == s[l]:
                if (r+1-l) > sol_lengt:
                    solution = s[l:r+1]
                    sol_lengt = (r+1-l)
                l -= 1
                r += 1

        return solution


        
# @lc code=end

