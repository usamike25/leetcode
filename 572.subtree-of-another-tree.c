/*
 * @lc app=leetcode id=572 lang=c
 *
 * [572] Subtree of Another Tree
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

bool same_tree(struct TreeNode *root, struct TreeNode *subRoot)
{
    if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    if ((root == NULL || subRoot == NULL) || (root->val != subRoot->val))
    {
        return false;
    }

    if (root->val == subRoot->val)
    {
        bool l = same_tree(root->left, subRoot->left);
        bool r = same_tree(root->right, subRoot->right);

        if (l == true && r == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot)
{
    // edge cases
    if (subRoot == NULL)
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }

    bool curr = same_tree(root, subRoot);
    if (curr == true)
    {
        return true;
    }
    else
    {
        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);
        if (l == true || r == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
// @lc code=end
