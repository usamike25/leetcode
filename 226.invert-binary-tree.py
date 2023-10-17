#
# @lc app=leetcode id=226 lang=python3
#
# [226] Invert Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        #depth first search

        #check base case
        if root is None:
            return None

        #swap
        temp = root.left
        root.left = root.right
        root.right = temp

        self.invertTree(root.right)
        self.invertTree(root.left)
        return root

# @lc code=end

