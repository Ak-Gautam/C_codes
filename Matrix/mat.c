// C program to read a matrix and print the transpose of the matrix
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, n, m, mat[10][10];
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &n, &m);
    
    printf("Enter the elements of the matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("The matrix is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("The transpose of the matrix is: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    return 0;
}
