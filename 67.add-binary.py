#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
#

# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        carry = 0

        # reverse
        a = a[::-1]
        b = b[::-1]

        # loop
        for i in range(max(len(a), len(b))):
            if i >= len(a):
                a_int = 0
            else:
                a_int = int(a[i])
            if i >= len(b):
                b_int = 0
            else:
               b_int = int(b[i])

            r = a_int+b_int + carry

            carry = 1 if r >= 2 else 0
            res += str(r % 2)
        if carry == 1:
            res += "1"

        return res[::-1]
# @lc code=end

