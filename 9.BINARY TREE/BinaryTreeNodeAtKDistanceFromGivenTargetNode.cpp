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
//we return distance
void PrintKthLevelNode(Node*root,int k)
{
    if(root==NULL)
    {
        return ;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        
    }
    PrintKthLevelNode(root->left,k-1);
    PrintKthLevelNode(root->right,k-1);
    return;
}
int PrintAtDistance(Node*root,Node*target,int k)
{
//Base case
if(root==NULL)
{
    return -1;
}
//reach the Target The Node
if(root==target)
{
    PrintKthLevelNode(target,k);
    //return distance from target node to upper root node
    return 0;
}
//if not so
//traverse in ancestor
int DL=PrintAtDistance(root->left,target,k);
if(DL!=-1)
{
    //Again There are 2 cases
    //Ancestor itself or You Need go to The right ancestor
    if(DL+1==k)
    {
      cout<<root->data<<" ";
    }
    else{
          PrintKthLevelNode(root->right,k-2-DL);
    }
    return 1+DL;
}
int DR=PrintAtDistance(root->right,target,k);
if(DR!=-1)
{
    if(DR+1==k)
    {
        cout<<root->data<<" ";

    }
    else{
        PrintKthLevelNode(root->left,k-1);
    }
    return 1+DR;
}

}
int main(){
Node*root=Build();
Node*target=root->left->left;
PrintAtDistance(root,target,2);
return 0;
}