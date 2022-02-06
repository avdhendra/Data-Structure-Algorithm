/*Class A->ClassB
   |          |
   class C-> cLass D it inhert two time class A so to prevent it we use
   vitrual base class
   */
  #include<iostream>
  using namespace std;
  class Student
  {
      protected:
      int roll_no;
      public:
      void set_number(int a)
      {
          roll_no=a;
      }
      void print_number(void)
  {  
      cout<<"your roll no"<<roll_no<<endl;
  }
  };
  class Test:virtual public Student{
      protected:
      float maths,physics;
      public:
      void set_marks(float m1,float m2)
      {
          maths=m1;
          physics=m2;
      }
      void print_marks(void)
  {
cout<<"U have obtained"<<endl;
cout<<"Maths : "<<maths<<endl;
cout<<"physics : "<<physics<<endl;
  }
  };
  class Sports:virtual public Student{
      protected:
      float score;
      public:
      void set_score(float src)
      {
          score=src;
      }
      void print_score(void)
      {
          cout<<"Score : "<<score<<endl;
      }
  };
  class Total:public Test,public Sports{

private:
float total;
public:

void display(void)
{
total=maths+physics+score;
print_number();
print_score();
print_marks();
cout<<"ur total score is "<<total<<endl;

}
  };
  int main()
  {
    Total h1;
    h1.set_number(420);
    h1.set_marks(75.1,99.4);
    h1.set_score(9);
h1.display();


  }

  /*
Virtual base classes are used in virtual inheritance in a way of
preventing multiple “instances” of a given class appearing in an
inheritance hierarchy when using multiple inheritances.
  */