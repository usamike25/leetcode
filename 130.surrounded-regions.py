#
# @lc app=leetcode id=130 lang=python3
#
# [130] Surrounded Regions
#

# @lc code=start
class Solution:

    


    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        # first scan borders and if an O if found perform DFS and mark as K, then go trough the entire array and change 
        # any o to x and then reverse the K to O again

        def dfs(i, j):
            if i < 0 or j < 0 or i == len(board) or j == len(board[0]) or board[i][j] != "O":
                return

            #change if O
            board[i][j] = "Z"
            dfs(i+1, j)
            dfs(i, j+1)
            dfs(i-1, j)
            dfs(i, j-1)


        for i in range(len(board)): # rows
                for j in range(len(board[0])): # columns
                    if (i == 0 or i == len(board)-1 or j == 0 or j == len(board[0])-1) and board[i][j] == "O":
                        dfs(i, j)

        
        # change O to X
        for i in range(len(board)): # rows
            for j in range(len(board[0])): # columns
                if board[i][j] == "O":
                    board[i][j] = "X"

        #change Z to O
        for i in range(len(board)): # rows
            for j in range(len(board[0])): # columns
                if board[i][j] == "Z":
                    board[i][j] = "O"

                    
        
# @lc code=end

