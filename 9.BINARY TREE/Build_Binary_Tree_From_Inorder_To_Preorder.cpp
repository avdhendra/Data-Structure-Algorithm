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
Node*Build()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        
    }
    Node*n1=new Node(d);
    n1->left=Build();
    n1->right=Build();
    return n1;
}
Node*CreateTreeFromTrav(int *in,int*pre,int start,int end)
{
    static int i=0; //this pointer variable is static
    //we dont want any backtracking 
    //static variable initial only once it not intializied
    //again and again when the function is call


    //base case
    if(start>end)
    {
        return NULL;
    }
    //Rec Case 
    Node*root=new Node(pre[i]);
    int index=-1;
    for(int j=start;start<=end;j++)
    {
        if(in[j]==pre[i])
        {
            index=j;
            break;
        }
    }
    i++;
    root->left=CreateTreeFromTrav(in,pre,start,index-1);
    root->right=CreateTreeFromTrav(in,pre,index+1,end);
    return root;

}
void PrintLevelOrder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(Q.empty()==false)
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

int in[]={3,2,8,4,1,6,7,5};
int pre[]={1,2,3,4,8,5,6,7};
int size=sizeof(pre)/sizeof(pre[0]);
Node*root=CreateTreeFromTrav(in ,pre,0,size-1);
PrintLevelOrder(root);
return 0;
}