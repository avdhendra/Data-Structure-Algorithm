#include<bits/stdc++.h>
using namespace std;
//Money Splitwise Algorithm
/*
Output- Should also show Transaction 

Rahul Pay 50 to Ajay
Rahul pays 10 to Neha

2 transaction


*/

class person_Compare{
    public:
    bool operator()(pair<string,int>p1,pair<string,int>p2)
    {
        return p1.second<p2.second;
    }
};

int main(){
int no_of_Transaction,Friends;
cin>>no_of_Transaction>>Friends;

//Name of Donor and Acceptor

string x,y;
int amount;
map<string,int>net;
for(int i=0;i<Friends;i++)
{
    cin>>x>>y>>amount;
    if(net.count(x)==0)
    { //initial if x is not in the map
        net[x]=0;
    }
    if(net.count(y)==0)
    {//initial if y is not in the map
        net[y]=0;
    }
    net[x]-=amount;
    net[y]+=amount;
}
//Iterate Over the Person add those person in the mulitset who have non zero net
multiset<pair<string,int>,person_Compare>m;
for(auto p:net)
{
    string person=p.first;
    int amount=p.second;
    if(net[person]!=0)
    {
       m.insert(make_pair(person,amount)); //when you enter first pair to in multiset it sort according to the first pair 
       //so we have to make the compare function for it
    }

}
//3. make Settlement(start & end)
int count=0;
while(!m.empty())
{
    auto low=m.begin();
    auto high=prev(m.end());

    string debit_name=low->first;
    int debit=low->second;
    
    string credit_name=high->first;
    int credit=high->second;
    
    //pop them out
    m.erase(low);
    m.erase(high);
    
    int settlement_amount=min(-debit,credit);
count++;
    debit+=settlement_amount;
    credit-=settlement_amount;
    cout<<debit_name<<" pay "<<settlement_amount<<" to "<<credit_name<<endl; 
if(debit!=0)
{
    m.insert(make_pair(debit_name,debit));
}
if(credit!=0)
{
    m.insert(make_pair(credit_name,credit));
}


}
cout<<count<<endl;
return 0;
}