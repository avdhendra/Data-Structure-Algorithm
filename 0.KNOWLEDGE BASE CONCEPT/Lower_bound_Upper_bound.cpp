#include<bits/stdc++.h>
using namespace std;
//if array vector are sorted then they works aso(log n but if not it take o(n))time
//they return location of that element
//upperbound only return large element of the given element
//lowerbound can give that value if exist but if not then the next largest element than that value

int main(){
//For array
int A[]={7,1,3,5,5,2,10,9};
int size=sizeof(A)/sizeof(A[0]);
sort(A,A+size);
int *ptr=lower_bound(A,A+size,4);
int *ptr2=upper_bound(A,A+size,5);
cout<<*ptr<<endl;
cout<<*ptr2<<endl;
int*p1=lower_bound(A,A+size,11);

if(p1==(A+size))
{
    cout<<"Not Found"<<endl;
}
else{
    cout<<*p1<<" "<<endl;
}
vector<int>l{6,1,5,8,9,8,10};
sort(l.begin(),l.end());
auto it=upper_bound(l.begin(),l.end(),3);
if(it==l.end())
{
    cout<<"Not Found";

}
cout<<*it<<endl;

//but for set and map it work as o(n) if u dont use it as key element

return 0;
}