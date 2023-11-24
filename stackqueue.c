//Stack using two queues
#include<stdio.h>
#include<stdlib.h>
#define size 5
int que1[size];
int que2[size];
int front1=-1,rear1=-1;
int front2=-1,rear2=-1;
int count=0;

void push(int x)
{
    enqueue1(x);
    count++;
}
int pop()
{
    int d;
    for(int i=0;i<count-1;i++) //All the elements will be dequeued except the last element
    {
        int element=dequeue1();
        enqueue2(element);
    }
    d=dequeue1();   //Store the last element in variable d
    printf("The deleted element is %d\n",d);
    count--;
    for(int i=0;i<count;i++)
    {
        int item=dequeue2();
        enqueue1(item);
    }
    return d;
}
int enqueue1(int x)
{
    if(front1==-1)
    front1=0;

    rear1=(rear1+1)%size;
    que1[rear1]=x;
    return 1;
}
int dequeue1()
{
    int item=que1[front1];
    if(front1==rear1)
        front1=rear1=-1;
    else
        front1=(front1+1)%size;
    return item;
}
void enqueue2(int element)
{
    if(front2==-1)
        front2=0;
    rear2=(rear2+1)%size;
    que2[rear2]=element;
}
int dequeue2()
{
    int item=que2[front2];
    if(front2==rear2)
        front2=rear2=-1;
    else
        front2=(front2+1)%size;
    return item;
}
void display()
{
    if(front1==-1)
        printf("Stack is empty");
    else{
        int i;
        printf("Stack Elements=\n");
        for(i=front1;i != rear1;i=(i+1)%size)
        {
            printf("%d\n",que1[i]);
        }
        printf("%d\n",que1[i]);
    }
}
int main()
{
    int ch,z;
    while(1)
    {
            printf("\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.QUIT\n");
            printf("Enter your choice=");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:if(rear1==size-1)
                          printf("Stack is full");
                       else
                          {
                              printf("Enter element you want push=");
                              scanf("%d",&z);
                              push(z);
                          }
                          break;
                case 2:if(front1==-1)
                        printf("Stack is empty");
                        else
                            pop();
                        break;
                case 3:display();
                break;
                case 4:exit(0);

            }
    }
}
