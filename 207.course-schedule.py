#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#

# @lc code=start
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:


        #create dict: course: [prereqs]
        pre_dict = {i:[] for i in range(numCourses)}

        for i in prerequisites:
            c = i[0]
            p = i[1]
            pre_dict[c].append(p)

        #go trough dict with a bfs

        visit_list = []

        def dfs(c):

            #basecases
            if c  in visit_list:
                return False

            if pre_dict[c] == []:
                return True

            visit_list.append(c)

            for p in pre_dict[c]:
                if not dfs(p): return False
            
            visit_list.remove(c)
            pre_dict[c] = []
            return True

        
        for c in range(numCourses):
            if not dfs(c): return False

        return True




# @lc code=end

