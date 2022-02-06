//Find the Diameter of the Tree
/*
A Diameter of A tree is the Number of Node on the Longest Path
b/w two end Nodes 
*/

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
//Function to create a new Node of tree and returns pointer

Node*build()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    Node*n1=new Node(d);
    n1->left=build();
    n1->right=build();
    
    return n1;
}
//Function to Compute the height of a tree
int height(Node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);

return max(ls,rs)+1;

}
//function to get Diameter of a binary tree
int diameter(Node*root)
{
    //base case where tree is empty 
    if(root==NULL)
    {
        return 0;
    }
    //get the height of left and right sub-trees
    int lh=height(root->left);
    int rh=height(root->right);
//get the diameter of left and right subtree
    int dl=diameter(root->left);
    int dh=diameter(root->right);
//Return max of following three
//1) diameter of left subtree
//2) diameter of right subtree
//3) diameter of right subtree+leftsubtree+1(root)

    return max(lh+rh,max(dl,dh));


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
        Node*d=Q.front();
        if(d==NULL)
        {
            cout<<endl;
            Q.pop();
            if(!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else{
            cout<<d->data<<" ";
            Q.pop();
            if(d->left!=NULL)
            {
                Q.push(d->left);

            }
            if(d->right!=NULL)
            {
                Q.push(d->right);
            }

        }
    }
}


int main(){
    Node*root=build();
    cout<<"Height of the given Binary Tree : "<<height(root)<<endl;
    cout<<"Diameter of The given Binary Tree"<<diameter(root)<<endl;
PrintLevel(root);
    

return 0;
}
