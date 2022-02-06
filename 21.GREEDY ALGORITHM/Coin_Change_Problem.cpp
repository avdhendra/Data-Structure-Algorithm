/*
This is Greedy way 
as read the Dp method




*/



#include<bits/stdc++.h>
using namespace std;
int make_Change(int *coins,int n,int money)
{
    int sum=0;
    while(money>0)
    {
        int idx=upper_bound(coins,coins+n,money)-1-coins; 
        //upper bound gave the address when subtract
        // it with coin base address we get index
         money=money-coins[idx];
        sum++;

    }
    return sum;

}
int main(){
int money;
cin>>money;
int Coins[]={1,2,5,10,20,50,100,200,500,2000};
int t=sizeof(Coins)/sizeof(Coins[0]);
cout<<make_Change(Coins,t,money);
return 0;
}