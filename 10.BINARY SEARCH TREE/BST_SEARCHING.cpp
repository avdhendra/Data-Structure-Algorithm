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
    return root;
}
bool Search(Node*root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data<data)
    {
         Search(root->left,data);
    }
    if(root->data>data)
    {
         Search(root->right,data);
    }
    if(root->data==data)
    {
        return true;
    }
}

int main(){
Node*root=Build();
if(Search(root,3))
{
    cout<<"Present "<<endl;
}
else{
    cout<<"Not Presenr"<<endl;
}
return 0;
}