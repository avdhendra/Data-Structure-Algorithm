/*
Here we find the element in matrix 

* we can apply  brute force method -0(n^2)
binary search but -0(nlog)
staircase search take n time complexity

search in row and col wise sorted matrix

*/

#include<iostream>
using namespace std;
int main()
{
    int row,col;
    cout<<"enter row : ";
    cin>>row;
    cout<<"enter col ; ";
    cin>>col;
    int A[row][col];
    int i=0;
    int j=col-1;
    int key;
    cout<<"enter key : ";
    cin>>key;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>A[i][j];
        }
    }
    while(i<row && j>=0)
 {   if(A[i][j]==key)
    {
        cout<<"key is found at : "<<i<<","<<j<<endl;
        
    }
    if(A[i][j]>key)
    {
        j--;
    }
    else
    {
        i++;
    }
}
cout<<"key is not found in Matrix : ";
}
