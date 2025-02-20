#
# @lc app=leetcode id=567 lang=python3
#
# [567] Permutation in String
#

# @lc code=start
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l = 0
        r = len(s1) 

        s1_dict = {}
        for e in s1:
            if e not in s1_dict.keys():
                s1_dict[e] = 1
            else:
                s1_dict[e] += 1

        while r <= len(s2):
            sub_str = s2[l:r]

            s1_dict_slice = {}

            for e in sub_str:
                if e not in s1_dict_slice.keys():
                    s1_dict_slice[e] = 1
                else:
                    s1_dict_slice[e] += 1

            if s1_dict == s1_dict_slice:
                return True
            
            l+=1
            r+=1

        return False


        
# @lc code=end

