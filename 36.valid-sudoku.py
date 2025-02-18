#
# @lc app=leetcode id=36 lang=python3
#
# [36] Valid Sudoku
#

# @lc code=start
class Solution:


    def isValidSudoku(self, board: List[List[str]]) -> bool:

        # this is an O(3n) solution, which reduches to O(N) it uses dictionarys with a lookup of O(1) most of the time in python. and it uses sets whiich have a
        # lookup of O 1 

        col_dict = {} # 0-8
        row_dict = {} # 0-8
        squares_dict = {} # 0-8

        for i in range(9):
            for j in range(9):
                if j not in col_dict.keys():
                    col_dict[j] = set()
                if i not in row_dict.keys():
                    row_dict[i] = set()
                if (i//3,j//3) not in squares_dict.keys():
                    squares_dict[(i//3,j//3)] = set()
                
                if board[i][j] == ".":
                    continue

                
                if board[i][j] in col_dict[j]:
                    return False
                else:
                    col_dict[j].append(board[i][j])

                if board[i][j] in row_dict[i]:
                    return False
                else:
                    row_dict[i].append(board[i][j])

                if board[i][j] in squares_dict[(i//3,j//3)]:
                    return False
                else:
                    squares_dict[(i//3,j//3)].append(board[i][j])
        
        return True
                
                




    
        
# @lc code=end

