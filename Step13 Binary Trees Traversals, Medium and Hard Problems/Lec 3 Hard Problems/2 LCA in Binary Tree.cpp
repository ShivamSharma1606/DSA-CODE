/*
*brute force approach    
!tc: 2(n) and sc: 2(n)

1. first find the path from root to both of the node and store in vector(or any other data structure)
2. after finding path of both node use single pointer on both array and compare their value and store some where if they are same let(ancestor)
3. traverse through array using pointer if both the value in vector are same update the ancestor
4. if value are different then return the last ancestor that is store
*/

//optimal approach

// very intersting dry run in one note task section

//*optimal approach
/*
step 1: if root is null or root is equal to p or root is equal to q then return root
step 2: find the left and right node of the tree
step 3: if left is null then return right
step 4: if right is null then return left
step 5: if both left and right are not null then return root
*/
//!tc: n and sc:n
#include<bits/stdc++.h>
using namespace std;

//structure of the root
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){  
            return root;
        }

        TreeNode* left= lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);

        if(left==NULL){  //our left branch has nothing then our element may be in right
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
};

int main(){
    TreeNode* root= new TreeNode(3);
    root->left= new TreeNode(5);
    root->right= new TreeNode(1);
    root->left->left= new TreeNode(6);
    root->left->right= new TreeNode(2);
    root->right->left= new TreeNode(0);
    root->right->right= new TreeNode(8);
    root->left->right->left= new TreeNode(7);
    root->left->right->right= new TreeNode(4);

    Solution s;
    TreeNode* p= root->left;
    TreeNode* q= root->right;
    TreeNode* ans= s.lowestCommonAncestor(root,p,q);
    cout<<ans->val<<endl;
    return 0;
}