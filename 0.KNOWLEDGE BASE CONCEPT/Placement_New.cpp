//What is placement new
/*
Normal new allocates memory in heap and constructs objects tehre whereas using placement new, object construction can be done at known address.
With normal new, it is not known that, at what address or memory location it’s pointing to, whereas the address or memory location that it’s pointing is known while using placement new.
The deallocation is done using delete operation when allocation is done by new but there is no placement delete, but if it is needed one can write it with the help of destructor
*/


/*
As it allows to construct an object on memory that is already allocated , it is required for optimizations as it is faster not to
 re-allocate all the time. There may be cases when 
 it is required to re-construct an object multiple 
 times so, placement new operator might be more 
 efficient in these cases.
 */
#include<iostream>
using namespace std;
class Base{
    public:
    Base()
    {
        cout<<"constructor"<<endl;
    }
    ~Base()
    {
        cout<<"destrucor"<<endl;
    }
};
int main()
{
    cout<<sizeof(Base)<<endl;
    cout<<"Normal case: New"<<endl;
    Base *obj=new Base(); //create a space in kernel where constructor store
    
    delete obj;
    //placement new case
    cout<<"Placement mew case :"<<endl;
    char* memory=new char[10*sizeof(Base)];
    Base *obj1=new(&memory[0]) Base();
    Base *obj2=new(&memory[4]) Base();
    Base *obj3=new(&memory[8]) Base();
    obj1->~Base();//here destructor is called explicity
    obj2->~Base();
    obj3->~Base();
    delete[] memory;
    return 0;
}