//? Build Heap

// Given an random array and we have to convert the array into min heap or max heap
// 1. Start from the right most last non-leaf node
// 2. Call heapify on the node
// 3. Repeat the above steps until the root node
// 4. The array is now a heap

// Dry Run is necessary to understand the concept

//! Time Complexity: O(n)
//! Space Complexity: O(1)

void minHeapify(vector<int>& arr, int i, int size){
    int smallest = i;
    int l = 2*i + 1; //left child index
    int r = 2*i + 2; //right child index

    if(l < size && arr[l] < arr[smallest]){
        smallest = l;
    }
    if(r < size && arr[r] < arr[smallest]){
        smallest = r;
    }

    if(i != smallest){
        swap(arr[i], arr[smallest]);
        minHeapify(arr, smallest, size);
    }
}

//we start iteration from the last non-leaf node

void buildHeap(vector<int>& arr, int size){
    for(int i = (size - 2)/2; i >= 0; i--){
        minHeapify(arr, i, size);
    }
}

