//BUBBLE SORT for sorting element ascending order
/*
Bubble Sort is the simplest sorting algorithm that 
works by repeatedly swapping the adjacent elements if 
they are in wrong order.
*/

/*
Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

Auxiliary Space: O(1)

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Sorting In Place: Yes

Stable: Yes
*/

#include<iostream>
using namespace std;
void swap(int *px,int *py)
{
    int temp=*px;
    *px=*py;
    *py=temp;
}
void bubblesort(int A[],int n)
{
    int counter=1;
    while(counter<n)
    {
        for(int i=0;i<n-counter;i++)
        {
            if(A[i]>A[i+1])
           swap(&A[i],&A[i+1]);

        }
        counter++;
    }
}
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ,";
        
    }
}
int main()
{
    int A[100];
    int n;
    cout<<"enter number of element u want to enter array : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];

    }
    bubblesort(A,n);
    printArray(A,n);
}