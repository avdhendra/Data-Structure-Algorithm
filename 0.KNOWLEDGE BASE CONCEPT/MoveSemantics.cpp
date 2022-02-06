#include<iostream>
#include<cstring>
using namespace std;
class String 
{
    private:
    char* m_Data;
    uint32_t m_Size;
    public:
    String()=default;
    String(const char* string )
    {
        cout<<"Created"<<endl;
        m_Size=strlen(string);
        m_Data= new char[m_Size];
        memcpy(m_Data,string ,m_Size);
    }
    String (const String&other)
    {
        cout<<"Copied"<<endl;
        m_Size=other.m_Size;
        m_Data=new char[m_Size];
        memcpy(m_Data,other.m_Data,m_Size);
    }
    //Move constructor
    String(String &&other)noexcept
    {
cout<<"Moved"<<endl;
m_Size=other.m_Size;
m_Data=other.m_Data;
other.m_Data=0;
other.m_Data=nullptr;

    }
    ~String()
    {
        cout<<"Destroyed"<<endl;
        delete m_Data;
    }
    void print()
    {
        for(int i=0;i<m_Size;i++)
        {
            cout<<m_Data[i];
        }
        cout<<endl;
    }
};

class Entity{
    private:
    String m_Name;
    public:
    //copy constructor
    Entity(const String& name)
    
      : m_Name(name){

      }
      //Rvalue
      Entity(String &&name)
      :m_Name((String &&)name)
      {
           
      }
    
    void Printname()
    {
        m_Name.print();
    }
};
int main()
{
    Entity e1("sarty");
    e1.Printname();
}
