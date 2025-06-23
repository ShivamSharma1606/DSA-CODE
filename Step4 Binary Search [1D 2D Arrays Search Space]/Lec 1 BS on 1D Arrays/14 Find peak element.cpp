#include <bits/stdc++.h>
// this code work fine if there is no consecutive duplicate element in the array
int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;
    int low = 1;
    int high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if ((arr[mid] > arr[mid + 1]) && (arr[mid] > arr[mid - 1]))
            return mid;

        else if (arr[mid] > arr[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
}

// pleaes refers to the new code because above code fails in some testcase if there is consecutive duplicate element in the array

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;
        int low = 1;
        int high = n - 2;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // if we are on left part then move to right part
            if (nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                // stay on the same search space becase same multiple element may be possible
                // eg {1,2,4,5,5,5,5}
                high = mid;
            }
        }

        return low;
    }
};