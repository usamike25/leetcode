#
# @lc app=leetcode id=199 lang=python3
#
# [199] Binary Tree Right Side View
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        #use level order traversal BFS
        if not root:
            return []
        res = []
        q = collections.deque()

        #append first
        
        q.append(root)

        while q:
            # add last value to result
            last_val = q[-1]
            res.append(last_val.val)

            #add children
            for i in range(len(q)):
                last = q.popleft()

                if last.left:
                    q.append(last.left)
                if last.right:
                    q.append(last.right)
        
        return res





# @lc code=end

