#include<bits/stdc++.h>
using namespace std;
/*
          (20)
    (A)----------(B)
     | \          |
     |   \  (50)  |
(10) |     \      |(30)
     |      \     |
     |        \   |
    (C)----------(D)
        ( 10 )



A      --->   (B,20)(D,50)(C,10)
string         list<pair<string,int>>
(key)              value

*/
class Graph{
    public:
    //adjacency list
    map<string,list<pair<string,int>>>l;
    void addEdge(string x,string y,bool bidir,int wt)
    {
        l[x].push_back(make_pair(y,wt));
        if(bidir)
        {
            l[y].push_back(make_pair(x,wt));
        }

    }
   void PrintAdjList()
   {
       //Iterate Over all the Keys in the Map
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
};







int main()
{

Graph G;
G.addEdge("A","B",true,20);
G.addEdge("B","D",true,40);
G.addEdge("A","C",true,10);
G.addEdge("C","D",true,40);
G.addEdge("A","D",false,50);

G.PrintAdjList();
}