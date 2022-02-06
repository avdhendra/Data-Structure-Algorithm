//subarray should be continous
#include<iostream>
using namespace std;

int main()
{
   int n;
   cout<<"Enter number of element : ";
    cin>>n;

int A[100];

for(int i=0;i<n;i++)
{
    cin>>A[i];
}
01234
12345
i
j
i=0,j=0 1,2,3,4
k i,j



for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        for(int k=i;k<=j;k++)
        {
            cout<<A[k]<<" ";
        }
        cout<<endl;
    }
}

}
