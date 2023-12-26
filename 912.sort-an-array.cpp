/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        if (low >= high)
            return;

        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);

        while (l <= mid and r <= high)
        {
            if (nums[l] < nums[r])
                sorted[k++] = nums[l++];
            else
                sorted[k++] = nums[r++];
        }

        while (l <= mid)
            sorted[k++] = nums[l++];
        while (r <= high)
            sorted[k++] = nums[r++];

        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
    }

     

    void mergeSort(vector<int> &arr, int l, int r)
    {
        // basecase if there is only one left
        if (l == r)
        {
            return ;
        }
        else
        {
            // run merge on left and rightside
            int m = (l + r) / 2; // integer devision

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
            return ;
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        // O(n*log(n))
        // mergesort, heapsort, quicksort(only best time)

        // merge sort:
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
