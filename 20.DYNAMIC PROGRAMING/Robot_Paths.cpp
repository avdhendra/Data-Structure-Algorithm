#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int Dp[1001][1001];
int NumberofWays(int M,int N)
{
    //base case
    if(Dp[0][0]==-1)
    {
        return 0;
    }
    //Compute the Number of ways for first rows
    for(int i=0;i<N;i++)
    {
        if(Dp[0][i]==-1)
        {
            break;
        }
        Dp[0][i]=1;
    }
    //Compute the Number of way for first coloumn
    for(int j=0;j<M;j++)
    {
        if(Dp[j][0]==-1)
        {
            break;
        }
        Dp[j][0]=1;
    }

    //Bottom Up Approach for Rest of the Matrix
    for(int i=1;i<M;i++)
    {
        for(int j=1;j<N;j++)
        {
            //if Cell is Blocked Leave it
            if(Dp[i][j]==-1)
            {
                continue;
            }
            Dp[i][j]=0;
            if(Dp[i][j-1]!=-1)
            {
                Dp[i][j]=(Dp[i][j-1])%MOD;
            }
            if(Dp[i-1][j]!=-1)
            {
                Dp[i][j]=(Dp[i][j]+Dp[i-1][j]);
            }
        }
       
    }
//Print Entire Dp table
for(int i=0;i<M;i++)
{
    for(int j=0;j<N;j++)
    {
        cout<<setw(3)<<Dp[i][j]<<" ";
    }
    cout<<endl;
}

     if(Dp[M-1][N-1]==-1)
        {
            return 0;
        }
        return Dp[M-1][N-1];

}

int main(){
memset(Dp,0,sizeof(Dp));
int M,N,P; //Number of Row:M,N:Number of Coloumn
//P is Blocks
cin>>M>>N>>P;

for(int i=0;i<P;i++)
{
    int x,y;
    //Mark all the Blocked Cell as -1
    cin>>x>>y;
    Dp[x-1][y-1]=-1;
}
cout<<NumberofWays(M,N)<<endl;

return 0;
}