//C++ Program for implementation of heap Sort
/*
There are two type of heap max heap and min heap
In max heap root element is largest element
heapify method to create max heap 0(n) time complexity
from where leaf node start or largest index start


we see heapify method to build max heap

*/
#include<iostream>
using namespace std;
//To heapify a subtree rooted with node i which is an
/*index in arr[]. n is size of heap*/
void heapify(int A[],int n,int i)
{
    int largest=i; //initialize largest as root
    int l=2*i+1;
    int r=2*i+2;
    //if left child is larger than root
    if(l<n &&A[l]>A[largest])
    largest=l;
    //if right child is largest than largest so far
    if(r<n &&A[r]>A[largest])
    largest=r;
    //if largest is not root it means it is updated
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        //Recursively Heapify the affected sub-tree
       heapify(A,n,largest);
    }

}
void heapsort(int A[],int n)
{
    //this for loop is to build max heap
    //build heap (rearrange array)
    for(int i=n/2-1;i>=0;i--) //here heapify start from n/2-1 for index=0 start

heapify(A,n,i); //feapify start from n/2 for i=-
//one by one element to be extracted from heap
for(int i=n-1;i>=0;i--)
{
    //swap first  root node  to end 
    swap(A[0],A[i]);
    //call max heapify on the reduced heap
    heapify(A,i,0);

}

}
//how to find leaf node in binary tree is by method 
//n/2+1 to n is leaf node of tree
void printArray(int A[],int n)
{
    for(int i=0;i<n;++i)
    {
        cout<<A[i]<<" ";
        
    }
}
int main()
{
int A[100];
int n;
cout<<"Enter number of element in array : ";
cin>>n;
cout<<"Enter element in array"<<endl;
for(int i=0;i,n;i++)
{
    cin>>A[i];
}
heapsort(A,n);
cout<<"Sorted array is ";
printArray(A,n);
}