/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum_rec(TreeNode *root, int targetSum, int cur_sum)
    {
        // basecase
        if (!root)
        {
            return false;
        }

        if (cur_sum + root->val == targetSum && !root->left && !root->right)
        {
            return true;
        }

        return hasPathSum_rec(root->left, targetSum, cur_sum + root->val) || hasPathSum_rec(root->right, targetSum, cur_sum + root->val);
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return hasPathSum_rec(root, targetSum, 0);
    }
};
// @lc code=end
