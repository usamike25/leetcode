#
# @lc app=leetcode id=647 lang=python3
#
# [647] Palindromic Substrings
#

# @lc code=start
class Solution:
    def countSubstrings(self, s: str) -> int:
        solution = 0


        
        for i in range(len(s)):
            l,r = i,i
            #check odd:
            while l >= 0 and r < len(s) and s[r] == s[l]:
                solution += 1
                l -= 1
                r += 1

            l,r = i,i+1
            #check normel:
            while l >= 0 and r < len(s) and s[r] == s[l]:
                solution += 1
                l -= 1
                r += 1
        
        return solution 

        
# @lc code=end

