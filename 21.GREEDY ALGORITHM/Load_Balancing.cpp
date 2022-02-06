 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 
     int arr[9000];
     int n,i,val,diff;
  while(1)
   {
         //Take Input current test case
         int max_load=0,load=0;
      cout<<"enter the Number of Processor : ";
         cin>>n;
         cout<<endl;
         //stop take input if N==-1
         if(n==-1)
           break;

cout<<"enter number of Job assign to Each Processor: "<<endl;
        for(int i=0;i<n;i++)
        {
           cin>>arr[i];
          load+=arr[i];  //sum all the job assign to processor
        }

        //check that load divide equally in each block if not return -1
        if(load%n!=0)
        {
         cout<<-1<<endl;
         continue;
        }
     //Find the Load that is to Be divided equally

      load=load/n;

//Greedy step
// | 0  |  6  |  10  | 0  |
/*
|0-4|=4
*/
         diff=0;
     for(int i=0;i<n;i++)
    {
     //find the difference btw final load to be assigned and current load
    diff+=(arr[i]-load);
   int ans=abs(diff);
   max_load=max(max_load,ans);

    }
    cout<<"Max Load : "<<max_load<<endl;
 }
 
 return 0;

 }