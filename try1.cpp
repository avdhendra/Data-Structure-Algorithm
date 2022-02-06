#include<bits/stdc++.h>
using namespace std;
vector<string>res;
void lettercase(char *s,int i)
{
    if(i==strlen(s))
    {
        res.push_back(s);
        return;
    }
    if(isdigit(s[i]))
    {
        lettercase(s,i+1);
    }
    else{
        s[i]=tolower(s[i]);
        lettercase(s,i+1);
        s[i]=toupper(s[i]);
        lettercase(s,i+1);
    }
    return ;
}
int main(){
char s[200];
cin>>s;

lettercase(s,0);
for(auto i:res)
{
    cout<<i<<" ";
}
return 0;
}