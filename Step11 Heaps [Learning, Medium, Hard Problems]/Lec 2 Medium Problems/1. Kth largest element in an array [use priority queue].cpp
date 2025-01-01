// finding the kth largest element in an array using priority queue

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    *brute force approach 
    is that we sort the array and return the value arr[n - k]
    !time complexity : O(n * logn)

    *better approach:
    1. create the max heap [tc : O(n)]
    2. Extract Max till k [ tc : O( k * logn)]

    !time complexity : O( n + k * logn) = something near O(n)

    *optimal approach:
    done on codestudio
    */


    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq(nums.begin(), nums.end());
        int answer;
        while(k--){
            answer = pq.top();
            pq.pop();
        }

        return answer;
    }
};

//!codestuio approach
#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	//creating the min-heap
	priority_queue<int , vector<int>, greater<int>> pq;

	for(int i = 0; i < size; i++){
		pq.push(arr[i]);
		if(pq.size() > K){
			pq.pop();
		}
	}

	return pq.top();
}