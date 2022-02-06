//Sort element in array in wave form

/* *    *   *     *
     *    *    *
wave form
Asked question in big companies

*/
#include<iostream>
using namespace std;

void wavesort(int A[],int n )
{
    //go to every 2nd element try to create a peak
    for(int i=0;i<n;i+=2)
    {
        //check for left element
        if(i>0 &&A[i-1]>A[i])
        {
            swap(A[i],A[i-1]);
        }
        if(i<=n-2 &&A[i+1]>A[i])
        {
            swap(A[i],A[i+1]);
        }
    }
}
void printArray(int A[],int n)
{
    cout<<"Print element in wave from : ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
    }
}

int main()
{
int A[100];
int n;
cout<<"Enter number element in array : ";
cin>>n;
cout<<"Enter element in array : ";
for(int i=0;i<n;i++)
{
    cin>>A[i];
}
wavesort(A,n);
printArray(A,n);

}