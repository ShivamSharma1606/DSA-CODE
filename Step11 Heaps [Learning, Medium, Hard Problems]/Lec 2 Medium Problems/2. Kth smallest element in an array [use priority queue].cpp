// finding the kth smallest element in an array using priority queue
//tc : O(n * logk) and sc : O(k)

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int n,int k,vector<int> arr)
{
    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }

    return pq.top();
}

int main(){
    int n = 6;
    int k = 3;
    vector<int> arr = { 3, 6, 2, 8, 4, 5};

    cout << kthSmallest(n, k, arr) << endl;
    return 0;
}