//? Get Min - To find the minimum value from the heap and return it
//? Extract Min - To find the minimum value from the heap and remove from the heap also

// *Get Min
// To find the minimum value from the heap and return it
// return the root element of the heap i.e arr[0]
//! Time Complexity: O(1)
//! Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int getMin(){
    if(size == 0)  return INT_MAX;
    return arr[0];
}


// *Extract Min
// To find the minimum value from the heap and remove from the heap also
// 1. Store the root element in a variable
// 2. Copy the last element of the heap to the root
// 3. Decrease the size of the heap
// 4. Call heapify on the root element
// 5. Return the stored root element
//! Time Complexity: O(log n)
//! Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int extractMin(){
    if(size <= 0)       return INT_MAX;
    if(size == 1){
        size--;
        return arr[0]
    }
    int mini = arr[0];
    swap(arr[0], arr[size-1]);
    size--;
    minHeapify(arr, 0, size);
    return arr[size]; //returning the last element which is already removed from the heap[vector]
}

