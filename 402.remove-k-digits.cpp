/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> myStack;
        for (int i = 0; i < num.size(); i++)
        {

            while (k > 0 && myStack.size() != 0 && myStack.top() > num[i])
            {

                myStack.pop();
                k--;
            }

            myStack.push(num[i]);
        }



        //pop for every k that is left
        for (int i = 0; i < k; i++)
        {
            myStack.pop();
            //k--;
        }
        

        //convert stack to string
        string result = "";
        while (!myStack.empty())
        {
            result += myStack.top();
            myStack.pop();
        }

        // reverse
        reverse(result.begin(), result.end());

        //remove leading 0
        while (result[0] == '0')
        {
            result.erase(0, 1);
        }

        return (result == "") ? "0" : result;
    }
};
// @lc code=end
