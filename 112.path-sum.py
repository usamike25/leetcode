#
# @lc app=leetcode id=112 lang=python3
#
# [112] Path Sum
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:

        # lets use a dfs
        def dfs(root, curr_sum):
            if root == None:
                return False
            
            curr_sum += root.val
            if not root.left and not root.right:
                return curr_sum == targetSum

            return any([dfs(root.left, curr_sum),dfs(root.right, curr_sum)])
        
        return  dfs(root, 0)



        
# @lc code=end

