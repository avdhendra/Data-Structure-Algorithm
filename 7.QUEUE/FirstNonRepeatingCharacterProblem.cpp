#include<iostream>
#include<queue>
using namespace std;

int main(){

queue<char>Q;
//freq for alphabets 1-26
int freq[27]={0};
char ch;
cout<<"enter element : ";
cin>>ch;
while(ch!='.')
{
    //logic will go there
    //insert in the q and f table 
//we have to map the element according to there index
//like for a index=0,b=1 etc.
//how we gonna do it 'a'-'a'=0,'b'-'a'=61-60 =1 using ascii value
   
   // insert the element in queue

   Q.push(ch);
   //increment the freq in arr at that 
   freq[ch-'a']++;

   //query
   while(!Q.empty())
   {
       //front element freq and index
       int idx=Q.front()-'a';
       //if frequecy of front element in more than the 1
       if(freq[idx]>1)
       {
         Q.pop();
       }
       //if frequency front is less than 2 
       else{
           cout<<Q.front()<<endl;
           break;
       }
   }
   //if q is empty
   if(Q.empty())
   {
       cout<<"-1"<<endl;
   }

    cin>>ch;
}

return 0;
}