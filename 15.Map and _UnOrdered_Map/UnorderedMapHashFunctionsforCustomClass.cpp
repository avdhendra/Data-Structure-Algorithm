#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Student{
    public:
    string firstname;
    string lastname;
    string rollno;
    Student(string firstname,string lastname,string rollno)
    {
        this->firstname=firstname;
        this->lastname=lastname;
        this->rollno=rollno;
    }
    bool operator ==(const Student &s)const
    {
        return rollno==s.rollno?true:false;
    }


};
class hashfunction{
    public:
    size_t operator()(const Student&s)const{
        return s.firstname.length()+s.lastname.length();
    }


};
int main()
{
unordered_map<Student,int,hashfunction>S;

Student S1{"Prateek","Narang","010"};
Student S2{"Rahul","Kumar","023"};
Student S3{"Prateek","Gupta","030"};
Student S4{"Rahul","Kumar","120"};
S[S1]=100;
S[S2]=120;
S[S3]=150;
S[S4]=160;
for(auto x:S)
{
    cout<<"["<<x.first.firstname<<","<<x.first.lastname<<"] "<<" = "<<x.second<<endl;
}
return 0;
}