#include <bits/stdc++.h>

vector<int> nextGreaterPermutation(vector<int> &arr)
{
    int index = -1;
    int n = arr.size();
    for (int i = n - 2; i > 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    else
    {
        for (int i = n - 1; i > index; i--)
        {
            if (arr[i] > arr[index])
            {
                swap(arr[index], arr[i]);
                break;
            }
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

int main()
{
}