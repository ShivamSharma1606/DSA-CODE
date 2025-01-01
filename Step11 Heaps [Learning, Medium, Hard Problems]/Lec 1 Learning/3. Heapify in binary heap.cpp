//? covertion of violate heap into max/min heap
//? heapify is a process of converting a binary tree into a heap

/*
If we heapify a paticular node then subtree of that will be heapify 
i.e node come to its original position where it has to be but
it is not necessary that whole tree will be heapify to heapify whole tree [if all node are violating]
we need to heapify all the nodes of the tree from bottom to top[build heap code is already there]
not only heapify root node
*/
//it is psecode code-more
void minHeapfiy(vector<int> arr, int i, int size){
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
        swap(arr[i], arr[smallest])
        minHeapfiy(arr, smallest, size);
    }
}