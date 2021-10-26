// C program to demonstrate Queue implemented using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
};

struct Queue *front = NULL;
struct Queue *rear = NULL;

void insert(int data)
{
    struct Queue *temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = data;
    temp->next = NULL;

    if(front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int delete()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        struct Queue *temp = front;
        front = front->next;
        return temp->data;
    }
}

void display()
{
    struct Queue *temp = front;
    if(temp == NULL)
    {
        printf("Queue is empty!!\n");
        return;
    }
    printf("The Queue is:\n");
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
    int choice, data;
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                data = delete();
                if(data != -1)
                    printf("Deleted element is %d\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

}
