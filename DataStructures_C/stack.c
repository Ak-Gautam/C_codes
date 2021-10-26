// c program to create a basic stack and perform pop, push and display

#include<stdio.h>
#include<stdlib.h>

void push(int);
int pop();
void display();

int top = -1;
int stack[40];

int main()
{
    int choice, item;
    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the item to be pushed: ");
                    scanf("%d", &item);
                    push(item);
                    break;
            case 2: item = pop();
                    if(item == -1)
                        printf("Stack is empty");
                    else
                        printf("Popped item is %d", item);
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Wrong choice");
        }
    }
    return 0;
}

void push(int item)
{
    if(top == 39)
    {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = item;
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty");
        return;
    }
    printf("Stack is: ");
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int pop()
{
    if(top == -1)
        return -1;
    return stack[top--];
}
