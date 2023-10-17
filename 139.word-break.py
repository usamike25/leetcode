#
# @lc app=leetcode id=139 lang=python3
#
# [139] Word Break
#

# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        #dynamic programming bottom up approach

        #chace a true false dict
        dp = [False] * (len(s)+1)
        dp[len(s)] = True
        len_s = len(s)

        # go trough s bottom up
        for i in sorted(range(len(s)), reverse=True):
            
            #check word
            for w in wordDict:
                if (i+ len(w)) <= len_s and s[i:i+len(w)] == w:
                    dp[i] = dp[i+len(w)]
                if dp[i] == True:
                    break

        return dp[0]



        
# @lc code=end

