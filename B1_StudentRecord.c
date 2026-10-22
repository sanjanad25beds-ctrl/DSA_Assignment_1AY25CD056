#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll_no;
    char name[20];
    float marks;
};

int main()
{
    int n, i, add;
    float sum = 0, avg;
    struct Student *ptr, *temp, *topper;

    printf("Enter number of students: ");
    scanf("%d", &n);

    ptr = (struct Student *)malloc(n * sizeof(struct Student));

    if (ptr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter roll, name, marks: ");
        scanf("%d %19s %f",
              &(ptr+i)->roll_no,
              (ptr+i)->name,
              &(ptr+i)->marks);
    }

    topper = ptr;
    sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += (ptr+i)->marks;

        if ((ptr+i)->marks > topper->marks)
            topper = ptr+i;
    }

    avg = sum / n;

    printf("Average marks: %.2f\n", avg);
    printf("Topper: %s (Roll %d, Marks %.2f)\n",
           topper->name, topper->roll_no,
           topper->marks);

    printf("Add 2 more students? (1-Yes/0-No): ");
    scanf("%d", &add);

    if (add == 1)
    {
        temp = (struct Student *)realloc(
                    ptr, (n+2) * sizeof(struct Student));

        if (temp == NULL)
        {
            printf("Memory reallocation failed");
            free(ptr);
            return 1;
        }

        ptr = temp;

        for (i = n; i < n+2; i++)
        {
            printf("Enter roll, name, marks: ");
            scanf("%d %19s %f",
                  &(ptr+i)->roll_no,
                  (ptr+i)->name,
                  &(ptr+i)->marks);
        }

        n = n + 2;
        sum = 0;

        for (i = 0; i < n; i++)
            sum += (ptr+i)->marks;

        printf("Updated average marks: %.2f\n",
               sum / n);
    }

    free(ptr);

    return 0;
}
