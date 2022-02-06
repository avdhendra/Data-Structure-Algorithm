/*
memberwise copy
each data member is copied from the source object
the pointer is copied not what it points to (shallow copy)

PROBLEM When we release the storage in the destructor the other object still
refers to the released storage!!

*/
#include<iostream>
using namespace std;
class Shallow{
    private:
    int *data;
    public:
    void set_data(int d){
        *data=d;

    }
    int get_data(){
        return *data;
    }
    Shallow(int d)
    {
        data=new int;
        *data=d;
    }
    Shallow(const Shallow &source){
        data=source.data;
        cout<<"Copy constructor-Shallow copy"<<endl;
    }
    ~Shallow(){
        delete data;
        cout<<"Destructor freeing data"<<endl;
    }
};
void display_shallow(Shallow s){
    cout<<s.get_data()<<endl;
}
int main()
{
Shallow obj1{100};
display_shallow(obj1);
Shallow obj2{obj1};
obj2.set_data(1000);
return 0;
}
/*Program is crash if obj point to address get delete*/

