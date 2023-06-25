#include <stdbool.h>
/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
#define MAX 9223372036854775807
#define MIN -9223372036854775808

bool isValidBSThelper(struct TreeNode *root, long int left, long int right)
{
    if (root == NULL)
    {
        return true;
    }

    // do checks
    if (root->val < right && root->val > left)
    {

        bool l = isValidBSThelper(root->left, left, root->val);
        bool r = isValidBSThelper(root->right, root->val, right);
        return l && r;
    }
    else
    {
        return false;
    }
}

bool isValidBST(struct TreeNode *root)
{
    // depth first search

    // te left and right boundary of root are + - inf inity we use a long int, since the max int val is a testcase
    return isValidBSThelper(root, MIN, MAX);
}
// @lc code=end
