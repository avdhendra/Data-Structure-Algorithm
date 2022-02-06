#include<bits/stdc++.h>
using namespace std;

int main()
{
//cbegin() :- return a constraint iterator pointing to the first element in the container
//cend:- Return a constant iterator pointing to the position past the last
//element in the container
int arr[]={14,15,12,11,10};
//Initialize the set from an array
set<int>s(arr,arr+5);
//print all element in set
//iterator start from last element and end at first element in set

for(auto it=s.cbegin();it!=s.cend();it++)
{
    cout<<*it<<" ";
    
}
cout<<endl;
//iterator start from the largest element and end to smallest elmeent in set

//Set::rbeing() return a reverse iterator pointing to the last element int the container
for(set<int>:: reverse_iterator it=s.rbegin();it!=s.rend();it++)
{
    cout<<*it<<" ";
}
cout<<endl;
int A[]={1,8,6,5,4,9};
set<int>s1(A,A+6);
//or u can use s.crbegin() same function instead of use reverse iterator
for(auto it=s1.crbegin();it!=s1.crbegin();it++)
{
    cout<<*it<<" ";
}
cout<<endl;
//swap()-This function is used to exchange the content of two sets but
//the set must be of sametype although size may differ
set<int> set1{1,23,45,64,52};
set<int> set2{1,2,3,4,5};
set1.swap(set2);
for(auto it=set1.crbegin();it!=set1.crend();it++)
{
    cout<<*it<<" ";
}
cout<<endl;
//Lower Bound which return an iterator pointing to the element in the container which equivalent
//to k passed in the parameter .In case K is not present in the set container
//the function return an iterator pointing to the immediate next element which is greater than k

//if array vector are sorted then they works aso(log n but if not it take o(n))time
//they return location of that element
//upperbound only return large element of the given element
//lowerbound can give that value if exist but if not then the next largest element than that value

cout<<"The set Element are : ";
auto it=set1.lower_bound(4);
if(it!=set1.end())
{
    cout<<"The Lower Bound of Key 4 is: ";
    cout<<*it<<endl;
}
else{
    cout<<"the Element entered is larger than the greates element in the set"<<endl;
}
set<int> h;
h.insert(2);
h.insert(3);
h.insert(4);
//set become 0,2,6,8,9
//adding unique element
h.emplace(5);
//set become 2,3,4,5
h.emplace(2);
//adding element which already
//exist there will be no 
//change in the set
for(auto it=h.begin();it!=h.end();it++)
{
    cout<<*it<<" ";
}
cout<<endl;