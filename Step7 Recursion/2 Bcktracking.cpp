// backtracking: is a technique for solving problems incrementally, building candidates to the solutions, and abandoning candidates ("backtracking") as soon as it is determined that they cannot lead to a valid solution.

//print 1 to N with backtracking

#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    
    //base case
    if(i > n){
        return;
    }
    cout << i << " ";
    print(i + 1, n);
}


// print 1 to N with backtracking
void printB(int i, int n){
    
    //base case
    if(i < 1){
        return;
    }
    printB(i - 1, n);
    cout << i << " ";
}


int main(){
    int n;
    cin >> n;
    print(1, n);
    cout << endl;
    printB(n, n);
    return 0;
}

//print N to 1 without backtracking


// print N to 1 with backtracking