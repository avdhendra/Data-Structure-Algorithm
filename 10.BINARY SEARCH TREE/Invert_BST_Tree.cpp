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
if(root->data>= d)
{
    root->left=InsertAtBST(root->left,d);
}
else{
    root->right=InsertAtBST(root->right,d);
}
return root;
}
Node*build()
{
    int d;
    cin>>d;
    Node*root=NULL;
    while(d!=-1)
    {
        root=InsertAtBST(root,d);
      cin>>d;
    }
    return root;
}
void InvertBST(Node*root)
{
    //base case if the Tree is Empty
    if(root==NULL)
    {
        return ;
    }
    //Swap Left Subtree with right Subtree
    swap(root->left,root->right);
    //Invert Left Subtree
    InvertBST(root->left);
    //Invert right Subtree
    InvertBST(root->right);
}
void InvertBQ(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node*n=Q.front();
        Q.pop();
        swap(n->left,n->right);
        if(n->left!=NULL)
        {
            Q.push(n->left);
        }
        if(n->right!=NULL)
        {
            Q.push(n->right);
        }
    }

}
int main(){

return 0;
}