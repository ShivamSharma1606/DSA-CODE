//? Multiple recursion is a type of recursion where a function makes more than one recursive call to itself in its definition.
// This can lead to a tree-like structure of function calls, where each call can branch into multiple further calls.
// Multiple recursion is often used in problems that can be divided into smaller subproblems, each of which can be solved independently.

// fibonacci series
// tc: O(2^n) and sc: O(n)

#include <bits/stdc++.h>
using namespace std;

int fabonacci(int num)
{

    if (num <= 1)
    {
        return num;
    }

    return fabonacci(num - 1) + fabonacci(num - 2);
}

// Subsequences is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
// Subsequences can be of two types: continuous and non-continuous.

// Subsequence of an array
void print(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// tc: O(2^n) and sc: O(n)
void sub(vector<int> arr, int ind, vector<int> &curr)
{

    if (ind >= arr.size())
    {
        print(curr);
        return;
    }

    // taking the element
    curr.push_back(arr[ind]);
    sub(arr, ind + 1, curr);
    curr.pop_back();

    // not taking the element(backtracking)
    sub(arr, ind + 1, curr);
}

// Print all subsequence whose sum is equal to target
void subtar(vector<int> &arr, int sum, int target, int ind, vector<int> &curr)
{

    if (ind >= arr.size())
    {
        if (sum == target)
        {
            print(curr);
        }
        return;
    }

    // taking the element
    curr.push_back(arr[ind]);
    subtar(arr, sum + arr[ind], target, ind + 1, curr);

    curr.pop_back();
    // not taking the element
    subtar(arr, sum, target, ind + 1, curr);
}

// Print one subsequence whose sum is equal to target
bool subtarone(vector<int> &arr, int sum, int target, int ind, vector<int> &curr)
{

    if (ind >= arr.size())
    {
        if (sum == target)
        {
            print(curr);
            return true;
        }
        return false;
    }

    // taking the element
    curr.push_back(arr[ind]);
    if (subtarone(arr, sum + arr[ind], target, ind + 1, curr))
    {
        return true;
    }

    curr.pop_back();
    // not taking the element
    if (subtarone(arr, sum, target, ind + 1, curr))
    {
        return true;
    }

    return false;
}

// Count the number of subsequence in an array
int subcount(vector<int> &arr, int sum, int target, int ind){
    if(ind == arr.size()){
        if(sum == target){
            return 1;
        }
        return 0;
    }

    // taking the element
    int l = subcount(arr, sum + arr[ind], target, ind + 1);

    // not taking the element
    int r = subcount(arr, sum, target, ind + 1);

    return l + r;
}

int main()
{
    vector<int> arr0 = {1, 2, 1, 0};
    int target1 = 3;
    cout << subcount(arr0, 0, target1, 0) << endl;

    vector<int> arr1 = {1, 2, 1};
    int target = 3;
    vector<int> curr1 = {};
    subtar(arr1, 0, target, 0, curr1);

    int n;
    cin >> n;
    cout << fabonacci(n);
    cout << endl;

    vector<int> arr = {8, 2, 3};
    vector<int> curr = {};
    sub(arr, 0, curr);
    return 0;
}