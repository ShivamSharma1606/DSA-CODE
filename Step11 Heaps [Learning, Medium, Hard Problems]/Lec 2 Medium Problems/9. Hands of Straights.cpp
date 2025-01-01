//! Simple hashing question [done without priority queue]

class Solution {
public:
//! it is not a optimal approach
    bool isNStraightHand(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n % k != 0)  return false;

        //creating the frequency map
        map<int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }

        while(!mpp.empty()){
            auto it = mpp.begin();
            int curr = it->first;

            for(int i = 0; i < k; i++){
                if(mpp[curr + i] == 0 ){
                    return false;
                }
                mpp[curr +i ]--;

                //if the elment have only one element
                if(mpp[curr + i] < 1){
                    mpp.erase(curr + i);
                }
            }
        }

        return true;
    }
};