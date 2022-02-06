/*Create a copy of the pointed to data
each copy will have a pointer to unique storage in the heap
deep copy when you have a raw pointer as a class data member
*/
#include<iostream>
using namespace std;
class Deep{
    private:
    int *data;
    public:
    void set_data_value(int d){
        *data=d;
    }
    int get_data_value(){
        return *data;
    }
    //constructor
    Deep(int d){
        data=new int ;
        *data=d;
    };
    Deep(const Deep &source)
    {
        data=new int;
        *data=*(source.data);
        cout<<"Copy constructor-deep copy"<<endl;
    };
    ~Deep()
    {
         delete data;
         cout<<"Destructor freeing data"<<endl;
    }

};

void display_deep(Deep s)
{
    cout<<s.get_data_value()<<endl;
}

int main()
{
Deep obj1{100};
display_deep(obj1);
Deep obj2{obj1};
obj2.set_data_value(1000);
}