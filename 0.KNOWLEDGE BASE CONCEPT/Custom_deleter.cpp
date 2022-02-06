 /*
 
 Custom Deleter
 *Sometimes when we destroyed a smart pointer we need more than to just
 destroyed the object on the heap

 these are special use-case

 c++ smart Pointer allow u to provide custom deleters
 lots of way to achieve this


 **Function 
 **Lambdas

 
 
 
 */


#include<iostream>
#include<memory>
using namespace std;
class A
{
    private:
    int data;
    public:
    A():data{0}{
        cout<<"\tA constructor ("<<data<<")"<<endl;
    }
    A(int data):data{data}{
        cout<<"A Constructor ("<<data<<")"<<endl;
    }
    int get_data() const{
        return data;

    }
    ~A(){
        cout<<"A destructor ("<<data<<")"<<endl;
    }
};

void my_delete(A*ptr)
{
    cout<<"Using my custom function deleteer"<<endl;
    delete ptr;
}
int main()
{
    {
        shared_ptr<A>ptr1{new A{100},my_delete};
    }
    cout<<"+++++++++++++++++++++++++++"<<endl;
    //using  a lambda expression
    shared_ptr<A>ptr2(new A(100),[](A*ptr2){
        cout<<"Using my custom deleter lambda "<<endl;
        delete ptr2;}
    );


}

