#include<iostream>
using namespace std;
int maxSumsubmatrix(int **arr,int R,int C)
{
    //col wise addition first  
    for(int i=R-1;i>=0;i--)
    {
        for(int j=C-2;j>=0;j--)
        {
            arr[i][j]+=arr[i][j+1];
        }
    }
    //Row wise addition secondly
    for(int i=C-1;i>=0;i--)
    {
        for(int j=R-2;j>=0;j--)
        {
            arr[j][i]+=arr[j+1][i];
        }
    }
    int res=INT8_MIN;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            res=max(res,arr[i][j]);
        }
    }
    return res;
}
int main()
{
    int R,C;
    cin>>R>>C;
    int **arr=new int *[R];
    for(int i=0;i<R;i++)
    {
        arr[i]=new int [C];
    }
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>arr[i][j];
        }

    }
    cout<<maxSumsubmatrix(arr,R,C)<<endl;
}