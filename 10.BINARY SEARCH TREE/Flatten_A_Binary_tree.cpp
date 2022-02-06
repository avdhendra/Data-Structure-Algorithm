#include<bits/stdc++.h>
using namespace std;
class Binary{
    public:
    int data;
    Binary*left;
    Binary*right;
    Binary(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
Binary*Build()
{
    int d;
    cin>>d;
    while(d==-1)
    {
        
    }
}
class LinkedList{
    public:
    Binary*head;
    Binary*tail;

};
LinkedList flatten(Binary*root)
{
    LinkedList l;
    if(root==NULL)
    {
        l.head=l.tail=NULL;
        return l;
    }
    if(root->left==NULL && root->right==NULL)
    {
        l.head=l.tail=root;
        return l;
    }
    //if Left is Not NULL
    if(root->left!=NULL && root->right==NULL)
    {
        LinkedList leftLL=flatten(root->left);
        leftLL.tail->right=root;
        l.head=leftLL.head;
        l.tail=root;
        return l;
    }
    // Right is Not NULL
    if(root->left==NULL && root->right!=NULL)
    {
        LinkedList rightll=flatten(root->right);
        root->right=rightll.head;

        l.head=root;
        l.tail=rightll.tail;
        return l;
    }
    //Both Side are Not NULL
    LinkedList leftll=flatten(root->left);
    LinkedList rightLL=flatten(root->right);
    leftll.tail->right=root;
    root->right=rightLL.head;

    l.head=leftll.head;
    l.tail=rightLL.tail;
    return l;
}
int main(){
    

return 0;
}