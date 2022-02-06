#include<iostream>
#include<set>
using namespace std;
//Set are a tyoe of Associative container in which each element has be Unique because the value
//of element identifies it.The value of the element cannot be modiefied once it is added to the set
//thought it is possible to remove and add the modified value of that element

int main(){
//begin()-return an iterator to the first element in the set
set<int> myset{1,2,3,5};
//set<char> myset{'a','b','c'};
//set<string>myset{"abc","set","gcd"};
set<int> set1;
for(int i=0;i<myset.size();i++)
{
    set1.insert(i);
}
for(set<int>::iterator i=myset.begin();i!=myset.end();i++)
{
    cout<< " "<<*i;
}
cout<<endl;
for(auto it=set1.begin();it!=set1.end();it++)
{
    cout<<" "<<*it;
}
cout<<endl;
//end()- return an iterator to the theoretical element that follows last element in the set
//Size()-return number of element in the set
cout<<"Set Size : "<<myset.size()<<endl;

//max-size()- Return the Maximum number of element that the set can hold

set<int>s2,s3;
s2.insert(1);
//If set already contain element
cout<<s2.max_size()<<endl;
cout<<s3.max_size()<<endl;
//empty()
if(!myset.empty())
{
    cout<<"true"<<endl;
}
else{
    cout<<"false"<<endl;
}

//assign the element from s1 to S2
set<int>s4(set1.begin(),set1.end());
for(auto it=s4.begin();it!=s4.end();it++)
{
    cout<<*it<< " ";
}
cout<<endl;
//Erase remove the value 'a' from the set
set<int>w;
for(int i=10;i<=100;i+=10)
{
    w.insert(i);
}
w.erase(w.begin(),w.find(30));
for(auto it=w.begin();it!=w.end();it++)
{
    cout<<*it<< " ";
}
cout<<endl;
auto pos=w.find(40); //this it have  not the bool type return  

for(auto it=pos;it!=w.end();it++)
{
    cout<<*it<<  " ";
}
cout<<endl;
//count - return bool type 
if(w.count(30))
{
    cout<<"true"<<endl;
}
else{
    cout<<"False"<<endl;
}

set<int>mys1{1,2,3,4,5,6,7,8};
mys1.clear();
//become empty
for(auto it=mys1.begin();it!=mys1.end();it++)
{
    cout<<*it<<" ";
}
cout<<endl;


return 0;
}