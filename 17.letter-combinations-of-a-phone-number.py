#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#

# @lc code=start
class Solution: 

    # timecomplexity O(n*4^n)
    def letterCombinations(self, digits: str) -> List[str]:
        letter_dict = {2: ["a","b","c"],
        3: ["d","e","f"],
        4: ["g","h","i"],
        5: ["j","k","l"],
        6: ["m","n","o"],
        7: ["p","q","r","s"],
        8: ["t","u","v"],
        9: ["w","x","y","z"]}

        solution = []

        def backtrack(i, current_solution):
            if i >= len(digits):
                solution.append(current_solution)
                return
            
            for letter in letter_dict[int(digits[i])]:
                backtrack(i+1, current_solution+letter)

        backtrack(0,"")

        if solution == [""]:
            return []
        else:
            return solution


        
# @lc code=end

