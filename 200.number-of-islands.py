#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#

# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, columns = len(grid), len(grid[0])

        v_matrix = [["0" for _ in range(columns)] for _ in range(rows)]
        

        #bfs!
        def bfs(r,c):

            q = collections.deque()
            v_matrix[r][c] = "1"
            q.append((r,c))

            while q:
                r, c = q.popleft()
                directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
                
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < columns and grid[nr][nc] == "1" and v_matrix[nr][nc] == "0":
                        q.append((nr, nc))
                        v_matrix[nr][nc] = "1"
                 




        #start at top/left
        #r,c = 0,0
        count = 0
        for i in range(rows):
            for x in range(columns):
                if v_matrix[i][x] == "0" and grid[i][x] == "1":
                    bfs(i,x)
                    count += 1
        
        return count




        
# @lc code=end

