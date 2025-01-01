//Convert min heap to max heap

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void maxHeapify(vector<int> &arr, int i, int size){
        int largest = i;
        int l = 2*i + 1; //left child index
        int r = 2*i + 2; //right child index
    
        if(l < size && arr[l] > arr[largest]){
            largest = l;
        }
        if(r < size && arr[r] > arr[largest]){
            largest = r;
        }
    
        if(i != largest){
            swap(arr[i], arr[largest]);
            maxHeapify(arr, largest, size);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int size){
        //same code of build heap
        for(int i = (size - 2)/2; i >=0; i--){
            maxHeapify(arr, i, size);
        }
    }
    
};

int main(){
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int size = arr.size();
    Solution obj;
    obj.convertMinToMaxHeap(arr, size);
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
