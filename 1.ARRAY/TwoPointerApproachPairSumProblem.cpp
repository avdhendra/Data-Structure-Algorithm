/*
Given a sorted Array ,find Pair of elements that sum to K(given)

//Brute force approach **N^2

two pointer apporach is array is sorted
time complexity is N

*/

#include<iostream>
using namespace std;
int main()
{
int n,key;
cin>>n;
cout<<"Enter key :  ";
cin>>key;
int A[]={1,3,5,7,10,11,12,13};
int s=16;
int i=0;
int j=sizeof(A)/sizeof(int)-1;
while(i<j)
{
    int current_Sum=A[i]+A[j];
    if(current_Sum>key)
    {
        j--;
    }
    else if(current_Sum<key)
    {
        i++;
    }
    else if(current_Sum==key)
    {
        cout<<A[i]<<" and "<<A[j];
    i++;
    j--;
    
    }
}
}
/*
1,2,3,4,5,6

i         j
these two are pointer
if we decreased the j the sum if less
or if we decreased the i the sum if increased
because the array is sorted
so we increament and derecment each acrroding to 
*/