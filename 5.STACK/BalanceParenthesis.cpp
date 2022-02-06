#include<bits/stdc++.h>
using namespace std;
bool isValid(char*S)
{
    stack<char>stk;
    for(int i=0;S[i]!='\0';i++)
    {
        char ch=S[i];
        if(ch=='(')
        {
            stk.push(ch);
        }
        else if(ch==')')
        {
            if(stk.empty() or stk.top()!='(')
            {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}
int main(){
char S[200]="((a+b)+(b+c))";
if(isValid(S))
{
    cout<<"BalanceParenthesis "<<endl;

}
else{
    cout<<"not balance"<<endl;
}


return 0;
}