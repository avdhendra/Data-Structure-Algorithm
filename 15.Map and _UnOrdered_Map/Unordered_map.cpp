#include<iostream>
#include<unordered_map>
#include<iterator>
using namespace std;

/*
unordered map store in form of hashtable
*/
int main()
{
    unordered_map<string,int>unm;
    unm.insert(make_pair("Sachin Tendulkar",50000));
    unm.insert(make_pair("Ricky pointing",490000));
    unm.insert(make_pair("Rohit",40000));
    unm.insert(make_pair("Virat",5100000));


    for(auto x:unm)
    {
        cout<<x.first<<" and "<<x.second<<endl;
    }
   auto it =unm.find("Virat");
   cout<<it->first<<" and "<<it->second<<endl;
   /*
   all the function used  in set are used with it
   */

}