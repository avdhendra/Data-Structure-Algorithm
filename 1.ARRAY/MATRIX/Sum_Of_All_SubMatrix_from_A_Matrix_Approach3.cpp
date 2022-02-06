/*
In each submatrix the element will be contributing for the sum

contribution of each cell/element in my final sum

sum the contribution


final sum=A[i][j]*no of submatrix this cell wil be part of

total submatrix that can be made
is X x Y X=(i+1)*(j+1) s box for tl
Y=(n-i)*(m-j) box for BR
time is 0(n^2)
space is 0(1)
*/

#include<iostream>
using namespace std;
int main()
{
    int R,C;
    cin>>R;
    cin>>C;
    int A[R][C];
    int sum=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int i=0;i<=R-1;i++)
    {
        for(int j=0;j<=C-1;j++)
        {
            sum+=A[i][j]*((i+1)*(j+1)*(R-i)*(C-j));
        }
    }
cout<<sum<<endl;
}
