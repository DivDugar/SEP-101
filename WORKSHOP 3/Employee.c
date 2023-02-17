// Employee.c
// Divyanshu Dugar 
// Student ID : 177110210


#include <stdio.h>
#include "Employee.h"

#define SIZE 4 // Defining the size as 4 (That is the number of employees).

int main()
{
    struct Employee employees[SIZE] = { // initializing all the elements of the array of stuructures to 0.
        {0, 0, 0.0},
        {0, 0, 0.0},
        {0, 0, 0.0},
        {0, 0, 0.0}};

    printf("---=== EMPLOYEE DATA ===---\n"); 
    printf("1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\nPlease select from the above options: "); // printing the options to be selected by the user.

    int option;
    double newSalary = 0.0;

    do
    {
        scanf("%d", &option); // taking input from the user to perform a particular task.
        switch (option)
        {
        case 0:

            break;

        case 1: // Display employee data
            printf("EMP ID  EMP AGE EMP SALARY\n");
            printf("======  ======= ==========\n");

            for (int i = 0; i < SIZE; i++)
            {
                if (employees[i].id > 0) // if we have data we print it for the user
                {
                    printf("%6d%9d%11.2lf", employees[i].id, employees[i].age, employees[i].salary);
                    printf("\n");
                }
            }
            printf("\n");
            printf("1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\nPlease select from the above options: ");
            break;

        case 2: // Add employees
            printf("Adding Employee\n");
            printf("===============\n");

            for (int i = 0; i < SIZE; i++)
            {
                if (employees[i].id == 0) // If an open spot exists prompting the user for data (Employee id, age and salary).
                {
                    printf("Enter Employee ID: ");
                    scanf("%d", &employees[i].id);
                    printf("Enter Employee Age: ");
                    scanf("%d", &employees[i].age);
                    printf("Enter Employee Salary: ");
                    scanf("%lf", &employees[i].salary);
                    printf("\n");
                    printf("1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\nPlease select from the above options: ");
                    break;
                }
                if (i == SIZE - 1 && employees[i].id != 0) // If no spot left, prompting the user that max numbers of employees have reached
                {
                    printf("ERROR!!! Maximum Number of Employees Reached\n\n");
                    printf("1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\nPlease select from the above options: ");
                    break;
                }
            }
            break;

        case 3: // Updating the salary of the employees
            printf("Update Employee Salary\n");
            printf("======================\n");

            int emp_ID;
            int found = 0;
            do
            {
                printf("Enter Employee ID: ");
                scanf("%d", &emp_ID);
                for (int i = 0; i < SIZE; i++)
                {
                    if (emp_ID == employees[i].id)
                    {
                        found = 1;
                        printf("The current salary is %.2f\n", employees[i].salary);
                        printf("Enter Employee New Salary: ");
                        scanf("%lf", &newSalary);
                        employees[i].salary = newSalary;

                        printf("\n1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\nPlease select from the above options: ");
                        break;
                    }
                    if (i == SIZE - 1 && (emp_ID != employees[i].id)) // if id is not found till the end of the loop we promt the user id not found
                    {
                        printf("*** ERROR: Employee ID not found! ***\n");
                        break;
                    }
                }
            } while (found == 0);
            break;

        case 4: // Removing a data from the data base
            printf("Remove Employee\n");
            printf("===============\n");

            int emp_Id;
            int flag = 0;
            do
            {
                printf("Enter Employee ID: ");
                scanf("%d", &emp_Id);
                for (int i = 0; i < SIZE; i++)
                {
                    if (emp_Id == employees[i].id) // we compare and check if the id entered by the user is valid and is present in our data base
                    {
                        flag = 1;
                        printf("Employee %d will be removed\n", employees[i].id);
                        employees[i].id = 0;

                        printf("\n1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\nPlease select from the above options: ");
                        break;
                    }
                    if (i == SIZE - 1 && (emp_Id != employees[i].id)) // if we do not find the id entered by the user anywhere, we display an error message
                    {
                        printf("***ERROR! Employee Id Not found!***");
                        printf("\n");
                        break;
                    }
                }
            } while (flag == 0);

            break;

        default: // if the user enters an option out of the range, prompting him to enter a correct option.
            printf("ERROR: INCORRENT OPTION: Try Again\n\n");
            printf("1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\nPlease select from the above options: ");
            break;
        }
    } while (option != 0); // if the user enters 0 exiting the program.
    printf("Exiting Employee Data Program. Good Bye!!!\n");
    return 0;
}