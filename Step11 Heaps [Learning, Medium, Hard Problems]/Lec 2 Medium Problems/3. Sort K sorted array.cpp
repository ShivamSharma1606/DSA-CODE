//* brute force approach
/*
1. create a result vector
2. put all the elements of the array in result vector
3. sort the result vector

tc : (n * k)log(n * k)
*/

//* optimal approach
// 1. create a priority queue
// 2. push the first element of all the array in the priority queue
// 3. create a result vector
// 4. pop the top element of the priority queue and push it in the result vector
// 5. push the next element of the array from which the element is popped in the priority queue
// 6. repeat the process till the priority queue is empty
// 7. return the result vector
//! tc : O(n * k * log(k)) and sc : O(k)

#include<bits/stdc++.h>
using namespace std;

struct data{
    public:
    int val;
    int apos; //array position
    int epos; // element position
    
    data(int val, int apos, int epos){
        this->val = val;
        this->apos = apos;
        this->epos = epos;
    }
};

struct comp{
    bool operator()(data a, data b){
        return a.val > b.val;
    }
};

class Solution
{
    //creating the constructor to sort the element of the priority queue
    public:
    
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<data, vector<data>, comp> pq;
        //pushing all the first elment of the nested array
        for(int i = 0; i < k; i++){
            data d(arr[i][0], i, 0);
            pq.push(d);
        }
        
        //vector to store the resultant array
        vector<int> result;
        
        //Finding the minimum from the heap
        while(!pq.empty()){
            data curr = pq.top();
            pq.pop();
            
            int value = curr.val;
            int arrp = curr.apos; //array position
            int elep = curr.epos; //element position
            
            //inserting the minimum value at given time in the array
            result.push_back(value);
            
            //checking the next element of that array exist or not
            if(elep + 1 < arr[arrp].size()){
                data d(arr[arrp][elep + 1], arrp, elep + 1);
                pq.push(d);
            }
        }
        
        return result;
    }
    
    
};

