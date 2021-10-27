// C program to implement binary tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(struct node **root, int data)
{
    if (*root == NULL)
    {
        *root = newNode(data);
        return;
    }
    if (data <= (*root)->data)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}

int delete(struct node **root, int data)
{
    if (*root == NULL)
        return 0;
    if (data < (*root)->data)
        return delete(&(*root)->left, data);
    else if (data > (*root)->data)
        return delete(&(*root)->right, data);
    else
    {
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
            return 1;
        }
        else if ((*root)->left == NULL)
        {
            struct node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return 1;
        }
        else if ((*root)->right == NULL)
        {
            struct node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return 1;
        }
        else
        {
            struct node *temp = (*root)->right;
            while (temp->left != NULL)
                temp = temp->left;
            (*root)->data = temp->data;
            delete(&(*root)->right, temp->data);
        }
    }
}

//Display function to display the nodes in structured format
void display(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}

int main()
{
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    int choice, data, flag;
    struct node *root = NULL;
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            flag = delete(&root, data);
            if (flag == 1)
                printf("%d deleted\n", data);
            else
                printf("%d not found\n", data);
            break;
        case 3:
            display(root);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}