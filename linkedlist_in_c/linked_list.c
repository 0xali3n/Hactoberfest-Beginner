#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head;

void insert_at_start()
{
    struct node *temp, *newnode;
    int num;
    printf("Enter the value at start\n");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (head == NULL)
    {
        head = newnode;
        head->link = NULL;
    }
    else
    {
        temp = head;
        head = newnode;
        head->link = temp;
    }
}

void insert_at_end()
{
    struct node *temp, *newnode;
    int num;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value at end\n");
    scanf("%d", &num);
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        head->data = num;
        head->link = NULL;
    }
    else
    {
        temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
        temp = temp->link;
        temp->link = NULL;

    }
}

void delete_from_end()
{
    struct node *temp, *prev;
    if (head == NULL)
    {
        printf("list is already empty\n");
    }
    else if (head->link == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        temp = prev = head;

        while (temp != NULL)
        {
            temp = temp->link;
            if (temp->link != NULL)
            {
                prev = prev->link;
            }
            else
            {
                break;
            }
        }
        prev->link = NULL;
        free(temp);
    }
}

void delete_from_start()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("list already empty\n");
    }
    else
    {
        temp = head;
        head = head->link;
        temp->link = NULL;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("list iss empty\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    head =NULL;
    int num = 0;
    int ch;
    while (1)
    {
        printf("\n---------Linked List---------\n");
        printf("Enter choices :-\n");
        printf("1. Insert at start\n2. delete at start\n3. display\n4. Exit\n5. insert at end\n6. delete at end\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_at_start();
            break;
        case 2:
            delete_from_start();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        case 5:
            insert_at_end();
            break;
        case 6:
            delete_from_end();
            break;
        default:
            printf("Entered choice is invalid\n");
            break;
        }
    }
}
