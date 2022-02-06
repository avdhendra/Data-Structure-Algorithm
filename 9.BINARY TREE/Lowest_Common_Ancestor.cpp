//Find the Lowest Common Ancestor
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
Node*lca(Node*root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a or root->data==b)
    {
        return root;
    }
    Node*leftAns=lca(root->left,a,b);
    Node*rightAns=lca(root->right,a,b);
    if(leftAns!=NULL and rightAns!=NULL)
    {
        return root;
    }
    if(leftAns!=NULL)
    {
        return leftAns;
    }
    return rightAns;

}
int main(){
    Node*root=Build();
int a=7,b=9;
cout<<"LCA OF 4 AND 7 IS  "<<lca(root,6,9)->data;

return 0;
}