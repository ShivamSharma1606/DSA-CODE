//todo : [status:done]

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // indexing is increased by 1[for reason go to dp-25 vs code]

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    int leftTaken = dp[i - 1][j];
                    int rightTaken = dp[i][j - 1];
                    dp[i][j] = max(leftTaken, rightTaken);
                }
            }
        }

        // length of maximum subsequence is
        int k = dp[n][m];
        int delOperation = n - k;
        int insertOperation = m - k;
        return delOperation + insertOperation;
    }
};