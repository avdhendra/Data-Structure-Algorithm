/*
Generate all the Subset of Given string
with bit masking


set={1,2,3}
   binary representation
0       =000 ={}
1       =001 ={3}
2       =010 ={2}
3       =011 ={2,3}
4       =100 ={1}
5       =101 ={1,3}
6       =110 ={1,2}
7       =111 ={1,2,3}


0 --> 1 is not included

1  --> 2 is included in the set

0 --->3 is not included in the set





*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<char>>getSubsets(string &s)
{
    int size=s.length();
    int subsetnum=(1<<size);
    vector<vector<char>>allSubsets;
    for(int subsetMask=0;subsetMask<subsetnum;++subsetMask)
    {
        vector<char>subset;
        for(int i=0;i<size;i++)
        {
            if((subsetMask & (1<<i))!=0)
            {
                subset.push_back(s[i]);
            }
            allSubsets.push_back(subset);
        }

    }
    return allSubsets;

}
int main(){
string s;
cin>>s;
vector<vector<char>>st=getSubsets(s);

return 0;
}