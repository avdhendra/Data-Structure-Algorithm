//How to stop SomeOne Inherting from your class
//use Final Keyword, Dont use any other tweak to achive that
// just use final keyword
#include<iostream>
using namespace std;
 
class Base final {
    int b_var;
    public:
    Base(){}
    Base(int var):b_var(var){}
};
class Derived: public Base{
    int d_var;
    public:
    Derived(){}
    Derived(int a,int b):Base(a),d_var(b){}
};
 
int main()
{
  Derived d(1,2);
  return 0;
}
/*final is not a keyword in C++ 11. final has meaning only when used in above contexts, otherwise it’s just an identifier. 
One possible reason to not make final a keyword is to ensure backward compatibility. There may exist production codes which use final for other purposes.
#include <iostream>
using namespace std;
 
int main()
{
    int final = 20;
    cout << final;
    return 0;
}*/


