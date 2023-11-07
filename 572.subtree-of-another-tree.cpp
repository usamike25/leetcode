/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool is_same_tee(TreeNode *root1, TreeNode *root2)
    {

        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        {
            return false;
        }

        return (root1->val == root2->val && is_same_tee(root1->left, root2->left) && is_same_tee(root1->right, root2->right));
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL)
        {
            return true;
        }
        if ((root == NULL && subRoot != NULL) || (root != NULL && subRoot == NULL))
        {
            return false;
        }
        if (is_same_tee(root, subRoot))
        {
            return true;
        }
        else
        {
            return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        }
    }
};
// @lc code=end
