//Longest subarray with sum k
#include<bits/stdc++.h>
using namespace std;
int MaximumSubarraywithSum_K(int *A,int n,int k)
{
    unordered_map<int,int>um;
    int len=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum==k)
        { len=i+1;

        }
        if(um.find(sum-k)!=um.end())
        {
            len=max(len,i-um[sum-k]);
        }
        else{
            um[sum]=i;
        }
    }
    return len;
}
int main(){
    int A[]={1,-1,5,-2,3};
    int k=3;
    int n=sizeof(A)/sizeof(A[0]);
    cout<<"Maximum length of subarray having sum K : "<<MaximumSubarraywithSum_K(A,n,k)<<endl;

return 0;
}