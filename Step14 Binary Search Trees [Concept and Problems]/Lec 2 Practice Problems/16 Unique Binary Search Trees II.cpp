#include<bits/stdc++.h>
using namespace std;

// todo[status: done] https://leetcode.com/problems/unique-binary-search-trees-ii/description/
//*same problem as above but with different constraints
// todo[status: done] https://leetcode.com/problems/unique-binary-search-trees/description/

// please check oneNote
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//*problem 2
//! time complexity: O(n*(4^n/n^1.5)) n*[catalan number]
class SolutionNumber
{
public:
    int fun(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans = 0;
        // considering all element as root node
        for (int i = 1; i <= n; i++)
        {
            ans += fun(i - 1, dp) * fun(n - i, dp);
        }

        return dp[n] = ans;
    }

    int tabu(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        // starting from the 2nd node[1 and 0 are already calculated]
        for (int j = 2; j <= n; j++)
        {
            for (int i = 1; i <= j; i++)
            {
                dp[j] += dp[i - 1] * dp[j - i];
            }
        }
        return dp[n];
    }
    int numTrees(int n)
    {
        // please check oneNote
        //  memorization approach
        //  vector<int> dp(n+1, -1);
        //  return fun(n, dp);

        // tabulation approach
        return tabu(n);
    }
};

//*problem 1
class Solution {
public:
    vector<TreeNode*> allPossibleBST(
        int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        if (memo.find(make_pair(start, end)) != memo.end()) {
            return memo[make_pair(start, end)];
        }
        // Iterate through all values from start to end to construct left and
        // right subtrees recursively.
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubTrees = allPossibleBST(start, i - 1, memo);
            vector<TreeNode*> rightSubTrees = allPossibleBST(i + 1, end, memo);

            // Loop through all left and right subtrees and connect them to the
            // ith root.
            for (auto left : leftSubTrees) {
                for (auto right : rightSubTrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }
        return memo[make_pair(start, end)] = res;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return allPossibleBST(1, n, memo);
    }
};

int main(){
    SolutionNumber s;
    cout<<s.numTrees(3);
    return 0;
}