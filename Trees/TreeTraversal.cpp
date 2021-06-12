/* TREE TRAVERSALS (INORDER, PREORDER, POSTORDER)
If tree is 1 2 3 4 5 (bfs)
Depth First Traversals:
(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1

Link: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
*/

#include <iostream>
using namespace std;

//tree structure
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->data=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
void preOrder(Node* currNode)
{
    //if leaf node return
    if(currNode==nullptr)
        return;
    //print root
    cout<<currNode->data<<" ";
    //traverse left subtree
    preOrder(currNode->left);
    //traverse right subtree
    preOrder(currNode->right);
}
void postOrder(Node* currNode)
{
    //if leaf node return
    if(currNode==nullptr)
        return;
    //traverse left subtree
    postOrder(currNode->left);
    //traverse right subtree
    postOrder(currNode->right);
    //print root
    cout<<currNode->data<<" ";
}
void inOrder(Node* currNode)
{
    //if leaf node return
    if(currNode==nullptr)
        return;
    //traverse left subtree
    inOrder(currNode->left);
    //print root
    cout<<currNode->data<<" ";
    //traverse right subtree
    inOrder(currNode->right);
}
int main()
{
    //define tree
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    preOrder(root);
    cout << "\nPostorder traversal of binary tree is \n";
    postOrder(root);
    cout << "\nInorder traversal of binary tree is \n";
    inOrder(root);

    return 0;
}
/*
Test Case:
    Input:
    1 2 3 4 5
    Representation:
      1
      /\
     2 3
    /\
    4 5
    Output:
    Preorder traversal of binary tree is
    1 2 4 5 3
    Postorder traversal of binary tree is
    4 5 2 3 1
    Inorder traversal of binary tree is
    4 2 5 1 3

Time Complexity: O(n)
Space Complexity: O(1)
*/
