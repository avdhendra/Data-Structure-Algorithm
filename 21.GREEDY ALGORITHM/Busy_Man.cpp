/*

You have a big schedule of activities. Your aim is
to do as much as activities as possible.

In the given figure, if you go to date with crush, 
you cannot participate in the coding contest and you 
can’t watch the movie. Also if you play DotA, 

you can’t study for the exam. 
If you study for the exam you can’t sleep
peacefully. The maximum number of activities 
that you can do for this schedule is 3.


Activitys
1.dating with Crush 1pm-->5pm

2.Participate in coding contest 1pm---->8pm

3. Play Dot A
3.watch movie 

4.sleep peacefull

5.study for exam
 




 we need some criteria to pick a activity

1.) sort according to start time (Start early) ---> but this not be good idea may be that activity duration is large
 we cann't do other activity

2.) sort according to duration time(which duration is less) 

 what if a activity come in between two activity 

 <--------------> <-------------->
          <--------------->

like this we can skip the two activity for one activity 

so this apporach is wrong

3.) sort according to end time which activity end first we take it

(this is Greedy thinking)


Spoj Problem

*/
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2)
{
    return p1.second<p2.second;
}
int main(){
int t,start,end;
cin>>t;
while(t--)
{
    vector<pair<int,int>>v;
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>start>>end;
        v.push_back(make_pair(start,end));
    }
    //Activity Selection Algorithm
    //Sort
    sort(v.begin(),v.end(),compare);
   int res=1;
   int fin=v[0].second;
   //iterate Over reamining activites
   for(int i=1;i<N;i++)
   {
       if(v[i].first>=fin)
       {
           fin=v[i].second;
           res++;
       }
       
   }
   cout<<res<<endl;
    v.clear();
}
return 0;
}