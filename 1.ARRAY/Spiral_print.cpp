#include<bits/stdc++.h>
using namespace std;
int row;
int col;
void SpiralPrint(int row,int col,int A[][100])
{
    int StartRow=0;
    int StartCol=0;
    int EndRow=row-1;
    int EndCol=col-1;
    
    //
    while(StartRow<=EndRow and StartCol<=EndCol )
    {
        /* Print the first row from
               the remaining rows */
        for(int i=StartCol;i<=EndCol;i++)
        {
            cout<<A[StartRow][i]<<" ";
        }
        StartRow++;
        /* Print the last column
         from the remaining columns */
        for(int i=StartRow;i<=EndRow;i++)
        {
            cout<<A[i][EndCol]<<" ";
        }
        EndCol--;
    //Bottom Row
    /* Print the last row from
                the remaining rows */
    if(EndRow>StartRow)
    {
        
        for(int i=EndCol;i>=StartCol;i--)
        {
            cout<<A[EndRow][i]<<" ";
        }
        EndRow--;
    }
        //Start Col
         /* Print the first column from
                   the remaining columns */
if(EndCol>StartCol)
{
    
        for(int i=EndRow;i>=StartRow;i--)
        {
        cout<<A[i][StartCol]<<" ";
        }
        StartCol++;
}
    }

}
int main()
{
    
    cout<<"Enter number of Row: ";
    cin>>row;
    cout<<"Enter number of col :  ";
    cin>>col;
    int A[100][100];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>A[i][j];
        }

    }
    SpiralPrint(row ,col,A);
}