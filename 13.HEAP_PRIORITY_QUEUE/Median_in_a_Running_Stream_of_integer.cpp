
/**
 
 Algorithm: 
 

Create two heaps. One max heap to maintain elements 
of lower half and one min heap to maintain elements 
of higher half at any point of time..

Take initial value of median as 0.For every newly 
read element, insert it into either max heap or 
min-heap and calculate the median based on the 

following conditions: 
If the size of max heap is greater than the size of 
min-heap and the element is less than the previous 

median then pop the top element from max heap and 
insert into min-heap and insert the new element to 

max heap else insert the new element to min-heap. 
Calculate the new median as the average of top of 

elements of both max and min heap.
If the size of max heap is less than the size of 

min-heap and the element is greater than the previous 
median then pop the top element from min-heap and 

insert into the max heap and insert the new element 
to min heap else insert the new element to the max 

heap. Calculate the new median as the average of top 
of elements of both max and min heap.

If the size of both heaps is the same. Then check if 
the current is less than the previous median or not. 

If the current element is less than the previous 
median then insert it to the max heap and a new 

median will be equal to the top element of max heap. 
If the current element is greater than the previous 

median then insert it to min-heap and new median 
will be equal to the top element of min heap.
 
 
 
 **/
/*
Time Complexity: O(n Log n). 
Time Complexity to insert element in min heap is log n. So to insert n element is O( n log n).
Auxiliary Space : O(n). 
The Space required to store the elements in Heap is O(n).

*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> leftHeap; //maxHeap
    priority_queue<int,vector<int>,greater<int>>rightHeap;  //min Heap

    int d;
    cin>>d;
    leftHeap.push(d);
    float med=d;
    cout<<" Median "<<med<<" ";
    cin>>d;
while(d!=-1)
{
    //logic
    if(leftHeap.size()>rightHeap.size())
    {
        if(d<med)
        {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
            leftHeap.push(d);
        }
        else{
            rightHeap.push(d);
        }
        med=(leftHeap.top()+rightHeap.top())/2.0;
    }
    
    else if(leftHeap.size()==rightHeap.size())
    {
        if(d<med)
        {
            leftHeap.push(d);
            med=leftHeap.top();
        }
        else{
            rightHeap.push(d);
            med=rightHeap.top();
        }
    }
    else{
        if(d>med)
        {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
            rightHeap.push(d);
        }
        else{
            leftHeap.push(d);
        }
        med=(leftHeap.top()+rightHeap.top())/2.0;

    }

    cout<<" Med "<<med<<endl;
    cin>>d;
}

return 0;
}