
/*

o(n) time complexity 
and o(n) space
*/

#include<bits/stdc++.h>
using namespace std;
int findLargestSeq(int A[],int n)
{
    unordered_map<int,int>um; //number ,streak_lenght
    for(int i=0;i<n;i++)
    {
        int no=A[i];
        // if that number left and right element is not present then we start new
        //streak
        if(um.count(no-1)==0 and um.count(no+1)==0)
        {
            um[no]=1 ; //in hash we insert the streak_length of that number=1

        }
        //if both left and right of that number is present 
        //so we join that element with left and right 
        //so the streak length =left_length +right_length+1

        else if(um.count(no-1) and um.count(no+1))
        {
           int len1=um[no-1];
           int len2=um[no+1];
           int streak=len1+1+len2;
           um[no-len1]=streak;   //we update start point of streak
           um[no+len1]=streak;

        }
        //if left of that number is present but not right
        //123 6789 .. 4 is has to enter
        else if(um.count(no-1) and !um.count(no+1) )
        {
            int len=um[no-1];
            um[no]=len+1;
            um[no-len]=len+1;
        }
        //if right of that number is present but not left
        else {
            int len=um[no+1];
            um[no+len]=len+1;
            um[no]=len+1;
        }
    }
    int largest=0;
    for(auto i:um)
    {
        largest=max(largest,i.second);
    }
    return largest;

}
int main(){
int A[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17,10};
int n=sizeof(A)/sizeof(int);
cout<<"Largest Streak Length : "<<findLargestSeq(A,n)<<endl;
return 0;
}