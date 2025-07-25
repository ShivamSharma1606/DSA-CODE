#include<bits/stdc++.h>
using namespace std;

//time complexity is o(nlogn) and space complexity is o(n)

// merge function will merge the two sorted arrays
// low to mid and mid+1 to high
// and store the result in the original array
// this will take o(n) time
void merge(vector<int> &arr, int low, int mid, int high)
{

    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}


// it will divide the array into two parts
// and call merge function to merge the two sorted arrays
// this will take o(logn) time
void mSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mSort(arr, low, mid);
    mSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n)
{
    // merge will take o(n)time TC
    // sort will take o(logn) TC HENCE TOTOAL IS NLOGN          
    //  SC is o(n)
    mSort(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    mergeSort(arr, n);
    // print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
