/*Bucket Sort Applications
Bucket sort is used when:

input is uniformly distributed over a range.
there are floating point values
*/
/*

Time Complexity	 

Best	O(n+k)

Worst	O(n2)

Average	O(n)

Space Complexity	O(n+k)
Stability	Yes

Worst Case Complexity: O(n2)

When there are elements of close range in the array, they are likely to be placed in the same bucket. This may result in some buckets having more number of elements than others.
It makes the complexity depend on the sorting algorithm used to sort the elements of the bucket.
The complexity becomes even worse when the elements are in reverse order. If insertion sort is used to sort elements of the bucket, then the time complexity becomes O(n2).

Best Case Complexity: O(n+k)

It occurs when the elements are uniformly distributed in the buckets with a nearly equal number of elements in each bucket.
The complexity becomes even better if the elements inside the buckets are already sorted.
If insertion sort is used to sort elements of a bucket then the overall complexity in the best case will be linear ie. O(n+k). O(n) is the complexity for making the buckets and O(k) is the complexity for sorting the elements of the bucket using algorithms having linear time complexity at the best case.


Average Case Complexity: O(n)
It occurs when the elements are distributed randomly in the array. Even if the elements are not distributed uniformly, bucket sort runs in linear time. It holds true until the sum of the squares of the bucket sizes is linear in the total number of elements.
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//function to sort arr[] of
//size n using bucket sort
void bucketSort(float A[],int n)
{
    //create n empty buckets
    vector<float>b[n];
    //put array elements
    //in different buckets
    for(int i=0;i<n;i++)
    {
        int bi=n*A[i];
        b[bi].push_back(A[i]);
    }
    // Sort individual buckets
    for(int i=0;i<n;i++)
    {
    sort(b[i].begin(),b[i].end());
    }
    //concatenate all bucket into arr[]
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            A[index++]=b[i][j];
        }
    }

}
void print(float A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    float A[]={0.897,0.565,0.656,0.1234,0.665,0.3434};
    int n=sizeof(A)/sizeof(A[0]);
    bucketSort(A,n);
    print(A,n);
}