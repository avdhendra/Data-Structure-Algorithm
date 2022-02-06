/*
Minimum Number of Dice Throws Required To reach the Destination
36 Starting from the Source 
Find the Shortest Path as Well

This will be Unweighted Graph
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
map<T,list<T>>l;
public:
void addEdge(int x,int y)
{
    l[x].push_back(y); //Single edge
   
}
T BFS(T src,T dest)
{
    map<T,int>Dist;
    queue<T>Q;
     map<T,T>parent;
    for(auto it:l)
    {
        T node=it.first;
        Dist[node]=INT_MAX;
    }
    
    Q.push(src);
    Dist[src]= 0;
    parent[src]=src;

    while(!Q.empty())
    {
        T node=Q.front();
        Q.pop();
        for(auto it:l[node])
        {
            if(Dist[it]==INT_MAX)
            {
               Q.push(it);
               Dist[it]=Dist[node]+1;
               parent[it]=node;
            }
        }
    }
   
  


//we traverse back from destination to src
//Path to Dest to Src
T temp=dest;
while(temp!=src)
{
    cout<<temp<<"-->";
    temp=parent[temp];
}
cout<<src<<endl;
    //Print The Dist To Dest Node
    return Dist[dest];
}
};
int main(){
int Board[50]={0};
//Snakes //Ladders
Board[2]=13;  // for Ladder + the digit 
Board[5]=2;
Board[9]=18;
Board[18]=11;
Board[17]=-13;  //for snake -ve the digit
Board[20]=-14;
Board[24]=-8;
Board[25]=10;
Board[32]=-2;
Board[34]=-22;

Graph<int> G;
for(int i=0;i<=36;i++)
{
    for(int dice=1;dice<=6;dice++)
    {
        int j=i+dice;
        j+=Board[j];

        if(j<=36)
        {
           G.addEdge(i,j);   //link btw src to destination
        }
    }
}
G.addEdge(36,36);
cout<<G.BFS(0,36);

return 0;
}