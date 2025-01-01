// top k frequent elements

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        //creating the map tc: o(n)
        for(auto &it: nums){
            mpp[it]++;
        }

        priority_queue<pair<int,int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;

        for(auto[x, y]: mpp){
            pq.push({y, x});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> result;
        for(int i = 0; i < k; i++){
            auto it = pq.top();
            result.push_back(it.second);
            pq.pop();
        }

        return result;
    }
};

