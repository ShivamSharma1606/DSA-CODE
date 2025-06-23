#include<bits/stdc++.h>
using namespace std;

//only applicable for square matrix
//modifiecation of code done for non square matrix
//only approach to solve this problem

//TC=O(N*M) AND SC=O(1)
vector<int> spiralMatrix(vector<vector<int>>&arr) {
    vector<int> ans;

    int n=arr.size();
    int m=arr[0].size();

    int left=0,right=m-1;
    int top=0,bottom=n-1;

    while(left<=right&&top<=bottom)   {
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom){
            for (int i = right; i >= left; i--) {
              ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for (int i = bottom; i >= top; i--) {
              ans.push_back(arr[i][left]);
            }
            left++;
        }
    }

    return ans;
    
}



int main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans=spiralMatrix(arr);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}