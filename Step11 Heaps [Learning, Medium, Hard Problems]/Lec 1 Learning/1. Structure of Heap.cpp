//structure of min-Heap

//* I am doing with class but we can also do with stuctue

class Heap(){
    private:
    int size = 0;
    int capacity = 0;
    int *arr;

    public:
    //creating the constructor
    Heap(int capacity){
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    int left(int ind){
        return (2*ind + 1);
    }
    int right(int ind){
        return (2*ind + 2);
    }
    int parent(int ind){
        return ((ind - 1) / 2);
    }
};

//? More functionality of heaps are:

ExtractMin(){

}

MinHeapify(){

}

DecreaseKey(){

}

BuildHeap(){

}

GetMin(){

}

Delete(){
    
}