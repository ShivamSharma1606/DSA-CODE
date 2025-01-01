class Solution {
public:
    //todo : do with two pointer approach
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        vector<int> result;
        
        priority_queue<pair<int, int>> pq;

        for(auto it: arr){
            pq.push({abs(x - it), it});
            if(pq.size() > k){
                pq.pop();
            }
        }

        for(int i = 0; i < k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};