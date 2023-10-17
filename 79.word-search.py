#
# @lc app=leetcode id=79 lang=python3
#
# [79] Word Search
#

# @lc code=start
class Solution:
    #time complexity: O(n * m * 4^n)

    def exist(self, board: List[List[str]], word: str) -> bool:
        l_rows, l_columns = len(board), len(board[0])
        path = set()

        def dfs(r,c,i):
            if i == len(word):
                return True
            if r < 0 or c < 0 or r >= l_rows or c >= l_columns or word[i] != board[r][c] or (r,c) in path:
                return False

            path.add((r,c))
            res = (dfs(r+1,c, i+1),dfs(r-1,c, i+1),dfs(r,c+1, i+1),dfs(r,c-1, i+1))
            
            path.remove((r,c))

            return any(res)

        
        for r in range(l_rows):
            for c in range(l_columns):
                if dfs(r,c,0): return True
        
        return False
        
# @lc code=end

