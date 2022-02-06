/*
Find the length of largest subarray with 0 sum
*/
/*
Time Complexity: O(n), 
as use of the good hashing function, will allow 
insertion and retrieval operations in O(1) time.

Space Complexity: O(n), for the use of extra space to
 store the prefix array and hashmap.

*/
#include<iostream>
#include<unordered_map>
using namespace std;
//return Length of the required Subarray
int maxLen(int A[],int n)
{
    //Map to Store the previous Sum
    unordered_map<int,int>preSum;
    //initialize the sum of element 
    
    int sum=0;
    
    //initialize result
    
    int max_len=0;
    //traverse through the given array
    for(int i=0;i<n;i++)
    {
        //add current element to sum
        sum+=A[i];
        if(sum==0)
        {  
            max_len=i+1;

        }

        //Look for this sum in Hash Table
        else{
            if(preSum.find(sum)!=preSum.end())
            {
                //If this sum is seen before then update max_len
                max_len=max(max_len,i-preSum[sum]);
            }
            else{
                //if Sum is not seen before then insert
                preSum[sum]=i;
            }
        }
    }
return max_len;
    

}
int main()
{
int A[]={15,-2,2,-8,1,7,10,23};
int n=sizeof(A)/sizeof(A[0]);
cout<<"length of the Longest 0 sum subarray is : "<<maxLen(A,n);
return 0;

}
