//Implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct node *next;
} node;
node *temp, *new, *head;

node *get_node()
{
    temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    return temp;
}
int main()
{
    int choice;
    while(1)
    {
        printf("\nMAIN MENU\n");
        printf("1.Push\t2.Pop\t3.Display\t4.Exit\t");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}
void push()
{
    int value;
    new=get_node();
    temp=new;
    if (temp == NULL)
        printf("Not able to push!\n");
    else
    {
        printf("Enter element to push: ");
        scanf("%d", &value);
        if (head==NULL)
        {
            temp->data = value;
            temp->next = NULL;
            head = temp;
        }
        else
        {
            temp->data = value;
            temp->next = head;
            head = temp;
        }
        printf("Element %d is pushed\n", value);
    }
}
void pop()
{
    int element;
    if (head == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        element = head->data;
        temp = head;
        head = head->next;
        printf("Element %d is poped\n", element);
        free(temp);
    }
}
void display()
{
    temp = head;
    if (temp == NULL)
        printf("Stack Underflow\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
