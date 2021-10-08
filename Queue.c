#include<stdio.h>
#define MAX 5
struct queue
{
    int ar[MAX];
    int front,rear;

}s;
void insertion(int n)
{
    if(s.rear==MAX-1)printf("QUEUE is full");
    else if(s.rear==-1)
    {
        s.rear=s.front=0;
        s.ar[s.rear]=n;
    }
    else
    {
        s.rear++;
        s.ar[s.rear]=n;
    }
}
int deletion()
{ int b;
  if(s.front==-1)printf("QUEUE is empty\n");
  else if(s.rear==s.front)
  {
      b=s.ar[s.front];
      s.front=s.rear=-1;
  }
  else
  {
      b=s.ar[s.front];
      s.front++;
  }
  return b;
}
  void display()
  {
      if(s.rear==-1)printf("QUEUE is empty");
      else{
        for(int i=s.front;i<=s.rear;i++)printf("%d ",s.ar[i]);
      }
  }
  void main()
  {
      s.front=s.rear=-1;
      int choice,k=1,n;
      while(k==1)
      {
          printf("Press 1 for insertion\nPress 2 for deletion\nPress 3 for display\n");
          scanf("%d",&choice);
          switch(choice)
          {
          case 1:
            printf("Enter the integer to be inserted ");
            scanf("%d",&n);
            insertion(n);
            break;
          case 2:
             n=deletion();
            if(s.rear!=-1)printf("deleted value is: %d",n);
            break;
          case 3:
            display();
            break;
          default:
            printf("Wrong option entered");
          }
      printf("If you want to continue the procedure press 1\nPress 0 for exit\n");
        scanf("%d",&k);
      }
  }


