/*
**TWO MATRIX -> multiply

**A^n A->[k*k]

in logn time complexity
*/
#include<iostream>
using namespace std;
void multiply(int A[][2],int B[][2])
{
    int mul[2][2]={0};
for(int i=0;i<2;i++)
{
    for(int j=0;j<2;j++)
    {
        for(int k=0;k<2;k++)
        {
        mul[i][j]+=A[i][k]*B[k][j];
        }
    }
}
for(int i=0;i<2;i++)
{
    for(int j=0;j<2;j++)
    {
        A[i][j]=mul[i][j]; //updating our matrix
    }
}
}
void power(int A[2][2],int n)
{
    if(n==0||n==1)
    {
        return;
    }
    power(A,n/2);
    //multiple A^n/2 with A^n/2 when n is even
    multiply(A,A);
    //is n is odd mutiply A^n/2 with A^n/2 with A 
    if((n%2)!=0){
        int M[2][2]={{1,1},{1,0}};
        multiply(A,M);
    }

}
int fib(int n)
{
    int A[2][2]={{1,1},{1,0}};
    if(n==0)
    {
        return 0;
    }
    power(A,n-1);
    return A[0][0];
}
int main()
{
    cout<<fib(20)<<endl; 
    
}