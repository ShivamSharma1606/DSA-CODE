//? Multiple recursion is a type of recursion where a function makes more than one recursive call to itself in its definition. 
// This can lead to a tree-like structure of function calls, where each call can branch into multiple further calls. 
// Multiple recursion is often used in problems that can be divided into smaller subproblems, each of which can be solved independently.

// fibonacci series
// tc: O(2^n) and sc: O(n)

#include<bits/stdc++.h>
using namespace std;

int fabonacci(int num){

    if(num <= 1){
        return num;
    }

    return fabonacci(num - 1) + fabonacci( num - 2);
}

// Subsequences is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
// Subsequences can be of two types: continuous and non-continuous.

// Subsequence of an array
void print(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

// tc: O(2^n) and sc: O(n)
void sub(vector<int> arr, int ind, vector<int>&curr){

    if(ind >= arr.size()){
        print(curr);
        return;
    }

    //taking the element
    curr.push_back(arr[ind]);
    sub(arr, ind + 1, curr);
    curr.pop_back();

    //not taking the element(backtracking)
    sub(arr, ind + 1, curr);
}

int main(){
    int n;
    cin >> n;
    cout << fabonacci(n);
    cout << endl;
    
    vector<int> arr = {8, 2, 3};
    vector<int> curr = {};
    sub(arr, 0, curr);
    return 0;
}