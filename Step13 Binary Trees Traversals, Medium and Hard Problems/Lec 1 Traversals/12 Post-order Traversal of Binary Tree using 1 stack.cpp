//todo:  status: Done
//Iterative Post-order Traversal of Binary Tree using 1 stack
//time complexity: O(2n) and space complexity: O(n)


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *left;
    Node *right;

    int data;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> postOrderUsingStack(Node *root){
    vector<int> result;
    stack<Node*> st;
    Node *curr = root;
    st.push(curr);

    while(!st.empty() || curr!=NULL){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            auto temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                result.push_back(temp->data);

                while(! st.empty() && temp == st.top() ->right){
                    temp = st.top();
                    st.pop();
                    result.push_back(temp->data);
                }
            }
            else{
                curr = temp;
            }
        }
    }

    return result;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = postOrderUsingStack(root);
    for(auto x: result){
        cout<<x<<" ";
    }
    return 0;
}