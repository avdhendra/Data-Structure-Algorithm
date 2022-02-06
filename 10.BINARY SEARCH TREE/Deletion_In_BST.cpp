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
    if(d<=root->data)
    {
        root->left=InsertAtBST(root->left,d);

    }
    else{
        root->right=InsertAtBST(root->right,d);

    }
    return root;
}
Node*Build()
{
    int d;
    cin>>d;
    Node*root=NULL;
    while(d!=-1)
    {
        root=InsertAtBST(root,d);
        cin>>d;
    }
}
/*
Given a Binary Search tree and a Key ,This Function delete 
*/
Node*DeleteNode1(Node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    //If the Key to be deleted is smaller than the root
    //key then it lies in left subtree
    if(data<root->data)
    {
        root->left=DeleteNode1(root->left,data);
    }
    //if the key to be deleted is greater than the root 
    //key then it lies in right subtree
    else if(data>root->data)
    {
        root->right=DeleteNode1(root->right,data);

    }
    //if key is same as root key then this the node
    //to be deleted
    else{
        //1. Node with 0 children -leaf Node

        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //2. Case Only 1 Child
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
         // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        while(replace->left!=NULL)
        {
            replace=replace->left;
        }
        // Copy the inorder successor's content to this node
        root->data=replace->data;
        // Delete the inorder successor
        root->right=DeleteNode1(root->right,replace->data);
        return root;
    }

    
}
void PrintLevel(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty())
    {
        Node*n1=Q.front();

    }

}
int main(){
Node*root=Build();
PrintLevel(root);
Node*root1=DeleteNode1(root,6);
PrintLevel(root1);
return 0;
}