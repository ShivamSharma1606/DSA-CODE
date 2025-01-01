//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){
        
        vector<int> result(n);
        //creating the min-heap
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //creating the map
        for(int i = 0; i < n; i++){
            pq.push({arr[i], i});
        }
        
        int rank = 1;
        int prevalue = -1;
        
        while(!pq.empty()){
            
            auto it = pq.top();
            int value = it.first;
            int index = it.second;
            pq.pop();
            
            if(value != prevalue){
                prevalue = value;
                result[index] = rank++;
            }
            else{
                result[index] = rank - 1;
            }
            
        }
        
        return result;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends