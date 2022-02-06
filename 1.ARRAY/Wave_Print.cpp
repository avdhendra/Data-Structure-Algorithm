#include<iostream>
using namespace std;
int main()
{
    int row;
    int col;
    cout<<"enter row : ";
    cin>>row;
    cout<<"enter col : ";
    cin>>col;
    int A[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>A[i][j];

        }
    }
    for(int i=0;i<col;i++)
    {
       if(i%2==0)
       {
           for(int j=0;j<row;j++)
           {
               cout<<A[j][i]<<" ";
           }
           cout<<endl;
       }
       else
       {
           for(int j=row-1;j>=0;j--)
           {
               cout<<A[j][i]<<" ";
           }
           cout<<endl;
       }
    }
    
}