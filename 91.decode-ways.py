#
# @lc app=leetcode id=91 lang=python3
#
# [91] Decode Ways
#

# @lc code=start
class Solution:
    def numDecodings(self, s: str) -> int:
        dp = {len(s):1}

        def dfs(i):
            #basecase
            if i in dp:
                return dp[i]
            
            if s[i] == "0":
                return 0

            #singele
            res = dfs(i+1)

            #double
            if i + 1 < len(s) and int(s[i:i+2]) <= 26:
                res += dfs(i + 2)

            dp[i] =  res
            return res

        dfs(0)
        if not 0 in dp.keys():
            return 0
        return dp[0]

# @lc code=end

