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

        
        #lets us a bfs



        q = deque()
        output_list = []

        q.append(root)

        while q:

            level = []

            for i in range(len(q)):
                element = q.popleft()
                if element:
                    q.append(element.left)
                    q.append(element.right)
                    level.append(element.val)
            
            if level:
                output_list.append(level)
        
        return output_list