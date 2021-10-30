#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linklist
{
node *start,*end;
public:
    linklist()
    {
        start=NULL;
        end=NULL;
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
    void append(int data)
    {
         node *temp = new node;
        temp->data = data;
        temp->next=NULL;      
        if(end==NULL)
        {
            start =temp;
            end=temp;
            return;
        }
        end->next=temp;
        end=temp;

         
    }
    int removefirst()
    {
        if(start==NULL)
        {
            cout<<"     Linklist is empty !!!! \n";
            return -1;  //its senital value / special value
        }
        if(start==end)
        {
            int t = start->data;
            delete start;
            start=NULL;
            end=NULL;
            return t;
        }
        node* temp=start;
        start=start->next;
        int tem = temp->data;
        delete temp;
        return tem;
    }
};
class queue{
    linklist l;
    public:

    void enqueue(int x)
    {
        l.append(x);
    }
    int dequeue()
    {
        return l.removefirst();
    }
    void print ()
    {
        l.display();
    }
};

int main()
{
    queue q;
    q.enqueue(12);
    q.enqueue(15);
    q.enqueue(20);
    q.print();
    cout<<q.dequeue()<<" removed"<<endl;
    cout<<q.dequeue()<<" removed"<<endl;
    q.enqueue(25);
    q.enqueue(27);
    q.print();
    return 0;
}