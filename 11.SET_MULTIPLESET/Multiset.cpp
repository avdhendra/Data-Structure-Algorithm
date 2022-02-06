#include<bits/stdc++.h>
using namespace std;
int &func()
{
    static int a=10;
    return a;
}
int main(){
//Multiset - that can store multiple element that have same element
//store in a specific order sorted according to internal comparision object
//value once inserted cant be modified 
//associative container->element are refered by their value and not by the index
//underlying data structure =bst
int A[]={10,20,30,20,10};

multiset<int>m(A,A+5);
//multiple value not store more than once
set<int>s(A,A+5);

//they both give sorted element 
//iterate over the set
for(int x:m)
{
    cout<<x<<" ,";
}
cout<<endl;
for(int x:s)
{
    cout<<x<<" ,";
}
// give total count of that element
cout<<endl;
cout<<m.count(20)<<endl;
//get all element which are equal to a element 'a'
pair<multiset<int>::iterator,multiset<int>::iterator>range=m.equal_range(20);
for(auto it=range.first;it!=range.second;it++)
{
    cout<<*it<<" -- ";
}
cout<<endl;
int &y=func();
y=y+30;
cout<<func();

return 0;
}
//all the property of set is apply in multiset