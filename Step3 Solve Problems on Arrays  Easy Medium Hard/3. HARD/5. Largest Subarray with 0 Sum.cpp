#include<bits/stdc++.h>

// brute force approach
// TC=O(n^2) SC=O(1)
int getLongestZeroSumSubarrayLengthBrute(vector<int> &arr){
    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==0) maxi=max(maxi,j-i+1);
        }
    }
    return maxi;
}

// optimal approach
// TC=O(n) SC=O(n)
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	unordered_map<int ,int> mpp; //because map take more TC
    int n=arr.size();
    int sum=0;
    int maxi=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0)  maxi=i+1;
        else{
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
    }
    return maxi;
	
}

int main(){
    vector<int> arr={15,-2,2,-8,1,7,10,23};
    cout<<getLongestZeroSumSubarrayLength(arr);
    return 0;    
}