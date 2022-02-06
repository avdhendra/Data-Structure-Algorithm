//for clock wise rotation 90`
/*
if anticlock wise we use colomn
there wise row
*/
//rotation of matrix by 90 degree in 
/*
 rotation of matrix by 90 degree
// without using extra space
*/
/*here we rotate the matrix by 90 in clockwise
*/

/*
Time complexity :O(R*C). 
The matrix is traversed twice, so the complexity is O(R*C).*/

#include<bits/stdc++.h>
using namespace std;
void printMatrix(int A[3][3]);
void swapMatrix(int A[3][3],int i,int j,int k)
{
    int temp;
    if(k!=0)
    {
        temp=A[i][j];
A[i][j]=A[i][k];
A[i][k]=temp;


    }
    else{
        temp=A[i][j];
        A[i][j]=A[j][i];
        A[j][i]=temp;
        
    }
}
void transpose(int A[3][3])
{
for(int i=0;i<3;i++)
{
    for(int j=i;j<3;j++)
    {
        swapMatrix(A,i,j,0);
    }
}
}
/*
// After transpose we swap
// elements of column
// one by one for finding left
// rotation of matrix
// by 90 degree
*/
void reverserow(int A[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0,k=3-1;j<k;j++,k--)
        {
            swapMatrix(A,i,j,k);
            

        }
    }

}

    

void printMatrix(int A[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<A[i][j]<<" ";

        }
        cout<<endl;
    }
}
int main()
{
    int A[3][3];
    for(int i=0;i<3;i++)
    { 
        for(int j=0;j<3;j++)
        {
            cin>>A[i][j];
        }

    }
    transpose(A);
    cout<<"Transpose matrix : "<<endl;;
    printMatrix(A);
    cout<<endl;
    

    reverserow(A);
cout<<"Rotated Image of Matrix : "<<endl;
    printMatrix(A);

}