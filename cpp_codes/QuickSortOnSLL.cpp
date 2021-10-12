#include<bits/stdc++.h>
using namespace std ;
class node
{
    public:
    int data;
    node *next ;
};
void push(node **head, int num)
{
    node *n= new node ;
    n->data=num;
    n->next=*head;
    *head=n;
}
node* gettail(node *head)
{
    node *temp= head ;
    while (temp->next!=NULL)
    {
        temp=temp->next ;
    }
    return temp;
}
node* partition(node *head, node *end, node **newhead, node **newend)
{
    node *pivot=end;
    node *prev=NULL ,*curr=head ;
    while (curr!=pivot)
    {
        if (curr->data<pivot->data)
        {
            if ((*newhead==NULL))
            {
                *newhead=curr;
            }
            prev=curr;
            curr=curr->next;
        }
        else
        {
            if (prev)
            {
                prev->next=curr->next;
            }
            node *temp=curr->next;
            curr->next=NULL;
            end->next=curr;
            end=curr;
            curr=temp;
        }
        
    }
    if ((*newhead==NULL))
    {
        (*newhead)=pivot;
    }
    (*newend)=end;
       return pivot;
}
node* quicksort(node *head,node *tail)
{
    if (head==NULL || head==tail)
    {
        return head;
    }
    node *newhead=NULL ,*newend=NULL ;
    node *pivot=partition(head,tail,&newhead,&newend);
    if (newhead!=pivot)
    {
        node *temp= newhead ;
        while (temp->next!=pivot)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        newhead=quicksort(newhead,temp);
        temp=gettail(newhead);
        temp->next=pivot;
    }
     pivot->next=quicksort(pivot->next, newend);
     return newhead;
}
void qsort(node **headref)
{
   (*headref)=quicksort(*headref,gettail(*headref));
   return ;
}
void printList(node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main()
{
    node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    qsort(&a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}