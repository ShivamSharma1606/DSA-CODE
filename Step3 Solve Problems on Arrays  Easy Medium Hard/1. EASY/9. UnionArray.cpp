#include <bits/stdc++.h>
using namespace std;

// Function to return the count of number of elements in union of two arrays.
int doUnion(int a[], int n, int b[], int m)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        st.insert(b[i]);
    }
    int arr[st.size()] = {0};
    int i = 0;
    for (auto it : st)
    {
        arr[i++] = it;
    }

    return st.size();
}

//optimised approach only suitable for sorted arrays

int fun(vector<int> arr1, vector<int> arr2)
{
    int i = 0, j = 0;
    int count = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            count++;
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            count++;
            j++;
        }
        else
        {
            count++;
            i++;
            j++;
        }
    }
    while (i < arr1.size())
    {
        count++;
        i++;
    }
    while (j < arr2.size())
    {
        count++;
        j++;
    }
    return count;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3};
    cout << doUnion(a, 5, b, 3) << endl;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3};
    cout << fun(arr1, arr2) << endl;
    return 0;
}