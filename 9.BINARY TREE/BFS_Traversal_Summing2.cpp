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
void Bfs(Node*root,int &sum)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    while(Q.empty()==false)
    {
        Node*n=Q.front();
sum+=n->data;
Q.pop();
if(n->left!=NULL)
{
    Q.push(n->left);

}
if(n->right!=NULL)
{
    Q.push(n->right);
}

}
}
int SumNode(Node*root)
{
int sum=0;
Bfs(root,sum);
return sum;
}
int main(){
Node*root=Build();
cout<<SumNode(root)<<endl;

return 0;
}