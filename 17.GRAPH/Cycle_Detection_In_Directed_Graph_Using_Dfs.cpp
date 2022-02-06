/*
Approach: Depth First Traversal can be used to detect 
a cycle in a Graph. DFS for a connected graph 
produces a tree. There is a cycle in a graph only if 
there is a back edge present in the graph. A back 
edge is an edge that is from a node to itself 
(self-loop) or one of its ancestors in the tree 
produced by DFS. 

*/
/*


(0)
 |
 |
 V                   
(1)----------------->(5)-------->(6)
 |                   ^
 |                   |------
 V     (Back Edge)(4,2)    |
(2) <-----------------|    |
 |                    |    |
 |                    |    |
 |                    |    |
(3)----------------->(4)---|



| 4 |----|
| 3 |    | (BackEdge ) since 5 is Not in the Stack so this can't be Back Edge
| 2 |<----
| 1 |
| 0 | 

|0|  this Stack has Not backEdge
|1|
|5|
|6|


*/

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    public:
   map<T,list<T>>l; 
   void addEdge(int x,int y)
   {
       l[x].push_back(y);

   }
   bool Cycle_helper(T src,map<T,bool>&Visited,map<T,bool>&RecStack)
   {
       if(Visited[src]==false)
       {//Mark The current Node as Visited and Part of Recursion Stack
           Visited[src]=true;
           RecStack[src]=true;
       }
       for(auto nbr:l[src])
       {//two case
       //if that nbr is already present in  stack 
       /*    like in 0->1->2->3->4
                           ^
                           |------|
                   
       
       
       
       */                 
         if(RecStack[nbr]==true)
         return true ;  //this is cycle
         else if(Visited[nbr]==false)
         {
             /*
             here 4 call to 2 and 2 is in the stack and return true
             4 return true to 3
             3 return true to 2
             2 return true to 1
             1 return true to 0 to main true
             
             
             */
             bool cycle_mila=Cycle_helper(nbr,Visited,RecStack);
             if(cycle_mila==true)
             return true;
             
         
         }

       }
       //Leave a Node
       RecStack[src]=false;  //use on end when no cycle is present and nbr of src are end
       return false;
   
   }
   bool Contain_Cycle(T src){
       //Check for cycle in Directed Graph
       // Mark all the vertices as not visited and not part of recursion
    // stack
    map<T,bool>Visited;
    map<T,bool>RecurStack;
    for(auto i:l)
    {
        T Node=i.first;
        Visited[Node]=false;
        RecurStack[Node]=false;
    }
    return Cycle_helper(src,Visited,RecurStack);
   } 
};
int main(){
Graph<int>G;

G.addEdge(0,1);
G.addEdge(1,2);
G.addEdge(2,3);
G.addEdge(3,4);
G.addEdge(4,5);
G.addEdge(1,5);
G.addEdge(5,6);
//G.addEdge(4,2);

if(G.Contain_Cycle(0))
{
    cout<<"Yes it Has Cycle ";
}
else {
    cout<<"No it doesnt have any cycle ";
}
return 0;
}