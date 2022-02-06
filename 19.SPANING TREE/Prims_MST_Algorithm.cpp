/*
Prims MST Algorithm
-Weight Undirected Graph
-Greedy Algorithm

*/
/*
Graph:-          ( 1 )
                        /|\
                  (1)  / | \  (2)
                      / (2) \
                   ( 2 )---( 3 )
                     \   |   /
                ( 3 ) \(2)|  / ( 3 )
                       \ | /
                       ( 4 )
Term we Use
MST set =[] for put value of vertex 
Active Edge =edge from a vertext in MST set
MST Edge= an Edge that Has Been  Included in MST So Far


//Algorithm:
1.Start From any Source Vertex
2.Out of All Active Edge Pick the One with smallest weight
 -Select in Y in MST
 -Add Edge Starting From Y in active Edge List

             ( 1 ) having active edges are
          1 /  |  \
           / 2 | 2 \ 
        ( 2 )  |  ( 3 )
             ( 4 )

insert 1 in MST Array MST=[1,]

the minimum weight edge is 1 to  2
so we Insert it to MST=[1,2]
what are the Active Edge From 2 but still here active edge of 1 is present we
have to find the minum edge weight of all active edge
              (1)
           (2  |  \ (2) here we can pick any minimum edge of weight 2 
           (2) |   \
        (2)--- |  -->(3)
         \     |
        3  \   |
             (4)
        
        
  so we insert 3 in mst array =[1,2,3,]

  and its active edges are 


               (1)
           (2  |  \ (2) here we can pick any minimum edge of weight 2 
           (2) |   \
        (2)--- |  -->(3)
         \     |    /     
        3  \   |   /(3)
             (4)          
since only one minimum edge is present btw 1 and 4 so we add 4 in mst array


and also we dont take that edge whose element are present in mst set because it will make cycle 


to Find Minimum edge weight of all active edge we use min heap because it have 
time complexity 0(log n)




Prim's algorithm is significantly faster in the limit
when you've got a really dense graph with many more 
edges than vertices. Kruskal performs better in 
typical situations (sparse graphs) because it uses 
simpler data structures.








*/

#include<bits/stdc++.h>
using namespace std;
class Graph{
    //Adjacency List Implementation
    public:
    vector<pair<int,int>>*l;               /*   
                                               *l--|
                                                   |
                                                   V
                                                  | 1 |-->{node ,weight},{Node ,weight}     
                                           
                                           
                                           
                                           */
    int v;
    Graph(int n)
    {
        v=n;
        l=new vector<pair<int,int>>[n];
    }
    void AddEdge(int x,int y,int w)
    {
        //Undirected Graph
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
    int prims_mst(){
        //Most important stuff
        //Init a Min Heap
              //type of  value,format in which we store         by default comparator is max       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
      //Another Array
      //Visited array that denote whether a node has been included in MSt or Not
      bool*visited=new bool[v]{0};
      int ans=0;

      //begin
      Q.push({0,0});//weight,Node we find according to weight 
      while(!Q.empty())
      {
          //Pick out the Edge with Min Weight
          auto best=Q.top();  //due to min heap top element have the least weight
           Q.pop();
            int To_Node=best.second;
            int weight=best.first;
            if(visited[To_Node]) //if that Node already visited we skip that or we can say the node which is already in mst 
            {//discard the Edge and Continue
            continue;

            }
            //OtherWise take The current edge
            ans+=weight;
            //mark that edge visited
            visited[To_Node]=1;
            //Add the New Edge in the Queue
            for(auto x:l[To_Node]) //all the Neighbour of to Node  
            {
                if(visited[x.first]==0) //in adjacency list first denote the Node
                {
                    Q.push({x.second,x.first});
                }
            }
      }
      return ans;
    
    }

};
int main(){

return 0;
}