/*
Operator OverLoading 
the following operator cannot be overload
operator
::
:?
.*
.
sizeof
*/
#include<iostream>
#include<cstring>
using namespace std;
class Mystring{
    private:
    char *str; //pointer to a char[] that hold a c-style string 
    public:
    Mystring();  //No-args constructor
    Mystring(const char*s); //overloading constructor
    Mystring (const Mystring &source); //copy constructor
    ~Mystring(); //destructor
    void display()const;
    int get_length()const; //getter
    const char*get_str()const;

};
//No-args constructor
Mystring::Mystring():str(nullptr)
{
    str=new char[1];
    *str='\0';
}
Mystring::Mystring(const char*s):str(nullptr)
{
    if(s==nullptr)
    {
        str=new char [1];
        *str='\0';
    }
    else{
        str=new char[strlen(s)+1];
        strcpy(str,s);
    }
}
//Copy constructor 
Mystring::Mystring(const Mystring &source)
:str(nullptr){
    str=new char[strlen(source.str)+1];
    strcpy(str,source.str);
}
//Destructor
Mystring::~Mystring()
{
    delete []str;
}
void Mystring::display()const{
    cout<<str<<":"<<get_length()<<endl;

}
//length getter
int Mystring::get_length()const {
    return strlen(str);
}
//string getter
const char*Mystring::get_str()const{
    return str;
}
int main()
{
    Mystring empty;
    Mystring larry("larry"); //overloaded constructor
    Mystring stooge{larry}; //copy constructor
    empty.display();
    larry.display();
    return 0;
}