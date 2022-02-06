/*
Kosaraju's Algorithm for Strongly Connected Components




Q. what are Strongly Connected Component?(this concept of Directed Graph)


 

*/
#include<bits/stdc++.h>
using namespace std;
void DFS2(vector<int>Graph[],int i,bool *Visited)
{
    Visited[i]=true;
    cout<<i<<" ,";
    for(auto nbr:Graph[i])
    {
        if(!Visited[nbr])
        {
            DFS2(Graph,nbr,Visited);
        }
    }
}
void dfs(vector<int>Graph[],int i,vector<int>&Stack,bool *visited)
{
    visited[i]=true;
    for(auto Nbr:Graph[i])
    {
        if(!visited[Nbr])
        {
            dfs(Graph,Nbr,Stack,visited);
        }
    }
    //Function Call is Complete
    //
    Stack.push_back(i);
}
void  Solve(vector<int>Graph[],int N,vector<int>Rev_Graph[])
{
    //Mark all the Vertices as Not Visited(for First DFS)
    bool Visited[N];
    memset(Visited,0,N);
    vector<int>Stack;
    //Step -1 Need to store the Vertices acc to dfs Finish time
    /*Finish time is when you are at a Node where you can not go any where and return from that Node s
    so we Store that on Stack*/
    for(int i=0;i<N;i++)
    {
        if(!Visited[i])
        {
            dfs(Graph,i,Stack,Visited);
        }
    }
    //Mark all Vertices as Not Visited(For Second DFS)
    memset(Visited,0,N);
    char component_Name='A';
    for(int i=Stack.size()-1;i>=0;i--)
    {int Node=Stack[i];
       
        if(!Visited[Node])
        {
             cout<<component_Name<<" ---> ";
            //There is Component Starting From this Node
            DFS2(Rev_Graph,Node,Visited);
            
        cout<<endl;
        component_Name++;
        }
        

    }

}
int main(){
int N; //Number of Vertices
cin>>N;
vector<int>Graph[N];
vector<int>Rev_Graph[N];
int M;
cin>>M;
while(M--)
{
    int x,y;
    cin>>x>>y;
    Graph[x].push_back(y);
    Rev_Graph[y].push_back(x);
}
Solve(Graph, N,Rev_Graph);
return 0;
}