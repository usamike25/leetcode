/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int max_route(TreeNode *root, int &d)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = max_route(root->left,d);
        int r = max_route(root->right,d);

        if (r + l > d)
        {
            d = r + l;
        }

        return max(r, l) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        int m = max_route(root, d);
        return d;
    }
};
// @lc code=end
