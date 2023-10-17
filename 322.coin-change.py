#
# @lc app=leetcode id=322 lang=python3
#
# [322] Coin Change
#

# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        #bottom up dynamic programming
        dp = [ amount+1] * (amount+1) #init dp and init to max val
        dp[0] = 0 #basecase to get to 0 we use 0 coins


        for a in range(1,amount+1):
            for c in coins:
                #check if not negative
                if a-c >= 0:
                    dp[a] = min(dp[a], 1+dp[a-c])

        return dp[amount] if dp[amount] != amount+1 else -1
         
        
# @lc code=end

