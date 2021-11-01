#include <stdio.h>
int main()
{
    int n, front = -1, rear = -1, ch, el, i;
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    int queue[n];
    do
    {
        printf("\nEnter the operation you want to do");
        printf("\n1)Enter element");
        printf("\n2)Delete element");
        printf("\n3)Display elements");
        printf("\n4)Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (front == 0 && rear == n - 1)
                printf("\nOverflow");
            else if (front == -1 && rear == -1)
            {
                printf("\nEnter the element of queue:");
                scanf("%d", &el);
                rear = 0;
                front = 0;
                queue[rear] = el;
            }
            else if (rear == n - 1)
            {
                printf("\nqueue full");
            }
            else
            {
                printf("\nEnter the element of queue:");
                scanf("%d", &el);
                rear++;
                queue[rear] = el;
            }
            break;
        case 2:
            if (front == -1 && rear == -1)
            {
                printf("\nUnderflow");
            }
            else if (front == rear)
            {
                front = rear = -1;
                printf("\nElement deleted");
            }
            else
            {
                front += 1;
                printf("\nElement deleted");
            }
            break;
        case 3:
            i = front;
            printf("\nElements of queue: ");
            while (i <= rear)
            {
                printf("%d ", queue[i]);
                i++;
            }
            break;
        case 4:
            printf("\nExiting");
            break;
        default:
            printf("\nInvalid choice");
        }
    } while (ch != 4);
    return 0;
}