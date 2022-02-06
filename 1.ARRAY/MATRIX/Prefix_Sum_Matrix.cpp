#include<iostream>
using namespace std;
#define R 3
#define C 3
void print(int Aux[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;i<C;j++)
        {
            cout<<Aux[i][j];
        }
    }
}
void prefix_Sum(int A[R][C],int Aux[R][C])
{
    //copy first row of mat[][] to aux[][]
    for(int j=0;j<R;j++)
    {
        Aux[0][j]=A[0][j];
    }
    //Do column wise sum
    for(int i=1;i<R;i++)
    {
        for(int j=0;j<C;i++)
        {
            Aux[i][j]=A[i][j]+Aux[i-1][j];
        }
    }
    //Do row wise sum
    for(int i=0;i<R;i++)
    {
        for(int j=1;j<C;j++)
        {
            Aux[i][j]+=Aux[i][j-1];
        }
    }
    print(Aux);

}
int main()
{
    int A[R][C];
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>A[i][j];
        }
    }
    int Aux[R][C];
    prefix_Sum(A,Aux);
}