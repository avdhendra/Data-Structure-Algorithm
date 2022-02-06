//Q what is the one of the use of decltype in c++
//it checks the type of expression
#include<iostream>
using namespace std;
//templated function
/*
template<typename T1,typename T2>
T2 add(T1 a,T2 b)
{
    return a+b;
}
here we get logical error because in 1st cout t2 is float 
so the ans is 4.2
but in 2nd cout t2 is int so 3 to get rid of this we use decltype
int main()
{
    cout<<add(2,2.4)<<endl;
    cout<<add(1.8,2)<<endl;
}
*/
template<typename T1,typename T2>
//trailing type
auto add(T1 a,T2 b) -> decltype(a+b)
{
    return a+b;
}

int main()
{
    cout<<add(2,2.4)<<endl;
    cout<<add(1.8,2)<<endl;
}
