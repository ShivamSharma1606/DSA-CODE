//todo : [status:done]
/* 
    todo
    I don't know two pointer approach solution exist or not but try to do with two pointer [homework]
*/

class Solution
{
public:
    
    int minInsertions(string s)
    {
        int n = s.size();
        string srev = s;
        reverse(srev.begin(), srev.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == srev[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    int leftTaken = dp[i - 1][j];
                    int rightTaken = dp[i][j - 1];
                    dp[i][j] = max(leftTaken, rightTaken);
                }
            }
        }

        int maxPalindromeSubLength = dp[n][n];
        return n - maxPalindromeSubLength;
    }
};