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
void dfs(Node*root,int &sum)
{
    if(root==NULL)
    {
        return;
    }
    sum+=root->data;
    dfs(root->left,sum);
    dfs(root->right,sum);
}
int SumAllNode(Node*root)
{
    int sum=0;
    dfs(root,sum);
    return sum;
}

int main(){
Node*root=Build();
cout<<SumAllNode(root);
return 0;
}