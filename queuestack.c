//Queue using two stack
#include<stdio.h>
#define size 5
int st1[size],st2[size];
int top1=-1;
int top2=-1;
int count=0;

void push1(int item)
{
    if(top1==size-1)
        printf("\nOVERFLOW 1");
    else
    {
        top1++;
        st1[top1]=item;
    }
}
int pop1()
{
    if(top1==-1)
        printf("UNDERFLOW 2");
    else
    {
        int val=st1[top1];
        top1--;
        return val;

    }
}
void push2(int element)
{
    if(top2==size-1)
        printf("OVERFLOW 2");
    else
    {
        top2++;
        st2[top2]=element;

    }
}
int pop2()
{
    if(top2==-1)
        printf("UNDERFLOW 2");
    else
    {
        int x=st2[top2];
        top2--;
        return x;
    }
}
void enqueue(int x)
{
    push1(x);
    count++;
}
void dequeue()
{
    if(top1==-1 && top2==-1)
        printf("Queue is Empty");
    else
    {
        for(int i=0;i<count;i++)   //count represents the number of elements in a stack
        {
            int element=pop1();    //Pop all the elements from stack1
            push2(element);        //Push all that elements in stack2
        }
        int b=pop2();              //Store the value of top of stack2
        printf("The dequeued element is %d",b);
        count--;
        for(int i=0;i<count;i++)
        {
            int element=pop2();    //Pop all the elements from stack2
            push1(element);        //Again push them onto stack1
        }
    }
}
void display()
{
    for(int i=0;i<=top1;i++)
    {
        printf("%d\n",st1[i]);
    }printf("\n");
}
int main()
{
    int z,ch;
    while(1)
    {
            printf("\nMENU\n1.EQUEUE\n2,DEQUEUE\n3.DISPLAY\n4.QUIT\n");
            printf("Enter your choice=");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:if(top1==size-1)
                          printf("Queue is full");
                       else
                          {
                              printf("Enter element you want enqueue=");
                              scanf("%d",&z);
                              enqueue(z);
                          }
                          break;
                case 2:dequeue();
                        break;
                case 3:display();
                break;
                case 4:exit(0);

            }
    }
}
