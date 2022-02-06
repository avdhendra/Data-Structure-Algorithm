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
Node*Build()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    Node*root=new Node(d);
    root->left=Build();
    root->right=Build();
    return root;
}

Node*LCA(Node*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Node*leftAns=LCA(root->left);
    Node*rightAns=LCA(root->right);
    if(leftAns!=NULL and )
}    
int main(){
Node*root=Build();
return 0;
}