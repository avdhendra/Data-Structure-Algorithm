/*
Naive Approach: The idea is to first sort the array 
and find the longest subarray with consecutive 
elements.After sorting the array and removing the 
multiple occurrences of elements, run a loop and keep
 a count and max (both initially zero). 
 Run a loop from start to end and if the current 
 element is not equal to the previous (element+1) 
 then set the count to 1 else increase the count.
Update max with a maximum of count and max.
*/
/*

Time complexity: O(nLogn). 
Time to sort the array is O(nlogn).
Auxiliary space : O(1). 
As no extra space is needed.

*/

#include<bits/stdc++.h>
using namespace std;
int FindLongestSubsequeue(int *A,int n)
{
    int ans=0, count=0;
    //sort the array
    sort(A,A+n);
   
    vector<int>V;
   
    V.push_back(A[0]);
    //insert repeated element only once in the vector
    for(int i=1;i<n;i++)
    {
        if(A[i]!=A[i-1])
        {
            V.push_back(A[i]);
        }
    }
    //Find the Maximum length
    //by traversing the array

    for(int i=0;i<n;i++)
    {
        //check if the current element is equal to 
        //previous element+1
        if(i>0&& V[i]==V[i-1]+1)
        {
         count++;
         
        } 
        //reset the count
        else{
          count=1;
        }
        //Update the maximum
        ans=max(ans,count);
    }
return ans;

}
int main()
{
    int A[]={1,2,2,3};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<"Length of the Longest Contigous subsequeuce is : "<<FindLongestSubsequeue(A,n)<<endl;
}