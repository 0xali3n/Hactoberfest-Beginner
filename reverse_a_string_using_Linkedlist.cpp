#include<iostream>
using namespace std;
struct node
{
    char data;
    struct node *next;
};
struct node *first;
void ll(char a)
{
    struct node *nn;
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=a;
    nn->next=NULL;
    if(first==NULL)
    {
        first=nn;
    }
    else
    {
        nn->next=first;
        first=nn;
    }

}
void display()
{
    cout<<"Reverse of the String is :"<<endl;
    struct node *temp;
    temp=first;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main()
{
    first=NULL;
    string s;
    cout<<"Enter the String: "<<endl;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        ll(s[i]);
    }
    display();
}
