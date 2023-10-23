/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int dfs(TreeNode *root, int max_val)
    {
        // basecase
        if (root == NULL)
        {
            return 0;
        }

        if (root->val >= max_val)
        {
            return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        }
        else
        {
            return dfs(root->left, max_val) + dfs(root->right, max_val);
        }
    }

    int goodNodes(TreeNode *root)
    {

        return dfs(root, root->val);
    }
};
// @lc code=end
