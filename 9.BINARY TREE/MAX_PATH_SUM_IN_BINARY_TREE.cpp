//MAX_PATH_SUM_IN BINARY_TREE
//Path can start at anyNode &end at Any node

//Path may start &end at any point but it should 
//always be continous
//Path may or may not go through root
//Path can have one node minimum

//3 case To handle
//case1: current Node is in path of Max Sum
//case2: Current Node is root of Max Sum Path
//case3: Current Node is Not in path of MaxSum

//How to Solve ?
/*
i) we Need to Maintain a variable to keep track
of max sum already found(case-3)

ii) we need to compare all 3 cases for each node

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
Node*Build()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    Node*root=new Node(d);
    root->left=Build();
    root->right=Build();
    return root;
}
//This Function returns Overall Maximum path in 'res'
//and returns max path sum going through root
int FindMaxSumPath(Node*root,int &result)
{
    //Base case
    if(root==NULL)
    {
        return 0;

    }
    //l and r store maximum path sum going through left and 
    //right child of root respectively
    int left=FindMaxSumPath(root->left,result);
    int right=FindMaxSumPath(root->right,result);
    //Max path for parent call of root this path must
    //Include at most one Child of root
    int max_Straight=max(max(left,right)+root->data,root->data);
    //Max Top represent the sum when the Node under
    //Consideration is the Root of the MaxSum Path and No
    //Ancestors of root are there in Max Sum Path
    int max_top=max(max_Straight,left+right+root->data);
     
    result=max(max_top,result);
    //Store the Maximum Result

    return max_Straight;
}
//Returns Maximum Path Sum in tree With Given root
int res(Node*root)
{
    //Initialize Result
    int res=INT_MIN;
    //Compute And return Result
    FindMaxSumPath(root,res);
    return res;
}

int main(){
Node*root=Build();
cout<<res(root);
return 0;
}