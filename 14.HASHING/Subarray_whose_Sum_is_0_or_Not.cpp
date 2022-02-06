/*

ime Complexity of this solution can be considered as O(n) 
under the assumption that we have good hashing function 
that allows insertion and retrieval operations in O(1) 
time. 

Space Complexity: O(n) .Here we required extra space
 for unordered_set to insert array elements.
*/
#include<iostream>
#include<unordered_set>
using namespace std;
bool checkSum(int A[],int n)
{
    unordered_set<int>S;
    //Traverse through array
    //and Store prefix Sums

    int pre=0;
    for(int i=0;i<n;i++)
    {
        pre+=A[i];
        //if prefix sum is 0 or 
        //it is already present
        if(pre==0 ||S.find(pre)!=S.end())
        {
            return true;
        }
        S.insert(pre);

    }
    return false;
}
int main()
{
    int arr[]={6,-1,2,-1,2,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(checkSum(arr,n))
    {
        cout<<" Found a Subaray with 0 Sum ";
    }
    else{
        cout<<"No such ARRay exist!";
        
    }
return 0;
}