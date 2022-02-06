//C++ implementation of radix sort
#include<iostream>
using namespace std;
int getmax(int A[],int n)
{
    int mx=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>mx)
        {
            mx=A[i];
        }
    }
    return mx;
}
void countSort(int A[],int n,int exp)
{
    int output[n];
    int i, count[10]={0};
    //Store count of occurences in count[]
    for(i=0;i<n;i++)
    {
        count[(A[i]/exp)%10]++;
    }//change count[i] so that count[i] now contain actual
    //position of this digit in output[]
    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];

    }
    //Build the output array
    for(i=n-1;i>=0;i--){
        output[count[(A[i]/exp)%10]-1]=A[i];
        count[(A[i]/exp)%10]--;
    }
    //Copy the output array to arr[] so that A[] noew 
    //contain sorted number according to current digit

    //now copy output to original array
    for(i=0;i<n;i++)
    {
        A[i]=output[i];
    }


}
void radixSort(int A[],int n)
{
    //find the maximum number to know number of digit
    int m=getmax(A,n);
    //Do counting sort for every digit Note that instead 
    //of passing digit number ,exp is passed exp is 10^i
    //where i is current digit number
    for(int exp=1;m/exp>0;exp*=10)
    {
        countSort(A,n,exp);
    }

}
void printSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int A[]={170,45,75,54,679,564,145,540};
    int n=sizeof(A)/sizeof(A[0]);
    radixSort(A,n);
    printSort(A,n);
}