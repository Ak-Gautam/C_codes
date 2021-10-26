// C program to implement stack using linked list

#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void insert(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = top;
    top = temp;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        struct node *temp = top;
        top = top->next;
        int data = temp->data;
        free(temp);
        return data;
    }
}

void display()
{
    struct node *temp = top;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    int ch, data;
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            data = pop();
            if(data != -1)
                printf("Popped data is %d\n", data);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Bye Homie\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}