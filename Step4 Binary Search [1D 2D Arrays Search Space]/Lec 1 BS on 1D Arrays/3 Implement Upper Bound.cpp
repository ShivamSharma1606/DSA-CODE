#include<bits/stdc++.h>
//upper bound is first number which is greater than given number;
int upperBound(vector<int> &arr, int x, int n){
	int ans=n;
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>x){// only change with lower boud is >= will become >
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return ans;	
}

//! lower bound is first number which is greater than or equal to given number;
//? CPP library function lower_bound does the same thing
int lowerbound = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
int upperbound = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
//? lower_bound and upper_bound are inbuilt functions in C++ STL which are used to find the first element which is greater than or equal to the given element
//?  and the first element which is greater than the given element respectively.

int main(){

}