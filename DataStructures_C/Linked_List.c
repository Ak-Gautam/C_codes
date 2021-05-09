/* A program implementing linked list with insert, delete by position and delete by value feature. (without using extra variable for count)
*/
//Reversing the LinkedList

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;

void insert()
{
	int n;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to store\n");
	scanf("%d", &n);
	temp->data = n;
	temp->next = NULL;
	if(head == NULL)
		head = temp;
	else
	{	
		temp->next = head;
		head = temp;
	}
	return;
}

void del()
{
	int n,i;
	struct node* temp1 = head;
	printf("Enter the position of element to delete\n");
	scanf("%d", &n);
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	else if(n==0)
	{
		printf("Invalid pos\n");
		return;
	}
	else if(n==1)
	{
		head = (*temp1).next; //euivalent to temp1->next;
		free(temp1);
		return;
	}

	struct node* temp2 = NULL;
	for(i=0; i<n-2; i++)
		temp1 = temp1->next; //n-1 node
	temp2 = temp1->next; //n node
	temp1->next = temp2->next; //n-1 next field contains n+1 address
	free(temp2);
}


void display()
{
	struct node* temp = head;
	if(head == NULL)
	{
		printf("List is empty....\n");
		return;
	}
	printf("Element of the list:\n");
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp=temp->next;
	}
}

void delVal()
{
	struct node* temp = head;
	struct node* temp1 = NULL;
	int n, i;
	printf("Enter the value to delete\n");
	scanf("%d", &n);
	if(temp->data == n)
	{
		head = temp->next;
		free(temp);
		return;
	}
	while(temp != NULL)
	{
		temp1 = temp->next;
		if(temp1->data == n)
		{
			temp->next = temp1->next;
			free(temp1);
			return;
		}
		temp=temp->next;
	}
	printf("Element is not present\n");
	return;
}

void revList()
{
	struct node *temp, *prev, *next;
	temp=head;
	prev=NULL;
	while(temp!=NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev=temp;
		temp=next;
	}
	head = prev;
	printf("Reversed\n");
	return;
}


int main() {
	int ch;
  printf("1.Insert\n2.Delete\n3.Display\n4.Delete a value\n5.Reverse\n6.Exit\n");
	for(;;)
	{
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: insert();
							break;
			case 2: del();
							break;
			case 3: display();
							printf("\n");
							break;
			case 4: delVal();
							break;
			case 5: revList();
							break;			
			case 6: printf("Bye\n");
							exit(0);
			default:printf("Wrong choice, try again\n");
							break;
		}
	}
	
  return 0;
}