/*
二分搜索

比较绕的是 nums[mid] 比较 target

如果是小于，那么就应该把 mid +1 变成 left，也就是目标值在右边

*/
#include <stdio.h>

int loop_search(int *nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int recursion_binary_search(int *nums, int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    else if (nums[mid] < target)
    {
        return recursion_binary_search(nums, mid + 1, right, target);
    }
    else
    {
        return recursion_binary_search(nums, left, mid - 1, target);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    int target = 4;

    int rst = loop_search(arr, sizeof(arr) / sizeof(arr[0]), target);
    printf("rst = %d\n", rst);

    rst = binary_search(arr, sizeof(arr) / sizeof(arr[0]), target);
    printf("rst = %d\n", rst);

    rst = recursion_binary_search(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, target);
    printf("rst = %d\n", rst);

    return 0;
}
