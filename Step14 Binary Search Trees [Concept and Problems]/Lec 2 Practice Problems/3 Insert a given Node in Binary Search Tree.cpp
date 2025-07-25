//tc: log(base2) n and sc: 1
// their can be multiple answer we return one of them

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
    //answer tree , root will be return
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode *curr=root; // copy root in curr beacuse we do operation on curr so its value will be change

        while(true){
            if(curr->val<val){
                if(curr->right!=NULL){
                    curr=curr->right;
                }
                else{
                    curr->right= new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left!=NULL){
                    curr=curr->left;
                }else{
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};