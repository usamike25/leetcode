/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        // inorder traversal for bst results in on ordered ascending values

        // iiterative solution
        int n = 0;          // visited elements
        stack<TreeNode*> myStack; // init stack
        TreeNode *curr = root;

        while (curr || !myStack.empty())
        {
            while (curr)
            {
                myStack.push(curr);
                curr = curr->left;
            }
            curr = myStack.top();
            myStack.pop();
            n++;
            if (n == k)
            {
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
    }
};
// @lc code=end
