/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool helper(TreeNode *root, long long min, long long max)
    {

        if (root == NULL)
        {
            return true;
        }

        if (root->val > min && root->val < max)
        {
            return helper(root->left, min, root->val) && helper(root->right, root->val, max);
        }
        else
        {
            return false;
        }
        }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
// @lc code=end
