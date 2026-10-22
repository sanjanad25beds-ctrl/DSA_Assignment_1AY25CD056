
#include <stdio.h>
#include <stdlib.h>

enum Type
{
    FULL_TIME, CONTRACT
};

typedef struct
{
    char name[20];
    int emp_id;
    enum Type type;

    union
    {
        float salary;

        struct
        {
            float hourly_rate;
            int hours_worked;
        } contract_info;

    } pay;

} Employee;

int main()
{
    int n, i, type;
    float amount, total = 0;
    Employee *e;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    e = (Employee *)malloc(n * sizeof(Employee));

    if (e == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter employee name and ID: ");
        scanf("%19s %d", (e+i)->name, &(e+i)->emp_id);

        printf("Enter type (0-Full time, 1-Contract): ");
        scanf("%d", &type);

        if (type == 0)
        {
            (e+i)->type = FULL_TIME;

            printf("Enter monthly salary: ");
            scanf("%f", &(e+i)->pay.salary);
        }
        else if (type == 1)
        {
            (e+i)->type = CONTRACT;

            printf("Enter hourly rate and hours: ");
            scanf("%f %d",
            &(e+i)->pay.contract_info.hourly_rate,
            &(e+i)->pay.contract_info.hours_worked);
        }
        else
        {
            printf("Invalid employee type!");
            free(e);
            return 1;
        }
    }

    printf("\n----- EMPLOYEE PAYSLIPS -----\n");

    for (i = 0; i < n; i++)
    {
        if ((e+i)->type == FULL_TIME)
            amount = (e+i)->pay.salary;
        else
            amount = (e+i)->pay.contract_info.hourly_rate *
                     (e+i)->pay.contract_info.hours_worked;

        printf("\nEmployee: %s", (e+i)->name);
        printf("\nEmployee ID: %d", (e+i)->emp_id);
        printf("\nTotal Pay: %.2f\n", amount);

        total += amount;
    }

    printf("\nTotal Salary Bill: %.2f\n", total);

    free(e);

    return 0;
}

