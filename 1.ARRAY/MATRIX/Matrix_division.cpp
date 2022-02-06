#include<bits/stdc++.h>
using namespace std;
void add_Matrix(int (&A)[3][3],int (&B)[3][3])
{
    for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        A[i][j]=(A[i][j]/B[i][j]);
    }
}


}


int main(){
int A[3][3];
int B[3][3];
int i,j;
//int C[3][3];
cout<<"Enter matrix A :"<<endl;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cin>>A[i][j];
    }
}
cout<<"Enter matrix B : "<<endl;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cin>>B[i][j];
    }
}
cout<<"TWO MATRIX ADDDITION :: "<<endl;

add_Matrix(A,B);
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<A[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}