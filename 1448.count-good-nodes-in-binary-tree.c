/*
 * @lc app=leetcode id=1448 lang=c
 *
 * [1448] Count Good Nodes in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode *root, int max)
{

    // bs
    if (root == NULL)
    {
        return 0;
    }

    // init res
    int res;

    if (root->val >= max)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }
    if (root->val > max)
    {
        max = root->val;
    }

    res += dfs(root->left, max);
    res += dfs(root->right, max);
    return res;
}

int goodNodes(struct TreeNode *root)
{
    // dfs
    return dfs(root, root->val);
}
// @lc code=end
