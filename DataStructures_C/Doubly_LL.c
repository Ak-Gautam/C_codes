#include <stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
  struct node* prev;
};

struct node* head = NULL;

void insert()
{
	int n;
	printf("Enter the element to insert\n");
	scanf("%d", &n);
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->next = head;
	temp->prev = NULL;
	head = temp;
	return;
}

void display()
{
	if(head == NULL)
	{
		printf("List is empty!!!");
		return;
	}

	struct node* temp = head;
	while(temp!=NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}



int main()
{
	int ch;
	printf("1.Insert\n2.Display\n3.Delete\n4.Exit\n");
	for(;;)
	{
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: insert();
							break;
			case 2: display();
							break;
			case 4: printf("Adios, Amigo....");
							exit(0);
			default: printf("Invalid choice, try again\n");
		}
	}
  return 0;
}