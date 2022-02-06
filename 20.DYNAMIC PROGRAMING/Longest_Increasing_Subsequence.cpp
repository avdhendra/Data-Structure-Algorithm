#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n2). 
// As nested loop is used.
// Auxiliary Space: O(n). 
// Use of any array to store LIS values at each index.

int LIS(int *arr,int n)
{
    int dp[100];
    int best=-1;
//Initialize first all the value with 1
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        
        for(int j=0;j<i;j++)
        {
            if(arr[i]>=arr[j]) //current element should be greater then previous all element 
            {
                //Jth Element can be Absorbed by ith Element
                int currentLen=1+dp[j];    //we increment current value by 1
                dp[i]=max(currentLen,dp[i]);
            }
        }
        best=max(best,dp[i]); // we return max max of all 
    }
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
return best;
}
int main(){
int arr[100];
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>arr[i];

}
int ans=LIS(arr,n);
cout<<"Length of Longest Sequence : "<<ans<<endl;
return 0;
}