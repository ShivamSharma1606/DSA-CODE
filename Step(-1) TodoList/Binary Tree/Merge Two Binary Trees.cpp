//! Important problem merge two bst

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr, right(nullptr)) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* dfs(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)    return nullptr;

        if(!root1)  return root2;
        if(!root2)  return root1;

        TreeNode *root = new TreeNode(root1->val + root2->val);

        root->left = dfs(root1->left, root2->left);
        root->right = dfs(root1->right, root2->right);

        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)    return nullptr;
        return dfs(root1, root2);
    }
};

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    Solution obj;
    TreeNode* root = obj.mergeTrees(root1, root2);

    return 0;
}