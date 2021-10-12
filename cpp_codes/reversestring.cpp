#include<bits/stdc++.h>
using namespace std ;
class Stack
{
public:
   int top, capacity ;
   char *str;
};
Stack* createstack( int m)
{
    Stack *s;
    s= new Stack();
    s->top=-1;
    s->capacity= m;
    s->str= new char[(s->capacity*sizeof(char))];
     return s ;

}
void push(Stack *s ,char d)
{
    s->str[++s->top]=d ;
}
char pop(Stack *s)
{
    return s->str[s->top--];

}
int main()
{ 
    int n ,i;
    string word;
    cout<<"Enter the size of string :  ";
    cin>>n;
    cout<<"Enter word : ";
    cin>>word;
    fflush(stdin);
    Stack *s= createstack( n);
    for ( i = 0; i < n; i++)
    {
        push( s,word[i]);
    }
    for ( i = 0; i < n; i++)
    {
        word[i]=pop(s);
        
    }
    cout<<word<<endl;
    
}