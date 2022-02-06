//worst case (n^2)
//when n is the number of node in skewed tree

//0(n)+0(n-1)+0(n-2).....
//compute Level=o(n^2)

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
//finding height of binary tree
int findheight(Node*root)
{
    if(root==NULL)
    {
       return 0;
    }
    int rs=findheight(root->left);
    int ls=findheight(root->right);
    return max(rs,ls)+1;
}
//print only one level
void PrintLevel(Node*root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return ;
    }

PrintLevel(root->left,k-1);
PrintLevel(root->right,k-1);
return;
}
void PrintAllLevel(Node*root)
{
    int h=findheight(root);
    for(int i=1;i<=h;i++)
    {
        PrintLevel(root,i);

    }
    return;

}
int main(){
Node*root=Build();
cout<<findheight(root)<<endl;
PrintAllLevel(root);

return 0;
}