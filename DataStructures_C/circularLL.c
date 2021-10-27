// A Circular linked list in C

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void beginsert ();   
void lastinsert ();  
//void randominsert();  
void begin_delete();  
void last_delete();  
//void random_delete();  
void display();  
void search();  

int main()
{
    printf("1.Insert Start\n2.Insert Last\n3.Delte Start\n4.Delete End\n");
    printf("5.Display\n6.Search\n7.Exit\n");
    int ch;
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            begin_delete();
            break;
        case 4:
            last_delete();
            break;
        case 5:
            display();
            break;
        case 6:
            search();
            break;
        case 7:
            printf("\tBye....\n");
            exit(0);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}

void beginsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOverflow !!!\n");
    else
    {
      printf("\nEnter the data: ");
      scanf("%d", &item);
      ptr->data = item;
      if(head==NULL)
      {
        head = ptr;
        ptr->next = head;
      }
      else
      {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOverflow\n");
    else
    {
        printf("\nEnter the data: ");
        scanf("%d", &item);
        ptr->data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = ptr;
            ptr->next= head;
        }
        printf("\nInserted Node\n");
    }
}

void begin_delete()
{
    struct node *ptr;
    if(head==NULL)
        printf("\nUnderflow\n");
    else if(head->next == head)
    {
        head=NULL;
        free(head);
        printf("\nDeleted successfull\n");
    }
    else
    {
        ptr = head;
        while(ptr->next != head)
            ptr = ptr->next;
        
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNode deleted\n");
    }
}

void last_delete()
{
    struct node *ptr, *preptr;
    if(head == NULL)
        printf("\nUnderflow!!!\n");
    else if(head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nNode deleted\n");        
    }
}

void search()
{
    struct node *ptr;
    int item, i=0, flag=1;
    ptr = head;
    if(ptr==NULL)
        printf("\nEmpty list\n");
    else
    {
        printf("\nEnter search item\n");
        scanf("%d", &item);
        if(head->data == item)
        {
            printf("\nItem found at %d\n", i+1);
            flag = 0;
        }
        else
        {
            while (ptr->next != head)
            {
                if(ptr->data == item)
                {
                    printf("\nItem found at %d\n", i+1);
                    flag = 0;
                    break;
                }
                else
                    flag = 0;
                i++;
                ptr = ptr->next;
            }
        }
        if(flag != 0)
            printf("\nItem not found\n");
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if(head == NULL)
        printf("\nEmpty list\n");
    else
    {
        printf("\nThe elemnets of the list are: \n");
        while(ptr->next != head)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ",ptr->data);
    }
}


