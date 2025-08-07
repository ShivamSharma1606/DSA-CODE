// backtracking: is a technique for solving problems incrementally, building candidates to the solutions, and abandoning candidates ("backtracking") as soon as it is determined that they cannot lead to a valid solution.

// print 1 to N with backtracking

#include <bits/stdc++.h>
using namespace std;

void print(int i, int n)
{

    // base case
    if (i > n)
    {
        return;
    }
    cout << i << " ";
    print(i + 1, n);
}

// print 1 to N with backtracking
void printB(int i, int n)
{

    // base case
    if (i < 1)
    {
        return;
    }
    printB(i - 1, n);
    cout << i << " ";
}

// print N to 1 without backtracking
void printf(int n)
{
    // base case
    if (n < 1)
    {
        return;
    }
    cout << n << " ";
    printf(n - 1);
}

// print N to 1 with backtracking
void printfb(int n, int i)
{
    //base case
    if( i > n){
        return;
    }
    printfb(n, i + 1);
    cout << i << " ";
}

int main()
{
    int n;
    cin >> n;
    print(1, n);
    cout << endl;
    printB(n, n);
    cout << endl;
    printf(n);
    cout << endl;
    printfb(n, 1);
    return 0;
}
