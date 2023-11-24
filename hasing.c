#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];
int i;
int value;
void insert(int value)
{
    int key=value%size;
    if(arr[key]==-1)
    {
        arr[key]=value;
        printf("\n%d is inserted at [%d]",value,key);
    }
    else
    {
        printf("\nCollision Occurs");
        int i=1;
        int originalkey=key;
        while(arr[key]!=-1)
        {
            key=(originalkey+i)%size;
            i++;
        }
        arr[key]=value;
        printf("\n%d is inserted at [%d]",value,key);
    }
}
void delete(int value)
{
    int key=value%size;
    if(arr[key]==value)
    {
        arr[key]=-1;
        printf("\n%d is deleted from [%d]",value,key);
    }
    else
    {
        int i=1;
        int originalkey=key;
        while(arr[key]!=-1 && arr[key]!=value)
        {
            key=(originalkey+i)%size;
            i++;
        }
        if(arr[key]==value)
        {
            arr[key]=-1;
            printf("\n%d is deleted from arr[%d]",value,key);
        }
        else
        {
            printf("\n%d is not present in the hash table",value);
        }
    }
}
void search(int value)
{
    int key=value%size;
    int i=1;
    int originalkey=key;
    while(arr[key]!=-1 && arr[key]!=value)
    {
        key=(originalkey+i)%size;
        i++;
    }
    if(arr[key]==value)
    {
        printf("\n%d is present at [%d]",value,key);
    }
    else
    {
        printf("\n%d is not found",value);
    }
}
void display()
{
    
    for(int i=0;i<size;i++)
    {
        printf("\narr[%d]=%d",i,arr[i]);
    }
}
int main()
{
    for(int i=0;i<size;i++)
    {
        arr[i]=-1;
    }
    insert(10);
    insert(39);
    insert(40);
    insert(59);
    delete(59);
    delete(37);
    search(40);
    search(39);
    search(59);
    display();
    return 0;
}
