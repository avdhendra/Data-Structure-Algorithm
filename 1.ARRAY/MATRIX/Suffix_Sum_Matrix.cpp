#include<iostream>
using namespace std;
void print(int **A,int R,int C)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void suffixSum(int **A,int R,int C)
{
    //coloumn wise addition
    for(int i=R-1;i>=0;i--)
    {
        for(int j=C-2;j>=0;j--)
        {
            A[i][j]+=A[i][j+1];

        }

    }

    //Row wise addition
    for(int i=C-1;i>=0;i--)

    {
        for(int j=R-2;j>=0;j--)
        {
            A[j][i]+=A[j+1][i];
        }
    }
    print(A,R,C);
}

int main()
{
    int R,C;
    cin>>R>>C;
    int **A=new int *[R];
    for(int i=0;i<R;i++)
    {
        A[i]=new int [C];
    }
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
    {
        cin>>A[i][j];
    }

    }
    suffixSum(A,R,C);
}
