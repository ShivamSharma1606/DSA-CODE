class Solution {
  public:
    vector<vector<int>> result;
    bool dfs(Node* root, vector<int> &tempVec){
        
        if(root == NULL){
            return true;
        }
        
        tempVec.push_back(root->data);
        
        bool left = dfs(root->left, tempVec);
        bool right = dfs(root->right, tempVec);
        
        if(left && right){
            result.push_back(tempVec);
            tempVec.pop_back();
            return false;
        }
        else{
            tempVec.pop_back();
            return false;
        }
    }
    vector<vector<int>> Paths(Node* root) {
        vector<int> tempVec;
        dfs(root, tempVec);
        return result;
    }
};

//? The above code is a simple recursive code to find all the root to leaf paths in a binary tree. 
//!The time complexity of the code is O(n) and the space complexity is O(h) where h is the height of the tree. 
//The code is simple and easy to understand. The code can be optimized by using a stack or queue to store the path