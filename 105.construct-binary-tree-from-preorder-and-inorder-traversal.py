#
# @lc app=leetcode id=105 lang=python3
#
# [105] Construct Binary Tree from Preorder and Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    #first val is the root in preorder traversal

    # inotder to determine left and right side

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        #basecase no node
        if not preorder or not inorder:
            return None

        root = TreeNode(preorder[0])

        #find pos in inorder array
        m = inorder.index(preorder[0])

        #build subtreees
        root.left = self.buildTree(preorder[1:m+1], inorder[:m])

        root.right = self.buildTree(preorder[m+1:], inorder[m+1:])

        return root







# @lc code=end

