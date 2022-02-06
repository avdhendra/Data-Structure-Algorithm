/**
 A C++ Program to implement Game of Nim . The Program
 assume that Both Players are playing optimally
*/
#include<bits/stdc++.h>
using namespace std;
#define COMP 1
#define HUMAN 2
/**
 A Structure to hold the two parameter of a Move

 A Move has two parameters:-
 1) Pile_index=The index of pile from which stone is going to be removed

 2) Stones_remove=Number of Stone removed from the Pile indexed=pile_index

*/
class moves{
    public:
    int pile_index;
    int stone_removed;
};
/*
Piles[] -> array having the initial count of stones/coins
            in each piles before the game has started.
n     -> Number of piles
  
The piles[] are having 0-based indexing
  
 A C function to output the current game state.
*/
void showpiles(int piles[],int n) {
    int i;
    cout<<"Current Game Status -->";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<piles[i];
        
    }
    cout<<"\n";
    return;
}
//A C++ function that returns true if game has ended and 
//False if game is not yet over
bool gameOver(int piles[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(piles[i]!=0) {
            return false;
        }
        return true;
    }
}
//A c++ function to declare the winner of the game
void declareWinner(int whoseTurn)
{
    if(whoseTurn==COMP)
    {
        cout<<"\nHUMAN WON\n";
    }
    else
    {
        cout<<"\nCOMPUTER WON \n";
    }
    return;
}
//A C++ function to calculater the NIM SUM at any Point in
//of the game
int calculaterNimSum(int piles[],int n){
    int i,nimsum=piles[0];
    for(int i=1;i<n;i++)
    {
        nimsum=nimsum^piles[i];
    }
    return nimsum;
}
//A C++ function to make move of the NIM Game
void makeMove(int piles[],int n,moves* move1)
{
    int i,nim_sum=calculaterNimSum(piles,n);
     // The player having the current turn is on a winning
    // position. So he/she/it play optimally and tries to make
    // Nim-Sum as 0
    if(nim_sum!=0){
        for(i=0;i<n;i++){
            //if this is not an illegal Move
            //then make this move
           // r<b when b is 
            if((piles[i]^nim_sum)<piles[i]){
                (*move1).pile_index=i;
                (*move1).stone_removed=piles[i]-(piles[i]^nim_sum);
                piles[i]=(piles[i]^nim_sum);
                break;
            }
        }
    }

}
int main(){

return 0;
}