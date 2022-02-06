//Sort Element in ascending order
//Selection sort
/*
Time complexity:- 0(n^2) as there are two nested loop
Auxiliary space :0(1)

the good thing about selection sort is it never make  than 0(n) swaps and can 
be useful when memory write is a costly operation
*/
#include<iostream>
using namespace std;
void selectionSort(int A[],int n)
{
    for(int i=0;i<n-1;i++) //n-1 iteration
    {
        //Assume the current (ith) is min
        int minIndex=i;
        //min element in rem part
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[minIndex])
    {
        minIndex=j;
    } 
        }
        //Minindex min element
swap(A[minIndex],A[i]);
    }
}
int main()
{
 int A[10],n;
    cout<<"number of element want to enter in array"<<endl;
    cin>>n;
    cout<<"enter element in array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"enter element in array ("<<i+1<<") :";
        cin>>A[i];
    }
    selectionSort(A,n);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;

}