/*
form of query{
    Tli,tly,bri,brj
}
we have to find that sub matrix sum
we can do brute force for which 0(m*n)

we can do prefix sum matrix

*/
#include<iostream>
using namespace std;
#define R 3
#define C 3

/*
A o(1) time function to compute sum of submatrix
between (tli,tlj) and (rbi,rbj) using aux[][]
which is built by the preprocess function


*/
int SumQuery(int Aux[R][C],int tli,int tlj,int bri,int brj)
{
//Result is now sum of element between (0,0) and
//(rbi,rbj)
int res=Aux[bri][brj];
//remove element between (0,0) and (tli-1,rbi)
if(tli>0)
{
    res=res-Aux[tli-1][brj];
}
if(tlj>0)
{
    res=res-Aux[bri][tlj-1];
}
//Add Aux [tli-1][tlj-1] as element between (0,0)
//and (tli-1 ,tlj-1) are subtracted twice
if(tli>0 && tlj>0)
{
    res=res+Aux[tli-1][tlj-1];
}
return res;

}

/*
Function to preprocess input mat[M][N].this function
mainly fills aux [m][n] such that aux[i][j] store sum
of element from(0,0) to (i,j)

*/
void preProcess(int A[R][C],int Aux[R][C])
{
//copy first row of mat[][] to aux[] []
for(int i=0;i<R;i++)
{
    Aux[0][i]=A[0][i];
}
//Do column wise sum
for(int i=1;i<R;i++)
{
    for(int j=0;j<C;j++){
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
}
int main()
{int t;
while(t--)
{
   
int i=1;
int Aux[R][C]; //to store the prefix sum of given matrix
    int A[R][C];
    for(int i=0;i<R;i++)
   for(int j=0;j<C;j++)
   {
       cin>>A[i][j];
   }
   preProcess(A,Aux);
int tli,tlj,bri,brj;
cout<<"Enter top left x element : ";
cin>>tli;    //Top left x element
cout<<"enter the top left y element : ";

cin>>tlj;   //Top left y element
cout<<"Enter the bottom x element : ";
cin>>bri;  //Bottom right x element 
cout<<"Enter the bottom y element : ";
cin>>brj; //Bottom right y element 
cout<<"Query "<<i++<<" : "<<SumQuery(Aux,tli,tlj,bri,brj);
}  
}