//todo: https://leetcode.com/problems/min-cost-to-connect-all-points/description/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        
        
        
        int ans = 0;
        while(pq.size() > 1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            ans = ans + f + s ;
            pq.push(f + s);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends