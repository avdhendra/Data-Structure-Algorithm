#include<iostream>
using namespace std;
int main()
{
    int A[3][3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                cin>>A[i][j][k];
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                cout<<A[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

}