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
Node*insertInBst(Node*root,int data)
{
    if(root==NULL)
    {
        return new Node(data);
    }
    if(data<=root->data)
    {
        root->left=insertInBst(root->left,data);
    }
    else{
        root->right=insertInBst(root->right,data);
    }
    return root;
}
Node*build()
{
    int d;
    cin>>d;
    Node*root=NULL;
    while(d!=-1)
    {
     root=insertInBst(root,d);
        cin>>d;
    }
    return root;
}
void Display(Node*root)
{
    if(root==NULL)
    {
        return ;

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
Node*root=build();
Display(root);
return 0;
}