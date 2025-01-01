class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> banset(banned.begin(), banned.end());

        int count = 0;

        for(int i = 1; i <= n; i++){
            if(banset.count(i))   continue;

            if(maxSum - i < 0)  return count;

            maxSum -= i;
            count++;
        }

        return count;
    }
};