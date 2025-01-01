#include <bits/stdc++.h>
//? Selection Sort
// Selection sort is a simple sorting algorithm. This sorting algorithm is an in-place comparison-based algorithm in which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty, and the unsorted part is the entire list.
// steps:
// 1. Find the minimum element in the unsorted array.
// 2. Swap the minimum element with the first element of the unsorted array.
// 3. Repeat the above steps for the remaining unsorted array.
// 4. The array is now sorted.
//! Time Complexity: O(n^2)
//! Space Complexity: O(1)

// we can also reverse the selection sort and take the largest element from unsorted array and perform the swap operaton for the last element of the array

#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();

    // we take n-2 becase last elemnt become sorted automatically
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;    
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
    /*
    Time complexity
    Best Case: O(n^2)
    Average Case: O(n^2)
    Worst Case: O(n^2)
    */
}

int main()
{
    vector<int> numbers = {5, 3, 8, 1, 9, 4};

    cout << "Before sorting:" << endl;
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    selectionSort(numbers);

    cout << "After sorting:" << endl;
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}