/*
two matrix multiply 
*/
#include<bits/stdc++.h>
using namespace std;
void multiply_matrix(int (&mat1)[3][3],int (&mat2)[3][3],int (&mat3)[3][3])
{
int i,j,k;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        mat3[i][j]=0;
        for(k=0;k<3;k++)
        {
            mat3[i][j]+=mat1[i][k]*mat2[k][j];
        }
    }
}
}

int main(){
int mat1[3][3];
int mat2[3][3];
int i,j;
int mat3[3][3];
cout<<"Enter mat1 : "<<endl;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cin>>mat1[i][j];
    }
}
cout<<"Enter mat2 : "<<endl;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cin>>mat2[i][j];
    }
}
multiply_matrix(mat1,mat2,mat3);
cout<<" Result matrix is :  "<<endl;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<mat3[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}