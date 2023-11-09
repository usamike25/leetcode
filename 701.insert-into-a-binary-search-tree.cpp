/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        
        // itterative solution
        TreeNode *head = root;
        TreeNode *last = root;
        TreeNode *insert = new TreeNode(val);

        while (root != NULL)
        {
            if (root->val > val)
            {
                last = root;
                root = root->left;
            }
            else
            {
                last = root;
                root = root->right;
            }
        }
        if (last == NULL)
        {
            return insert;
        }

        if (last->val > val)
        {
            last->left = insert;
        }
        else
        {
            last->right = insert;
        }

        return head;
    }
};
// @lc code=end
