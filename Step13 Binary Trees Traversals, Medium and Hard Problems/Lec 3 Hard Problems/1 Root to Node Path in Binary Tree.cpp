#include <iostream>
#include <vector>
using namespace std;

//todo: [staus: solved] https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
//Check in the solution in todo section or link above
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left != NULL) {
            delete left;
        }
        if (right != NULL) {
            delete right;
        }
    }
};

//!time complexity: O(n) and space complexity: O(h) where h is the height of the tree

bool path(TreeNode<int>* root, int x, vector<int>& result) {
    if (root == NULL) {
        return false;
    }
    result.push_back(root->data);

    if (root->data == x) return true;

    if (path(root->left, x, result) || path(root->right, x, result)) {
		return true;
	}
    result.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int>* root, int x) {
    vector<int> result;
    if (!root) return result;
    path(root, x, result);
    return result;
}

int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);

    int x = 5;
    vector<int> result = pathInATree(root, x);

    for (int val : result) {
        cout << val << " ";
    }

    delete root;
    return 0;
}