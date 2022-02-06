#include<bits/stdc++.h>
using namespace std;
class Node
{
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
class Pair{
    public:
    int height;
    int diameter;
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
Pair Fastdiameter(Node*root)
{
    Pair p;
    if(root==NULL)
    {
        p.diameter=p.height=0;
        return p;
    }
    Pair left=Fastdiameter(root->left);
    Pair right=Fastdiameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
    return p;

}

int main(){
Node*root=Build();
Pair p1=Fastdiameter(root);
cout<<p1.diameter<<endl;
cout<<p1.height<<endl;
return 0;
}