#include<bits/stdc++.h>
using namespace std;
int cnt=0;
//Basic Way 
//Complexity 2^n

int MaxProfit(int *Arr,int beg,int end,int Year)
{
    ++cnt;
    if(beg>end)
    {
        return 0;
    }
    int Ans1=Year*Arr[beg]+MaxProfit(Arr,beg+1,end,Year+1);  //Sell from beg
    int Ans2=Year*Arr[end]+MaxProfit(Arr,beg,end-1,Year+1);  //sell from end
    int max1=max(Ans1,Ans2);
    return max1;

}
int cnt1=0;
int Memo[100][100];
//Memoization
int MaxProfit1(int *Arr,int beg,int end,int Year)
{
     cnt1++;
    if(beg>end)
    {
        return 0;
    }
    if(Memo[beg][end]!=-1)
    {
        return Memo[beg][end]; 
    }
    int Ans1=Year*Arr[beg]+MaxProfit1(Arr,beg+1,end,Year+1);
    int Ans2=Year*Arr[end]+MaxProfit1(Arr,beg,end-1,Year+1);
    int ans=max(Ans1,Ans2);
    Memo[beg][end]=ans;
    return ans;


}
/*
  2   3  5    1   4
|___|___|___|___|___|

|<----->|                       these are have length of 2
    |<----->|
        |<----->|  
            |<----->|


            and we have to start=0 and end=n-len-1

*/
int MaxProfit3(int *Arr,int n)
{
    int dp[100][100]={};
    int year=n;
    //First we fill the diagonal
    //which represent we have only one bottle
    for(int i=0;i<n;i++)
    {
        dp[i][i]=year*Arr[i]; // u are doing that if we sell the bottle
                             // at n year than what is the price
                             // dp[0][0]=a[0]*5;
    }
    --year;
    //Year now left is 4
    //filling from len=2 to len=n

    //first we take length of two and upto

    for(int len=2;len<=n;len++)
    {
        int start=0;
        int end=n-len; //the last index of len upto which u are seeing the bottle 
        while(start<=end)
        {
            int endwindow=start+len-1; //endwindow is the index u r filling along the row like 0,1 0,2 --0,4 that 1,2 1,3  1,4  than 2,3 2,4 and so
            dp[start][endwindow]=max(Arr[start]*year + dp[start+1][endwindow] , Arr[endwindow]*year+  dp[start][endwindow-1]);

        ++start;    
        }
        --year;
        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<setw(3)<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];

}
int main(){
int Num_wine;
cout<<"enter number of Wine : ";
cin>>Num_wine;
int Arr_wine[200];
for(int i=0;i<Num_wine;i++)
{
    cin>>Arr_wine[i];
}
//Basic
/*int Ans=MaxProfit(Arr_wine,1,Num_wine,1);
cout<<"Total Profit : "<<Ans<<endl;
cout<<"Number of Call: "<<cnt<<endl;  //total 63 call perform
//Memoization
memset(Memo,-1,sizeof(Memo));
int ans1=MaxProfit1(Arr_wine,1,Num_wine,1);
cout<<ans1<<endl;
cout<<"Number of call "<<cnt1<<endl;
*/
//Dp method
int ans2=MaxProfit3(Arr_wine,Num_wine);
cout<<"The Max Profit : "<<ans2<<endl;


return 0;
}