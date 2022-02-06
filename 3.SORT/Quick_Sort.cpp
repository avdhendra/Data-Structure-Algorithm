//C++ program for implementation of Quick Sort
#include<iostream>
using namespace std;
//A utility function to swap two element
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
/*
This function takes last element as pivot,places the pivot element at its
correct position in sorted array, and places all smaller(smaller than pivot)
to left of pivot and all greater element to right of pivot

*/

int partition(int A[],int low,int high)
{
    int pivot=A[low];
    int start=low;
    int end=high;
    while(start<end)
    {
        while (A[start]<=pivot)
        {
            start++;
        }
        while(A[end]>pivot)
        {
            end--;
        }
        if(start<end)
    {
        swap(A[start],A[end]);
    }
        
    }
swap(A[low],A[end]);
return end;
}
void quicksort(int A[],int low,int high)
{
    if(low<high)
    {
        /*pi is partition index ,A[p] is now at right place*/
        int pi=partition(A,low,high);
        //separately sort element before
        //partition and after partition
        quicksort(A,low,pi-1);
        quicksort(A,pi+1,high);
    }
}
/*
function to print an array
*/
void printArray(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {

        cout<<A[i]<<" ";
        cout<<endl;

    }
}


int main()
{
    int A[100];
    int n;
    cout<<"enter number of element : ";
    cin>>n;
    cout<<"enter element in array : ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    quicksort(A,0,n-1);
    cout<<"Sorted array: \n";
    printArray(A,n);
    return 0;
}