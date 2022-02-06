//Inorder Binary Search would always be in ascending order
//always construct bst from inorder if not given convert it

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
//To find next Greater Element of the Root in the o(logn) time
//This will Find the Starting Index of the Right subtree if Exists
int FindNextGreater(int *pre,int start,int end,int key )
{
    int index=end+1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(pre[mid]>key)
        {
            index=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return index;
}
Node*BSTfromPreorder(int* pre,int start,int end)
{
 //Base case for Returning NULL
 if(start>end)
 {
     return NULL;
 }
 //Base case for Leaf Node
 if(start==end)
 {
     return new Node(pre[start]);

 }
 //Build the Tree//When the Tree Just Start
 Node*root=new Node(pre[start]);
 int idx=FindNextGreater(pre,start+1,end,pre[start]);
 root->left=BSTfromPreorder(pre,start+1,idx-1);
 root->right=BSTfromPreorder(pre,idx,end);
 return root;
   

}
void LevelOrder(Node*root)
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
int A[]={15, 10, 8, 12, 20, 16, 25};
int size= sizeof(A)/sizeof(A[0]);
cout<<"Constructing the BST From its Preorder Traversal\n";
Node*root=BSTfromPreorder(A,0,size-1);
LevelOrder(root);


return 0;
}