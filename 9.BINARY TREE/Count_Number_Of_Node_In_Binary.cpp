#include<iostream>
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

int height(Node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(rs,ls)+1;
}
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
int count(Node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 1;

    }
    return count(root->left)+count(root->right)+1;
}
int main()
{
Node*root=Build();
cout<<count(root)<<endl;
cout<<height(root)<<endl;
}