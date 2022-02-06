#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left;
    Node*right;
    int data;
    Node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
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
//preorder call
void PreorderPrint(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreorderPrint(root->left);
    PreorderPrint(root->right);

}
void InOrderPrint(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    InOrderPrint(root->left);
    cout<<root->data<<" ";
    InOrderPrint(root->right);


}
void PostOrderPrint(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    PostOrderPrint(root->left);
    PostOrderPrint(root->right);
    cout<<root->data<<" ";
}
int main(){
    
Node*root=Build();
PreorderPrint(root);
cout<<"\n";
InOrderPrint(root);
cout<<"\n";
PostOrderPrint(root);
return 0;
}