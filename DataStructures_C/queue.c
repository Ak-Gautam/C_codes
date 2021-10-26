// C program to create a simple queue and perform basic operations on it

#include <stdio.h>
#include <stdlib.h>

void insert(int);
int delete();
void disp();

int queue[20];
int front=-1, back=-1;

int main()
{
    int ch, ele;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: printf("Enter the element to insert: ");
                scanf("%d", &ele);
                insert(ele);
                break;
        case 2: ele = delete();
                printf("Deleted item is %d\n",ele);
                break;
        case 3: disp();
                break;
        case 4: exit(0);
        default: printf("Wrong choice, try again\n");
            break;
        }
    }
}

void insert(int ele)
{
    if(back >= 20)
    {
        printf("Memory Full\n");
        return;
    }
    else
    {
        queue[++back] = ele;
        if(front == -1)
        {
            front++;
        }
        printf("Element inserted!\n");
    }
}

int delete()
{
    int ele;
    if(front == -1 && back == -1)
    {
        printf("Queue is empty !!\n");
        return 0;
    }
    else
    {
        ele = queue[front];
        front += 1;
        return ele;
    }
}

void disp()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        printf("The queue elements are:\n");
        for (i = front; i < back+1; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
        
    }
    
}