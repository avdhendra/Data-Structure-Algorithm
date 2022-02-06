//Precomputing 
//cumulative sum
/*
csum[i]=csum[i-1]+a[i];

n+n^2
*/
#include<iostream>
using namespace std;
int main()
{
    int A[100];
    int cumSum[100]={0};
    
    int maxSum=0;
    int currentSum=0;

    int left=-1;
    int right=-1;
    
    int n;
    cout<<"enter number of element  : ";
    cin>>n;

    cin>>A[0];
    cumSum[0]=A[0];
    
    for(int i=1;i<n;i++)
    {
cin>>A[i];
cumSum[i]=cumSum[i-1]+A[i];
    }
    //generate all subarrays
    for(int i=0;i<n;++i)
    {

        for(int j=i;j<n;j++)
        {
            //Element of subarray(i,j)
            currentSum=0;
            if(i==j)
            {
                currentSum=A[i];

            }
            else
            {
                  currentSum=cumSum[j];
            }
            

            //Update Maximum if Cs>maxisum
            if(currentSum>maxSum)
            {
                maxSum=currentSum;
                left=i;
                right=j;
            }

        }
    }
    cout<<"Maximum sum is: "<<maxSum<<endl;
    //Print the subarray
    for(int i=left;i<=right;i++)
    {
        cout<<A[i]<<", ";
    }
}
