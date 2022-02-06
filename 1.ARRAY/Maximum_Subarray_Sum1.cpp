#include<iostream>
using namespace std;
int main()
{
    int A[100];
    int currentSum=0;
    int maxSum=0;
    int left=-1;
    int right=-1;
    int n;
    cout<<"Enter number of element  :  ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            currentSum=0;
            for(int k=i;k<=j;k++)
            {
                currentSum+=A[k];
            }
            //update maximum sum if Cs>maximumsum
            if(currentSum>maxSum)
            {
                maxSum=currentSum;
                left=i;
                right=j;
            }
        }
    }
    cout<<"Maximum Sum is : "<<maxSum<<endl;
    for(int i=left;i<=right;i++)
    {
        cout<<A[i]<<" ";
    }
}