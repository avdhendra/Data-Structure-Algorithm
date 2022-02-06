#include<bits/stdc++.h>
using namespace std;
class Stk{
    public:
Stk *Next;
int data;
Stk*top;
Stk(int d)
{
    Next=NULL;
    data=d;
}

void push(int d) 
{
  Stk*head;
  head=new Stk(d);
  if(!head)
  {
      cout<<"Heap Overflow";
      exit(1);
  }
    head->data=data;
    head->Next=head;
    top=head;

}
void pop(){
Stk*temp;

    if(top==NULL){
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
else{
    temp=top;
top=top->Next;
temp->Next=NULL;
delete(temp);

}


}
int TOP()
{
     
    // Check for empty stack
    if (top!=NULL)
        return top->data;
    else
        exit(1);
}
void display(){
    Stk*temp;
    if(top==NULL)
    {
    cout<<"Stack Underflow";
    exit(1);	

    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
 
            
            temp = temp->Next;
        }
    }
}
};
int main(){
Stk element(5);
element.push(6);
element.push(7);
element.pop();
element.display();
return 0;
}