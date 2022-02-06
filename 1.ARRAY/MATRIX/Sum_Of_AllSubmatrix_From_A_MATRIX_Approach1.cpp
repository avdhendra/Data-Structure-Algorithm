/*
Given A 2x2 matrix
1 1
1 1
4 matrix of(1x1)-4x1=4
2 submatrix of(1x2)-2x2=4
2 submatrix of2x1-2x2=4
1 submatrix of (2x2)-> 1x4=4


so total sum of submatrix is 16
*/
/*
Brute force approach
time complexity=0(n^6) space 0(1)
*/
#include<iostream>
using namespace std;
int main()
{
    int R,C;
    cin>>R;
    cin>>C;
    int A[R][C];
    int count=0;

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int Li=0;Li<R;Li++)
    {
        for(int Lj=0;Li<C;Lj++)
        {
            for(int Bi=Li+1;Bi<R;Bi++)
            {
                for(int Bj=Lj+1;Bj<C;Bj++)
                {
                    for(int i=Li;i<Bi;i++)
                    {
                        for(int j=Lj;j<Bj;j++)
                        {
                          count+=A[i][j];
                        }
                    }
                }
            }
        }

    }
    cout<<"Sum of Matrix : "<<count<<endl;
}
