//BFS Method(Binary First Search)
//C++ using Queue Print Level Of Binary
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
Node*Build()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    Node* root=new Node(d);
    root->left=Build();
    root->right=Build();
    return root;

}
void PrintLevelOrder(Node*root)
{
    //Base Case
    if(root==NULL)
    {
        return;
    }
    //Create an Empty Queue For Level Order Transversal
    queue<Node*>Q;
    //Enqueue Root and Intializing height
    Q.push(root);
    while(Q.empty()==false)
    {
        Node*n=Q.front();
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

int main(){
Node*root=Build();
PrintLevelOrder(root);
return 0;
}