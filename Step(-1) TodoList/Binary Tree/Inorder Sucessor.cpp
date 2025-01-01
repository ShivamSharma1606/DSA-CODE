void reverseInorder(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node, BinaryTreeNode<int> *&next, BinaryTreeNode<int> *&ans)
{
    if (root == NULL)
    {
        return;
    }
    // First traverse the right subtree.
    reverseInorder(root->right, node, next, ans);

    if (root == node)
    {
        // Then if the current node is the given node, then we already have the last visited node.
        ans = next;
    }

    // Assign this node as the last visited node before going to the left subtree.
    next = root;
    reverseInorder(root->left, node, next, ans);
}

BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    BinaryTreeNode<int> *ans = NULL;
    BinaryTreeNode<int> *next = NULL;
    reverseInorder(root, node, next, ans);

    return ans;
}