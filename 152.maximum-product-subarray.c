/*
 * @lc app=leetcode id=152 lang=c
 *
 * [152] Maximum Product Subarray
 */
int max(int x, int y)
{

    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int min(int x, int y)
{

    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

// @lc code=start
int maxProduct(int *nums, int numsSize)
{

    int res = nums[0];
    int currentMin = 1;
    int currentMax = 1;

    // set to max int in nums, becaus its the minimum max!
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > res)
        {
            res = nums[i];
        }
    }

    // iterate trough numbers
    for (int i = 0; i < numsSize; i++)
    {
        // handle specal case
        if (nums[i] == 0)
        {
            currentMin = 1;
            currentMax = 1;
            continue;
        }

        // recompute current min and max
        int tempcurrentMin = fmin(fmin(nums[i], nums[i] * currentMin), nums[i] * currentMax); // create temp, becous we need it in current max calculaton
        currentMax = fmax(fmax(nums[i], nums[i] * currentMax), nums[i] * currentMin);
        currentMin = tempcurrentMin;
        res = fmax(res, currentMax);
    }

    return res;
}
// @lc code=end
