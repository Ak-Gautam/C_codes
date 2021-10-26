// Write a c program to sort an array using bubble sort

#include<stdio.h>
#include<stdlib.h>

void display();
void bubbleSort();

int main()
{
    int i,n,a[100];
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array is: \n");
    display(a,n);
    printf("Array after tyhe sort is:\n");
    bubbleSort(a,n);
    display(a,n);
    return 0;
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}