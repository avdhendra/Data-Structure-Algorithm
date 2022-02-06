//Kaden Algorithm
/*
time complexity:0(n)
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of element in N : ";
    cin>>n;
    int Array[1000];
    int current_Sum=0;
    int max_so_far=INT8_MIN;
    int start=0;
    int end=0;
    int S=0;
    for(int i=0;i<n;i++)
    {
        cin>>Array[i];
    }
    //Kadane's Algorithm for Maximum Subarray Sum
    for(int i=0;i<n;i++)

    {
        //here we donot take cumulative sum as
        current_Sum=current_Sum+Array[i];
        if(max_so_far<current_Sum)
        {
          max_so_far=current_Sum;
          start=S;
          end=i;

        }
        if(current_Sum<0)
        {
            current_Sum=0;
            S=i+1;
        }
        
    }
    cout<<"Maximum is : "<<max_so_far<<endl;
    cout<<"And element in this subarray are : ";
    for(int i=start;i<=end;i++)
    {
        cout<<Array[i]<<" ,";
    }

}