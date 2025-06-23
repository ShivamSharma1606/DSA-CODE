#include <bits/stdc++.h>
using namespace std;

//tc is o(n^2) in worst case and o(nlogn) in average case
// quick will take o(n)time TC
// pivot will take o(logn) TC
// SC is o(1)

int pivotIndex(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right)
    {
        while (arr[left] <= pivot && left <= high - 1)
        {
            left++;
        }
        while (arr[right] > pivot && right >= low + 1)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[low], arr[right]);
    return right;
}

void quickS(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = pivotIndex(arr, low, high);
        quickS(arr, low, pivot - 1);
        quickS(arr, pivot + 1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    quickS(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {3, 4, 5, 2, 1};
    arr = quickSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
