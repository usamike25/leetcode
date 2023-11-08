/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int dfs(TreeNode *root)
    {
        // basecase
        if (root == NULL)
        {
            return 1;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
        {
            return -1;
        }
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {
        if (dfs(root) != -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
