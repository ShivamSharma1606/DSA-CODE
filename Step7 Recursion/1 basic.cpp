// when a function call itself its called recurssion and
// if we have not breaking condition then it will go into infinite loop until specified condition is met
// base condition is the condition which will stop the recursion
// in recursion we have to think in terms of smaller subproblems

#include<bits/stdc++.h>
using namespace std;

//factorial of a number using recursion
//tc: O(n) and sc: O(n) due to function call stack
int factorial(int n){
    // base condition
    if(n == 0 || n == 1){
        return 1;
    }
    // recursive call
    return n * factorial(n - 1);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}

