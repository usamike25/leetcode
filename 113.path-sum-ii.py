#
# @lc app=leetcode id=113 lang=python3
#
# [113] Path Sum II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:

        # dfs again
        res = []

        def dfs(root, path):

            if not root:
                return 

            if not root.left and not root.right and sum(path + [root.val]) == targetSum:
                res.append(path)
                return
            
            dfs(root.right, path + [root.val])
            dfs(root.left, path + [root.val])

        dfs(root, [])
        return res


            
        
# @lc code=end

