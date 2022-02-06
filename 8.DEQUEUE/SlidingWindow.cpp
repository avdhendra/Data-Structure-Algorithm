//Given an Array and an Integer k find the maximum for each and every contigous 
//subarray of size k
#include<iostream>
#include<deque>
//A Deque base method for printing the maximum element of all subarray of size k

using namespace std;
int main()
{
    int arr[200];
    int n;
    cout<<"Enter number of element in array : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter number of element in Subarray : ";
    cin>>k;
    deque<int> D(k);
    int i;
    // we have to process first k element separetly
    for( i=0;i<k;i++)
    {
        // For every element the previous 
        //smaller elements are useless so 
        //remove them from Deque
        while((!D.empty()) && arr[i]>=arr[D.back()] )
        {
            //Remove from rear
            D.pop_back();
        }
        //Add new element at rear of queue
        D.push_back(i);
    }
//process the remaining element
for(;i<n;i++)
{
    //The element at the front of queue
    //is the largest element of previous window so print it

    cout<<arr[D.front()]<<" ";

    //1. remove the element index which are not the part of the window (Contraction process)
    
    while((!D.empty()) && D.front()<=i-k)
    {
        //remove from front of queu
        D.pop_front();
    }
    //2. remove the element which are not useful and are in window
    //means smaller than the currently being added element (remove useless elements)
    while((!D.empty()) && arr[i]>=arr[D.back()])
    {
        D.pop_back();
    }
    //3. Add the new elements(Expansion)
D.push_back(i);


}
//Print the maximum element //of last window
cout<<arr[D.front()];
return 0;

}
