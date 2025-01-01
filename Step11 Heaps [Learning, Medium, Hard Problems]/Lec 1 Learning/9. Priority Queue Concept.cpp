/*
we can convert array into min heap by inserting elements into the priority queue in negative form
and then multiply the element by -1 to get the original element

for example:
we want that our array arr = { 3, 6, 2, 8, 4, 5} act as a min heap
then we can insert elements into the pq[by default priority queue act as max heap] in negative form
pq = { -3, -6, -2, -8, -4, -5} and pq arranges the elements in descending order i.e
pq = { -2, -3, -4, -5, -6, -8}
and then multiply the element by -1 to get the original element
*/ 

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = { 3, 6, 2, 8, 4, 5};
    priority_queue<int> pq;

    for(int i = 0; i < arr.size(); i++){
        pq.push(-arr[i]);
    }

    while(!pq.empty()){
        //! important line
        cout << -pq.top() << " ";
        pq.pop();
    }
    return 0;
}

