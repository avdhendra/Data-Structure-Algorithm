/*
   Flood Fill Algorithm
   -Flood Fill is A Simple Variant of BFS/DFS that can be used to 
   label (color )the various connected component present in a graph
   
   -It is Generally performed on Implicit Graph(2d matrix)

   -Starting From a Particular cell we call 'DFS' on the Neighbouring Cell
   to Color them Neighbours Can be '4' (Up,down,left,right) or '8' if we include diagonals also


   Algorithm for BFS based approach :

Create a queue of pairs.

Insert an initial index given in the queue.

Mark initial index as visited in vis[][] matrix.

Until the queue is not empty repeat step 3.1 to 3.6

Take the front element from the queue

Pop from the queue

Store current value/color at coordinate taken out 
from queue (precolor)

Update the value/color of the current index which is 
taken out from the queue

Check for all 4 direction i.e (x+1,y),(x-1,y),(x,y+1),(x,y-1) 
is valid or not and if valid then check that value 
at that coordinate should be equal to precolor and
 value of that coordinate in vis[][] is 0.

If all the above condition is true push the 
corresponding coordinate in queue and mark as 
1 in vis[][]

Print the matrix.

*/


#include<bits/stdc++.h>
using namespace std;

int R,C;
//         W,N,E,S
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
/*
          ^  N
          |
          |
          |
  W       |             E
<_________|_____________>      
          |
          |
          |
          |
          V S




i+dx and j+dy

*/
void PrintMat(char input[][50])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;i<C;i++)
        {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
}


//Ch is the Character to Be replaced
//color is the character to be added
void FloodFill(char mat[][50],int i,int j,char ch,char color)
{


//Base Case //we are inside the matrix
if(i<0 or j<0 || i>=R|| j>=C)
return;


// figure Boundary Condition
if(mat[i][j]!=ch)
{
    return ;
}
//Recursive Call
mat[i][j]=color;
for(int k=0;k<4;k++) //in all four direction
{
    FloodFill(mat,i+dx[k],j+dy[k],ch,color);
}






}



int main(){

cin>>R>>C;
char input[15][50];
for(int i=0;i<R;i++)
{
    for(int j=0;j<C;j++)
    {
        cin>>input[i][j];
    }
}
PrintMat(input);
FloodFill(input,8,13,'.','R');//  replace item . with R
return 0;
}
