// one note example
// also can be done with dfs traversing

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// width: no of node between two node at a level (plus themself  i.e node(s) + 2)

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        long long ans = 0;
        //queue{node, position}
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            long long mmin = q.front().second; // take the min index for that level
            long long first, last;
            for (int i = 0; i < size; i++)
            {
                // we subtract with mmin because otherwise indexing will be go long to much
                long long curid = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curid;
                if (i == size - 1)
                    last = curid;

                if (node->left)
                    q.push({node->left, curid * 2 + 1});
                if (node->right)
                    q.push({node->right, curid * 2 + 2});
            }
            ans = max(ans, (last - first + 1));
        }

        return ans;
    }
};

int main()
{
}