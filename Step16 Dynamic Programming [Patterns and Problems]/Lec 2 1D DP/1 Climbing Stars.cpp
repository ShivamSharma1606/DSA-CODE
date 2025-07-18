class Solution {
public:
    int climbStairs(int n) {
        // //recursive solution
        // if(n==0)    return 1;
        // if(n==1)    return 1;

        // int left=climbStairs(n-1);
        // int right=climbStairs(n-2);

        // return left+right;

        //same as fabonnaci[please refer to that solution]
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];

        }
        int result=dp[n];
        return result;
    }
};