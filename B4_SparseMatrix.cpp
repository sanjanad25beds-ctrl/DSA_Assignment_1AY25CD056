
#include <stdio.h>

#define MAX 100

typedef struct
{
    int row, col, value;
} term;

void fast_transpose(term a[], term b[])
{
    int row_terms[MAX] = {0};
    int starting_pos[MAX] = {0};
    int i, j, num_cols;

    num_cols = a[0].col;

    for (i = 1; i <= a[0].value; i++)
        row_terms[a[i].col]++;

    starting_pos[0] = 1;

    for (i = 1; i < num_cols; i++)
        starting_pos[i] =
        starting_pos[i-1] + row_terms[i-1];

    printf("\nRow Terms: ");
    for (i = 0; i < num_cols; i++)
        printf("%d ", row_terms[i]);

    printf("\nStarting Positions: ");
    for (i = 0; i < num_cols; i++)
        printf("%d ", starting_pos[i]);

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    for (i = 1; i <= a[0].value; i++)
    {
        j = starting_pos[a[i].col]++;

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

void display(term a[])
{
    int i;

    printf("\nRow\tColumn\tValue\n");

    for (i = 0; i <= a[0].value; i++)
        printf("%d\t%d\t%d\n",
               a[i].row, a[i].col, a[i].value);
}

int main()
{
    int matrix[MAX][MAX];
    int r, c, i, j, k = 1;

    term a[MAX], b[MAX];

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    if (r <= 0 || c <= 0 || r >= MAX || c >= MAX)
        return 1;

    printf("Enter matrix elements:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0)
            {
                a[k].row = i;
                a[k].col = j;
                a[k].value = matrix[i][j];
                k++;
            }
        }
    }

    a[0].row = r;
    a[0].col = c;
    a[0].value = k - 1;

    printf("\nOriginal Triples:");
    display(a);

    fast_transpose(a, b);

    printf("\nTransposed Triples:");
    display(b);

    printf("\nTransposed triples are in row-major order.\n");

    return 0;
}

