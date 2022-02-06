//C++ Program for Merge Sort
#include<iostream>
using namespace std;
//merge two subarray of A[]
//First subarray is A[l....mid]
//Second Subarray is A[mid+1....r]
void merge(int A[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    //create temp arrays
    int L[n1],R[n2];
    //Copy data to temp array L[] and R[]
    for(int i=0;i<n1;i++)
    {
        L[i]=A[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=A[mid+1+j];
    }
    //Merge the temp array back into Arr[l....r]
    //initial index of first subarray
    int i=0;
    //initial index of second subarray
    int j=0;
    //initial index of merge subarray
    int k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
    //Copy the remaining element of 
    //L[] if there are any
    while(i<n1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
//l is for left index and r is right index of the sub array
//of A to be sorted
void mergeSort(int A[],int l,int r)
{
    if(l>=r)
    {
        return ; //return recursively


    }
    int mid=(l+r)/2;
    mergeSort(A,l,mid);
    mergeSort(A,mid+1,r);
    merge(A,l,mid,r);
}
//UTILITY FUNCTION
//FUNCTION TO PRINT AN ARRAY
void printArray(int A[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    int A[200];
    int n;
    cout<<"Enter number of element in array : ";
    cin>>n;
    cout<<"Given array is : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    printArray(A,n);
    mergeSort(A,0,n-1);
    cout<<"Sorted array is : "<<endl;
    printArray(A,n);
    return 0;
}