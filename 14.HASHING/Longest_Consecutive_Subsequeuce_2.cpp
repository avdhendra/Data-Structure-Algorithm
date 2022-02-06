/*
This problem can be solved in O(n) time using an 
Efficient Solution. The idea is to use Hashing.
 We first insert all elements in a Set. Then check
all the possible starts of consecutive subsequences.

*/
#include<bits/stdc++.h>
using namespace std;
//Return Length of the longest 
//Contiguous Subsequence
int findLongestConseqSubSeq(int *A,int n)
{
    unordered_set<int>S;  //this set take only unique value
    
    //Hash all the array element 
    for(int i=0;i<n;i++)
    {
        S.insert(A[i]);  //0(1) time in insertion
    }
    //Check each possible sequence from 
    //the Start then update optimal length

int max_streak=1;
    //iterate over all element 
    //target those which a streak can start
    for(int i=0;i<n;i++)
    {
        //if current element is the Starting 
        //element of a sequeuce
        if(S.find(A[i]-1)==S.end())  //that mean one smaller than that number is not find in set
        //so we start from here
        {//a[i] is starting point of streak
        //traverse the entire range that is container in that streak
        int next_no=A[i]+1;
      int streak_len=1;
      while(S.find(next_no)!=S.end()) //if we keep find the next number of that element we increase the size of streak
        {
            next_no+=1; //number next to next_no
            streak_len+=1;

        }
        max_streak=max(streak_len,max_streak);
    }
    }
return max_streak;
} 
int main(){
int A[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
int n=sizeof(A)/sizeof(int);
cout<<"Largest Streak Length : "<<findLongestConseqSubSeq(A,n)<<endl;
return 0;
return 0;
}