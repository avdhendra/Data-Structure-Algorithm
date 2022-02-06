#include<bits/stdc++.h>
using namespace std;
//MONEY SPLITWISE  
int main(){
int no_of_transaction,friends;
cin>>no_of_transaction>>friends;

int x,y,amount;
//Make 1D array to Store the Net amount that each person 
//will have to take at the end
int net[100000]={0};
while (no_of_transaction--)
{
    cin>>x>>y>>amount;
    net[x]-=amount;
    net[y]+=amount;
}
multiset<int>m;  //for multiple transaction same value
//Init a list and Sort it ==> Multiset
for(int i=0;i<friends;i++)
{
    if(net[i]!=0)
    {
        m.insert(net[i]);
    }
}
int count=0;  //count until this set is empty
//pop out two person from least right and least left
while(!m.empty()){
    auto low=m.begin();
    auto high=prev(m.end()); //m.end give pointer to the pointer after the last element

    int debit=*low;
    int credit=*high;
    //Erase
    m.erase(low);
    m.erase(high);

    int settlement_amount=min(-debit,credit);
    count++;
    //Settlement amount from donor to accepter
    debit +=settlement_amount;
    credit-=settlement_amount;
    /*
    any one of the would be zero
    
    
    */
 /*
 
 (A)----->(B)
 -50       30
 Debit     credit

settlement amount =min(-debit,credit)

 settlement amount=min(-(-50),30);  ==> 30

 debit=debit+settlement amount ===> -50+30= -20
 credit=credit-settlement amount ===>30-30= 0

 insert A agian in multiset and value
 
 */
//one of them will become zero

if(debit!=0)
{
    m.insert(debit);
}
if(credit!=0)
{
    m.insert(credit);
}


}
cout<<count<<endl;

return 0;
}