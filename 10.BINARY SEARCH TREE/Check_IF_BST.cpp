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
Node*InsertAt(Node*root,int d)
{
    if(root==NULL)
    {
        return new Node(d);
    }
    if(root->data>d)
    {
        root->left=InsertAt(root->left,d);
    }

    if(root->data<d)
    {
        root->right=InsertAt(root->right,d);
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
        root=InsertAt(root,d);
        cin>>d;
    }
    return root;
}
bool isBst(Node*root,int min=INT_MIN,int max=INT_MAX)
{
    if(root==NULL)
    {
        return false;
    }
    if(min<=root->data && root->data<=max && isBst(root->left,min,root->data)&& isBst(root->right,root->data,min))
    {
        return true;
    }
    return false;
}
int main(){
Node*root=build();
if(isBst(root))
{
    cout<<"IS BST TREE"<<endl;
}
else{
    cout<<"IS NOT THE BST TREE"<<endl;
}
return 0;
}