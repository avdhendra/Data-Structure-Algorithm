#include<iostream>
#include<map>
#include<iterator>
using namespace std;
/*
Maps are associative container that store element  in mapped fashion
Each element has a key value and a mapped value No two mapped value
can have same key value

value store in ordered way
*/


/*

map (like set) is an ordered sequence of unique
keys whereas in unordered_map key can be
stored in any order, so unordered. 
The map is implemented as a balanced 
tree structure that is why it is possible to 
maintain order between the elements 
(by specific tree traversal). The time 
complexity of map operations is 
O(log n) while for unordered_map, 
it is O(1) on average. 
*/
int main()
{
    //Empty map container
    map<string ,int> m;
    //we insert value in pair
    m.insert(make_pair("Tesla",90000));
    m.insert(make_pair("BMW",50000));
    m.insert(make_pair("Audi",75000));
    //or
    m.insert(pair<string,int>("Ferrari",120000));

    //printing map value;
    //iterator through all value
    /*
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" and "<<it->second<<endl;
    }
    */
    //this is for each loop
    for(auto x:m)
    {
        cout<<x.first<<" and "<<x.second<<endl;
    }
    
    /*apply all the operation you do with set*/




}