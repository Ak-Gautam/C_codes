// C program to create a circular Doubly Linked List andperform basic operations

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *head = NULL;

void insert_beginning();  
void insert_last();  
void delete_beginning();  
void delete_last();  
void display();  
void search();

int main()
{
    // printf("1.Insert at start\n2.Insert last\n3.Delete Start\n4.Delete last\n");
    // printf("5.Display\n6.Search\n7.Exit\n");
    int ch;
    while(1)
    {
        printf("1.Insert at start\n2.Insert last\n3.Delete Start\n4.Delete last\n");
        printf("5.Display\n6.Search\n7.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("color 5f");
            insert_beginning();
            system("color 0f");
            break;
        case 2:
            system("color 20");
            insert_last();
            system("color 0f");
            break;
        case 3:
            system("color 1f");
            delete_beginning();
            break;
        case 4:
            system("color 4f");
            delete_last();
            break;
        case 5:
            system("color 2f");
            display();
            break;
        case 6:
            system("color 3c");
            search();
            system("color 0f");
            break;
        case 7:
            system("cls");
            system("color 43");
            printf("\tBye ....\n");
            sleep(1);
            system("color 0f");
            system("cls");
            exit(0);
        
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}

void insert_beginning()
{
    struct node *temp, *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nMemory not allocated");
    else
    {
        printf("\nEnter the data: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
            head = ptr;
        }
        printf("\nInserted at beginning");
    }
}

void insert_last()
{
    struct node *temp, *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nMemory not allocated");
    else
    {
        printf("\nEnter the data: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
        printf("\nInserted at last");
    }
}

void delete_beginning()
{
    struct node *temp;
    if(head == NULL)
        printf("\nUnderflow");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nDeleted from beginning");
    }
    else
    {
        temp = head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
        printf("\nDeleted from beginning");
    }
}

void delete_last()
{
    struct node *temp;
    if(head == NULL)
        printf("\nUnderflow");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nDeleted from last");
    }
    else
    {
        temp = head;
        while(temp->next != head)
            temp = temp->next;
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
        printf("\nDeleted from last");
    }
}

void display()
{
    struct node *temp;
    if(head == NULL)
        printf("\nUnderflow");
    else
    {
        temp = head;
        printf("\nThe list is: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != head);
    }
}

void search()
{
    struct node *temp;
    int item,i=0, flag = 0;
    if(head == NULL)
        printf("\nUnderflow");
    else
    {
        printf("\nEnter the item to be searched: ");
        scanf("%d", &item);
        temp = head;
        do
        {
            if(temp->data == item)
            {
                printf("\nItem found at %d", i+1);
                flag = 1;
                break;
            }
            i++;
            temp = temp->next;
        }while(temp != head);
        if(flag == 0)
            printf("\nItem not found");
    }
}

