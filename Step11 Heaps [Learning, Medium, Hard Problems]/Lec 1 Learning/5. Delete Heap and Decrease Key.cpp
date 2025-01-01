//? Decrease Key
// To decrease the value of a key at a particular index and maintain the heap property of the heap
// i.e remove the value of that particular index and replace it with the new value 
// and then call heapify so that the heap property is maintained
//! Time Complexity: O(log n)
//! Space Complexity: O(1)


// steps:
// 1. Swap the value of the key with the new value
// 2. Check the parent of the key and if the parent is greater than the key then swap the parent with the key
// 3. Repeat the above step until the parent is smaller than the key or the key reaches the root of the heap
// 4. Return the new value of the key

int parent(int i) { 
    return (i-1)/2; 
}

void decreaseKey(int i, int new_val){
    arr[i] = new_val;
    while(i != 0 && arr[parent(i)] > arr[i]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

//? Delete Key
// To delete a key from the heap
// 1. Decrease the value of the key to INT_MIN
// 2. Call extractMin

//! Time Complexity: O(log n)    
//! Space Complexity: O(1)

void deleteKey(){
    decreaseKey(i, INT_MIN);
    extractMin();
}


