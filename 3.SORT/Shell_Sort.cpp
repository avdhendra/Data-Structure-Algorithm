#include<iostream>
using namespace std;
void shellsort(int A[],int n)
{
    //start with big gap then reduce the gap
    for(int gap=n/2;gap>0;gap/=2)
    {
        //Do a gapped insertion sort for this gap size
        //the first gap element A[0...gap-1] are already in gapped order
        //keep adding one more element until the entire array is
        //gap sorted
        for(int i=gap;i<n;i++)
        {
            //add A[i] to the elements that have been gap sorted
            //save A[i] in temp and make a hole in position
            int temp=A[i];
            //shift earlier gap-sorted element up untile the correct 
            //location for A[i] is found
            int j;
            for(j=i;j>=gap && A[j-gap]>temp;j-=gap)
            A[j]=A[j-gap];
            //put temp (the original A[i]) in its correction location
            A[j]=temp;
        }

    }
}
void print(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    int A[]={2,3,2,5,1};
    int n=sizeof(A)/sizeof(A[0]);
    shellsort(A,n);
    print(A,n);
}