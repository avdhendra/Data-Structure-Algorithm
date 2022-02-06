#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
Node*InsertAtBST(Node*root,int d)
{
    if(root==NULL)
    {
        return new Node(d);
    }
    if(root->data<=d)
    {
        root->left=InsertAtBST(root->left,d);
    }
    if(root->data>d)
    {
        root->right=InsertAtBST(root->right,d);
    }
    return root;
}
Node*DeleteFromNode(Node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    //if No child is there leaf node
    if(root->data==data)
    {
       if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        Node*temp=root->left;
        delete root;
        return temp;
    }
    if(root->right!=NULL && root->left==NULL)
    {
        Node*temp=root->right;
        delete root;
        return temp;
    }
    Node*replace=root->right;
    while(replace->left!=NULL)
    {
        replace=replace->left;

    }
    root->data=replace->data;
    root->right=DeleteFromNode(root->right,replace->data);
    return root;

    }
    if(root->data>data)
    {
        DeleteFromNode(root->left,data);
    }
    else{
        (root->right,data);
        
    }
    
}
int main(){

return 0;
}