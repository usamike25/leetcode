/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    void inorderTraversal_rec(TreeNode *root, vector<int> &result)
    {
        if (!root)
        {
            return;
        }
        inorderTraversal_rec(root->left, result);
        result.push_back(root->val);
        inorderTraversal_rec(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorderTraversal_rec(root, result);
        return result;
    }
};
// @lc code=end
