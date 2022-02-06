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
int FindDistance(Node*root,int end,int distance)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==end)
    {
        return distance;
    }
   int leftlevel= FindDistance(root->left,end,distance+1);
 if(leftlevel!=-1)
 {
     return leftlevel;
 }
 FindDistance(root->right,end,distance+1);
}
Node*LCA(Node*root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a or root->data==b)
    {
        return root;
    }
    Node*leftSide=LCA(root->left,a,b);
    Node*rightSide=LCA(root->right,a,b);
    if(leftSide!=NULL and rightSide!=NULL)
    {
        return root;
    }
    if(leftSide!=NULL)
    {
        return leftSide;
    }
    return rightSide;


}
int distbtwNode(Node*root,int a,int b)
{
    Node*lca=LCA(root,a,b);
    int d1=FindDistance(lca,a,0);
    int d2=FindDistance(lca,b,0);
    return d1+d2;
}
int main(){
    Node*root=Build();
    cout<<distbtwNode(root,4,6);


return 0;
}