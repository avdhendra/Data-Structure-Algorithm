/*
It is DP based Algorithm

*/


#include<bits/stdc++.h>
using namespace std;
vector<int>bellman_Ford(int V,int src,vector<vector<int>>edges)
{
    //Step:1
    //Create a Vector
    vector<int>dist(V+1,INT_MAX);
    //Init src dist to 0
    dist[src]=0;
    //Step 2:
    //relax all Edges V-1 Times
    for(int i=0;i<V-1;i++)
    {
        //Go to Every Edge and relax
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            //Apply Relaxation to every Node until V-1 Iteration
            if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;

            }

        }


    }
    //Step 3 :
    //Check Negative Wt Cycle
    //So we again this loop if ,if statement true then it contain cycle
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        if(dist[u]!=INT_MAX and dist[u]+wt<dist[v]) //if distance change after v-1 iteration then it contain negative wt cycle
        {
            cout<<" Negative wt cycle Found ";
            exit(0);
        }
    }
return dist;
}

int main(){
int n,m;
cin>>n>>m; //n is vertices and m is edges
//edge List
vector<vector<int>>edgeList; //(a,b,3)(c,d,5)....

for(int i=0;i<m;i++)  
{
    int u,v,wt;
    cin>>u>>v>>wt;
    edgeList.push_back({u,v,wt});

     
}

vector<int>Bellmam_vector_Dist=bellman_Ford(n,1,edgeList);

for(int i=1;i<=n;i++)
{
    cout<<" Node "<<i<<"is at Dist "<<Bellmam_vector_Dist[i]<<endl;
}

return 0;
}