#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};
class linklist
{
node *start;
public:
    linklist()
    {
        start=NULL;
    }
    void addatbeg(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next=NULL;      
        if(start==NULL)
        {
            start =temp;
            return;
        }
        temp->next=start;
        start=temp;
    }
    void display()
    {
             node*temp;
            temp=start;
        if(temp==NULL)
        {
            cout<<"---Linklist is empty------\n";
            return;
        }
            while(temp->next!=NULL)
            {
                cout<<temp->data<<"  ";
                temp=temp->next;
            }
            cout<<temp->data<<"  "<<"\n";
    }
    int removefirst()
    {
        if(start==NULL)
        {
            cout<<"     Linklist is empty !!!! \n";
            return -1;//-1 value special meaning 
        }
        node* temp=start;
        start=start->next;
        int dt=temp->data;
        delete temp;
        return dt;

    }
    void firstprint()
    {
       if(start==NULL)
        {
            cout<<"---Linklist is empty------\n";
            return;
        }  
        cout<<start->data<<" ";
    }
    
};

class dynamicstack
{
private:
    linklist l;
public:
    void push(int x)
    {
        l.addatbeg(x);
    }
    int pop(){
        return l.removefirst();
    }
    void peek()
    {
        l.firstprint();
    }
    void displaywhole()
    {
        l.display();
    }
};


int main()
{
    dynamicstack s1;
s1.push(10);
    s1.displaywhole();
    s1.push(20);
    s1.displaywhole();
    s1.push(30);
        s1.displaywhole();
    cout<<s1.pop()<<" removed from the stack \n";
        s1.displaywhole();
    cout<<s1.pop()<<" removed from the stack \n";
        s1.displaywhole();
    cout<<s1.pop()<<" removed from the stack \n";
        s1.displaywhole();
    cout<<s1.pop()<<" removed from the stack \n";//should cause underflow
        s1.displaywhole();
    return 0;
}
