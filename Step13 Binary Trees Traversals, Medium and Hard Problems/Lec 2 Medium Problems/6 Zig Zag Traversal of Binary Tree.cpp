//tc: o(n) and sc:o(n)

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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> q;
        bool ltr = true; // left to right
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (ltr) {
                    temp[i] = node->val;
                } else {
                    temp[n - 1 - i] = node->val;
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            result.push_back(temp);
            ltr = !ltr; // flip the flag
        }

        return result;
    }
};

