#
# @lc app=leetcode id=572 lang=python3
#
# [572] Subtree of Another Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    #def isSubtree_rec(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]):
    def isSame(self, root1, root2):
        
        # if both nodes are None, return True
        if not root1 and not root2:
            return True

        # if one of them is None, return False
        if not root1 or not root2:
            return False

        # if values don't match, return False
        if root1.val != root2.val:
            return False

        # recursively check left and right subtrees
        return self.isSame(root1.left, root2.left) and self.isSame(root1.right, root2.right)



    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if self.isSame(root, subRoot):
            return True
        else:
            left = False
            if root.left:
                left = self.isSubtree(root.left,subRoot)
            right = False
            if root.right:
                right = self.isSubtree(root.right,subRoot)
            

            return True if left or right else False
        
        
# @lc code=end

