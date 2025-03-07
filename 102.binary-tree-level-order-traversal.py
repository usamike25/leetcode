#
# @lc app=leetcode id=102 lang=python3
#
# [102] Binary Tree Level Order Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # lets do a bfs
        q = deque()
        q.append(root)
        res = []

        while len(q) != 0:
            cur_res = []
            for i in range(len(q)):
                curr = q.popleft()
                if curr != None:
                    cur_res.append(curr.val)
                    q.append(curr.left)
                    q.append(curr.right)
            
            res.append(cur_res) if len(cur_res) != 0 else None
        
        return res




