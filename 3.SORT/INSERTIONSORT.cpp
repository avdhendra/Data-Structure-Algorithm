//Sort element in ascending order
//INSERTIOn sort
/*Time complexity:-0(n*2)
auxiliary space :-0(1)
*/
#include<iostream>
using namespace std;
void insertionSort(int A[],int n)
{//we start from 1 because we see one element is already sorted
 
    for(int i=1;i<n;i++)
    {
        int j=i-1; //element before current element i-1
        //i=1 j=0
        int current =A[i];
        while(j>=0 && A[j]>current)
        {
            A[j+1]=A[j];
            j--; //we check sorted sublist from right to left
        }
        A[j+1]=current;
    }
}
void printSortArray(int A[],int n)
{
    cout<<"print Sorted Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ,";
    }
}
int main()
{
    int A[100];
    int n,i;
    cout<<"enter element want to enter : ";
    cin>>n;
    cout<<"enter element in array : ";
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    insertionSort(A,n);
    printSortArray(A,n);
}