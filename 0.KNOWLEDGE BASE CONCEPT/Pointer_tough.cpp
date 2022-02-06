#include<bits/stdc++.h>
using namespace std;
int main(){
int i;
const char*arr[]={"Prep","Bytes","coding","Plateform"};
const char*(*ptr)[4]=&arr;
cout<<++(*ptr)[2];
return 0;
}