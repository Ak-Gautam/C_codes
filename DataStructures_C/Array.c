// C program to create an array and perform basic opertaions using functions.

#include<stdio.h>
#include<stdlib.h>

void insert(int *, int);
void display(int *, int);
void delete(int *, int);
void search(int *, int);

int a[40];
int n;

int main()
{
    int ch, ele;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements in the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    do
    {
        printf("\n1. Insert an element\n2. Delete an element\n3. Search an element\n4. Display the array\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &ele);
            insert(a, ele);
            break;
        case 2:
            printf("Enter the element to be deleted: ");
            scanf("%d", &ele);
            delete(a, ele);
            break;
        case 3:
            printf("Enter the element to be searched: ");
            scanf("%d", &ele);
            search(a, ele);
            break;
        case 4:
            display(a, n);
            break;
        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 5);
    return 0;
}

void insert(int *a, int ele)
{
    int i, pos;
    printf("\nEnter the pos to insert the element[1-n]:\t");
    scanf("%d", &pos);
    a[pos-1] = ele;
}

void delete(int *a, int ele)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == ele)
        {
            a[i] = a[i+1];
        }
    }
    if (i == n)
    {
        printf("Element not found\n");
        return;
    }
    n--;
}

void display(int *a, int n)
{
    printf("\nThe array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void search(int *a, int ele)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == ele)
        {
            printf("Element found at location %d\n", i + 1);
            return;
        }
    }
    printf("Element not found\n");
}