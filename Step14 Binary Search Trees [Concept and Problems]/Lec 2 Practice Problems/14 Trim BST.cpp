// todo:[status done] https://leetcode.com/problems/trim-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST1(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        // If the current node's value is less than low, trim the left subtree
        if (root->val < low) {
            return trimBST1(root->right, low, high);
        }

        // If the current node's value is greater than high, trim the right subtree
        if (root->val > high) {
            return trimBST1(root->left, low, high);
        }

        // Otherwise, recursively trim the left and right subtrees
        root->left = trimBST1(root->left, low, high);
        root->right = trimBST1(root->right, low, high);

        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trimBST1(root, low, high);
        return root;
    }
};