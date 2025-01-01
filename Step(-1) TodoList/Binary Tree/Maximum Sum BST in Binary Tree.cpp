//!Hard Problem 1373: Maximum Sum BST in Binary Tree

//stucture of the tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr, right(nullptr)) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class NodeValues{
public:
    int min, max, size, sum;
    NodeValues(int min, int max, int size, int sum){
        this->min = min;
        this->max = max;
        this->size = size;
        this->sum = sum;
    }
};

class Solution {
public:
    NodeValues finder(TreeNode* root,int &result){
        if(!root){
            return NodeValues(INT_MAX, INT_MIN, 0, 0);
        }
        
        auto left = finder(root->left, result);
        auto right = finder(root->right, result);

        //checking bst
        if(root->val > left.max && root->val < right.min){
            int current_sum = root->val + left.sum + right.sum;
            result = max(result, current_sum);
            return NodeValues(min(root->val,left.min), max(root->val,right.max),left.size+right.size+1,current_sum);
        }
        //if don't satisfy the condition of BST
        return NodeValues(INT_MIN, INT_MAX,max(left.size,right.size),0);
    }
    int maxSumBST(TreeNode* root) {
        int result = 0;
        finder(root, result);
        return result;
    }
};