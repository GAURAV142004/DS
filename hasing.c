//Hashing with Linear Probing
#include <stdio.h>
#include <stdlib.h>
#define size 10

int arr[size];
int i, choice;
int value;

void insert(int value)
{
    int key = value % size;

    if (arr[key] == -1)
    {
        arr[key]=value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision Occurs\n");
        int i = 1;
        int originalKey = key;
        while (arr[key] != -1)
        {
            key = (originalKey + i) % size;
            i++;
        }

        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
}

void delete(int value)
{
    int key = value % size;

    if (arr[key] == value)
    {
        arr[key] = -1;
        printf("%d deleted from arr[%d]\n", value, key);
    }
    else
    {
        int i = 1;
        int originalKey = key;
        while (arr[key] != -1 && arr[key] != value)
        {
            key = (originalKey + i) % size;
            i++;
        }

        if (arr[key] == value)
        {
            arr[key] = -1;
            printf("%d deleted from arr[%d]\n", value, key);
        }
        else
        {
            printf("%d not present in the hash table\n", value);
        }
    }
}


void search(int value)
{
    int key = value % size;
    int i = 1;
    int originalKey = key;
    while (arr[key] != -1 && arr[key] != value)
    {
        key = (originalKey + i) % size;
        i++;
    }

    if (arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void display()
{
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

int main()
{
    for (i = 0; i < size; i++)
    {
        arr[i] = -1;
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

