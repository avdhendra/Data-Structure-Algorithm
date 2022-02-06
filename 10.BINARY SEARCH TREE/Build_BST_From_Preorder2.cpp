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
//Recursive function to Build a BST from a Preorder Sequeue
Node*BuildBSt(int A[],int size,int min=INT_MIN,int max=INT_MAX)
//Start from the root node (the first element in a preorder sequeue)
//Set the root node range as [-Infinity ,Inifinity] and recur
{
static int pIndex=0;
//BASE CASE
if(pIndex==size)
{
    return NULL;
}
//Return if the Next element of preorder traversal is not in the Valid
//range
int val=A[pIndex];
if(val<min || val>max)
{
    return NULL;
}
//Construct The Root Node and Increment 'PIndex'
Node*root=new Node(val);
pIndex++;
//Since all element in the Left subtree of a bst must be less
//than the root node value set range as [min,val-1] and recur
root->left=BuildBSt(A,size,min,val-1);
/*
Since all element in the right Subtree of a BST Must be greater
than the root node Value set range as [val+1...max ] and recur
*/
root->right=BuildBSt(A,size,val+1,max);

return root;

}
void levelOrder(Node*root)
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
int A[]={15,10,8,12,20,16,25};
int size=sizeof(A)/sizeof(A[0]);
Node*root= BuildBSt(A,size);
levelOrder(root);
return 0;
}