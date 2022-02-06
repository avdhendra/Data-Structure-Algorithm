/*
   DIJKSTRAS ALGORITHM

to find shortest path in non weighted Graph BFS algorithm can be Used


To find single shortest source path in weighted graph Dijkstra algorithm works

             ( 1 )
            /  |  \
           /   |   \
          /    |    \
         /     |     \
      ( 4 )--( 3 )--( 2 )

Adjacency List to Implement


        Node with min distance
            /             \ 
           /               \ 
          /                 \
     (Array Linear Search)  Priority Queue/Set of pair(dist,Node) sorted according to dist
        (0(N))                            find in(0(1))
                                          delete in(0(logn))
        Time Complexity(ElogV)                               
 
*/ 
#include<bits/stdc++.h>
#include<map>
#include<set>
using namespace std;
template<typename T>
class Graph{
    public:
    map<T,list<pair<T,int>>>l;
    void AddEdge(T x,T y,int dist,bool bidir=true)
    {
        l[x].push_back(make_pair(y,dist));
        if(bidir)
        {
        l[y].push_back(make_pair(x,dist));
        }
    }
    void PrintAdj(){
        for(auto i:l)
       {
           cout<<"| "<<i.first<<" |"<<"->";
           for(auto it:i.second)
           {
               cout<<"( "<<it.first<<","<<it.second<<")"<<",";
           }
           cout<<endl;
       }
    }


    //Dijkstra Algorithm
void DijkstraSSSP(T src)
{
map<T,int>dist;
//Set all Distance to Infinity
for(auto i:l)
{
    dist[i.first]=INT_MAX; //all nodes distance become infinity
}
//Make a Set to Find a Out Node with the Minimum distance
//Set sort according to the First Parameter thats why we add src in set first
/*  
set sort according to distance
   dist   | 0 |  |  |  |
   Node   | 1 |  |  |  |    

*/
/*MAke  a Set to Find a Out Node with the Minimum Distance*/
set<pair<int,T>>s;  //first is dist second is Node
dist[src]=0;
s.insert(make_pair(0,src));


while(!s.empty())
{
    //Find the Pair at the Front
    auto p=*(s.begin());  //s.begin is pointer
    T Node=p.second;
    int NodeDist=p.first;
    s.erase(s.begin()); //first Node should be erase
//Iterate Over Neighbour/children of the Current Node
for(auto childpair:l[Node])
{   //parent dist+child distance
    if(NodeDist+childpair.second<dist[childpair.first])
    {//In the Set Updation of a Particular Node is Not Possible
    //so we have to remove the Old pair and Insert the New Pair to Stimulation Updation
    T dest=childpair.first;
    auto f=s.find(make_pair(dist[dest],dest));
    if(f!=s.end())
    {
        s.erase(f);
    }
    //Insert the New Pair
    dist[dest]=NodeDist+childpair.second;
    s.insert(make_pair(dist[dest],dest));

    }
}





}
//Distance to All other Node

for(auto i:dist)
{
    cout<<i.first<<"is Located at a Dist of "<<i.second<<endl;
}
}
};
int main(){
/*Graph<int>G;
G.AddEdge(1,2,1);
G.AddEdge(1,3,4);
G.AddEdge(2,3,1);
G.AddEdge(3,4,2);
G.AddEdge(1,4,7);
G.PrintAdj();*/
Graph<string>G;
G.AddEdge("Amritsar","Delhi",1);
G.AddEdge("Amritsar","Jaipur",4);
G.AddEdge("Jaipur","Delhi",2);
G.AddEdge("Jaipur","Mumbai",8);
G.AddEdge("Bhopal","Agra",2);
G.AddEdge("Mumbai","Bhopal",3);
G.AddEdge("Agra","Delhi",1);
G.DijkstraSSSP("Amritsar");

return 0;
}