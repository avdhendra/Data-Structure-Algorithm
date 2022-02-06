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
int ReplaceSum(Node*root)
{
if(root==NULL)
{
    return 0;
}
if(root->left==NULL && root->right==NULL)
{
    return root->data;
}
int lsum=ReplaceSum(root->left);
int rsum=ReplaceSum(root->right);
int temp=root->data;
root->data=lsum+rsum;
return temp+root->data;

}
void PrintLevel(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty())
    {
        Node*n1=Q.front();
        if(n1==NULL)
        {
            cout<<endl;
            Q.pop();
            if(!Q.empty())
            {
                Q.push(NULL);

            }
        }
        else{
            cout<<n1->data<<" ";
            Q.pop();
            if(n1->left!=NULL)
            {
                Q.push(n1->left);
            }
            if(n1->right!=NULL)
            {
                Q.push(n1->right);
            }
        }
    }
}
int main(){
Node*root=Build();
ReplaceSum(root);
PrintLevel(root);
return 0;
}