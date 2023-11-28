/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // basecase
        if (!root)
        {
            return root;
        }

        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // easy scenarion if one child is NULL
            if (!root->left)
            {
                return root->right;
            }
            else if (!root->right)
            {
                return root->left;
            }
            
            // find minimum and run the delete node algo in it
            TreeNode *cur = root->right;
            while (cur->left)
            {
                cur = cur->left;
            }
            root->val = cur->val;
            root->right = deleteNode(root->right, root->val);
            
        }
        return root;
    }
};
// @lc code=end
