#include<iostream>
#include<cstring>
using namespace std;
class Mystring{
    private:
    char* str; //pointer to a char[] that hold a c-style string
    public:
    Mystring():str(nullptr){
        str=new char[1];
        *str='\0';
    }   //No args Constructor
    Mystring(const char*s) //Overloaded Constructor
    :str(nullptr){
        if(str==nullptr)
        {
            str=new char[1];
            *str='\0';
        }

        str=new char[strlen(s)+1];
        strcpy(str,s);

    } 
    Mystring(const Mystring &source):str(nullptr)
    {
        str=new char[strlen(source.str)+1];
        strcpy(str,source.str);

    }; //copy constructor
    Mystring(Mystring &&source)
    :str(source.str){
        cout<<"Move constructor"<<endl;
        source.str=nullptr;
    } //Move constructor
    ~Mystring() //Destructor
    {
        if(str==nullptr)
        {
            cout<<"calling destructor for Mystring :: Nullptr"<<endl;
        }
        else{
            cout<<"calling destructor for Mystring :"<<str<<endl;
        }
         delete[]str;

    }
    Mystring &operator=(const Mystring &rhs)
    {
        cout<<"USing copy assignment"<<endl;
        if(this==&rhs)
        return *this;
        delete [] str;
        str=new char[strlen(rhs.str)+1];
        strcpy(str,rhs.str);
        return*this;
        
        
        }//copy assignment
    Mystring &operator=(Mystring &&rhs)
    {
        cout<<"Move assignment : "<<endl;
        if(this==&rhs)
        return *this;
        delete []str;
        str=rhs.str;
        rhs.str=nullptr;
        return *this;
    } //Move assignment
    Mystring operator-()const
    {
        char *buff=new char[strlen(str)+1];
        strcpy(buff,str);
        for(size_t i=0;i<strlen(buff);i++)
        {
            buff[i]=tolower(buff[i]);

        }
        
        Mystring temp{buff};
        delete []buff;
        return temp;

    } //make lowercase unary operator take no parameter
    Mystring operator+(const Mystring &rhs)const
    {
        char*buff=new char[strlen(str)+strlen(rhs.str)+1];
        strcpy(buff,str);
        strcat(buff,rhs.str);
        Mystring temp{buff};
        delete [] buff;
        return temp;

    } //concatenate binary operator take one parameter
    bool operator==(const Mystring &rhs)const
    {
        return (strcmp(str,rhs.str)==0);
    } //
//display method
    void display()const
    {
        cout<<str<<" : "<<get_length()<<endl;
    }
    //Length getter
    int get_length()const
    {
        return strlen(str);
    }
    //string getter
    const char*get_str() const
    {
        return str;
    }



};

int main()
{
    cout<<boolalpha<<endl;
    Mystring larry{"LARRY"};
    Mystring moe{"Moe"};
    Mystring stooge=larry;   //Larry
    larry.display();
    moe.display();
    cout<<(larry==moe)<<endl;
    cout<<(larry==stooge)<<endl;
    larry.display();
    Mystring larry2=-larry;
    larry2.display();
    Mystring stooges=larry+"Moe";
    //Mystring stooges="larry"+moe;
    Mystring two_stooges=moe+" "+"Larry";
    two_stooges.display();
    Mystring three_stooges=moe+" "+larry+ " "+ "curlly";
    three_stooges.display();

}