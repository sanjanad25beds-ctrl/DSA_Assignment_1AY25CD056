
#include <stdio.h>

typedef struct
{
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b)
{
    polynomial c;
    int i, exp;

    c.degree = (a.degree > b.degree)
               ? a.degree : b.degree;

    for (i = 0; i <= c.degree; i++)
    {
        exp = c.degree - i;
        c.coef[i] = 0;

        if (exp <= a.degree)
            c.coef[i] += a.coef[a.degree - exp];

        if (exp <= b.degree)
            c.coef[i] += b.coef[b.degree - exp];
    }

    return c;
}

void display(polynomial p)
{
    int i, exp, first = 1;
    float x;

    for (i = 0; i <= p.degree; i++)
    {
        x = p.coef[i];
        exp = p.degree - i;

        if (x == 0)
            continue;

        if (!first)
        {
            if (x > 0)
                printf(" + ");
            else
                printf(" - ");
        }
        else if (x < 0)
            printf("-");

        if (x < 0)
            x = -x;

        if (exp == 0)
            printf("%.2g", x);
        else if (exp == 1)
            printf("%.2gx", x);
        else
            printf("%.2gx^%d", x, exp);

        first = 0;
    }

    if (first)
        printf("0");

    printf("\n");
}

int main()
{
    polynomial a, b, c;
    int i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &a.degree);

    if (a.degree < 0 || a.degree > 100)
        return 1;

    printf("Enter coefficients from highest degree to constant:\n");

    for (i = 0; i <= a.degree; i++)
        scanf("%f", &a.coef[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &b.degree);

    if (b.degree < 0 || b.degree > 100)
        return 1;

    printf("Enter coefficients from highest degree to constant:\n");

    for (i = 0; i <= b.degree; i++)
        scanf("%f", &b.coef[i]);

    c = add(a, b);

    printf("\nFirst Polynomial: ");
    display(a);

    printf("Second Polynomial: ");
    display(b);

    printf("Resultant Polynomial: ");
    display(c);

    return 0;
}

