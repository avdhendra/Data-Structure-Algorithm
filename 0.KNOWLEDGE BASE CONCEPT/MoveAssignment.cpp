#include<iostream>
#include<cstring>
using namespace std;
class String {
private:
char* m_data;
int m_size;
public:
//construtor
String()
{
m_size=0;
m_data=new char[m_size];
memcpy(m_data,0,m_size);
}
String(const char*string)
{
    cout<<"Created constructor"<<endl;
    m_size=strlen(string);
    m_data=new char[m_size];
    memcpy(m_data,string,m_size);
}
//copy constructor
String(const String & other)
{
    cout<<"Copied"<<endl;
    m_size=other.m_size;
    m_data=new char[m_size];
    //strcpy(m_data,other.m_data); can also be used in it
    memcpy(m_data,other.m_data,m_size);

}
//Move constructor
String(String &&other)noexcept
{
    cout<<"Moved"<<endl;
    m_size=other.m_size;
    m_data=other.m_data;
    other.m_data=0;
    other.m_data=nullptr;
}
//Move Assignment 
String& operator= (String &&other)noexcept
{
    //we move same object to it self we just need to return itself only but if not we 
    //move to 
    if(this!=&other)   //when dest=move(dest)
    {cout<<"MOved assignment"<<endl;
    delete [] m_data;    //using when dest have already have a value but dest=move(dest) it will delete the dest and we lost the data

    m_size=other.m_size;
    m_data=other.m_data;
    other.m_size=0;
    other.m_data=nullptr;
    }
    return *this;
}

//String&& is equal as move 

~String()
{
    cout<<"Destroyed"<<endl;
    delete m_data;
}
void print()
{
    for(int i=0;i<m_size;i++)
    {
        cout<<m_data[i];
    }
    cout<<endl;
}

};
class Entity


{
    private:
    String m_Name;
    public:
    //copy  constructor
    Entity(const String &name)
    :m_Name{name}{

    }
    //move construtor
    Entity(String &&name)
    :m_Name{move(name)}{

    }
    void printname()
    {
        m_Name.print();
    }
};

int main()
{
//    { Entity E1("Sarty");
//     E1.printname();
//    }
    String apple="Apple";
    String dest;
    cout<<"Apple : ";
    apple.print();
    cout<<"Dest : ";
    dest.print();
    dest=std::move(apple); //move is keyword for typecast it to r-value referene (string &&) apple
    cout<<"Apple : ";
    apple.print();
    cout<<"Dest : ";
    dest.print();

//different object but same data we still have to move because we move some ones data to other objecct
//but if object is same it just return this
/*
dest=move(dest);
*/

}