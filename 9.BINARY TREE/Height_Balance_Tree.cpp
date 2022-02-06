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
class HBpair{
    public:
int height;
int balance;
};
Node*Build()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    Node*n1=new Node(d);
    n1->left=Build();
    n1->right=Build();
    return n1;
}
HBpair heightBalance(Node*root)
{
    HBpair p;
    if(root==NULL)
    {
      p.balance=true;
      p.height=0;
      return p;
    }
    HBpair left=heightBalance(root->left);
    HBpair right=heightBalance(root->right);
    if(abs(left.height-right.height)<=1 && left.balance &&right.balance)
    {
        p.balance=true;
    }
    else{
        p.balance=false;
    }
    return p;
}


int main(){
Node*root=Build();
HBpair p=heightBalance(root);
if(p.balance)
{
    cout<<"Tree is Balance"<<endl;
}
else{
    cout<<"Not Balanced"<<endl;
}

return 0;
}