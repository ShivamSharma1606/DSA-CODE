// Sum of first n number
#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    //base case
    if(n==0){
        return 0;
    }
    return n + sum(n-1);
}

//factoral of n
int fact(int n){
    //base case
    if(n==1){
        return 1;
    }
    return n * fact(n-1);
}

// Reverse an array
void reverseA(vector<int>& arr, int start, int end){
    
    if(start >= end){
        return;
    }

    swap(arr[start],arr[end]);
    reverseA(arr, start + 1, end - 1);
}

// Reverse array using single argument
void ReverseAs(vector<int> &arr, int i, int n){

    if(n/2 <= i){
        return;
    }
    swap(arr[i], arr[n-1-i]);
    ReverseAs(arr, i + 1, n);
}

// Reverse print an array
void reverseprint(vector<int> &arr){
    int n = arr.size();
    ReverseAs(arr, 0, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return;
}

// Checck whether a string is palindrome or not
bool isPalindrome(string &s, int start, int end){

    if(s[start] != s[end-1]){
        return false;
    }

    //base case
    if(start >= end){
        return true;
    }

    return isPalindrome(s, start + 1, end - 1);
}

//using single argument

int main(){
    int n;
    cin >> n;
    cout << sum(n) << endl;
    cout << fact(n) << endl;
    vector<int> arr = {5,10,2,1};
    reverseprint(arr);
    cout << endl;
    string s1 = "shivam";
    string s2 = "1aba1";
    cout << isPalindrome(s1, 0, 6) << endl;
    cout << isPalindrome(s2, 0, 5) << endl;
    return 0;
}