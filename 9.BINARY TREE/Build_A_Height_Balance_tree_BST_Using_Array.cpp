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
Node*SortedArrayToBST(int A[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    Node*root=new Node(mid);
    root->left=SortedArrayToBST(A,start,mid-1);
    root->right=SortedArrayToBST(A,mid+1,end);
    return root;
}
void PrintLevelOrder(Node*root)
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
        Node*n=Q.front();
        if(n==NULL)
        {
            cout<<endl;
            Q.pop();
            if(!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else{
            cout<<n->data<<" ";
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
}
int main(){
    int A[]={1,2,3,4,5,6,7};
    int size=sizeof(A)/sizeof(A[0]);
Node*root=SortedArrayToBST(A,1,size);
PrintLevelOrder(root);
return 0;
}