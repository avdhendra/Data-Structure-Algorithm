//Counting sort

/*
not a compare sorting 

Advantages of Counting Sort:
It is quite fast
It is a stable algorithm
Note: For a sorting algorithm to be stable, the order of elements with equal keys (values) in the sorted array should be the same as that of the input array.

Disadvantages of Counting Sort:
It is not suitable for sorting large data sets
It is not suitable for sorting string values
*/
/*
COUNTING SORT APPLICATION 
* there are smaller integer with multiple counts
* linear complexity is the need

SPACE COMPLEXITY

0(MAX).LARGER THE RANGE OF ELEMENT LARGER IS THE SPACE COMPLEXITY

TIME COMPLEXITY
0(n+k) for all cases



*/


#include<bits/stdc++.h>
using namespace std;
void countSort(int A[],int n)
{
//the size of count must be at least the (max+1) but
/*
we cannot assign declare it as int count(max+1) in c++ as
it does not support dynamic memory allocation
so it size is provided statically

*/
int output[10];
int count[10];
int max=A[0];
//find the largest element of the array
for(int i=1;i<n;i++)
{
    if(A[i]>max)
    max=A[i];
}
//Intialize count array with all zeros
for(int i=0;i<=max;i++)
{
    count[i]=0;
}
//store the count of each element 
for(int i=0;i<n;i++)
{
    count[A[i]]++; 
}
//store the cumulative count of each array
for(int i=1;i<=max;i++)
{
    count[i]+=count[i-1];
}
//find the index of each element of the original array in count array,and
//place the element in output array
for(int i=n-1;i>=0;i--)
{
    output[count[A[i]]-1]=A[i];
    count[A[i]]--;
}
//copy the sorted element into original array
for(int i=0;i<n;i++)
{
    A[i]=output[i];
}
}
//function to print an array
void printArray(int A[],int n)
{
    cout<<"Sorting array : ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ,";
    }
}
int main(){
int A[100],n;
cout<<"enter number of element : ";
cin>>n;
cout<<"enter element : ";
for(int i=0;i<n;i++)
{
    cin>>A[i];
    
}
countSort(A,n);
printArray(A,n);
return 0;
}