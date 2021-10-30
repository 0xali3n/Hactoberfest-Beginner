#include<bits/stdc++.h>
using namespace std;
class Stack 
{
    public :
    int top, capacity ;
    int *array ;
};
Stack * createstack(int m)
{
     Stack *s= new Stack();
     s->top=-1;
     s->capacity= m;
     s->array= new int[s->capacity*sizeof(int )];
     return s;
}
int isstackempty( Stack *s)
{
    return (s->top==-1);
}
void push(Stack *s, int n)
{
   

            s->array[++s->top]=n;
    
}
int pop( Stack *s)
{
    if (!isstackempty(s) )
    return s->array[s->top--];
}
int peep( Stack *s)
{
    if (!isstackempty(s))
    {
        return s->array[s->top];
    }
    
}
int main()
{
    int n,i,j;
    cout<<"Enter number of integers :  ";
    cin>>n;
    int arr[n];
    Stack *s;
    s=createstack( n);
    for ( i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    push(s, arr[0]);
    for ( i = 1; i < n; i++)
    {
         while (!isstackempty(s)&&arr[i]>peep(s))
        {
            cout<<pop(s)<<" -> "<<arr[i]<<endl;
        
        }
         push( s, arr[i]);
        
    }
    while (!isstackempty(s))
    {
        cout<<pop(s)<<" => -1"<<endl;
    }
    
}