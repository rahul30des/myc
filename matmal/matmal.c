/* 
 * Fill 2 matrices and perform operations on them
 */
#include<stdio.h>
#include<stdlib.h>
void add(int ***mat1, int ***mat2, int *r1, int *c1, int *r2, int *c2);
void sub(int ***mat1, int ***mat2, int *r1, int *c1, int *r2, int *c2);
void multi(int ***mat1, int ***mat2, int *r1, int *c1, int *r2, int *c2);
void enter(int ***mat1, int ***mat2, int *r1, int *c1, int *r2, int *c2);
void display(int ***mat1, int ***mat2, int *r1, int *c1, int *r2, int *c2);
int main() 
{
    int **mat1 = NULL, **mat2 = NULL; 
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
    char ch = 0;
    enter(&mat1, &mat2, &row1, &col1, &row2, &col2);
    while (1) 
    {
        printf("\nMENU");
        printf("\n1 ADD");
        printf("\n2 SUB");
        printf("\n3 MULTI");
        printf("\n4 (RE)ENTER");
        printf("\n5 DISPLAY");
        printf("\n6 EXIT");
        printf("\nYour choice : ");
        do{
            scanf("%c", &ch);
        } while (ch == '\n');
        switch(ch) {
          case '1':
            add(&mat1, &mat2, &row1, &col1, &row2, &col2);
            break;
          case '2':
            sub(&mat1, &mat2, &row1, &col1, &row2, &col2);
            break;
          case '3':
            multi(&mat1, &mat2, &row1, &col1, &row2, &col2);
            break;
          case '4':
            enter(&mat1, &mat2, &row1, &col1, &row2, &col2);
            break;
          case '5':
            display(&mat1, &mat2, &row1, &col1, &row2, &col2);
            break;
          case '6':
            exit(0);
          default:
            break;
        }

    }
    return 0;
}

/*
 * Allocate memory to the matrices and fill them
 */
void enter(int ***m1, int ***m2, int *r1, int *c1, int *r2, int *c2) 
{
    int i = 0, j = 0;
    // Freeing up pointer for reuse
    if (*m1 != NULL) {
        for (i = 0; i < *r1; i++)
            free(*(*m1 +i));
        free(*m1);
    }
    printf("\n Enter number of rows in the first matrix : ");
    scanf("%d", r1); 
    printf("\n Enter number of columns in the first matrix : ");
    scanf("%d", c1); 

    // First Matrix
    *m1 = (int **) malloc(sizeof(int *) * (*r1));
    for (i = 0; i < *r1; i++)
        *(*m1 + i) = (int *) malloc(sizeof(int) * (*c1));
    
    printf("\n Enter the elements of the first matrix : ");

    for (i = 0; i < *r1; i++) 
    {
        for (j = 0; j < *c1; j++) 
        {
           scanf("%d", *(*m1 + i) + j);
        }
    }

    // Freeing up pointer for reuse
    if (*m2 != NULL) {
        for (i = 0; i < *r2; i++)
            free(*(*m2 +i));
        free(*m2);
    }

    printf("\n Enter number of rows in the second matrix : ");
    scanf("%d", r2); 
    printf("\n Enter number of columns in the second matrix : ");
    scanf("%d", c2); 
    // Second Matrix
    *m2 = (int **) malloc(sizeof(int *) * (*r2));
    for (i = 0; i < (*r2); i++)
        *(*m2 + i) = (int *) malloc(sizeof(int) * (*c2));
    
    printf("\n Enter the elements of the second matrix : ");

    for (i = 0; i < *r2; i++) 
    {
        for (j = 0; j < *c2; j++) 
        {
           scanf("%d", *(*m2 + i) + j);
        }
    }
}

void sub(int ***m1, int ***m2, int *r1, int *c1, int *r2, int *c2) 
{
    int i = 0, j = 0;
    int **m3 = NULL;
    if ((*r1 != *r2) || (*c1 != *c2))
    {
        printf("\n Subtraction not possible because number of rows/columns mismatch");
        return;
    } 
    
    m3 = (int **) malloc(sizeof(int *) * (*r1));
    for (i = 0; i < *r1; i++)
        *(m3 + i) = (int *) malloc(sizeof(int) * (*c1));

    // Subtraction logic
    for (i = 0; i < *r1; i++) 
    {
        for (j = 0; j < *c1; j++) 
        {
            *(*(m3 +i) + j) = *(*(*m1 +i) + j) - *(*(*m2 +i) + j); 
        }
    }

    printf("\n Subtraction matrix : \n");

    for (i = 0; i < *r1; i++) 
    {
        for (j = 0; j < *c1; j++) 
        {
           printf("%d", *(*m3 + i) + j);
        }
        printf("\n");
    }
}

void multi(int ***m1, int ***m2, int *r1, int *c1, int *r2, int *c2) 
{
    int i = 0, j = 0, k = 0;
    int **m3 = NULL;
    if (*c1 != *r2)
    {
        printf("\n Multiplication not possible because number of rows/columns mismatch");
        return;
    } 
    
    m3 = (int **) malloc(sizeof(int *) * (*r1));
    for (i = 0; i < *r1; i++)
        *(m3 + i) = (int *) malloc(sizeof(int) * (*c2));

    // Multiplication logic
    for (i = 0; i < *r1; i++) 
    {
        for (k = 0; k < *c2; k++) 
        {
            *(*(m3 +i) + k) = 0;
            for (j = 0; j < *c1; j++) 
            {
                *(*(m3 + i) + k) = (*(*(*m1 +i) + j)) * (*(*(*m2 +j) + k)) + *(*(m3 +i) + k); 
            }
        }
    }

    printf("\n Multiplication matrix : \n");

    for (i = 0; i < *r1; i++) 
    {
        for (k = 0; k < *c2; k++) 
        {
           printf("%d", *(*(m3 + i) + k));
        }
        printf("\n");
    }
}

void add(int ***m1, int ***m2, int *r1, int *c1, int *r2, int *c2) 
{
    int i = 0, j = 0;
    int **m3 = NULL;
    if ((*r1 != *r2) || (*c1 != *c2))
    {
        printf("\n Addition not possible because number of rows/columns mismatch");
        return;
    } 
    
    m3 = (int **) malloc(sizeof(int *) * (*r1));
    for (i = 0; i < *r1; i++)
        *(m3 + i) = (int *) malloc(sizeof(int) * (*c1));

    // Addition logic
    for (i = 0; i < *r1; i++) 
    {
        for (j = 0; j < *c1; j++) 
        {
            *(*(m3 +i) + j) = *(*(*m1 +i) + j) + *(*(*m2 +i) + j); 
        }
    }

    printf("\n Addition matrix : \n");

    for (i = 0; i < *r1; i++) 
    {
        for (j = 0; j < *c1; j++) 
        {
           printf("%d", *(*(m3 + i) + j));
        }
        printf("\n");
    }
}

/*
 * Display matrices
 */
void display(int ***m1, int ***m2, int *r1, int *c1, int *r2, int *c2) 
{
    int i = 0, j = 0;

    printf("\n First matrix : \n");

    for (i = 0; i < *r1; i++) 
    {
        for (j = 0; j < *c1; j++) 
        {
           printf("%d ", *(*(*m1 + i) + j));
        }
        printf("\n");
    }

    printf("\n Second matrix : \n");

    for (i = 0; i < *r2; i++) 
    {
        for (j = 0; j < *c2; j++) 
        {
           printf("%d ", *(*(*m2 + i) + j));
        }
        printf("\n");
    }
}

