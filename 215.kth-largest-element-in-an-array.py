#
# @lc app=leetcode id=215 lang=python3
#
# [215] Kth Largest Element in an Array
#

# @lc code=start
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        # solution s
        # sort and go trough list n log n
        # max heap and pop (priority queue) <---
        # with a stak that keeps the largest one on top

        # negate the values to we can use heapq

        nums = [-n for n in nums]
        heapq.heapify(nums)

        res = None

        for i in range(k):
            res = heapq.heappop(nums)

        return -res
            




        
# @lc code=end

