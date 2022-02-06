/*
Usually, results of competitions are based on the
scores of participants. However, we are planning a 
change for the next year of IPSC. During the 
registration each team will be able to enter a 
single positive integer : their preferred place in 
the ranklist. We would take all these preferences 
into account, and at the end of the competition we 
will simply announce a ranklist that would please 
all of you.

But wait... How would that ranklist look like if it 
won't be possible to satisfy all the requests?

Suppose that we already have a ranklist. For each 
team, compute the distance between their preferred 
place and their place in the ranklist. The sum of 
these distances will be called the badness of this 
ranklist.


*/ 
#include<bits/stdc++.h>
using namespace std;
#define LL long long
int abs(int actual_rank,int given_rank)
{
    if(actual_rank>given_rank)
    {
        return actual_rank-given_rank;
    }
    return given_rank-actual_rank;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

int t;
scanf("%d",&t);
while(t--)
{

    string name;
    int n,rank;
    scanf("%d ",&n); //number of team
    int *arr=(int*)malloc(n+2*sizeof(int));
     memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++)
    {
        cin>>name;
        scanf("%d",&rank);
        arr[rank]++;// we have a frequency array for given rank

    }
    //Greedy approach -Assign the Team nearest rank available
    int actual_rank=1;
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        while(arr[i])
        {
            sum+=abs(actual_rank,i);
            arr[i]--;
            actual_rank++;
        }
    }
    printf("%lld\n",sum);
}
return 0;
}