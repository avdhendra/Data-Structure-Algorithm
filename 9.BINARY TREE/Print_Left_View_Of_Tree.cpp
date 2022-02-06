#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    int hd;//horizontal distance of the Node
    Node*left;
    Node*right;
    Node(int d)
    {
        data=d;
        hd=INT_MAX;
        left=NULL;
        right=NULL;
    }
};
Node*build()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    Node*root=new Node(d);
    root->left=build();
    root->right=build();
    return root;

}
//Recursive Function to print
//Right view of a binary tree
void RightView(Node*root,int level,int &maxLevel)
{
    //Base case
    if(root==NULL)
    {
        return ;
    }
    //If this is the last Node of its Level
    if(maxLevel<level)
    {
        cout<<root->data<<" ";
        maxLevel=level;
    }
    //Recurs For Right Subtree First
    //Then Left Subtree
    RightView(root->right,level+1,maxLevel);
    RightView(root->left,level+1,maxLevel);
}
//Recursive Function to Print
//Left View of A Binary Tree
void LeftView(Node*root,int level,int &maxLevel)
{
    //base case
    if(root==NULL)
    {
        return;
    }
    //If this is the First Node of its Level
    if(maxLevel<level)
    {
        cout<<root->data<<" ";
        maxLevel=level;
    }
    //Recur for Left Subtree First
    //Then Right Subtree
    LeftView(root->left,level+1,maxLevel);
    LeftView(root->right,level+1,maxLevel);
    
}
void BottomView(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    //Initialize a varibale 'hd' with 0
    //For The root element
    int hd=0;
    //Tree Map which store key value Pair
    //Sorted on key value
    map<int,int>m;
    //Queue to Store tree Nodes in Level
    //Order traversal
    queue<Node*>Q;
    //Assign initialized horizontal distance
    //value to root and add it to the Queue
    root->hd=hd;
    Q.push(root); //
    //Loop Until the queue is empty
    while(!Q.empty())
    {
        Node*temp=Q.front();
        Q.pop(); //dequeue the Item
        //Extract The Horizontal distance value
        //from the dequeued tree Node
        hd=temp->hd;

        //Put the Dequeued Tree Node To TreeMap
        //Having Key as Horizontal Distance .Every 
        //Time We find a node having same horizontal
        //distance we need to replace the data in
        //the Map
        m[hd]=temp->data;
        //if the dequeu node has a left child add
        //it to the queue with a horizontal distance hd-1
        if(temp->left!=NULL)
        {
            temp->left->hd=hd-1;
            Q.push(temp->left);
        }

//If the deque node has a right child ,add
//it to the queue with horizontal distance
//hd+1
if(temp->right!=NULL)
{
    temp->right->hd=hd+1;
    Q.push(temp->right);
}
    }
    //Traverse the map element using the iterator
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
}
void PrintLevel(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<Node*> Q;
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
        else
        {
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
istream &operator>>(istream &is,Node*&root)
{
    root=build();
    return is;
}
 ostream &operator<<(ostream & os ,Node*&root)
{
PrintLevel(root);
return os;
}
int main(){
Node*root=NULL;
cin>>root;

int maxlevel=-1;
//RightView(root,0,maxlevel);
int maxlevel2=-1;
//LeftView(root,0,maxlevel2);
BottomView(root);
return 0;
}