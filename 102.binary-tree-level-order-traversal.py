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
        
        #init queue
        q = collections.deque()

        #add first level
        q.append(root)

        list = []
        #while loop
        while q:
            sub_list = []
            len_q = len(q)
            for i in range(len_q):

                pop_item = q.popleft()
                if not pop_item:
                    continue

                if pop_item.left:
                    q.append(pop_item.left)
                if pop_item.right:
                    q.append(pop_item.right)

                sub_list.append(pop_item.val)

            if sub_list:
                list.append(sub_list)

        return list



# @lc code=end

