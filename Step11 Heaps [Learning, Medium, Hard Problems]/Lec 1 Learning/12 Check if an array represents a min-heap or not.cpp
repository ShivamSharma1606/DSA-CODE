//Checking if an array represents a min-heap or not

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i = 0; i < n; i++){
            int parent = arr[i];
            int left = 2*i + 1, right = 2*i + 2;
            if(left < n && parent < arr[left]) {
                return false;
            }

            // Check right child
            if(right < n && parent < arr[right]) {
                return false;
            }   
        }
        
        return true;
    }
};

int main(){
    int arr[] = {90, 15, 10, 7, 12, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    cout<<obj.isMaxHeap(arr, n);
    return 0;
}