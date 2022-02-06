/***
 * Given a List of n string S0,S1,S2,S3...Sn-1 
 
 *Each consist of digit and space (not alpha bet) 
 
 *Number of spaces is the same for each entry,the goal is to implement a variation of a sort command 

 *None of the string contain consecutive spaces 
 
 *No string starts with a space nor end with it space are used to divide string into coloumn

 *integer denoting the colomn used as a key in comparision the left most column is denoted by 1
  for ex:- S1 51 _ 32 _ 89
           S2 640_83_90
           key =2 which means we have to compare 2 coloumn element 
           which is 32 and 83

 * comparision type:- Lexicograph or numeric 

 * 
 * test case
 
 * 3-number of string
 * 92 022 -s1 string 022 is key
 * 82 12 s2
 * 77 13 s3
 
 * first we have to use tokenization
 * convert key into numeric
 * 
 * sorting -lexio,numeric 
 * is reverse is true check
 * */
#include<bits/stdc++.h>
using namespace std;
//we extract string about key from this function

string ExtractStringAtKey(string str,int key)
{  
    /*
    first call 66_56_75
    we get 66 then 56 then 75
    we get this by .c_str()
    we have to convert str to char
    strtok take char and delimiter
    */
    char *s=strtok((char*)str.c_str()," ");
    while(key>1)
    {
        s=strtok(NULL," ");
        key--;
    }
    return (string)s;

}
int convertToInt(string S)
{
    int ans=0;
    int p=1;
    for(int i=S.length()-1;i>=0;i--)
    {
        ans+=((S[i]-'0')*p);
        p=p*10;
    }
    return ans;
}
bool numericCompare(pair<string,string>S1,pair<string,string>S2)

{
    string key1,key2;
    key1=S1.second;
    key2=S2.second;
    return convertToInt(key1)<convertToInt(key2);

}
bool lexioCompare(pair<string,string>S1,pair<string,string>S2)
{
    string key1,key2;
    key1=S1.second;
    key2=S2.second;
    //we can compare directly
    return key1<key2;

}
int main(){
    int n;
    cin>>n;
    cin.get();
    string A[100];
    for(int i=0;i<n;i++)
    {
        getline(cin,A[i]);
    }
    int key;
    cin>>key;
    string reversal,ordering; //reverse the order we gave true or false
                             // how ordering will be done lexio and numeric we have to gave it by typing
    //helper function extract a token
    //sort extract token every time we compare and store it once 
    cin>>reversal;
    cin>>ordering;
    
    pair<string,string>strPair[100];
    for(int i=0;i<n;i++)
    {
        strPair[i].first=A[i];
        strPair[i].second=ExtractStringAtKey(A[i],key);
    }
    //Next=Sorting
    if(ordering=="numeric"){
        sort(strPair,strPair+n,numericCompare);
    }
    else
    {
        sort(strPair,strPair+n,lexioCompare);
    }
//Reversal
if(reversal=="true")
{
    for(int i=0;i<n/2;i++)
    {
        swap(strPair[i],strPair[n-i-1]);
    }
}
//Print the output
for(int i=0;i<n;i++)
{
    cout<<strPair[i].first<<" ";
}
return 0;


}