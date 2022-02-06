#include<bits/stdc++.h>
using namespace std;
void helloWorld(int a)
{
    cout<<"Helloworld???"<<":"<<a<<endl;
}
int main(){
    /*void(*function)()*/  
auto function=helloWorld;
function(5);
function(6);
return 0;
}