/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        // stack
        stack<char> myStack;

        for (int i = 0; i < s.size(); i++)
        {
            if (myStack.empty())
            {
                myStack.push(s[i]);
                continue;
            }

            if (myStack.top() == '(' and s[i] == ')' || myStack.top() == '[' and s[i] == ']' || myStack.top() == '{' and s[i] == '}')
            {
                myStack.pop();
                continue;
            }
            else
            {
                myStack.push(s[i]);
            }
        }

        return myStack.empty();
    }
};
// @lc code=end
